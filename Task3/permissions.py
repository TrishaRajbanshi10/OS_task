"""
ST5004CEM Operating Systems and Security
Task 3 - File Permissions

Author: Trisha Rajbanshi
"""

import os
import stat

FILENAME = "sample.txt"


def show_permissions():

    if not os.path.exists(FILENAME):
        print("File does not exist.")
        return

    permissions = oct(os.stat(FILENAME).st_mode)[-3:]

    print("=" * 50)
    print("CURRENT FILE PERMISSIONS")
    print("=" * 50)
    print(f"File: {FILENAME}")
    print(f"Permissions: {permissions}")


def make_read_only():

    if os.path.exists(FILENAME):
        os.chmod(FILENAME, stat.S_IREAD)
        print("File changed to Read Only.")
    else:
        print("File does not exist.")


def make_read_write():

    if os.path.exists(FILENAME):
        os.chmod(FILENAME, stat.S_IREAD | stat.S_IWRITE)
        print("File changed to Read and Write.")
    else:
        print("File does not exist.")


def menu():

    while True:

        print("\n" + "=" * 50)
        print("FILE PERMISSION MANAGER")
        print("=" * 50)

        print("1. Show Permissions")
        print("2. Make Read Only")
        print("3. Make Read and Write")
        print("4. Exit")

        choice = input("Enter choice: ")

        if choice == "1":
            show_permissions()

        elif choice == "2":
            make_read_only()

        elif choice == "3":
            make_read_write()

        elif choice == "4":
            print("Exiting...")
            break

        else:
            print("Invalid Choice.")


if __name__ == "__main__":
    menu()
