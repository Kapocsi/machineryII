#include "adler32.h"
#include "font.h"
#include "global.h"
#include "raster.h"

#include <osbind.h>
#include <stdio.h>
#include <string.h>

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
    char str[] = "123 @@ &";
    u32 i = 0;

    white_screen(base);

    for (i = 0; i < strlen(str) && 48 * (i + 1) < SCREEN_WIDTH; i++) {
        drawBitMap(base, &depixel[str[i]], 48 * i, 200, SET);
    }

    printf("%08lx\n", adler32((u8 *)base, SCREEN_BUFFER_SIZE * 4));

    Crawcin();

    enable_cursor();

    return 0;
}
