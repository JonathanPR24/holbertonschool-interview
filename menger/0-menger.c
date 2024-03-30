#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void drawSquare(int size, int x, int y) {
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (i == y + size / 2 && j == x + size / 2)
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}

void mengerRecursive(int level, int size, int x, int y) {
    if (level == 0) {
        drawSquare(size, x, y);
        return;
    }
    
    int newSize = size / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!(i == 1 && j == 1)) {
                mengerRecursive(level - 1, newSize, x + j * newSize, y + i * newSize);
            }
        }
    }
}

void menger(int level) {
    if (level < 0)
        return;
    
    int size = (int)pow(3, level);
    mengerRecursive(level, size, 0, 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s level\n", argv[0]);
        return EXIT_FAILURE;
    }

    int level = atoi(argv[1]);
    menger(level);

    return EXIT_SUCCESS;
}
