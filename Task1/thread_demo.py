"""
ST5004CEM Operating Systems and Security
Task 1 - Basic Multithreading

Author: Trisha Rajbanshi
"""

import threading
import time


def worker(thread_name):
    """Function executed by each thread."""
    for step in range(1, 6):
        print(f"{thread_name} -> Working... Step {step}")
        time.sleep(1)

    print(f"{thread_name} completed.\n")


def main():
    print("=" * 60)
    print("TASK 1 - BASIC MULTITHREADING")
    print("=" * 60)

    threads = []

    for i in range(3):
        thread = threading.Thread(
            target=worker,
            args=(f"Thread-{i+1}",)
        )
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()

    print("=" * 60)
    print("All threads finished successfully.")
    print("=" * 60)


if __name__ == "__main__":
    main()

