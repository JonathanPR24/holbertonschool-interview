#!/usr/bin/python3
import sys
import signal

# Initialize variables to store statistics
total_size = 0
status_code_count = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0

# Function to handle SIGINT (Ctrl+C)
def signal_handler(sig, frame):
    print_stats()
    sys.exit(0)

# Function to print statistics
def print_stats():
    global total_size, status_code_count
    print("File size:", total_size)
    for status_code in sorted(status_code_count.keys()):
        if status_code_count[status_code] > 0:
            print(f"{status_code}: {status_code_count[status_code]}")

# Register signal handler for SIGINT
signal.signal(signal.SIGINT, signal_handler)

# Read stdin line by line
for line in sys.stdin:
    line = line.strip()
    parts = line.split()
    if len(parts) != 7:
        continue  # Skip lines with incorrect format
    try:
        status_code = int(parts[-2])
        file_size = int(parts[-1])
        if status_code in status_code_count:
            status_code_count[status_code] += 1
        total_size += file_size
        line_count += 1
        # Print statistics every 10 lines
        if line_count % 10 == 0:
            print_stats()
    except ValueError:
        continue  # Skip lines with non-integer status code or file size
