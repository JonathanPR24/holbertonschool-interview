#!/usr/bin/python3

from collections import deque

def canUnlockAll(boxes):
    num_boxes = len(boxes)
    unlocked = [False] * num_boxes
    unlocked[0] = True

    queue = deque([0])

    while queue:
        current_box = queue.popleft()

        for key in boxes[current_box]:
            if key < num_boxes and not unlocked[key]:
                unlocked[key] = True
                queue.append(key)

    return all(unlocked)