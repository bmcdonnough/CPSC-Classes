from socket import *
import sys, logging


class TCPClient:
    def __init__(self, host="127.0.0.1", port=65432):
        """
        Initializes the client instance with specified host and port.

        This constructor sets up the client with the necessary attributes for
        establishing a socket connection and initializes a logger for the client.

        Parameters:
            host (str): The host address for the socket connection. Defaults to '127.0.0.1'.
            port (int): The port number for the socket connection. Defaults to 65432.

        Usage Example:
            client = Client('192.168.0.1', 8080)

        Note:
            - This method should be called to create a Client instance before
              starting the client with the start() method.
        """
        # Initializes the logging configuration for the client
        self.logger = logging.getLogger("CLIENT")
        self.handler = logging.StreamHandler(sys.stdout)
        formatter = logging.Formatter('%(asctime)s - %(levelname)s - %(message)s')
        self.handler.setFormatter(formatter)
        self.logger.addHandler(self.handler)
        self.logger.propagate = False
        self.logger.info("Initializing client...")

        # TODO: Implement any initialization code you need
        self.host = host
        self.port = port
        self.client_socket = socket(AF_INET, SOCK_STREAM)

        


    def start(self):
        """
        Initiates a connection to the server and marks the client as running. This function
        does not attempt to send or receive any messages to or from the server.

        This method is responsible for establishing a socket connection to the specified
        server using the host and port attributes set during the client's initialization.
        It creates a TCP socket object, attempts to connect to the server, and sets the
        self.is_running attribute to True upon a successful connection. It logs
        the connection attempt and reports any errors encountered during the process.

        Exceptions:
            - socket.error: Raised if the socket encounters a problem (e.g., network
              issue, invalid host/port).

        Usage Example:
            client = Client('192.168.1.10', 12345)
            client.start()

        Note:
            - It is important to call this method before attempting to send or receive
              messages using the client.
            - Ensure that the server is up and running at the specified host and port
              before calling this method.
        """
        self.logger.info(f"Client is connecting to {self.host}:{self.port}...")

        # TODO: Implement the client-side logic described in the method description

        self.client_socket.connect((self.host, self.port))           
        self.is_running = True


    def run(self):
        """
        Manages the client-side interaction with a server using a socket connection.

        This method is responsible for querying the user for input, sending messages to
        the server, and handling server responses. It maintains an interactive loop for
        the user to input commands or data, which are then transmitted to the server.
        It also handles specific exceptions related to socket connections.

        The function should only be called after the client socket has been properly
        initialized and started with the start() method. An exception should be raised
        if this function is called prior to connecting to the server.

        The user can input operations (ADD, SUB, DIV, MUL) followed by operands,
        which are sent to the server for processing. The server's response is then
        received and displayed. If the user inputs 'quit', the loop terminates.

        The user should be given the following prompt for input:
        >> Enter operation (ADD/SUB/DIV/MUL) and operands (e.g., ADD 5 10) or 'quit' to exit:

        The user should log responses from the server using the following command:
        self.logger.info(f'Response from server: {data.decode()}')

        The following exceptions associated with sending and receicing should be handled
        appropriately (log and shutdown the client if appropriate).
        Exceptions:
            - ConnectionResetError: Raised if the server resets the connection.
            - ConnectionAbortedError: Raised if the server aborts the connection.
            - OSError: Captures and logs any other socket-related errors.

        The method ensures the client is properly shut down upon completion or in
        case of an exception, by calling the shutdown() method in a finally block.

        Usage Example:
            client_instance.run()

        Note:
            - Ensure the client is started with start() before calling this method.
            - This method is blocking and will continue running until 'quit' is entered
              or an exception occurs. Some exceptions indicate normal behavior and are
              expected with network communication. For instance, a ConnectionResetError
              can indicate that the server has terminated its socket and the client should
              clean up and close its socket as well.
        """
        self.logger.info("Client is running...")

        # TODO: Implement the client-side logic described in the method description
        while self.is_running:
            message = input('Enter operation (ADD/SUB/DIV) and operands (e.g., ADD 5 10) or quit to exit:')
            print(message)
            self.client_socket.send(message.encode())
            while message != 'quit':   
                answer = self.client_socket.recv(1024)
                self.logger.info(f'Response from server: {answer.decode()}')
                print(answer.decode())
                message = input('\nEnter another operation or type "quit" to finish:\n')
                self.client_socket.send(message.encode())

            self.shutdown()


    def shutdown(self):
        """
        Shuts down the client by stopping its operation and closing the socket.

        This method is responsible for cleanly terminating the client's operation.
        It indicates that the client is no longer in operation. If the client has an 
        active socket connection (client_socket is not None), it closes the socket 
        to ensure proper release of resources and network cleanup.

        The method logs the shutdown process, providing visibility into the client's
        state transitions. It's designed to be safely callable even if the socket is
        already closed or not initialized, preventing any unexpected exceptions during
        the shutdown process.

        Usage Example:
            client = Client('192.168.1.10', 12345)
            client.start()
            # ... operations ...
            client.shutdown()

        Note:
            - It is recommended to call this method to properly close the client,
              especially after completing all desired operations or in case of an error.
        """
        self.logger.info("Client is shutting down...")

        # TODO: Implement the client-side logic described in the method description

        self.logger.removeHandler(self.handler)

        self.is_running = False
        self.client_socket.close()


if __name__ == "__main__":
    client = TCPClient()
    client.start()
    client.run()
