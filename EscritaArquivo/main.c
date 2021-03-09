#include <stdio.h>
#include <stdlib.h>

int main()
{
    int variavel = 10;
    int vetor[3];
    vetor[0] = 10;
    vetor[1] = 20;
    vetor[2] = 30;
    FILE *arq = fopen("Dados.txt", "w");
    fprintf(arq, "Texto: %d\n",variavel);
    int i;
    for(i=0; i<3; i++){
        fprintf(arq, "Texto: %d\n", vetor[i]);
    }
    fclose(arq);
}
