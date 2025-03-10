#include "super.h"
#include <osbind.h>
#include <stdio.h>

static long ssp = 0;

void superIn() {
    if (ssp == 0) {
        ssp = Super(0);
    }
}

void superOut() {
    if (ssp != 0) {
        Super(ssp);
        ssp = 0;
    }
}
