#include "bitmaps.h"
#include "font.h"
#include "global.h"
#include "raster.h"
#include "events.h"

#include <assert.h>
#include <osbind.h>

/* Required Algorithm Structure in Main (Stage 5)

initialize model
render model (first frame)
set quit = false

repeat until quit
    if input is pending
        process async event <-- update model requests
    if clock has ticked
        process sync events <-- update model data
        render model (next frame)
*/

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

void setBuffer(void *);

int main(int argc, char *argv[]) {
    int x, i = 0;
    Screen **screens = initScreen();
    Screen *base = screens[Original];
    white_screen(base);

    for (x = 0; x < 64; x++) {
        drawBitMap(base, &test_pattern8, x, 0, SET);
        Cconin();
        drawBitMap(base, &test_pattern8, x, 0, UNSET);
    }
    for (x = 0; x < 64; x++) {
        drawBitMap(base, &test_pattern16, x, 0, SET);
        Cconin();
        drawBitMap(base, &test_pattern16, x, 0, UNSET);
    }
    for (x = 0; x < 64; x++) {
        drawBitMap(base, &test_pattern32, x, 0, SET);
        Cconin();
        drawBitMap(base, &test_pattern32, x, 0, UNSET);
    }
    for (x = 0; x < 64; x++) {
        drawBitMap(base, &test_pattern64, x, 0, SET);
        Cconin();
        drawBitMap(base, &test_pattern64, x, 0, UNSET);
    }

    return 0;
}
