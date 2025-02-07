#include "global.h"
#include "raster.h"

#include <osbind.h>
#include <stdio.h>

void disable_cursor() {
    printf("\033f");
    fflush(stdout);
}

void enable_cursor() {
    printf("\033e");
    fflush(stdout);
}

int main(int argc, char *argv[]) {
    Screen *base = (Screen *)Physbase();
    int i = 0;
    int j = 0;
    int k = 0;

    /* Setup Game Draw Canvas */
    disable_cursor();
    white_screen(base);

    for (i = 5 + k; i < 300 + k; i++)
        for (j = 5 + k; j < 100 + k; j++)
            set_pixel(base, i, j, BLACK);

    for (i = 20 + k; i < 280 + k; i++)
        for (j = 20 + k; j < 80 + k; j++)
            set_pixel(base, i, j, WHITE);

    /* Wait for user input to quit */
    enable_cursor();
    return 0;
}
