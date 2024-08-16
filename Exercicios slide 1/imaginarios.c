#include <stdio.h>
#include <math.h>


void soma(double z1r, double z1i, double z2r, double z2i, double *somr, double *somi)
{
    *somr = z1r + z2r;
    *somi = z1i + z2i;
}

void sub(double z1r, double z1i, double z2r, double z2i, double *subr, double *subi)
{
    *subr = z1r + z2r;
    *subi = z1i + z2i;
}




int main()
{
    double z1r, z1i, z2r, z2i, somr, somi, subr, subi;

    printf("Digita os numero real e iimaginario ai cuzao \n");
    scanf("%lf%lf%lf%lf ", &z1r, &z1i, &z2r, &z2i);

    soma(z1r, z1i, z2r, z2i, &somr, &somi);
    sub(z1r, z1i, z2r, z2i, &subr, &subi);

    printf("A soma dos numeros z1 e z2 e: %lf %lf+i", somr, somi );









    return 0;
}