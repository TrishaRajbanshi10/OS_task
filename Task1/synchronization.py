"""
ST5004CEM Operating Systems and Security
Task 1 - Thread Synchronization using Lock

Author: Trisha Rajbanshi
"""

import threading
import time

# Shared resource
counter = 0

# Mutex Lock
lock = threading.Lock()


def increment_counter(thread_name):
    global counter

    for i in range(5):

        # Only one thread can access this section
        with lock:
            current = counter
            print(f"{thread_name} is accessing the counter...")

            time.sleep(0.2)

            counter = current + 1

            print(f"{thread_name} updated counter to {counter}")

        time.sleep(0.3)

    print(f"{thread_name} completed.\n")


def main():

    print("=" * 60)
    print("TASK 1 - THREAD SYNCHRONIZATION")
    print("=" * 60)

    threads = []

    for i in range(3):
        thread = threading.Thread(
            target=increment_counter,
            args=(f"Thread-{i+1}",)
        )

        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()

    print("=" * 60)
    print("Final Counter Value:", counter)
    print("=" * 60)


if __name__ == "__main__":
    main()
