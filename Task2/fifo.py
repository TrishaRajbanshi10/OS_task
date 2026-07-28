"""
ST5004CEM Operating Systems and Security
Task 2 - FIFO Page Replacement

Author: Trisha Rajbanshi
"""

from collections import deque


def fifo_page_replacement(reference_string, frames):
    memory = deque()
    page_faults = 0

    print("=" * 60)
    print("FIFO PAGE REPLACEMENT")
    print("=" * 60)

    for page in reference_string:

        if page not in memory:

            page_faults += 1

            if len(memory) == frames:
                removed = memory.popleft()
                print(f"Removed Page: {removed}")

            memory.append(page)
            print(f"Inserted Page: {page}")

        else:
            print(f"Page {page} -> HIT")

        print("Frames:", list(memory))
        print("-" * 40)

    print("=" * 60)
    print(f"Total Page Faults : {page_faults}")
    print("=" * 60)


def main():

    reference_string = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2]

    frames = 3

    fifo_page_replacement(reference_string, frames)


if __name__ == "__main__":
    main()
