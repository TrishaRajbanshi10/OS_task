"""
ST5004CEM Operating Systems and Security
Task 1 - Race Condition Demonstration

Author: Trisha Rajbanshi
"""

import threading
import time

counter = 0


def increment():
    global counter

    for _ in range(10000):
        temp = counter
        temp += 1
        counter = temp


def main():

    global counter

    print("=" * 60)
    print("RACE CONDITION DEMONSTRATION")
    print("=" * 60)

    threads = []

    for i in range(5):
        thread = threading.Thread(target=increment)
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()

    print(f"Expected Counter Value : 50000")
    print(f"Actual Counter Value   : {counter}")
    print("=" * 60)


if __name__ == "__main__":
    main()
