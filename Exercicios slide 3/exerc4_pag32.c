#include <stdio.h>

typedef struct
{
    char fabricante[255];
    char modelo[255];
    int ano;
    char cor[255];
    double preco;
}carro;



carro createcarro(){
    carro carro1;
    printf("Digite a fabricante\n");
    scanf(" %[^\n]", &carro1.fabricante);

    printf("Digite o modelo\n");
    scanf(" %[^\n]", &carro1.modelo);

    printf("Digite o ano\n");
    scanf("%d", &carro1.ano);

    printf("Digite a cor\n");
    scanf(" %[^\n]", &carro1.cor);
    
    printf("Digite preco\n");
    scanf("%lf", &carro1.preco);

    return carro1;
}


int parsedate(int ano){
    return ano % 100;
}

void printcarro(carro *c1){
    
    c1->ano = 
    (*c1).ano

    printf("Seu carro e:\n%s\n%s\n%d\n%s\n%lf", c1.fabricante, c1.modelo, parsedate(c1.ano), c1.cor , c1.preco);

}

void parsecarro()


int main(){
    carro c1;

    c1 = createcarro();

    printcarro(c1);
    


    return 0;
}