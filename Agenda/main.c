#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    void *pBuffer;
    void *op;
    void *count;
    void *lp;

    pBuffer = (void*)malloc((sizeof(int)*3));               // Aloca os 3 inteiros descritos abaixo no inicio do programa
    *(int *)pBuffer = 0;                                    // Variavel para Menu de Opção
    *(int *)(pBuffer + sizeof(int)) = 0;                    // Variavel para Looping
    *(int *)(pBuffer + (2*sizeof(int))) = 0;                // Variavel para Contar
    refreshVar(pBuffer, &op, &count, &lp);                  // Função que atualiza os ponteiros locais de main

    pBuffer = AddTo(pBuffer, count);
    refreshVar(pBuffer, &op, &count, &lp);
    PrintAll(pBuffer, count, lp);
    pBuffer = AddTo(pBuffer, count);
    refreshVar(pBuffer, &op, &count, &lp);

    return 0;
}
