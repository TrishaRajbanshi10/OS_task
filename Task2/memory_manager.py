"""
ST5004CEM Operating Systems and Security
Task 2 - Memory Manager

Author: Trisha Rajbanshi
"""

from fifo import fifo_page_replacement
from lru import lru_page_replacement


REFERENCE_STRING = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2]
FRAMES = 3


def display_menu():
    print("\n" + "=" * 60)
    print("MEMORY MANAGEMENT SIMULATOR")
    print("=" * 60)
    print("1. FIFO Page Replacement")
    print("2. LRU Page Replacement")
    print("3. Compare FIFO and LRU")
    print("4. Exit")


def compare():
    print("\nRunning FIFO...\n")
    fifo_page_replacement(REFERENCE_STRING, FRAMES)

    print("\nRunning LRU...\n")
    lru_page_replacement(REFERENCE_STRING, FRAMES)


def main():

    while True:

        display_menu()

        choice = input("Enter your choice: ")

        if choice == "1":
            fifo_page_replacement(REFERENCE_STRING, FRAMES)

        elif choice == "2":
            lru_page_replacement(REFERENCE_STRING, FRAMES)

        elif choice == "3":
            compare()

        elif choice == "4":
            print("Exiting Memory Manager...")
            break

        else:
            print("Invalid Choice. Try Again.")


if __name__ == "__main__":
    main()
