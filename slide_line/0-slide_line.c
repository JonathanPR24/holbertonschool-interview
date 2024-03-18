#include "slide_line.h"

/**
 * merge_values - Merge adjacent identical numbers in the line array
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: Direction of the merge operation (left or right)
 */
void merge_values(int *line, size_t size, int direction)
{
    size_t i;

    if (direction == SLIDE_LEFT) {
        for (i = 0; i < size - 1; i++) {
            if (line[i] == line[i + 1]) {
                line[i] *= 2;
                line[i + 1] = 0;
            }
        }
    } else if (direction == SLIDE_RIGHT) {
        for (i = size - 1; i > 0; i--) {
            if (line[i] == line[i - 1]) {
                line[i] *= 2;
                line[i - 1] = 0;
            }
        }
    }
}

/**
 * slide_line - Slide and merge an array of integers to the specified direction
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: Direction of the slide operation (SLIDE_LEFT or SLIDE_RIGHT)
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, j, k;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return 0;

    merge_values(line, size, direction);

    if (direction == SLIDE_LEFT) {
        // Slide to the left
        j = 0;
        for (i = 0; i < size; i++) {
            if (line[i] != 0) {
                line[j++] = line[i];
            }
        }
        for (k = j; k < size; k++) {
            line[k] = 0;
        }
    } else if (direction == SLIDE_RIGHT) {
        // Slide to the right
        j = size;
        for (i = size - 1; i < size; i--) {
            if (line[i] != 0) {
                line[--j] = line[i];
            }
        }
        for (k = j; k < size; k++) {
            line[k] = 0;
        }
    }

    return 1;
}
