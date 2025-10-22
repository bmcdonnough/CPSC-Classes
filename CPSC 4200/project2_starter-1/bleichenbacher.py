#!/usr/bin/python3

# Run me like this:
# $ python3 bleichenbacher.py "coach+username+100.00"
# or select "Bleichenbacher" from the VS Code debugger

from roots import * 

import hashlib
import sys


def main():
    if len(sys.argv) < 2:
        print(f"usage: {sys.argv[0]} MESSAGE", file=sys.stderr)
        sys.exit(-1)
    message = sys.argv[1]

    # Generate a hash of the message using SHA-256
    message_hash = hashlib.sha256(message.encode()).digest()
    
    # PKCS#1 v1.5 padding prefix for SHA-256
    asn1_magic_bytes = bytes.fromhex('3031300d060960864801650304020105000420')
    message_with_asn = asn1_magic_bytes + message_hash
    
    block = bytes.fromhex("0001FF00") + message_with_asn

    padding_len = 256 - len(block)
    block = block + (b'\00' * padding_len)


    # Convert to integer
    m = bytes_to_integer(block)
    
    # Find the smallest e-th root of m (where e = 3 is typical)
    e = 3
    c, exact = integer_nthroot(m, e)  # Unpack both values from the tuple
    
    # Check if we need to increase to get a perfect e-th root
    if pow(c, e) < m:
        c += 1

    forged_signature = c
    print(bytes_to_base64(integer_to_bytes(forged_signature, 256)))


if __name__ == '__main__':
    main()

