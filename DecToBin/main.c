#include <stdio.h>
#include <stdlib.h>

// Programa que converte decimal para Binario de até 2 bytes
// 2 bytes = 16 bits = Max Int 65535 = Max Bin 1111111111111111
int main()
{
    int i=0;
    int var1, var2;
    int *pBuffer;
    int *aux;

    pBuffer = (int *)calloc(16, sizeof(int)); // Aloca um inteiro para cada 0 ou 1, então 16*inteiros

    printf("Escreva um decimal para conversao:!\n");
    scanf("%d", &var1);

    aux = pBuffer; // atualização do ponteiro auxiliar para pbuffer
    while(var1 != 0){
        *(aux++) = var1%2; // resto da divisão guarda no pBuffer original;
        var1 = var1/2;     // divide o que tem, pela metade, se for !=0 continua no looping
        i++;               // variavel contadora
    }

    //troca de variaveis, para puxar os caras da esquerda para direita
    for(var1=0; var1<i; var1++){ // i = numero de 0 e 1 que foram alocados em pbuffer
        var2 = pBuffer[15-var1];
        pBuffer[15-var1] = pBuffer[var1];
        pBuffer[var1] = var2;
    }

    printf("\n");
    aux = pBuffer; // atualização do ponteiro auxiliar para pbuffer
    for(var1=0; var1<16; var1++){
        printf("%d", *(aux++));
    }
    free(pBuffer);
    return 0;
}
