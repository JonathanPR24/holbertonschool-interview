#!/usr/bin/python3
from collections import deque

def canUnlockAll(boxes):
    """
    Determines whether all the boxes can be opened.

    Parameters:
    - boxes (List[List[int]]): A list of lists representing the boxes and keys.

    Returns:
    - bool: True if all boxes can be opened, else False.
    """
    num_boxes = len(boxes)
    
    # Initialize a list to track the state of box unlocking
    unlocked = [False] * num_boxes
    unlocked[0] = True  # The first box is initially unlocked

    # Use a queue for breadth-first search starting with the first box
    queue = deque([0])

    # Perform breadth-first search
    while queue:
        current_box = queue.popleft()

        # Explore keys in the current box
        for key in boxes[current_box]:
            # Check if the key is valid and the corresponding box is not already unlocked
            if key < num_boxes and not unlocked[key]:
                unlocked[key] = True
                queue.append(key)

    # Check if all boxes are unlocked
    return all(unlocked)

# Example usage
boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))
