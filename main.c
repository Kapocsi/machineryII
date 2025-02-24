#include "bitmap.h"
#include "global.h"
#include "raster.h"

#include "font.h"

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
    BitMap test = {glyphs['a'], 8, 16};
    int x = 0;

    printf("%ld", sizeof(short));

    disable_cursor();
    white_screen(base);

    for (x = 0; x < 128 - 33; x++) {
        test.longs = glyphs[x + 33];

        drawBitMap(base, &test, (x * 8) % SCREEN_WIDTH,
                   17 * ((x * 8) / SCREEN_WIDTH), SET);
    }

    Vsync();

    fgetc(stdin);
    enable_cursor();

    return 0;
}
