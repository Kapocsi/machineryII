#include "font.h"
#include "global.h"
#include "raster.h"
#include "events.h"

#include <osbind.h>
#include <stdio.h>
#include <string.h>

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

    Model model;
    start_game(&model);

    

    char str[] = "Hello World!";

    white_screen(base);
    drawBigText(base, str, strlen(str), 0, 200, SET);

    return 0;
}
