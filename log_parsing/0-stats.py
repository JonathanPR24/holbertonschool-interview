#!/usr/bin/python3
import sys
from collections import defaultdict

def print_statistics(total_size, status_counts):
    print(f"File size: {total_size}")
    for code, count in sorted(status_counts.items()):
        print(f"{code}: {count}")

def main():
    total_size = 0
    status_counts = defaultdict(int)
    line_count = 0

    try:
        for line in sys.stdin:
            line = line.strip()
            parts = line.split()
            if len(parts) != 7:
                continue

            ip, _, _, status_code, file_size = parts[0], parts[3], parts[5], parts[6]
            if not status_code.isdigit():
                continue

            status_code = int(status_code)
            file_size = int(file_size)

            total_size += file_size
            status_counts[status_code] += 1
            line_count += 1

            if line_count % 10 == 0:
                print_statistics(total_size, status_counts)

    except KeyboardInterrupt:
        print_statistics(total_size, status_counts)

if __name__ == "__main__":
    main()
