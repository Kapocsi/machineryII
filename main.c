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
    char str[] = "Hello World!";

    white_screen(base);
    drawBigText(base, str, strlen(str), 0, 200, SET);

    return 0;
}
