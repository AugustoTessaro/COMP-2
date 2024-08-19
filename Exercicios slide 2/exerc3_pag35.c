#include <stdio.h>
#include <math.h>

#define size 5

void p1();
void p3();
int *copia();


void p1(int *vetor)
{
    for (size_t i = 0; i < size ; i++)
    {
        printf("Digite o valor da posicao %d/%d \n", i + 1, size);
        scanf(" %d", &vetor[i]);
    }
}

void p3(int *vetor, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("O valor da posicao %d/%d: %d\n", i + 1, n, vetor[i]);
    }
    
}

int *copia(int *v1)
{   
    static int v2[size];

    p1(v1);

    for (size_t i = 0; i < size; i++)
    {
        v2[i] = v1[i];
    }
    
    return v2;
}


int main(){
    int banana[size], *resultado;



    resultado = copia(banana);
    p3(resultado, 5);

 
    return 0;
}