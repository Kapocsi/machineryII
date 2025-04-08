#include "vector.h"
#include "super.h"

Vector install_vector(int num, Vector vector) {
    Vector orig;
    Vector *vectp = (Vector *)((long)num << 2);

    SuperDo({
        orig = *vectp;
        *vectp = vector;
    });

    return orig;
}