def encode(data: bytes) -> bytes:
    return bytes((~b) & 0xFF for b in data)

def main():
    key = "" // an internal ID seemingly derived from the password
    u = "example@gmail.com" // email of customer with valid cheat license 

    i = input("Enter i: ")
    c = input("Enter c: ")
    m = input("Enter m: ")
    n = input("Enter n: ")

    plaintext = f"key={key}&i={i}&c={c}&m={m}&u={u}&n={n}\r\n"
    encoded = encode(plaintext.encode("ascii"))

    print("PLAINTEXT:")
    print(repr(plaintext))
    print("\nHEX:")
    print(encoded.hex().upper())

if __name__ == "__main__":
    main()
