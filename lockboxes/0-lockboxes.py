#!/usr/bin/python3

'''
determines if all the boxes can be opened
'''

def canUnlockAll(boxes):
    num_boxes = len(boxes)
    boxesOpened = [False] * num_boxes
    stack = [0]  # Using a stack to simulate recursion

    while stack:
        boxIndex = stack.pop()
        if not boxesOpened[boxIndex]:
            boxesOpened[boxIndex] = True
            stack.extend(boxes[boxIndex])

    return all(boxesOpened)