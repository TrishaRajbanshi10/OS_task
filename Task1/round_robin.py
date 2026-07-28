"""
ST5004CEM Operating Systems and Security
Task 1 - Round Robin Scheduling Simulation

Author: Trisha Rajbanshi
"""

from collections import deque
import time


class Process:
    def __init__(self, pid, burst_time):
        self.pid = pid
        self.burst_time = burst_time


def round_robin(processes, quantum):
    queue = deque(processes)

    print("=" * 60)
    print("ROUND ROBIN CPU SCHEDULER")
    print("=" * 60)

    while queue:

        process = queue.popleft()

        execution_time = min(quantum, process.burst_time)

        print(f"\nRunning {process.pid}")
        print(f"CPU Time Used : {execution_time}")

        time.sleep(1)

        process.burst_time -= execution_time

        if process.burst_time > 0:
            print(f"Remaining Burst Time : {process.burst_time}")
            queue.append(process)

        else:
            print(f"{process.pid} Completed Successfully.")

    print("\nAll Processes Completed.")
    print("=" * 60)


def main():

    processes = [

        Process("P1", 5),

        Process("P2", 3),

        Process("P3", 7)

    ]

    quantum = 2

    round_robin(processes, quantum)


if __name__ == "__main__":
    main()
