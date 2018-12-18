#include <stdio.h>
#include <stdlib.h>
struct Node{
    int valor;
    struct Node *NextNode;
    struct Node *PrevNode;
};
struct DataInfo{
    int NodeCount;
    struct Node *FirstNode;
    struct Node *LastNode;
};
struct DataInfo *StartNode(struct DataInfo *Info){
    Info = (struct DataInfo*)malloc(sizeof(struct DataInfo));
    Info->FirstNode = NULL;
    Info->LastNode = NULL;
    Info->NodeCount = 0;
    printf("Node Ready!\n");
    return Info;
};
void InsertNode(struct DataInfo *Info, int valor){
    if(Info->FirstNode == NULL){
        struct Node * New = (struct Node *)malloc(sizeof(struct Node));
        New->valor = valor;
        New->NextNode = NULL;
        New->PrevNode = NULL;

        Info->FirstNode = New;
        Info->LastNode = New;
        Info->NodeCount++;
        //printf("Atual    %d:\n", New);
    }
    else if(Info->FirstNode != NULL){
        struct Node * New = (struct Node *)malloc(sizeof(struct Node));
        struct Node * ANew = Info->LastNode;
        ANew->NextNode = New;

        New->valor = valor;
        New->NextNode = NULL;
        New->PrevNode = Info->LastNode;

        Info->LastNode = New;
        Info->NodeCount++;
    }
}
void PrintNode(struct DataInfo *Info){
    struct Node *Pointer = Info->FirstNode;
    do{
        printf("%d ", Pointer->valor);
        Pointer = Pointer->NextNode;
    }while(Pointer != NULL);
}
void SearchNode(struct DataInfo *Info, int valor){
    struct Node *Pointer = Info->FirstNode;
    do{
        if(Pointer->valor == valor){
            printf("Number %d found!\n", Pointer->valor);
        }
        Pointer = Pointer->NextNode;
    }while(Pointer != NULL);
}

int main()
{
    int i=0;

    struct DataInfo *StartNode();
    void InsertNode();
    void PrintNode();
    void SearchNode();

    struct DataInfo *Info = StartNode(Info);

    while(i<5){
        InsertNode(Info, i);
        i++;
    }

    struct Node *pcabeca;
    struct Node *primeiro;
    struct Node *ultimo;
    struct Node *Aux2;
    struct Node *teste;

    teste = Info->FirstNode;
    pcabeca = Info->FirstNode;

    while(teste != NULL){
        printf("%d ", teste->valor);
        if(teste->valor == 0){          // se achou o valor
            Aux2 = teste->PrevNode;     // guarda o anterior dele, em Aux2
            primeiro = teste;           // e guarda o elemento que achou como primeiro
        }
        if(teste->NextNode == NULL){
            ultimo = teste;             // se achou o ultimo elemento, guarda em ultimo
        }
    teste = teste->NextNode;
    }
    ultimo->NextNode = pcabeca;         // aponta o ultimo para pcabeça (q era o primeiro)
    Aux2->NextNode = NULL;              // aponta o elemento anterior do valor achado,
                                        // e faz o proximo dele apontar para um proximo null, pq agora ele é ultimo.
    printf("\n");
    struct Node *Pointer = primeiro;
    do{
        printf("%d ", Pointer->valor);
        Pointer = Pointer->NextNode;
    }while(Pointer != NULL);

    //PrintNode(primeiro);
    return 0;
}
