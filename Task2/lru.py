"""
ST5004CEM Operating Systems and Security
Task 2 - Least Recently Used (LRU) Page Replacement

Author: Trisha Rajbanshi
"""

def lru_page_replacement(reference_string, frames):

    memory = []
    page_faults = 0

    print("=" * 60)
    print("LEAST RECENTLY USED (LRU) PAGE REPLACEMENT")
    print("=" * 60)

    for page in reference_string:

        # Page Hit
        if page in memory:
            memory.remove(page)
            memory.append(page)
            print(f"Page {page} -> HIT")

        else:
            page_faults += 1

            if len(memory) == frames:
                removed = memory.pop(0)
                print(f"Removed Page: {removed}")

            memory.append(page)
            print(f"Inserted Page: {page}")

        print("Frames:", memory)
        print("-" * 40)

    print("=" * 60)
    print(f"Total Page Faults : {page_faults}")
    print("=" * 60)


def main():

    reference_string = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2]

    frames = 3

    lru_page_replacement(reference_string, frames)


if __name__ == "__main__":
    main()
