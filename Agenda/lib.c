#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void refreshVar(void *pBuffer, void **op, void **count, void **lp, struct Agenda **FirstC, struct Agenda **LastC){
    *op = pBuffer;
    *lp = pBuffer+sizeof(int);
    *count = pBuffer + (2*sizeof(int));

    if(*(int *)(pBuffer + (2*sizeof(int))) > 0){ // Verify if count > 0
        *FirstC = pBuffer + (2*sizeof(int)) + (sizeof(struct Agenda)); // If count > 0 we should refresh the pointer to contact list
        *LastC = pBuffer + (2*sizeof(int)) + ( *(int *)(pBuffer + (2*sizeof(int))) * sizeof(struct Agenda));
    }else{
        *FirstC = NULL;
        *LastC = NULL;
    }
}

void AddTo(void *pBuffer, int *count){

        *count = *count + 1;

        pBuffer = realloc(pBuffer, (3 * sizeof(int)) + ( (*count) * sizeof(struct Agenda)));
        struct Agenda * test;

        test = pBuffer + (3 * sizeof(int)) + ( (*count) * sizeof(struct Agenda));

        printf("Digite o Numero\n");
        fflush(stdin);
        scanf("%d", &test->cphone);
        printf("Digite o Nome\n");
        fflush(stdin);
        fgets (test->name , (sizeof(char)*10) , stdin);
}

void PrintAll(void *pBuffer, struct Agenda **FirstC, struct Agenda **LastC){
    printf("P1 %d\n", *FirstC);
    printf("P2 %d\n", *LastC);

    if(*(int *)(pBuffer + (2*sizeof(int)))>0){
        struct Agenda * test;
        for(*FirstC = *FirstC; *FirstC < *LastC;){
            test = pBuffer + (sizeof(int)*3) + sizeof(struct Agenda) * (*(int *)(pBuffer + (2*sizeof(int))));
            printf("\n");
            printf("Phone:%d\n", test->cphone);
            printf("Name:%s\n", test->name);
            printf("\n");
        }
    }
}

void menu(){
        /*pBuffer = realloc(pBuffer, (sizeof(pBuffer) + sizeof(struct Agenda)));
        struct Agenda * test;
        test = pBuffer + (sizeof(int)*3) + sizeof(struct Agenda);
        test->cphone = 999;
        test->name[0] = 't';
        printf("R2:%d\n", sizeof(pBuffer));

        printf("Ce : %d\n", &test->cphone);
        printf("No : %d\n", &test->name[0]);


        // *(int *)pBuffer = 7;
        // *(int *)(pBuffer + sizeof(int)) = 9;
        // *op = 10;
        // *lp = 5;
        //printf("RefV : %d\n", *(int *)pBuffer);
        */


 //   struct Agenda * test;
  //  test = pBuffer + (sizeof(int)*3) + sizeof(struct Agenda);
   // printf("Ce : %d\n", test->cphone);
   // printf("No : %d\n", test->name[0]);
    //printf("M: %d\n", pBuffer);

        //printf("Main : \n");
   // printf("OP : %i\n", op);
   // printf("LP : %i\n", *(int *)lp);
    //printf("CO : %i\n", *(int *)counT);

}
