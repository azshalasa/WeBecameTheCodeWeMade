#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    void *pBuffer;
    void *op;
    void *count;
    void *lp;

    pBuffer = (void*)malloc((sizeof(int)*3));
    *(int *)pBuffer = 0; // Menu de Opção
    *(int *)(pBuffer + sizeof(int)) = 0; // Looping
    *(int *)(pBuffer + (2*sizeof(int))) = 0; // Variavel Contadora
    refreshVar(pBuffer, &op, &count, &lp);

    printf("--------\n");
    printf("OP : %i\n", op);
    printf("CO : %i\n", *(int *)count);
    printf("LP : %i\n", *(int *)lp);


    //AddTo(pBuffer);
    //PrintAll(pBuffer);
    //struct Agenda * test;
    //test = pBuffer + (sizeof(int)*3) + sizeof(struct Agenda);
    //printf("Ce : %d\n", test->cphone);
    //printf("No : %s\n", test->name);
    //printf("Co : %d\n", *(int *)(pBuffer + (2*sizeof(int))));

    return 0;
}
