// Criado em 21/03/2018
#include "stdio.h"
#include "stdlib.h"


/*****************************************************************************************/
/** Prototipos para funções de ordenação interna                                         */
/*****************************************************************************************/
void selectionSort(int *V, int n, int *n_comp, int *n_mov);


/*****************************************************************************************/
/** Programa principal                                                                   */
/*****************************************************************************************/
int main(void) {

  int n = 5;
  int V[n], i, opcao, n_comp, n_mov;

  // zera as variáveis contadoras
  n_comp = 0;
  n_mov = 0;

  // carrega os números no vetor
  printf("\nDigite %i números para serem ordenados: \n", n);
  for(i=0;i<n;i++) scanf("%i", &V[i]);

  // ordena o vetor em ordem crescente
  selectionSort(V, n, &n_comp, &n_mov);

  // mostra o vetor ordenado
  printf("\n---------------------------------------------------------");
  printf("\n Vetor ordenado: ");
  for(i=0;i<=4;i++)  printf("%i ", V[i]);

  // mostra o número de comparação e movimentações executadas
  printf("\n Tamanho do vetor: %i ", n);
  printf("\n Número de comparações: %i ", n_comp);
  printf("\n Número de movimentações: %i ", n_mov);
  printf("\n---------------------------------------------------------\n\n");

  return 0;

}


/*****************************************************************************************/
/** Metodo de ordenacao Selection Sort (ordem crescente)                                 */
/*****************************************************************************************/
void selectionSort(int *V, int n, int *n_comp, int *n_mov){

  int eleito, menor, pos, j;

  // laço com a quantidade de elementos do vetor - 1
  for(int i=0;i<n-1;i++)
  {
    eleito = V[i];
    menor = V[i+1];
    pos = i + 1;

    // laço que percorre os elementos à esquerda do número eleito ou até encontrar a posição para recolocação do eleito em ordem crescente
    for(j=i+1; j<=n-1; j++)
    {
      // acrescenta 1 comparação
      (*n_comp)++;

      if(V[j] < menor)
      {
          menor = V[j];
          pos = j;
      }
    }

    // acrescenta 1 comparação
    (*n_comp)++;
    if(menor < eleito)
    {
      // acrescenta 1 comparação
      (*n_mov)++;

      V[i] = V[pos];
      V[pos] = eleito;
    }
  }
}
