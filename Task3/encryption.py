"""
ST5004CEM Operating Systems and Security
Task 3 - File Encoding and Decoding using Base64

Author: Trisha Rajbanshi
"""

import base64

FILENAME = "sample.txt"


def encode_file():
    try:
        with open(FILENAME, "r") as file:
            data = file.read()

        encoded = base64.b64encode(data.encode()).decode()

        with open(FILENAME, "w") as file:
            file.write(encoded)

        print("File encoded successfully.")

    except FileNotFoundError:
        print("File not found.")


def decode_file():
    try:
        with open(FILENAME, "r") as file:
            data = file.read()

        decoded = base64.b64decode(data.encode()).decode()

        with open(FILENAME, "w") as file:
            file.write(decoded)

        print("File decoded successfully.")

    except FileNotFoundError:
        print("File not found.")


def menu():

    while True:

        print("\n" + "=" * 50)
        print("FILE ENCODER / DECODER")
        print("=" * 50)

        print("1. Encode File")
        print("2. Decode File")
        print("3. Exit")

        choice = input("Enter Choice: ")

        if choice == "1":
            encode_file()

        elif choice == "2":
            decode_file()

        elif choice == "3":
            print("Goodbye!")
            break

        else:
            print("Invalid Choice.")


if __name__ == "__main__":
    menu()
