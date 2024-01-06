#!/usr/bin/python3

def canUnlockAll(boxes):
    """
    Determines whether all the boxes can be opened.

    Parameters:
    - boxes (List[List[int]]): A list of lists representing the boxes and keys.

    Returns:
    - bool: True if all boxes can be opened, else False.
    """
    # Initialize a list to track the state of box unlocking
    unlocked = [False] * len(boxes)
    unlocked[0] = True  # The first box is initially unlocked

    changed = True

    # Perform systematic exploration until no more changes can be made
    while changed:
        changed = False

        # Iterate through all boxes
        for i in range(len(boxes)):
            if not unlocked[i]:
                continue

            # Explore keys in the current box
            for j in range(len(boxes[i])):
                if boxes[i][j] >= len(boxes):
                    continue

                key = boxes[i][j]

                # Check if the corresponding box is not already unlocked
                if not unlocked[key]:
                    unlocked[key] = True
                    changed = True

    # Check if all boxes are unlocked
    return all(unlocked)

