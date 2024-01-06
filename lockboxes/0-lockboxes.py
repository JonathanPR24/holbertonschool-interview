#!/usr/bin/python3

def canUnlockAll(boxes):
    unlocked_boxes = {0}

    for box_index in unlocked_boxes:
        for key in boxes[box_index]:
            if key < len(boxes) and key not in unlocked_boxes:
                unlocked_boxes.add(key)

    return len(unlocked_boxes) == len(boxes)