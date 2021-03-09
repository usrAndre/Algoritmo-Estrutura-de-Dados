#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quadraticos.h"

clock_t t0, tf;
double tempo_gasto;

void bolha(int vet[], int tam){
    t0 = clock();
    int i, j, aux;
    for(i = 1; i < tam; i++){
        for(j = 0; j < tam-1; j++){
            if(vet[j] > vet[j+1]){
                aux = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = aux;
            }
        }
    }
    tf = clock();
    tempo_gasto = (( (double) (tf - t0) ) / (((double)CLOCKS_PER_SEC)/1000));
    printf("\n\nTempo gasto: %lf ms\n\n", tempo_gasto);
}

void bolhaInteligente(int vet[], int tam){
    t0 = clock();
    int i, j, aux;
    int troca = 0, quant = 0;
    for(i=0; i<tam; i++){
        j=0;
        troca = 0;
        while(j<(tam-i)){
            if(vet[j] > vet[j+1]){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
                troca = 1;
            }
            j++;
        }
        if(troca == 0){
            printf("\nExecutou %d vezes", quant);
            tf = clock();
            tempo_gasto = (((double)(tf-t0))/(((double)CLOCKS_PER_SEC)/1000));
    printf("\n\nTempo gasto: %lf ms\n\n", tempo_gasto);
            return;
        }
        quant++;
    }
    printf("\nExecutou %d vezes\n", quant);
    tf = clock();
    tempo_gasto = (( (double) (tf - t0) ) / (((double)CLOCKS_PER_SEC)/1000));
    printf("\n\nkkkkk Tempo gasto: %lf s\n\n", tempo_gasto);
    return;
}

void selecao(int vet[], int tam){
    t0 = clock();
    int i, j;
    int min, aux;
    for(i=0; i<tam-1; i++) {
        min = i;
        for(j=i+1; j<tam; j++) {
            if (vet[j] < vet[min])
                min = j;
        }
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }

    tf = clock();
    tempo_gasto = (( (double) (tf - t0) ) / (((double)CLOCKS_PER_SEC)/1000));
    printf("\n\nTempo gasto: %lf ms\n\n", tempo_gasto);
    return;
}

void insercao(int vet[], int tam){
    t0 = clock();
    int i, j, atual;
	for (i = 1; i < tam; i++) {
        atual = vet[i];
		for (j = i - 1; (j >= 0) && (atual < vet[j]); j--) {
			vet[j + 1] = vet[j];
        }
		vet[j+1] = atual;
	}
	tf = clock();
    tempo_gasto = (( (double) (tf - t0) ) / (((double)CLOCKS_PER_SEC)/1000));
    printf("\n\nTempo gasto: %lf ms\n\n", tempo_gasto);
    return;
}
