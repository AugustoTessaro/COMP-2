#include <stdio.h>
#define size 5 

void p1();


void p1(int *vetor)
{
    
    for (size_t i = 0; i < size ; i++)
    {
        printf("Digite o valor da posicao %d/5 \n", i + 1);
        scanf(" %d", &vetor[i]);
    }
    
}


int main(){
    int banana[size];

    p1(banana);
    return 0;
}