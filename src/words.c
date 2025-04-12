#include "words.h"
#include "psg.h"
#include <stdlib.h>
#include <string.h>

#define WORD_COUNT 30

/**
 * @brief The list of possible words to type.
 */
static const char WORDS[WORD_COUNT][10] = {
    "air ",   "bar ",   "bob ",   "eel ",   "man ",   "sea ",
    "sky ",   "try ",   "boat ",  "buoy ",  "dive ",  "down ",
    "fish ",  "help ",  "kelp ",  "land ",  "over ",  "rise ",
    "sink ",  "sunk ",  "swim ",  "board ", "death ", "drown ",
    "fight ", "ocean ", "shark ", "shore ", "tidal ", "under "};

void new_row(char *buf, u32 size) {
    int i = 0, j = 0;
    char *dest = buf;
    const char *src;

    strcpy(dest, WORDS[rand() % (WORD_COUNT - 1)]);
}
