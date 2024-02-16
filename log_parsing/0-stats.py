#!/usr/bin/python3
from sys import stdin

def printstats(file_size, status_codes):
    """
    Prints statistics every 10 lines and upon Keyboard interruption.
    Args:
        file_size (int): Total file size.
        status_codes (dict): Dictionary containing status codes and their counts.
    """
    print("File size:", file_size)
    for code in sorted(status_codes):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")


line_num = 0
file_size = 0
status_codes = {"200": 0, "301": 0, "400": 0, "401": 0,
                "403": 0, "404": 0, "405": 0, "500": 0}

try:
    for line in stdin:
        line_num += 1
        split_line = line.split()

        if len(split_line) >= 7:
            file_size += int(split_line[-1])
            status_code = split_line[-2]
            if status_code in status_codes:
                status_codes[status_code] += 1

        if line_num % 10 == 0:
            printstats(file_size, status_codes)

    printstats(file_size, status_codes)

except Exception as e:
    # Print statistics and raise exception upon error
    printstats(file_size, status_codes)
    raise e
