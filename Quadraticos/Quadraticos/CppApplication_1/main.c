#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ES.h"
#include "quadraticos.h"

int main(int argc, char** argv) {
    char metOrd[20], nomeArq[20];
    int tamE;

    printf("Insira o tamanho do vetor: ");
    scanf("%d", &tamE);

    int vet[tamE];

    printf("Insira o metodo a ser utilizado para a ordenacao: ");
    scanf("%s", metOrd);

    printf("Insira o nome do arquivo para leitura: ");
    scanf("%s", nomeArq);

    lerArquivo(nomeArq, vet);

    if(strcmp(metOrd, "bolha")==0){
        bolha(vet, tamE);
        escreverArquivo(vet, tamE);
    }
    else if(strcmp(metOrd, "bolhaInt")==0){
        bolhaInteligente(vet, tamE);
        escreverArquivo(vet, tamE);
    }
    else if(strcmp(metOrd, "selecao")==0){
        selecao(vet, tamE);
        escreverArquivo(vet, tamE);
    }
    else if(strcmp(metOrd, "insercao")==0){
        insercao(vet, tamE);
        escreverArquivo(vet, tamE);
    }
    else
        printf("Metodo nao encontrado!");

    return (EXIT_SUCCESS);
}


