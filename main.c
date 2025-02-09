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
    drawHorizontalLine(base, 200, 100, 500);

    /* Wait for user input to quit */
    enable_cursor();
    return 0;
}
