import threading
import time

# Shared resource
counter = 0

# Lock for synchronization
lock = threading.Lock()


def task(name):
    global counter

    for i in range(5):
        # Only one thread can enter this block at a time
        with lock:
            counter += 1
            print(f"{name} increased counter to {counter}")

        time.sleep(0.5)

    print(f"{name} has finished.\n")


def main():
    print("=" * 50)
    print("Task 1 - Thread Synchronization")
    print("=" * 50)

    threads = []

    for i in range(3):
        thread = threading.Thread(target=task, args=(f"Thread {i+1}",))
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()

    print("=" * 50)
    print(f"Final Counter Value: {counter}")
    print("All threads completed successfully.")
    print("=" * 50)


if __name__ == "__main__":
    main()
