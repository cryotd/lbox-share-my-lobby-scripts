import time
import requests

def send_payload(hex_string: str):
    hex_string = hex_string.replace(" ", "").strip()
    data = bytes.fromhex(hex_string)

    url = "https://lmaobox.net/sl/"

    response = requests.post(
        url,
        data=data,
        headers={
            "Content-Type": "application/octet-stream"
        },
        timeout=10
    )

    print(f"[{time.strftime('%H:%M:%S')}] Status:", response.status_code)
    print(response.text)
    print("-" * 50)


def main():
    hex_input = input("Enter hex payload: ")

    while True:
        try:
            send_payload(hex_input)
        except Exception as e:
            print("Error:", e)

        time.sleep(120)  # 2 minutes


if __name__ == "__main__":
    main()
