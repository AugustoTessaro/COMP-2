#include <stdio.h>

struct Data
{
    int dia;
    int mes;
    int ano;
};

typedef struct Data data;


int main(){
    data data1;

    printf("digite os dados da data\n");
    scanf("%d", &data1.dia);
    scanf("%d", &data1.mes);
    scanf("%d", &data1.ano);

    printf("A data completa e: %d/%d/%d\n", data1.dia, data1.mes, data1.ano);

    return 0;
}