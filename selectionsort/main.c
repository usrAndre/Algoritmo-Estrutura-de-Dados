// Criado em 21/03/2018
#include "stdio.h"
#include "stdlib.h"


/*****************************************************************************************/
/** Prototipos para fun��es de ordena��o interna                                         */
/*****************************************************************************************/
void selectionSort(int *V, int n, int *n_comp, int *n_mov);


/*****************************************************************************************/
/** Programa principal                                                                   */
/*****************************************************************************************/
int main(void) {

  int n = 5;
  int V[n], i, opcao, n_comp, n_mov;

  // zera as vari�veis contadoras
  n_comp = 0;
  n_mov = 0;

  // carrega os n�meros no vetor
  printf("\nDigite %i n�meros para serem ordenados: \n", n);
  for(i=0;i<n;i++) scanf("%i", &V[i]);

  // ordena o vetor em ordem crescente
  selectionSort(V, n, &n_comp, &n_mov);

  // mostra o vetor ordenado
  printf("\n---------------------------------------------------------");
  printf("\n Vetor ordenado: ");
  for(i=0;i<=4;i++)  printf("%i ", V[i]);

  // mostra o n�mero de compara��o e movimenta��es executadas
  printf("\n Tamanho do vetor: %i ", n);
  printf("\n N�mero de compara��es: %i ", n_comp);
  printf("\n N�mero de movimenta��es: %i ", n_mov);
  printf("\n---------------------------------------------------------\n\n");

  return 0;

}


/*****************************************************************************************/
/** Metodo de ordenacao Selection Sort (ordem crescente)                                 */
/*****************************************************************************************/
void selectionSort(int *V, int n, int *n_comp, int *n_mov){

  int eleito, menor, pos, j;

  // la�o com a quantidade de elementos do vetor - 1
  for(int i=0;i<n-1;i++)
  {
    eleito = V[i];
    menor = V[i+1];
    pos = i + 1;

    // la�o que percorre os elementos � esquerda do n�mero eleito ou at� encontrar a posi��o para recoloca��o do eleito em ordem crescente
    for(j=i+1; j<=n-1; j++)
    {
      // acrescenta 1 compara��o
      (*n_comp)++;

      if(V[j] < menor)
      {
          menor = V[j];
          pos = j;
      }
    }

    // acrescenta 1 compara��o
    (*n_comp)++;
    if(menor < eleito)
    {
      // acrescenta 1 compara��o
      (*n_mov)++;

      V[i] = V[pos];
      V[pos] = eleito;
    }
  }
}
