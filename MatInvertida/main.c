#include <stdio.h>
#include <stdlib.h>

// Pra que funcão criamatriz()??????????????
// Pra devolver um ponteiro pra fazer tudo que eu preciso fazer na main..
// Não existe matriz, é tudo uma ilusão a moral é converter em um vetor e simualr uma matriz ez pz  
int main(){
    int MAX= 3;  // Tamanho da matriz
    int *mat;
    int i, j;
    int c = 0;

    mat = calloc(MAX * MAX, sizeof(int)); // Cria matriz
    for(i=0; i<MAX; i++){
        for(j=0; j<MAX; j++){
            *(mat + i * MAX + j) = c++; // aloca de 1 a MAX * MAX dentro da "matriz"
        }
    }

    printf("\n");
    printf("Matriz:\n");
    for(i=0; i<MAX; i++){
        for(j=0; j<MAX; j++){
            printf("%d ", *(mat + i * MAX + j)); // printa a matriz normal
        }
    printf("\n");
    }

    printf("\n");
    printf("Invertida:\n");
    for(i=0; i<MAX; i++){
        for(j=0; j<MAX; j++){
            printf("%d ", *(mat + j * MAX + i)); // printa a matriz invertida
        }
    printf("\n");
    }
    free(mat);
    return 0;
}
