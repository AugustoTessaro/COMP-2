#include <stdio.h>
#include <math.h>


void medidasDoRetangulo(double l1, double  l2, double *A, double *P)
{
    *A = l1 * l2;
    *P = (l1 * 2) + (l2 * 2);
}


int main(){

    double l1, l2, A, P;

    printf("Digite os valores dos lados do seu retangulo\n");
    scanf("%lf%lf", &l1, &l2);    

    medidasDoRetangulo(l1, l2, &A, &P);
    
    printf("A area do retangulo e: %lf. \nO perimetro do seu retangulo e: %lf", A, P);
    return 0;
}
