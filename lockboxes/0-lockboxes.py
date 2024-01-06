#!/usr/bin/python3

def canUnlockAll(boxes):
    """
    Determines whether all the boxes can be opened.

    Parameters:
    - boxes (List[List[int]]): A list of lists representing the boxes and keys.

    Returns:
    - bool: True if all boxes can be opened, else False.
    """
    unlocked = [False] * len(boxes)
    unlocked[0] = True

    changed = True

    while changed:
        changed = False

        for i in range(len(boxes)):
            if not unlocked[i]:
                continue

            for j in range(len(boxes[i])):
                if boxes[i][j] >= len(boxes):
                    continue

                key = boxes[i][j]
                if not unlocked[key]:
                    unlocked[key] = True
                    changed = True

    return all(unlocked)
