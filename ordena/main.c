#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	FILE *arquivo = fopen("entrada.txt","w");
	int quantidade, i;
	printf("Digite a quantidade de números: ");
	scanf("%d", &quantidade);

	if (arquivo==NULL) {
		printf("Falha ao criar o arquivo.");
		exit(1);
	}
	else {
        fprintf(arquivo, "%d\n\n", quantidade);
		for (i=1;i<=quantidade;i++)
			fprintf(arquivo, "%d ", rand()%1000);
	}

	FILE *arquivo = fopen("entrada.txt","r");

	fclose(arquivo);
	return 0;
}
