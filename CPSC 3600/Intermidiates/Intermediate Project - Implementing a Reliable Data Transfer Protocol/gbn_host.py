from network_simulator import NetworkSimulator, EventEntity
from enum import Enum
from struct import pack, unpack

# We're importing the struct module below so we have access to the struct.error exception. We also import pack and 
# unpack above using from... import... for the convenience of writing pack() instead of struct.pack() 
import struct 

MAX_UNSIGNED_INT = 4294967295

class GBNHost():

    def __init__(self, simulator, entity, timer_interval, window_size):
        """ Initializes important values for GBNHost objects
        
        In addition to storing the passed in values, the values indicated in the initialization transition for the 
        GBN Sender and GBN Receiver finite state machines also need to be initialized. This has been done for you.
        
        Args:
            simulator (NetworkSimulator): contains a reference to the network simulator that will be used to communicate
                with other instances of GBNHost. You'll need to call four methods from the simulator: 
                pass_to_application_layer, pass_to_network_layer, start_timer, and stop_timer.
            entity (EventEntity): contains a value representing which entity this is. You'll need this when calling 
                any of functions in the simulator (the available functions are specified above).
            timer_interval (float): the amount of time that should pass before a timer expires
            window_size (int): the size of the window being used by this GBNHost
        Returns:
            nothing        
        """
        
        # These variables are relevant to the functionality defined in both the GBN Sender and Receiver FSMs
        self.simulator = simulator
        self.entity = entity
        self.window_size = window_size
        
        # The variables are relevant to the GBN Sender FSM
        self.timer_interval = timer_interval 
        self.window_base = 0
        self.next_seq_num = 0
        self.unacked_buffer = [None] * window_size  # Creates a list of length self.window_size filled with None values
        self.app_layer_buffer = []
        
        # These variables are relevant to the GBN Receiver FSM
        self.expected_seq_num = 0
        self.last_ack_pkt = self.create_ack_pkt(MAX_UNSIGNED_INT)
        
        

    def receive_from_application_layer(self, payload):
        """ Implements the functionality required to send packets received from simulated applications via the network 
            simualtor.
            
        This function will be called by the NetworkSimualtor when simulated data needs to be sent across the 
        network. It should implement all SENDING functionality from the GBN Sender FSM. Refer to the FSM for 
        implementation details.
            
        You'll need to call self.simulator.pass_to_network_layer(), self.simulator.start_timer(), and 
        self.simulator.stop_timer() in this function. Make sure you pass self.entity as the first argument when 
        calling any of these functions.
            
        Args:
            payload (string): the payload provided by a simulated application that needs to be sent
        Returns:
            nothing        
        """
        if(self.next_seq_num < self.window_base + self.window_size):
            if self.next_seq_num == len(self.unacked_buffer):
                self.unacked_buffer.append(self.create_data_pkt(self.next_seq_num, payload))
            else:
                self.unacked_buffer[self.next_seq_num] = self.create_data_pkt(self.next_seq_num, payload)
            
            self.simulator.pass_to_network_layer(self.entity, self.unacked_buffer[self.next_seq_num])

            if self.window_base == self.next_seq_num:
                self.simulator.start_timer(self.entity, self.timer_interval)
            self.next_seq_num += 1
        else:
            self.app_layer_buffer.append(payload)


    def receive_from_network_layer(self, packet):
        """ Implements the functionality required to receive packets received from simulated applications via the 
            network simualtor.
            
        This function will be called by the NetworkSimualtor when simulated packets are ready to be received from 
        the network. It should implement all RECEIVING functionality from the GBN Sender and GBN Receiver FSMs. 
        Refer to both FSMs for implementation details.
            
        Note that this is a more complex function to implement than receive_from_application_layer as it will 
        involve handling received data packets and acknowledgment packets separately. The logic for handling 
        received data packets is detailed in the GBN Receiver FSM and the logic for handling received acknowledgment 
        packets is detailed in the GBN Sender FSM.
        
        You'll need to call self.simulator.pass_to_application_layer() and self.simulator.pass_to_network_layer(), 
        in this function. Make sure you pass self.entity as the first argument when calling any of these functions.
        
        HINT: Remember that your default ACK message has a sequence number that is one less than 0, which turns into 
              4294967295 as it's unsigned int. When you check to make sure that the seq_num of an ACK message is 
              >= window_base you'll also want to make sure it is not 4294967295 since you won't want to update your 
              window_base value from that first default ack.
        
        Args:
            packet (bytes): the bytes object containing the packet data
        Returns:
            nothing        
        """
        try:
            if (self.is_corrupt(packet)):
                self.simulator.pass_to_network_layer(self.entity, self.last_ack_pkt)
                return
        
            packet_data = self.unpack_pkt(packet)
        except struct.error:
            self.simulator.pass_to_network_layer(self.entity, self.last_ack_pkt)
            return

        #Data
        packet_type = packet_data['packet_type']
        if (packet_type == 0x0):
            ack_num = packet_data['seq_num']
            payload = packet_data['payload']
            if ack_num == self.expected_seq_num:
                self.simulator.pass_to_application_layer(self.entity, payload)
                self.last_ack_pkt = self.create_ack_pkt(ack_num)
                self.simulator.pass_to_network_layer(self.entity, self.last_ack_pkt)
                self.expected_seq_num += 1
            else:
                self.simulator.pass_to_network_layer(self.entity, self.last_ack_pkt)  


        # Ack
        elif(packet_type == 0x1):
            ack_num = packet_data['seq_num']
            if ack_num >= self.window_base and ack_num != MAX_UNSIGNED_INT:
                self.window_base = ack_num + 1
                self.simulator.stop_timer(self.entity)
                if self.window_base != self.next_seq_num:
                    self.simulator.start_timer(self.entity, self.timer_interval)
                while len(self.app_layer_buffer) > 0 and self.next_seq_num < self.window_base + self.window_size:
                    payload = self.app_layer_buffer.pop(0)                    
                    if self.next_seq_num == len(self.unacked_buffer):
                        self.unacked_buffer.append(self.create_data_pkt(self.next_seq_num, payload))
                    else:
                        self.unacked_buffer[self.next_seq_num] = self.create_data_pkt(self.next_seq_num, payload)
                    self.simulator.pass_to_network_layer(self.entity, self.unacked_buffer[self.next_seq_num])
                    if self.window_base == self.next_seq_num:
                        self.simulator.start_timer(self.entity, self.timer_interval)
                    self.next_seq_num += 1
            
            
    

    def timer_interrupt(self):
        """ Implements the functionality that handles when a timeout occurs for the oldest unacknowledged packet
        
        This function will be called by the NetworkSimulator when a timeout occurs for the oldest unacknowledged packet 
        (i.e. too much time as passed without receiving an acknowledgment for that packet). It should implement the 
        appropriate functionality detailed in the GBN Sender FSM. 

        You'll need to call self.simulator.start_timer() in this function. Make sure you pass self.entity as the first 
        argument when calling this functions.
        
        Args:
            None
        Returns:
            None        
        """
        for i in range(self.window_base, self.next_seq_num):
            self.simulator.pass_to_network_layer(self.entity, self.unacked_buffer[i])
        self.simulator.start_timer(self.entity, self.timer_interval)
    
    
    def create_data_pkt(self, seq_num, payload):
        """ Create a data packet with a given sequence number and variable length payload
        
        Data packets contain the following fields:
            packet_type (unsigned half): this should always be 0x0 for data packets
            seq_num (unsigned int): this should contain the sequence number for this packet
            checksum (unsigned half): this should contain the checksum for this packet
            payload_length (unsigned int): this should contain the length of the payload
            payload (varchar string): the payload contains a variable length string
        
        Note: generating a checksum requires a bytes object containing all of the packet's data except for the checksum 
              itself. It is recommended to first pack the entire packet with a placeholder value for the checksum 
              (i.e. 0), generate the checksum, and to then repack the packet with the correct checksum value.
        
        Args:
            seq_num (int): the sequence number of this packet
            payload (string): the variable length string that should be included in this packet
        Returns:
            bytes: a bytes object containing the required fields for a data packet
        """
        packet_type = 0x0
        payload_length = len(payload)
        encoded_payload = payload.encode()
        checksum = (self.create_checksum(struct.pack(f"!HIHI{payload_length}s", packet_type, seq_num, 0, payload_length, encoded_payload)))
        struct_format = f"!HIHI{payload_length}s"
        return struct.pack(struct_format, packet_type, seq_num, checksum, payload_length, encoded_payload)

    
    def create_ack_pkt(self, seq_num):
        """ Create an acknowledgment packet with a given sequence number
        
        Acknowledgment packets contain the following fields:
            packet_type (unsigned half): this should always be 0x1 for ack packets
            seq_num (unsigned int): this should contain the sequence number of the packet being acknowledged
            checksum (unsigned half): this should contain the checksum for this packet
        
        Note: generating a checksum requires a bytes object containing all of the packet's data except for the checksum 
              itself. It is recommended to first pack the entire packet with a placeholder value for the checksum 
              (i.e. 0), generate the checksum, and to then repack the packet with the correct checksum value.
        
        Args:
            seq_num (int): the sequence number of this packet
            payload (string): the variable length string that should be included in this packet
        Returns:
            bytes: a bytes object containing the required fields for a data packet
        """
        packet_type = 0x1
        checksum = (self.create_checksum(struct.pack(f'!HIH', packet_type, seq_num, 0)))
        struct_format = f"!HIH"
        return struct.pack(struct_format, packet_type, seq_num, checksum)



    # This function should accept a bytes object and return a checksum for the bytes object. 
    def create_checksum(self, packet):
        """ Create an Internet checksum for a given bytes object
        
        This function should return a checksum generated using the Internet checksum algorithm. The value you compute 
        should be able to be represented as an unsigned half (i.e. between 0 and 65536). In general, Python stores most
        numbers as ints. You do *not* need to cast your computed checksum to an unsigned half when returning it. This 
        will be done when packing the checksum.
        
        Args:
            packet (bytes): the bytes object that the checksum will be based on
        Returns:
            int: the checksum value
        """
        checksum = 0
        if len(packet) % 2 == 1:
            packet += bytes(1)
        for i in range(0, len(packet), 2):
            word = ((packet[i] << 8) | packet[i + 1])
            result = word + checksum
            checksum = (result & 0xFFFF) + (result >> 16)
        return ((~checksum) & 0xffff)  
    
    def unpack_pkt(self, packet):
        """ Create a dictionary containing the contents of a given packet
        
        This function should unpack a packet and return the values it contains as a dictionary. Valid dictionary keys 
        include: "packet_type", "seq_num", "checksum", "payload_length", and "payload". Only include keys that have 
        associated values (i.e. "payload_length" and "payload" are not needed for ack packets). The packet_type value 
        should be either 0x0 or 0x1. It should not be represented a bool
        
        Note: unpacking a packet is generally straightforward, however it is complicated if the payload_length field is
              corrupted. In this case, you may attempt to unpack a payload larger than the actual available data. This 
              will result in a struct.error being raised with the message "unpack requires a buffer of ## bytes". THIS
              IS EXPECTED BEHAVIOR WHEN PAYLOAD_LENGTH IS CORRUPTED. It indicates that the packet has been corrupted, 
              not that you've done something wrong (unless you're getting this on tests that don't involve corruption).
              If this occurs, treat this packet as a corrupted packet. 
              
              I recommend wrapping calls to unpack_pkt in a try... except... block that will catch the struct.error 
              exception when it is raised. If this exception is raised, then treat the packet as if it is corrupted in 
              the function calling unpack_pkt().
        
        Args:
            packet (bytes): the bytes object containing the packet data
        Returns:
            dictionary: a dictionary containing the different values stored in the packet
        """
        try:
            unpackedStruct = struct.unpack(f"!HIH", packet[:struct.calcsize(f"!HIH")])
        except struct.error:
            return None
        

        packet_type, seq_num, checksum = unpackedStruct
        if(packet_type == 0x1):
            return {'packet_type': packet_type, 'seq_num': seq_num, 'checksum': checksum}
        elif(packet_type != 0x0):
            return None
        
        try:
            unpacked_PL_length = struct.unpack(f"!I", packet[struct.calcsize(f"!HIH"):struct.calcsize(f"!HIH") + struct.calcsize(f"!I")])
            payload_length = unpacked_PL_length[0]
            unpacked_PL = struct.unpack(f"!{payload_length}s", packet[struct.calcsize(f"!HIHI"):struct.calcsize(f"!HIHI") + payload_length])
            payload = unpacked_PL[0].decode()
            return {'packet_type': packet_type, 
                    'seq_num': seq_num, 
                    'checksum': checksum, 
                    'payload_length': payload_length, 
                    'payload': payload}
        except:
            return None

    
    # This function should check to determine if a given packet is corrupt. The packet parameter accepted
    # by this function should contain a bytes object
    def is_corrupt(self, packet):
        """ Determine whether a packet has been corrupted based on the included checksum

        This function should use the included Internet checksum to determine whether this packet has been corrupted.        
        
        Args:
            packet (bytes): a bytes object containing a packet's data
        Returns:
            bool: whether or not the packet data has been corrupted
        """        
        return self.create_checksum(packet) != 0
