#include <stdlib.h>
#include <stdio.h>

void exemplo_int();


void exemplo_int(){
    int *vetor;
    int n;

    printf("Digite o tamnho do vetor\n");
    scanf("%d", &n);

    vetor = malloc(n*sizeof(int));

    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }
    
    for (size_t i = 0; i < n; i++)
    {
        printf("P%d:  %d\n", i + 1,vetor[i]);
    }

    free(vetor);
}


int main(){

// exemplo de alocação dinamica com int
    exemplo_int();



    return 0;
}