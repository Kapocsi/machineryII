#include "global.h"
#include "input.h"
#include "model.h"
#include "render.h"
#include "screen.h"

#include <assert.h>
#include <osbind.h>
#include <stdio.h>

/* Required Algorithm Structure in Main (Stage 5)

initialize model
render model (first frame)
start music
set quit = false

repeat until quit
    if input is pending
        process async event <-- update model requests
    if clock has ticked
        process sync events <-- update model data
        render model (next frame)
        update music
*/

void disable_cursor() {
    printf("\033f");
    fflush(stdout);
}

void enable_cursor() {
    printf("\033e");
    fflush(stdout);
}

typedef Screen **Screens;

int main(int argc, char *argv[]) {
    Screens screens = initScreen();

    printf("TODO!\n");
    return 0;
}
