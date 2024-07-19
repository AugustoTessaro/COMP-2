#include <stdio.h>
#include <string.h>
#include <math.h>


double fatorial(int n)
{
  double fat;
  
  if ( n <= 1 )
    return (1);
  else
  {
    fat = n * fatorial(n - 1);
    return fat;
  }
}

double cosseno(double rad, int indice) 
{
    double cos = 0.0;
    for (int n = 0; n < indice; n++) {
        double termo = pow(rad, 2*n) / fatorial(2*n);
        if (n % 2 == 0) {
            cos += termo;  
        } else {
            cos -= termo;  
        }
    }
    return cos;
}



int main(){

    int graus, ng;
    double xg, cos;

    printf("Digite o valor do angulo\n");
    scanf("%d", &graus);

    xg = (graus * 3.14 )/ 180;

    printf("Digite a precisao\n");
    scanf("%d", &ng);
    
    cos = cosseno(xg, ng);


    printf("O valor apoximado do cosseno com a serie de taylor e %lf  com precisao de %d", cos, ng);

    return 0;
}