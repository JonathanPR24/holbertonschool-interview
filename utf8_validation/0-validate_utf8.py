#!/usr/bin/python3

def validUTF8(data):
    # Number of bytes to check for each UTF-8 character
    num_bytes_to_check = 0

    for num in data:
        # If num_bytes_to_check is 0, we are expecting the start of a new UTF-8 character
        if num_bytes_to_check == 0:
            # Count the number of leading 1s to determine the number of bytes in the UTF-8 character
            if num >> 5 == 0b110:
                num_bytes_to_check = 1
            elif num >> 4 == 0b1110:
                num_bytes_to_check = 2
            elif num >> 3 == 0b11110:
                num_bytes_to_check = 3
            # If num_bytes_to_check is still 0, it means it's either a single byte character or an invalid character
            elif num >> 7 == 0:
                num_bytes_to_check = 0
            else:
                return False
        else:
            # Check if the current number starts with the correct bit pattern
            if num >> 6 != 0b10:
                return False
            num_bytes_to_check -= 1

    # If num_bytes_to_check is not zero at the end, it means some characters are incomplete
    return num_bytes_to_check == 0
