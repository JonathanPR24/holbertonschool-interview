#include "menger.h"
#include <math.h>
#include <stdio.h>

/**
 * menger - Draws a 2D Menger Sponge
 * @level: Level of the Menger Sponge to draw
 */
void menger(int level)
{
    int size, row, col, _row, _col;

    if (level < 0)
        return;

    size = pow(3, level);

    char character = '#'; /* Declare and initialize character */

    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            _row = row;
            _col = col;

            /* Check if current cell should be empty */
            while (_row || _col)
            {
                if (_row % 3 == 1 && _col % 3 == 1)
                {
                    character = ' ';
                    break; /* No need to continue loop once determined */
                }
                _row /= 3;
                _col /= 3;
            }

            printf("%c", character); /* Print the character */
        }
        printf("\n"); /* Move to the next line after each row */
    }
}
