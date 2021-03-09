#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int file() {
	FILE *arquivo = fopen("entrada.txt","w");
	//char nome[10];
	int quantidade, i;
	//printf("Digite o nome do arquivo:");
	//scanf("%s", nome);
	printf("Digite a quantidade de números: ");
	scanf("%d", &quantidade);
	//arquivo = fopen(nome, "w");
	if (arquivo==NULL) {
		printf("Falha ao criar o arquivo.");
		exit(1);
	}
	else {
        fprintf(arquivo, "%d\n\n", quantidade);
		for (i=1;i<=quantidade;i++)
			fprintf(arquivo, "%d ", rand()%1000);
	}
	fclose(arquivo);

	//FILE *arquivo = fopen("entrada.txt","r");

	return 0;
}

