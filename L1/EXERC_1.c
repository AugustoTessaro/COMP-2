#include <stdio.h>
#include <string.h>

// Definição da struct memoria
typedef struct {
    double quantidade;
    char unidade[3]; // GB ou MB
} memoria;

// Definição da struct celular
typedef struct {
    char marca_modelo[50];
    double preco;
    memoria ram;
    int peso;
    int num_chips;
} celular;

// Procedimento para leitura de um celular
void leituraCelular(celular *c) {
    printf("Digite a marca/modelo do aparelho: ");
    fgets(c->marca_modelo, 50, stdin);
    c->marca_modelo[strcspn(c->marca_modelo, "\n")] = '\0'; // Remover o '\n' no final

    printf("Digite o preco: ");
    scanf("%lf", &c->preco);

    printf("Digite a quantidade de memoria RAM: ");
    scanf("%lf", &c->ram.quantidade);

    printf("Digite a unidade da memoria RAM (GB/MB): ");
    scanf("%s", c->ram.unidade);

    printf("Digite o peso em gramas: ");
    scanf("%d", &c->peso);

    printf("Digite o numero de chips: ");
    scanf("%d", &c->num_chips);
}

// Função para comparar dois celulares
int compara(celular c1, celular c2, int cam) {
    if (cam < 2 || cam > 5) {
        return 0;
    }

    switch (cam) {
        case 2:
            if (c1.preco < c2.preco) return 1;
            if (c1.preco > c2.preco) return 2;
            return 3;
        case 3: {
            double ram1 = c1.ram.quantidade;
            double ram2 = c2.ram.quantidade;
            if (strcmp(c1.ram.unidade, "MB") == 0) ram1 /= 1000;
            if (strcmp(c2.ram.unidade, "MB") == 0) ram2 /= 1000;
            if (ram1 > ram2) return 1;
            if (ram1 < ram2) return 2;
            return 3;
        }
        case 4:
            if (c1.peso < c2.peso) return 1;
            if (c1.peso > c2.peso) return 2;
            return 3;
        case 5:
            if (c1.num_chips > c2.num_chips) return 1;
            if (c1.num_chips < c2.num_chips) return 2;
            return 3;
    }

    return 0;
}

// Procedimento para imprimir os dados de um celular
void imprimeCelular(celular c) {
    printf("Marca/Modelo: %s\n", c.marca_modelo);
    printf("Preco: %.2lf\n", c.preco);
    printf("Memoria RAM: %.2lf %s\n", c.ram.quantidade, c.ram.unidade);
    printf("Peso: %d g\n", c.peso);
    printf("Numero de chips: %d\n", c.num_chips);
}

int main() {
    celular c1, c2;
    int cam, resultado;

    // Leitura dos celulares
    printf("Leitura do primeiro celular:\n");
    leituraCelular(&c1);
    getchar(); // Limpar o buffer do '\n' restante

    printf("Leitura do segundo celular:\n");
    leituraCelular(&c2);
    getchar(); // Limpar o buffer do '\n' restante

    // Comparação dos celulares
    do {
        printf("Digite o numero da caracteristica a ser analisada (2-5): ");
        scanf("%d", &cam);
        resultado = compara(c1, c2, cam);

        if (resultado == 1) {
            printf("Primeiro celular e melhor:\n");
            imprimeCelular(c1);
        } else if (resultado == 2) {
            printf("Segundo celular e melhor:\n");
            imprimeCelular(c2);
        } else if (resultado == 3) {
            printf("Ambos os celulares possuem o mesmo valor para a caracteristica %d:\n", cam);
            imprimeCelular(c1);
            imprimeCelular(c2);
        } else {
            printf("Erro: campo %d invalido.\n", cam);
        }
    } while (resultado != 0);

    return 0;
}
