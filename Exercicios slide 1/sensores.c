#include <stdio.h>
#include <math.h>


void leitura(int *s1,int *s2, int *s3)
{
    printf("Digite os valores para cada um dos sensores\n");
    scanf("%d%d%d", s1, s2, s3);
}

int media_sensor(int s1, int s2, int s3)
{
    leitura(&s1, &s2, &s3);
    printf("%d", (s1 + s2 + s3)/3 );

    return (s1 + s2 + s3)/3;
}

int main(){
    int s1, s2, s3, result;

    result = media_sensor(s1, s2, s3);
    printf("resultado dos sensores e: %d", result);


    return 0;
}