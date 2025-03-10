#include "super.h"
#include <osbind.h>
#include <stdio.h>

static long ssp = 0;

void superIn() {
    if (ssp == 0) {
        printf("Into Super\n");
        ssp = Super(0);
    }
}

void superOut() {
    if (ssp != 0) {
        printf("Out of Super\n");
        Super(ssp);
        ssp = 0;
    }
}
