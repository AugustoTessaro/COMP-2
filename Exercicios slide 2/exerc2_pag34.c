#include <stdio.h>
#include <math.h>

#define size 5

void p1();


void p1(int *vetor)
{
    for (size_t i = 0; i < size ; i++)
    {
        printf("Digite o valor da posicao %d/2 \n", i + 1);
        scanf(" %d", &vetor[i]);
    }
}

int multiplicacao_escalar(int *v1, int *v2)
{   
    int result = 0;

    p1(v1);
    p1(v2);

    for (size_t i = 0; i < size; i++)
    {
        result += v1[i] * v2[i];
    }
    
    return result;
}


int main(){
    int banana[size], banana2[size];

    printf("Resultado da multiplicacao escalar entre vetores e: %d", multiplicacao_escalar(banana, banana2));
 
    return 0;
}