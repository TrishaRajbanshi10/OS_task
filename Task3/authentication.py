"""
ST5004CEM Operating Systems and Security
Task 3 - User Authentication

Author: Trisha Rajbanshi
"""

users = {
    "admin": "admin123",
    "student": "student123"
}


def login():
    print("=" * 50)
    print("USER AUTHENTICATION SYSTEM")
    print("=" * 50)

    username = input("Enter Username: ")
    password = input("Enter Password: ")

    if username in users:
        if users[username] == password:
            print("\nLogin Successful!")
            print(f"Welcome, {username}")
        else:
            print("\nIncorrect Password.")
    else:
        print("\nUser does not exist.")


if __name__ == "__main__":
    login()
