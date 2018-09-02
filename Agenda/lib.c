#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void refreshVar(void *pBuffer, void **op, void **count, void **lp){
    *op = pBuffer;                              // Atualiza ponteiro do menu de opções
    *lp = pBuffer + sizeof(int);                // Atualiza ponteiro de looping
    *count = pBuffer + (2*sizeof(int));         // Atualiza ponteiro de count
}

void *AddTo(void *pBuffer, int *count){
        //printf("-----------------\n");
        //printf("BRealloc: %d \n", pBuffer);
        *count = *count + 1;
        pBuffer = (void*)realloc(pBuffer, (3 * sizeof(int)) + ( (*count) * sizeof(struct Agenda)));
        //printf("--------------%d\n", (3 * sizeof(int)) + ( (*count) * sizeof(struct Agenda)));
        //printf("-----------------\n");
        //printf("pBuffer: %d Count: %d \n", pBuffer, *count);

        struct Agenda * test;
        test = pBuffer + (3 * sizeof(int)) + ( (*count) * sizeof(struct Agenda));

        printf("-----------------\n");
        printf("Digite o Numero\n");
        fflush(stdin);
        scanf("%d", &test->cphone);
        printf("Digite o Nome\n");
        fflush(stdin);
        fgets (test->name , (sizeof(char)*10) , stdin);
        return pBuffer;
}

void PrintAll(void *pBuffer, int *count, int *lp){
    if(*count > 0){
        struct Agenda * test;
        do{
                *lp= (*lp)+1;
                test = pBuffer + (3 * sizeof(int)) + ( (*lp) * sizeof(struct Agenda));
                printf("\n");
                printf("Phone:%d\n", test->cphone);
                printf("Name:%s\n", test->name);
                printf("\n");
        }while(*lp < *count);
    }
}

void menu(){


}
