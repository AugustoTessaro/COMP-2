

#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 10

bool verificaRepetidos(double *vetor, double numero, int count) {
    for (int i = 0; i < count; i++) {
        if (numero == vetor[i]) {
            return false;
        }
    }
    return true;
}

void carregaConjunto(double *vetor) {
    int contador = 0;
    double numero;
    while (contador < TAMANHO) {
        printf("Digite um valor para o vetor, ate entao o vetor contem %d valores distintos \n", contador);
        scanf("%lf", &numero);
        if (verificaRepetidos(vetor, numero, contador)) {
            vetor[contador] = numero;
            contador++;
        } else {
            printf("Voce digitou um numero repetido amigo \n");
        }
    }
}

void diferenca(double *resultado, double *conjunto1, double *conjunto2, int *tamanhoResultado) {
    int contador = 0;
    for (int i = 0; i < TAMANHO; i++) {
        bool found = false;
        for (int j = 0; j < TAMANHO; j++) {
            if (conjunto1[i] == conjunto2[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            resultado[contador] = conjunto1[i];
            contador++;
        }
    }
    *tamanhoResultado = contador;
}

void imprimeConjunto(double *vetor, int tamanho) {
    printf("Elementos do conjunto resultado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%.2lf ", vetor[i]);
    }
    printf("\n");
}

int main() {
    double x[TAMANHO], y[TAMANHO], resultado[TAMANHO] = {0};
    int tamanhoResultado = 0;

    printf("Preencha o conjunto X:\n");
    carregaConjunto(x);

    printf("Preencha o conjunto Y:\n");
    carregaConjunto(y);

    diferenca(resultado, x, y, &tamanhoResultado);

    imprimeConjunto(resultado, tamanhoResultado);

    return 0;
}