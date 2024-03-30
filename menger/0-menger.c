#include "menger.h"
#include <math.h>
#include <stdio.h>

/**
 * menger - Draws a 2D Menger Sponge
 * @level: Level of the Menger Sponge to draw
 */
void menger(int level)
{
    int size, row, col, step;
    int r, c; /* Declare variables at the beginning */

    if (level < 0)
        return;

    size = pow(3, level);

    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            step = 1;
            r = row; /* Assign values after declaration */
            c = col;

            while (step <= size / 3)
            {
                if (r % 3 == 1 && c % 3 == 1)
                    break;
                r /= 3;
                c /= 3;
                step *= 3;
            }

            if (step > 1)
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}
