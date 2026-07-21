"""
ST5004CEM Operating Systems and Security
Task 3 - Audit Logging

Author: Trisha Rajbanshi
"""

from datetime import datetime

LOGFILE = "log.txt"


def write_log(action):

    with open(LOGFILE, "a") as log:

        log.write(f"{datetime.now()} - {action}\n")

    print("Action Recorded Successfully.")


def view_log():

    try:

        with open(LOGFILE, "r") as log:

            print("\n========== AUDIT LOG ==========\n")

            print(log.read())

    except FileNotFoundError:

        print("No Log File Found.")


def menu():

    while True:

        print("\n" + "=" * 50)
        print("AUDIT LOG")
        print("=" * 50)

        print("1. Record Login")
        print("2. Record File Created")
        print("3. Record File Deleted")
        print("4. View Log")
        print("5. Exit")

        choice = input("Enter Choice: ")
        if choice == "1":
            write_log("User Login")

        elif choice == "2":
            write_log("File Created")

        elif choice == "3":
            write_log("File Deleted")

        elif choice == "4":
            view_log()

        elif choice == "5":
            print("Exiting...")
            break

        else:
            print("Invalid Choice.")

if __name__ == "__main__":
    menu()
