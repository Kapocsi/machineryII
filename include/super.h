#ifndef SUPER_H
#define SUPER_H

#define SuperDo(code)                                                          \
    superIn();                                                                 \
    {                                                                          \
        code;                                                                  \
    }                                                                          \
    superOut();

void superIn();
void superOut();

#endif
