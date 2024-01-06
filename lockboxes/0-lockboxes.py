#!/usr/bin/python3

'''
Determines if all the boxes can be opened.
'''


def can_unlock_all(boxes):
    boxes_opened = [False] * len(boxes)
    boxes_opened = open_box(0, boxes, boxes_opened)

    return all(boxes_opened)


def open_box(box_index, boxes, boxes_opened):
    if 0 <= box_index < len(boxes_opened) and not boxes_opened[box_index]:
        boxes_opened[box_index] = True
        for var in boxes[box_index]:
            open_box(var, boxes, boxes_opened)

    return boxes_opened