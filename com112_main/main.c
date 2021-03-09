#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//#include "sort.h"
//#include "file.h"
//void leitura_dados(int *, int *);
//void imprimir_dados(int *, int, char *);
//void bubblesort(int *, int);
//void combsort(int *, int);
//void shakesort(int *, int);
//void quicksort(int *, int, int);
//int particao(int *, int, int);
//void mergesort(int *, int, int, int);
//void merge(int *, int, int, int, int);
//void heapsort(int*, int);
//void heap(int*, int, int);
//void shellsort(int *, int, int);
//void insercao_shellsort(int *, int, int, int);
//void selecao_direta(int *, int);

/**********************************************FUNCAO PRINCIPAL***********************************************************/

int main(){
	int *vet;
	int tam, opcao, h;

	vet = (int*) calloc(100, sizeof(int));
	file("entrada.txt",r);
	imprimir_dados(vet, tam, "DADOS DESORDENADOS");
	do{
		printf("\n\n METODOS DE ORDENACAO");
		printf("\n 1. BUBBLESORT ");
		//printf("\n 2. COMBSORT ");
		//printf("\n 3. SHAKESORT ");
		printf("\n 4. QUICKSORT ");
		printf("\n 5. MERGESORT ");
		printf("\n 6. SHELLSORT ");
		printf("\n 7. HEAPSORT ");
		printf("\n 8. SELECAO DIRETA ");
		printf("\n 0. SAIR ");
		printf("\n Sua opcao: ");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
					bubblesort(vet, tam);
					imprimir_dados(vet, tam, "DADOS ORDENADOS PELO METODO BUBBLESORT");
					break;
			/*case 2:
					combsort(vet, tam);
					imprimir_dados(vet, tam, "DADOS ORDENADOS PELO METODO COMBSORT");
					break;
			case 3:
					shakesort(vet, tam);
					imprimir_dados(vet, tam, "DADOS ORDENADOS PELO METODO SHAKESORT");
					break;*/
			case 4:
					quicksort(vet, 0, tam-1);
					imprimir_dados(vet, tam, "DADOS ORDENADOS PELO METODO QUICKSORT");
					break;
			case 5:
					mergesort(vet, 0, tam-1, tam);
					imprimir_dados(vet, tam, "DADOS ORDENADOS PELO METODO MERGESORT");
					break;
			case 6:
					printf("\n\n Digite o valor do incremento h = ");
					scanf("%d", &h);
					shellsort(vet, tam, h);
					imprimir_dados(vet, tam, "DADOS ORDENADOS PELO METODO SHELLSORT");
					break;
			/*case 7:
					heapsort(vet, tam);
					imprimir_dados(vet, tam, "DADOS ORDENADOS PELO METODO HEAPSORT");
					break;*/
			case 8:
					selecao_direta(vet, tam);
					imprimir_dados(vet, tam, "DADOS ORDENADOS PELO METODO DA SELECAO DIRETA");
					break;
			case 0:
					printf("\n\n Saindo...");
					break;
			default:
					printf("\n Opcao invalida. Tente novamente!!!");
		}
	}while(opcao !=0);
	return 0;
}

/**********************************************METODO BUBBLESORT***********************************************************/

/*void bubblesort(int *vet, int tam){
	int troca, k, fim, aux;
	int *p, *q;
	troca = 1;
	fim = tam - 1;
	while(troca==1){
		troca = 0;
		p = vet;
		q = vet;
		q++;
		for(k=0; k<fim; k++){
			if(*p > *q){
				troca = 1;
				aux = *p;
				*p = *q;
				*q = aux;
			}
			p++;
			q++;
		}
		fim--;
	}
}

/**********************************************METODO COMBSORT***********************************************************/

/*void combsort(int *vet, int tam){
	int troca, k, h, aux;
	int *p, *q;
	troca = 0;
	h = tam;
	while(troca==0 || h != 1){
		h = h /1.3;
		p = vet;
		q = h + vet;
		for(k=0; k<tam-h; k++){
			if(*p > *q){
				aux = *p;
				*p = *q;
				*q = aux;
				troca = 1;
			}
			p++;
			q++;
		}
	}
}

/**********************************************METODO SHAKESORT***********************************************************/

/*void shakesort(int *vet, int tam){
	int troca, k, fim, aux;
	int *p, *q;
	troca = 1;
	fim = tam - 1;
	while(troca==1){
		troca = 0;
		p = vet;
		q = vet;
		q++;
		for(k=0; k<fim; k++){
			if(*p > *q){
				aux = *p;
				*p = *q;
				*q = aux;
				troca = 1;
			}
			p++;
			q++;
		}
		q = p;
		p--;
		for(k=fim; k>0; k--){
			if(*q < *p){
				troca = 1;
				aux = *q;
				*q = *p;
				*p = aux;
			}
			p--;
			q--;
		}
		fim--;
	}
}

/**********************************************METODO QUICKSORT***********************************************************/

/*void quicksort(int *vet, int inf, int sup){
	int k;
	if(sup>inf){
		k = particao(vet, inf, sup);
		particao(vet, inf, k-1);
		particao(vet, k+1, sup);
	}
}


/**********************************************METODO QUICKSORT - PARTICAO*************************************************/

/*int particao(int *vet, int inf, int sup){
	int m, k, aux;
	int *p, *q;
	k = inf;
	p = inf + vet;
	q = sup + vet;
	m = *p;
	do{
		while(sup > inf && *q >= m){
			sup--;
			q = sup + vet;
		}
		k = sup;
		if(sup != inf){
			aux = *p;
			*p = *q;
			*q = aux;
			while(inf < sup && *p <= m){
				inf++;
				p++;
			}
			k = inf;
			if(inf != sup){
				aux = *p;
				*p = *q;
				*q = aux;
			}
		}
	}while(inf != sup);
	return k;
}

/**********************************************METODO MERGESORT******************************************************/

/*void mergesort(int *vet, int l, int r, int tam){
	int meio;
	if(l<r){
		meio = (l+r)/2;
		mergesort(vet, l, meio, tam);
		mergesort(vet, meio+1, r, tam);
		merge(vet, l, meio, r, tam);
	}
}

/**********************************************METODO MERGESORT - MERGE***************************************************/

/*void merge(int *vet, int l, int meio, int r, int tam){
	int i, j, k;
	int *aux, *p, *q, *t;
	aux = (int*) calloc(tam, sizeof(int));
	i = j = l;
	k = meio + 1;
	while((j<=meio) && (k<=r)){
		p = j + vet;
		q = k + vet;
		t = i + aux;
		if(*p < *q){
			*t = *p;
			j++;
		}
		else{
			*t = *q;
			k++;
		}
		i++;
	}
	while(j<=meio){
		t = i + aux;
		p = j + vet;
		*t = *p;
		i++;
		j++;
	}
	for(i=l; i<k; i++){
		p = i + vet;
		t = i + aux;
		*p = *t;
	}
}

/**********************************************METODO SHELLSORT******************************************************/

/*void shellsort(int *vet, int tam, int h){
	int i;
	while(h>=1){
		for(i=0; i<=h; i++)
			insercao_shellsort(vet, tam, i, h);
		h = h / 2;
	}
}

/**********************************************METODO SHELLSORT - INSERCAO****************************************************/

/*void insercao_shellsort(int *vet, int tam, int i, int h){
	int j, k, t, ch;
	int *p, *q;
	for(j=0; j<tam; j++){
		k = 0;
		t = j - 1;
		p = j + vet;
		ch = *p;
		while(t>=0 && k==0){
			p = t + vet;
			if(ch < *p){
				q = (t+1) + vet;
				*q = *p;
				t--;
			}
			else
				k = t + 1;
		}
		q = k + vet;
		*q = ch;
	}
}

/**********************************************METODO HEAPSORT******************************************************/

/*void heapsort(int *vet, int tam){
	int *q , *p;
	int aux, e, d;
	if(tam%2==0)
		e = (tam/2)-1;
	else
		e = (tam / 2);
	d = tam-1;

	while(e>0){
		e--;
		heap(vet, e, d);
	}
	while(d>0){
		p = vet;
		q = d + vet;
		aux = *p;
		*p = *q;
		*q = aux;
		d--;
		heap(vet, 0, d);
	}
}

/**********************************************METODO HEAPSORT - HEAP******************************************************/

/*void heap(int *vet, int e, int d){
	int aux, i, j;
	int *p, *q, *r;
	i = e;
	j = (2*e) + 1;
	q = e + vet;
	aux = *q;
	p = j + vet;
	r = (j+1) + vet;
	if(j < d && *r > *p){
		j++;
	}
	p = j + vet;
	while(j <= d && *p > aux){
		*q = *p;
		i = j;
		j = (2*j) + 1;
		p = j + vet;
		r = p++;
		if(j < d && *r > *p){
			j++;
		}
		p = j + vet;
	}
	q = i + vet;
	*q = aux;
}

/**********************************************METODO DA SELECAO DIRETA******************************************************/

/*void selecao_direta(int *vet, int tam){
	int k, t, aux, troca, min;
	int *p, *q, *r;
	troca = 0;
	for(k=0; k<tam-1; k++){
		p = k + vet;
		min = *p;
		for(t=k+1; t<tam; t++){
			q =  t + vet;
			if(*q < min){
				min = *q;
				r = q;
				troca = 1;
			}
		}
		if(troca==1){
			aux = *p;
			*p = *r;
			*r = aux;
			troca = 0;
		}
	}
}

/**********************************************LEITURA DE DADOS***********************************************************/

/*void leitura_dados(int *vet, int *tam){
	FILE *arq;
	char *nome_arq;

	nome_arq = (char*) calloc(50, sizeof(char));

	printf("\n\n Digite o nome do arquivo: ");
	scanf("%s", nome_arq);

	arq = fopen(nome_arq, "rt");

	if(!arq){
		printf("\n\n Arquivo %s nao encontrado", nome_arq);
		getchar();
		exit(1);
	}
	*tam = 0;
	fscanf(arq, "%d", vet);
	while(*vet != -999){
		(*tam)++;
		vet++;
		fscanf(arq, "%d", vet);
	}
}

/**********************************************IMPRESSAO DE DADOS***********************************************************/

void imprimir_dados(int *vet, int tam, char *msg){
	int k;
	int *p;
	p = vet;
	printf("\n\n %s \n", msg);
	for(k=0; k<tam; k++){
		printf(" %d", *p);
		p++;
	}
	printf("\n");
}

/**************************************************************************************************************************/

