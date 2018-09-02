#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    void *pBuffer;
    void *op;
    void *count;
    void *lp;
    struct Agenda *FirstC;
    struct Agenda *LastC;

    pBuffer = (void*)malloc((sizeof(int)*3));
    *(int *)pBuffer = 0; // Menu de Opção
    *(int *)(pBuffer + sizeof(int)) = 0; // Looping
    *(int *)(pBuffer + (2*sizeof(int))) = 0; // Variavel Contadora

    refreshVar(pBuffer, &op, &count, &lp, &FirstC, &LastC);
    AddTo(pBuffer, count);
    refreshVar(pBuffer, &op, &count, &lp, &FirstC, &LastC);
    //AddTo(pBuffer, count);

    struct Agenda * test;
    test = pBuffer + (sizeof(int)*3) + ( *(int *)count * sizeof(struct Agenda));
    printf("Phone : %d\n", test->cphone);
    printf("Nome  : %s \n", test->name);


    /*AddTo(pBuffer, *(int *)op);
    refreshVar(pBuffer, &op, &count, &lp, &FirstC, &LastC);

    test = pBuffer + (sizeof(int)*3) + ( *(int *)count * sizeof(struct Agenda));
    printf("Phone : %d\n", test->cphone);
    printf("Nome  : %s \n", test->name); */

    //PrintAll(pBuffer, &FirstC, &LastC);
    //AddTo(pBuffer);
    //refreshVar(pBuffer, &op, &count, &lp, &FirstC, &LastC);
    //printf("%d", *(int *)(pBuffer + (2*sizeof(int))));


    return 0;
}
