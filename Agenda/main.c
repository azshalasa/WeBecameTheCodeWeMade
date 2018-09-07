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
    Note->cphone = 99;
    Note->name[0] = 'x';

        do{
        printf("-----------------------\n");
        printf("-----    Agenda    ----\n");
        printf("-----------------------\n");
        printf("- 1 > Adicionar       -\n");
        printf("- 2 > Remover         -\n");
        printf("- 3 > Listar          -\n");
        printf("- 4 > Buscar          -\n");
        printf("-----------------------\n");
        printf("- ");
        scanf("%d", (int *)op);

        switch (*(int *)op){

            case 1:
                pBuffer = AddTo(pBuffer, count);
                refreshVar(pBuffer, &op, &count, &lp);
            break;

            case 2:
                pBuffer = RemoveTo(pBuffer, count, lp, op);
                refreshVar(pBuffer, &op, &count, &lp);
            break;

            case 3:
                PrintAll(pBuffer, count, lp);
            break;

            case 4:
                SearchTo(pBuffer, count, lp, op);
            break;

            default:
                break;
        }
    }while(*(int *)op != 0);

    return 0;
}
