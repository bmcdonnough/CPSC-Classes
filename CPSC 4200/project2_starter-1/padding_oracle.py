#!/usr/bin/python3

# Run me like this:
# $ python3 padding_oracle.py "http://cpsc4200.mpese.com/username/paddingoracle/verify" "5a7793d3..."
# or select "Padding Oracle" from the VS Code debugger

import json
import sys
import time
from typing import Union, Dict, List

import requests

# Create one session for each oracle request to share. This allows the
# underlying connection to be re-used, which speeds up subsequent requests!
s = requests.session()


def oracle(url: str, messages: List[bytes]) -> List[Dict[str, str]]:
    while True:
        try:
            r = s.post(url, data={"message": [m.hex() for m in messages]})
            r.raise_for_status()
            return r.json()
        # Under heavy server load, your request might time out. If this happens,
        # the function will automatically retry in 10 seconds for you.
        except requests.exceptions.RequestException as e:
            sys.stderr.write(str(e))
            sys.stderr.write("\nRetrying in 10 seconds...\n")
            time.sleep(10)
            continue
        except json.JSONDecodeError as e:
            sys.stderr.write("It's possible that the oracle server is overloaded right now, or that provided URL is wrong.\n")
            sys.stderr.write("If this keeps happening, check the URL. Perhaps your uniqname is not set.\n")
            sys.stderr.write("Retrying in 10 seconds...\n\n")
            time.sleep(10)
            continue


def main():
    if len(sys.argv) != 3:
        print(f"usage: {sys.argv[0]} ORACLE_URL CIPHERTEXT_HEX", file=sys.stderr)
        sys.exit(-1)
    oracle_url, message = sys.argv[1], bytes.fromhex(sys.argv[2])

    if oracle(oracle_url, [message])[0]["status"] != "valid":
        print("Message invalid", file=sys.stderr)

    block_size = 16
    plaintext_blocks = []

    blocks = [message[i:i+block_size] for i in range(0,len(message),block_size)]

    for block in range(1, len(blocks)):
        current_block = blocks[block]
        prev_block = blocks[block-1]
        plaintext_bytes = bytearray(block_size)
        intermediate_bytes = bytearray(block_size)

        # Go through all of the bytes going from right to left
        for byte_pos in range(block_size - 1, -1, -1):
            prev_block_copy = bytearray(prev_block)

            found = False

            # Calculate what the padding value should be
            padding_val = block_size - byte_pos

            # Make sure to set the bytes already figured out
            for i in range(block_size - 1, byte_pos, -1):
                prev_block_copy[i] = intermediate_bytes[i] ^ padding_val

            messages = []

            # Try all possible values for the current byte
            for k in range(0, 256):
                orig_byte = prev_block_copy[byte_pos]
                prev_block_copy[byte_pos] = k

                messages.append(bytes(prev_block_copy) + current_block) 
            
            responses = oracle(oracle_url, messages)

            for k, response in enumerate(responses):
                if response["status"] != "invalid_padding":
                    #Yippee
                    intermediate_bytes[byte_pos] = k ^ padding_val
                    plaintext_bytes[byte_pos] = prev_block[byte_pos] ^ intermediate_bytes[byte_pos]
                    found = True
                    break
            
            if not found:
                print((b''.join(plaintext_blocks)).decode("utf-8", errors="replace"))
                sys.exit(-1)

        plaintext_blocks.append(plaintext_bytes)

    plaintext_message = b"".joinplaintext_blocks
    decrypted = bytes(plaintext_bytes)
    print(decrypted)


if __name__ == '__main__':
    main()

