"""
ST5004CEM Operating Systems and Security
Task 3 - File Manager

Author: Trisha Rajbanshi
"""

import os

FILENAME = "xyz.txt"


def create_file():
    with open(FILENAME, "w") as file:
        file.write("Welcome to ST5004 Operating Systems Assignment.\n")
    print("✓ File created successfully.")


def write_file():
    text = input("Enter text to append: ")
    with open(FILENAME, "a") as file:
        file.write(text + "\n")
    print("✓ Text added successfully.")


def read_file():
    if os.path.exists(FILENAME):
        print("\n----- File Content -----")
        with open(FILENAME, "r") as file:
            print(file.read())
        print("------------------------")
    else:
        print("File does not exist.")


def delete_file():
    if os.path.exists(FILENAME):
        os.remove(FILENAME)
        print("✓ File deleted successfully.")
    else:
        print("File does not exist.")


def menu():
    while True:
        print("\n" + "=" * 50)
        print("FILE MANAGER")
        print("=" * 50)
        print("1. Create File")
        print("2. Write to File")
        print("3. Read File")
        print("4. Delete File")
        print("5. Exit")

        choice = input("Enter your choice: ")

        if choice == "1":
            create_file()
        elif choice == "2":
            write_file()
        elif choice == "3":
            read_file()
        elif choice == "4":
            delete_file()
        elif choice == "5":
            print("Exiting File Manager...")
            break
        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
    menu()
