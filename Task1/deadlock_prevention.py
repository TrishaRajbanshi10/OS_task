"""
ST5004CEM Operating Systems and Security
Task 1 - Deadlock Prevention

Author: Trisha Rajbanshi
"""

import threading
import time

lock1 = threading.Lock()
lock2 = threading.Lock()


def worker(thread_name):

    print(f"{thread_name} is waiting for Lock 1")

    with lock1:

        print(f"{thread_name} acquired Lock 1")

        time.sleep(1)

        print(f"{thread_name} is waiting for Lock 2")

        with lock2:

            print(f"{thread_name} acquired Lock 2")
            print(f"{thread_name} is executing safely.\n")


def main():

    print("=" * 60)
    print("DEADLOCK PREVENTION")
    print("=" * 60)

    t1 = threading.Thread(target=worker, args=("Thread-1",))
    t2 = threading.Thread(target=worker, args=("Thread-2",))

    t1.start()
    t2.start()

    t1.join()
    t2.join()

    print("=" * 60)
    print("Program completed without deadlock.")
    print("=" * 60)


if __name__ == "__main__":
    main()
