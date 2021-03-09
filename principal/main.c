#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Entre com um numero: ");
    scanf("%d",&num);
    if(EhPar(num))
        printf("\n\nO numero eh par.\n");
    else
        printf("\n\nO numero eh impar.\n");
    return 0;

}
