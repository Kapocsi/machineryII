#include "global.h"
#include "raster.h"

#include "bitmaps.h"
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

    disable_cursor();
    white_screen(base);

    drawBitMap(base, &test, 0, 0, SET);

    fgetc(stdin);

    white_screen(base);
    drawBitMap(base, &test, 0, 0, SET);

    drawBitMap(base, &test, 0, 0, UNSET);

    fgetc(stdin);
    enable_cursor();

    return 0;
}
