#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	FILE *arquivo;
	char nome[10];
	int quantidade, i;
	printf("Digite o nome do arquivo:");
	scanf("%s", nome);
	printf("Digite a quantidade de números:");
	scanf("%d", &quantidade);
	arquivo = fopen(nome, "w");
	if (arquivo==NULL) {
		printf("Falha ao criar o arquivo.");
		exit(1);
	}
	else {
		for (i=1;i<=quantidade;i++)
			fprintf(arquivo, "%d\n", rand()%100);
	}

	fclose(arquivo);
	return 0;
}
