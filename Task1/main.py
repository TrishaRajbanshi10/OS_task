import threading
import time


def task(name):
    """
    Function executed by each thread.
    """
    for i in range(5):
        print(f"{name} is running... Step {i + 1}")
        time.sleep(1)

    print(f"{name} has finished.\n")


def main():
    print("=" * 50)
    print("Task 1 - Process Management and Threading")
    print("=" * 50)

    thread1 = threading.Thread(target=task, args=("Thread 1",))
    thread2 = threading.Thread(target=task, args=("Thread 2",))
    thread3 = threading.Thread(target=task, args=("Thread 3",))

    thread1.start()
    thread2.start()
    thread3.start()

    thread1.join()
    thread2.join()
    thread3.join()

    print("=" * 50)
    print("All threads completed successfully.")
    print("=" * 50)


if __name__ == "__main__":
    main()
