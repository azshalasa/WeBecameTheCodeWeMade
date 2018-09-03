#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    void *pBuffer;
    void *op;
    void *count;
    void *lp;
    struct Agenda * Note;

    pBuffer = (void*)malloc((sizeof(int)*3 + sizeof(struct Agenda)));               // Aloca os 3 inteiros descritos abaixo no inicio do programa
    *(int *)pBuffer = 0;                                    // Variavel para Menu de Opção
    *(int *)(pBuffer + sizeof(int)) = 0;                    // Variavel para Looping
    *(int *)(pBuffer + (2*sizeof(int))) = 1;                // Variavel para Contar, inicializa em 1 pois o primeiro contato serve para gerenciamento interno do programa
    refreshVar(pBuffer, &op, &count, &lp);                  // Função que atualiza os ponteiros locais de main
    Note = pBuffer + (3 * sizeof(int)) + ( (*(int *)count) * sizeof(struct Agenda));
    Note->cphone = 0;
    Note->name[0] = 'x';
    printf("Buffer: %d\n", pBuffer + (3 * sizeof(int)) + ( (*(int *)count) * sizeof(struct Agenda)));

    //pBuffer = AddTo(pBuffer, count);
    //refreshVar(pBuffer, &op, &count, &lp);
    //pBuffer = AddTo(pBuffer, count);
    refreshVar(pBuffer, &op, &count, &lp);
    //pBuffer = AddTo(pBuffer, count);
    //refreshVar(pBuffer, &op, &count, &lp);

    PrintAll(pBuffer, count, lp);

    return 0;
}
