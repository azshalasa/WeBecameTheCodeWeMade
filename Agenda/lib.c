#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

// RefresVar
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
    printf("\033[H\033[J");
    *(int *)count = (*(int *)count) + 1;
    pBuffer = realloc(pBuffer,      (3 * sizeof(int)) + ( (*(int *)(pBuffer + (2*sizeof(int)))) * sizeof(struct Agenda))); // PUTA QUE A CARALHA PERDE REFERENCIA DETRO DO WINDOWS DEPOIS DO REALLOC !#@$#%¨$#&
    struct Agenda * test;
    test = pBuffer + (3 * sizeof(int)) + ( (*(int *)(pBuffer + (2*sizeof(int)))) * sizeof(struct Agenda));
    printf("-----------------------\n");
    printf("- Digite o Numero:\n");
    printf("- ");
    scanf("%d", &test->cphone);
    printf("- Digite o Nome:\n");
    __fpurge(stdin);
    printf("- ");
    fgets (test->name , (sizeof(char)*10) , stdin);
    return pBuffer;
}
// RemoveTo = função tipo ponteiro para void, deve retornar ponteiro para pBuffer
// pBuffer  = Ponteiro tipo void para o buffer
// *count   = Ponteiro tipo int para variavel de contagem
// *lp      = Ponteiro tipo int para variavel de looping
void *RemoveTo(void *pBuffer, void *count, void *lp, void *op){
    printf("\033[H\033[J");
    struct Agenda * Note;
    struct Agenda * Aux;
    Aux = pBuffer + (3 * sizeof(int)) + (sizeof(struct Agenda));
    printf("-----------------------\n");
    printf("-----    Remove   -----\n");
    printf("-----------------------\n");
    printf("- 1 > Por Nome        -\n");
    printf("- 2 > Por Numero      -\n");
    printf("-----------------------\n");
    printf("- ");
    scanf("%d", (int *)op);
    printf("-----------------------\n");

    if((*(int *)op) == 1){
        printf("- Digite o Nome:\n");
        __fpurge(stdin);
        printf("- ");
        fgets (Aux->name , (sizeof(char)*10) , stdin);
    }else if((*(int *)op) == 2){
        printf("- Digite o Numero:\n");
        printf("- ");
        scanf("%d", &Aux->cphone);
    }else{
        return pBuffer;
    }

    for(*(int *)lp = 2; *(int *)lp <= *(int *)count; (*(int *)lp)++){
        Note = pBuffer + (3 * sizeof(int)) + ( (*(int *)lp) * sizeof(struct Agenda));
        if((*(int *)op) == 1){
            if( strcmp(Aux->name, Note->name) == 0 ){
                for((*(int *)lp) = (*(int *)lp); *(int *)lp <= *(int *)count; (*(int *)lp)++){
                    Note = pBuffer + (3 * sizeof(int)) + ((*(int *)lp) * sizeof(struct Agenda));
                    Aux = pBuffer + (3 * sizeof(int)) + ((*(int *)lp) * sizeof(struct Agenda)) + sizeof(struct Agenda);
                    strcpy(Note->name, Aux->name);
                    Note->cphone = Aux->cphone;
                }
            (*(int *)count)--;
            return realloc(pBuffer, (3 * sizeof(int)) + ((*(int *)count) * sizeof(struct Agenda)));
            }
        }else if((*(int *)op) == 2){
            if( Aux->cphone == Note->cphone ){
                for((*(int *)lp) = (*(int *)lp); *(int *)lp <= *(int *)count; (*(int *)lp)++){
                    Note = pBuffer + (3 * sizeof(int)) + ((*(int *)lp) * sizeof(struct Agenda));
                    Aux = pBuffer + (3 * sizeof(int)) + ((*(int *)lp) * sizeof(struct Agenda)) + sizeof(struct Agenda);
                    strcpy(Note->name, Aux->name);
                    Note->cphone = Aux->cphone;
                }
            (*(int *)count)--;
            return realloc(pBuffer, (3 * sizeof(int)) + ((*(int *)count) * sizeof(struct Agenda)));
            }
        }
    }
    printf("-----------------------\n");
    printf("- 404 Not Found xD    -\n");
    return pBuffer;
}
// PrintAll
// pBuffer  = Ponteiro tipo void para o buffer
// *count   = Ponteiro tipo int para variavel de contagem
// *lp      = Ponteiro tipo int para variavel de looping
void PrintAll(void *pBuffer, void *count, void *lp){
    printf("\033[H\033[J");
    if(*(int *)count > 0){
    struct Agenda * Note;
        for(*(int *)lp = 2; *(int *)lp <= *(int *)count; (*(int *)lp)++){
            Note = pBuffer + (3 * sizeof(int)) + ( (*(int *)lp) * sizeof(struct Agenda));
            printf("-----------------------\n");
            printf("----------- Contato %d\n", (*(int *)lp)-1);
            printf("- Phone:%d\n", Note->cphone);
            printf("- Name:%s", Note->name);
        }
    }
}
// SearchTo
// pBuffer  = Ponteiro tipo void para o buffer
// *count   = Ponteiro tipo int para variavel de contagem
// *lp      = Ponteiro tipo int para variavel de looping
// *op      = Ponteiro tipo int para variavel de menu de opções
void SearchTo(void *pBuffer, void *count, void *lp, void *op){
    printf("\033[H\033[J");

    struct Agenda * Note;
    struct Agenda * Aux;
    Aux = pBuffer + (3 * sizeof(int)) + (sizeof(struct Agenda));
    printf("-----------------------\n");
    printf("-----    Busca    -----\n");
    printf("-----------------------\n");
    printf("- 1 > Por Nome        -\n");
    printf("- 2 > Por Numero      -\n");
    printf("-----------------------\n");
    printf("- ");
    scanf("%d", (int *)op);
    printf("-----------------------\n");

    if((*(int *)op) == 1){
        printf("- Digite o Nome:\n");
        __fpurge(stdin);
        printf("- ");
        fgets (Aux->name , (sizeof(char)*10) , stdin);
    }else if((*(int *)op) == 2){
        printf("- Digite o Numero:\n");
        printf("- ");
        scanf("%d", &Aux->cphone);
    }else{
        return;
    }

    for(*(int *)lp = 2; *(int *)lp <= *(int *)count; (*(int *)lp)++){
        Note = pBuffer + (3 * sizeof(int)) + ( (*(int *)lp) * sizeof(struct Agenda));
        if((*(int *)op) == 1){
            if( strcmp(Aux->name, Note->name) == 0 ){
                printf("-----------------------\n");
                printf("----------- Contato %d\n", (*(int *)lp)-1);
                printf("- Phone:%d\n", Note->cphone);
                printf("- Name:%s", Note->name);
                return;
            }
        }else if((*(int *)op) == 2){
            if( Aux->cphone == Note->cphone ){
                printf("-----------------------\n");
                printf("----------- Contato %d\n", (*(int *)lp)-1);
                printf("- Phone:%d\n", Note->cphone);
                printf("- Name:%s", Note->name);
                return;
            }
        }
    }
    printf("-----------------------\n");
    printf("- 404 Not Found xD    -\n");
    return;
}
