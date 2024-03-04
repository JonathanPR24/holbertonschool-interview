#!/usr/bin/python3
""" 
utf8_validation 

This module provides a function to determine if a given data set represents
a valid UTF-8 encoding.
"""

def validUTF8(data):
    """ 
    Determines if a given data set represents a valid UTF-8 encoding.

    Args:
        data (list): A list of integers representing bytes of data.

    Returns:
        bool: True if data is a valid UTF-8 encoding, False otherwise.
    """
    bytes_to_check = 0

    for byte in data:
        if bytes_to_check == 0:
            if (byte & 0x80) == 0:
                continue
            elif (byte & 0xE0) == 0xC0:
                bytes_to_check = 1
            elif (byte & 0xF0) == 0xE0:
                bytes_to_check = 2
            elif (byte & 0xF8) == 0xF0:
                bytes_to_check = 3
            else:
                return False
        else:
            if (byte & 0xC0) != 0x80:
                return False
            bytes_to_check -= 1

    return bytes_to_check == 0