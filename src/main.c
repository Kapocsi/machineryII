#include "global.h"
#include "input.h"
#include "model.h"
#include "render.h"
#include "screen.h"

#include <assert.h>
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

typedef Screen **Screens;

int main(int argc, char *argv[]) {
    Screens screens = initScreen();
    inputState *i = initInput();
    /* Model m; */
    /**/
    /* switchBuffer(Secondary); */
    /* initModel(&m); */

    /* change_row(&m.row, "Hello World!"); */
    /* render(m, screens); */
    /**/
    /* switchBuffer(Original); */

    while (1)
        ;

    return 0;
}
