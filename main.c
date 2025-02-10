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

    printf("%lu %lu %d %d\n", BlackBox.longs[0], BlackBox.longs[1],
           BlackBox.width, BlackBox.height);

    return 0;
}
