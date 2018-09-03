#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
// refresVar
// pBuffer  = Ponteiro tipo void para o buffer
// *count   = Ponteiro para ponteiro tipo void
// *lp      = Ponteiro para ponteiro tipo void
// *op      = Ponteiro para ponteiro tipo void
void refreshVar(void *pBuffer, void **op, void **count, void **lp){
    *op = pBuffer;                              // Atualiza ponteiro do menu de opções
    *lp = pBuffer + sizeof(int);                // Atualiza ponteiro de looping
    *count = pBuffer + (2*sizeof(int));         // Atualiza ponteiro de count
}
// AddTo    = função tipo ponteiro para void, deve retornar ponteiro para pBuffer
// pBuffer  = Ponteiro tipo void para o buffer
// *count   = Ponteiro tipo int para variavel de contagem
void *AddTo(void *pBuffer, void *count){
    /*
        //printf("-----------------\n");
        //printf("BRealloc: %d \n", pBuffer);
        *count = *count + 1;
        pBuffer = realloc(pBuffer,      (3 * sizeof(int)) + ( (*count) * sizeof(struct Agenda))+ ( 1 * sizeof(struct Agenda)));
        //printf("----------%d\n",    pBuffer+(3 * sizeof(int)) + ( (*count) * sizeof(struct Agenda)));
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
        fgets (test->name , (sizeof(char)*10) , stdin);*/
        return pBuffer;
}
// RemoveTo = função tipo ponteiro para void, deve retornar ponteiro para pBuffer
// pBuffer  = Ponteiro tipo void para o buffer
// *count   = Ponteiro tipo int para variavel de contagem
// *lp      = Ponteiro tipo int para variavel de looping
void *RemoveTo(void *pBuffer, void *count, void *lp){
/*
        pBuffer = realloc(pBuffer,      (3 * sizeof(int)) + ( (*count) * sizeof(struct Agenda))+ ( 1 * sizeof(struct Agenda)));


        struct Agenda * test;
        for(*lp = 0; *lp<*count; *lp++){
            //test = pBuffer + (3 * sizeof(int)) + (*lp) * (sizeof(struct Agenda) );
        }
        printf("-----------------\n");
        printf("Digite o Numero\n");
        fflush(stdin);
        scanf("%d", &test->cphone);
        printf("Digite o Nome\n");
        fflush(stdin);
        fgets (test->name , (sizeof(char)*10) , stdin);
*/
        return pBuffer;
}
// PrintAll
// pBuffer  = Ponteiro tipo void para o buffer
// *count   = Ponteiro tipo int para variavel de contagem
// *lp      = Ponteiro tipo int para variavel de looping
void PrintAll(void *pBuffer, void *count, void *lp){
    printf("Buffer: %d\n", pBuffer + (3 * sizeof(int)) + ( (*(int *)count) * sizeof(struct Agenda)));

    if(*(int *)count > 0){
        struct Agenda * test;
        for(*(int *)lp = 0; *(int *)lp < *(int *)count; *(int *)lp++){

                test = pBuffer + (3 * sizeof(int)) + ( (*(int *)lp) * sizeof(struct Agenda));
                printf("\n");
                printf("Phone:%d\n", test->cphone);
                printf("Name:%s\n", test->name);
                printf("\n");
        }
    }
}

void menu(){


}
