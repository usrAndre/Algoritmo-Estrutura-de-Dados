// Criado em 21/03/2018
#include "stdio.h"
#include "stdlib.h"


/*****************************************************************************************/
/** Prototipos para funções de ordenação interna                                         */
/*****************************************************************************************/
void bubbleSort(int *V, int n, int *n_comp, int *n_mov);
void bubbleSort1(int *V, int n, int *n_comp, int *n_mov);
void bubbleSort2(int *V, int n, int *n_comp, int *n_mov);
void insertionSort(int *V, int n, int *n_comp, int *n_mov);


/*****************************************************************************************/
/** Programa principal                                                                   */
/*****************************************************************************************/
int main(void) {

  int n = 5;
  int V[n], i, opcao, n_comp, n_mov;

  // menu
  do{
    // zera as variáveis contadoras
    n_comp = 0;
    n_mov = 0;

    // menu de opções
    printf("\n--------------------------------------------------------- \n");
    printf(" Escolha uma opção no menu para ordenação: \n");
    printf("\n 1. Bubble Sort \n");
    printf(" 2. Bubble Sort Melhorado Versão 1 \n");
    printf(" 3. Bubble Sort Melhorado Versão 2 \n");
    printf(" 4. Insertion Sort \n");
    printf(" 5. Sair \n\n Opção: ");
    scanf("%i", &opcao);
    printf("--------------------------------------------------------- \n");

    if(opcao != 5)
    {
      // carrega os números no vetor
      printf("\nDigite %i números para serem ordenados: \n", n);
      for(i=0;i<n;i++) scanf("%i", &V[i]);

      // ordena o vetor em ordem crescente
      switch(opcao){
        case 1: bubbleSort(V, n, &n_comp, &n_mov);
                break;
        case 2: bubbleSort1(V, n, &n_comp, &n_mov);
                break;
        case 3: bubbleSort2(V, n, &n_comp, &n_mov);
                break;
        case 4: insertionSort(V, n, &n_comp, &n_mov);
                break;
      }

      // mostra o vetor ordenado
      printf("\n---------------------------------------------------------");
      printf("\n Vetor ordenado: ");
      for(i=0;i<=4;i++)  printf("%i ", V[i]);

      // mostra o número de comparação e movimentações executadas
      printf("\n Tamanho do vetor: %i ", n);
      printf("\n Número de comparações: %i ", n_comp);
      printf("\n Número de movimentações: %i ", n_mov);
      printf("\n---------------------------------------------------------\n\n");

    }else{
        printf("\nFinalizando...\n\n");
    }

  }while(opcao != 5);

  return 0;

}



/*****************************************************************************************/
/** Metodo de ordenacao Bubble Sort (ordem crescente)                                    */
/*****************************************************************************************/
void bubbleSort(int *V, int n, int *n_comp, int *n_mov){

  int aux;

  // laço com a quantidade de elementos do vetor
  for(int i=0;i<n;i++)
  {
    // laço que percorre da primeira à penúltima posição do vetor
    for(int j=0;j<(n-1);j++)
    {
      // acrescenta 1 comparação
      (*n_comp)++;

      if(V[j] > V[j+1]){

        // acrescenta 1 movimentação
        (*n_mov)++;

        aux = V[j];
        V[j] = V[j+1];
        V[j+1] = aux;
      }
    }
  }
}


/*****************************************************************************************/
/** Metodo de ordenacao Bubble Sort melhorado versão 1 (ordem crescente)                 */
/*****************************************************************************************/
void bubbleSort1(int *V, int n, int *n_comp, int *n_mov){

  int aux;

  // laço com a quantidade de elementos do vetor - 1
  for(int i=1;i<n;i++)
  {
    // laço que percorre da última posição à posição i do vetor
    for(int j=(n-1);j>=i;j--)
    {
      // acrescenta 1 comparação
      (*n_comp)++;

      if(V[j] < V[j-1]){

        // acrescenta 1 movimentação
        (*n_mov)++;

        aux = V[j];
        V[j] = V[j-1];
        V[j-1] = aux;
      }
    }
  }
}


/*****************************************************************************************/
/** Metodo de ordenacao Bubble Sort melhorado versão 2 (ordem crescente)                 */
/*****************************************************************************************/
void bubbleSort2(int *V, int n, int *n_comp, int *n_mov){

  int i, aux;
  int houve_troca = 1;

  // laço com a quantidade de elementos do vetor e enquanto houver troca
  while(i <= n && houve_troca)
  {
    houve_troca = 0;

    // laço que percorre da primeira à penúltima posição do vetor
    for(int j=0;j<(n-1);j++)
    {
      // acrescenta 1 comparação
      (*n_comp)++;

      if(V[j] > V[j+1]){

        // sinaliza que houve troca nesta iteração
        houve_troca = 1;

         // acrescenta 1 movimentação
        (*n_mov)++;

        aux = V[j];
        V[j] = V[j+1];
        V[j+1] = aux;
      }
    }
    i++;
  }
}



/*****************************************************************************************/
/** Metodo de ordenacao Insertion Sort (ordem crescente)                                 */
/*****************************************************************************************/
void insertionSort(int *V, int n, int *n_comp, int *n_mov){

  int eleito, j;

  // laço com a quantidade de elementos do vetor - 1
  for(int i=1;i<=(n-1);i++)
  {
    eleito = V[i];
    j = i - 1;

    // acrescenta 1 comparação
    (*n_comp)++;

    // laço que percorre os elementos à esquerda do número eleito ou até encontrar a posição para recolocação do eleito em ordem crescente
    while(j >= 0 && V[j] > eleito)
    {
      // acrescenta 1 comparação
      (*n_comp)++;

      // acrescenta 1 comparação
      (*n_mov)++;

      V[j+1] = V[j];
      j--;
    }

    V[j+1] = eleito;
  }
}
