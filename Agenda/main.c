#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
int main()
{
    printf("Hello world!\n");
    void *pBuffer;
    int *op;
    int *lp;
    struct Agenda *FirstC;
    struct Agenda *LastC;

    refreshVar(op, lp, FirstC, LastC, pBuffer);



    return 0;
}
