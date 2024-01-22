#!/usr/bin/python3
"""
Calculates the minimum operations
"""

def minOperations(n):
    """
    Calculate the fewest number of operations needed to reach exactly n H characters.

    Args:
    - n (int): Target number of H characters.

    Returns:
    - int: The fewest number of operations needed.
           If n is impossible to achieve, returns 0.
    """
    answer = 0
    x = 2
    while n > 1:
        while n % x == 0:
            answer += x
            n /= x
        x += 1
    return answer

# Example usage for testing
if __name__ == "__main__":
    n1 = 4
    print("Min # of operations to reach {} char: {}".format(n1, minOperations(n1)))

    n2 = 12
    print("Min # of operations to reach {} char: {}".format(n2, minOperations(n2)))
