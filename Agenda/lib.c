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
        *(int *)count = (*(int *)count) + 1;
        pBuffer = realloc(pBuffer,      (3 * sizeof(int)) + ( (*(int *)count) * sizeof(struct Agenda))); // PUTA QUE A CARALHA PERDE REFERENCIA DETRO DO WINDOWS DEPOIS DO REALLOC !#@$#%¨$#&
        struct Agenda * test;
        test = pBuffer + (3 * sizeof(int)) + ( (*(int *)(pBuffer + (2*sizeof(int)))) * sizeof(struct Agenda));
        printf("-----------------\n");
        printf("Digite o Numero\n");
        scanf("%d", &test->cphone);
        printf("Digite o Nome\n");
        __fpurge(stdin);
        fgets (test->name , (sizeof(char)*10) , stdin);
        return pBuffer;
}
// RemoveTo = função tipo ponteiro para void, deve retornar ponteiro para pBuffer
// pBuffer  = Ponteiro tipo void para o buffer
// *count   = Ponteiro tipo int para variavel de contagem
// *lp      = Ponteiro tipo int para variavel de looping
void *RemoveTo(void *pBuffer, void *count, void *lp){

        struct Agenda * Note;
        Note = pBuffer + (3 * sizeof(int)) + sizeof(struct Agenda);
        printf("-----------------\n");
        printf("Digite o Numero\n");
        scanf("%d", &Note->cphone);

        struct Agenda * Aux;
        struct Agenda * Aux1;

        if(*(int *)count >= 2){
        (*(int *)count)--;
            for(*(int *)lp = 1; *(int *)lp <= *(int *)count; (*(int *)lp)++){
                Aux = pBuffer + (3 * sizeof(int)) + (sizeof(struct Agenda));
                Aux1 = pBuffer + (3 * sizeof(int)) + ((*(int *)lp) * (sizeof(struct Agenda))) + sizeof(struct Agenda);
                if(Note->cphone == Aux->cphone){
                    Aux->cphone = Aux1->cphone; // Fazer um for aqui dentro para mover a galera da direira pra esquerda
                }
            }

        pBuffer = realloc(pBuffer,      (3 * sizeof(int)) + ( (*(int *)count) * sizeof(struct Agenda)));
        }

    return pBuffer;
}
// PrintAll
// pBuffer  = Ponteiro tipo void para o buffer
// *count   = Ponteiro tipo int para variavel de contagem
// *lp      = Ponteiro tipo int para variavel de looping
void PrintAll(void *pBuffer, void *count, void *lp){
    if(*(int *)count > 0){
        struct Agenda * Note;
            for(*(int *)lp = 2; *(int *)lp <= *(int *)count; (*(int *)lp)++){
                Note = pBuffer + (3 * sizeof(int)) + ( (*(int *)lp) * sizeof(struct Agenda));
                printf("\nPhone:%d\n", Note->cphone);
                printf("Name:%s\n", Note->name);
            }
        }
}

void menu(){


}
