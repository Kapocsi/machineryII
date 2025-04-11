#include "super.h"
#include <osbind.h>
#include <stdio.h>

static long ssp = 0;

void superIn() {
    if (!is_super())
        ssp = Super(0);
}

void superOut() {
    if (is_super() && ssp != 0) {
        Super(ssp);
        ssp = 0;
    }
}
