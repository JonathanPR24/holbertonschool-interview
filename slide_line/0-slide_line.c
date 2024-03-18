#include "slide_line.h"
#include <stdio.h>

/**
 * slide_line - Slide and merge an array of integers to the specified direction
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: Direction of the slide operation (SLIDE_LEFT or SLIDE_RIGHT)
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    if (direction == SLIDE_RIGHT)
        return slide_right(line, size);
    else if (direction == SLIDE_LEFT)
        return slide_left(line, size);
    else
        return 0; // Invalid direction
}

/**
 * slide_left - Slide and merge an array of integers to the left direction
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * Return: 1 upon success, 0 upon failure
 */
int slide_left(int *line, size_t size)
{
    size_t i, j;
    int merged = 0;

    for (i = 0; i < size; i++) {
        if (line[i] == 0)
            continue;

        for (j = i + 1; j < size; j++) {
            if (line[j] == 0)
                continue;
            if (line[i] == line[j]) {
                line[i] *= 2;
                line[j] = 0;
                merged = 1;
            }
            break;
        }
    }

    for (i = 0, j = 0; i < size; i++) {
        if (line[i] != 0) {
            if (i != j) {
                line[j] = line[i];
                line[i] = 0;
                merged = 1;
            }
            j++;
        }
    }

    if (!merged)
        fprintf(stderr, "Failed to slide and merge line\n");

    return merged;
}

/**
 * slide_right - Slide and merge an array of integers to the right direction
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * Return: 1 upon success, 0 upon failure
 */
int slide_right(int *line, size_t size)
{
    size_t i, j;
    int merged = 0;

    for (i = size - 1; i < size; i--) {
        if (line[i] == 0)
            continue;

        for (j = i - 1;; j--) {
            if (line[j] == 0 && j != 0)
                continue;
            if (line[i] == line[j]) {
                line[i] *= 2;
                line[j] = 0;
                merged = 1;
            }
            break;
        }
    }

    for (i = size - 1, j = size - 1; i < size; i--) {
        if (line[i] != 0) {
            if (i != j) {
                line[j] = line[i];
                line[i] = 0;
                merged = 1;
            }
            j--;
        }
    }

    if (!merged)
        fprintf(stderr, "Failed to slide and merge line\n");

    return merged;
}
