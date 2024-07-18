#include <stdio.h>
#include <string.h>

#define tamanho 10


bool verificaRepetidos(double *vetor, double numero, int count){
    for (size_t i = 0; i < count; i++)
    {
        if (numero == vetor[i])
        {
            return false;
        }
        
    }

    return true;
    
}

void cacarregaConjunto(double *vetor){
    int contador = 0;
    double numero;
    while (contador < tamanho)
    {
        printf("Digite um valor para o vetor, ate entao o vetor contem %d valores distintos \n", contador);
        scanf("%lf", &numero);
        if(verificaRepetidos(vetor, numero, contador))
        {
            vetor[contador] = numero;
            contador++;
        }
        else
        {
            printf("Voce digitou um numero repetido amigo \n");
        }
    }
     
}



int main(){

    double x[tamanho], y[tamanho], resultado[tamanho];

    cacarregaConjunto(x);
    cacarregaConjunto(y);

    
    
    for (size_t i = 0; i < tamanho; i++)
    {
        printf("%lf",x[i]);
    }
    


    return 0;
}

