#include <stdio.h>
# include <stdlib.h>

void input_tools();
void show_tools();
void mdealloc();

void input_tools(int **p, int *n){
    printf("Quantidade de ferramentas em posse da empresa\n");
    scanf("%d", n);

    *p = (int *)malloc( *n * sizeof(int));

    for(int i = 0; i < *n; i++){
        printf("Numero do patrimonio:\n");
        scanf("%d", &(*p)[i]);
    }

    printf("Codigos das ferramentas salvos com exito\n");
}

void show_tools(int *p, int n){
    for (size_t i = 0; i < n; i++)
    {
        printf("Ferramenta %d tem codigo igual a: %d\n", i + 1, p[i]);
    }
}

void mdealloc(int *p){
    free(p);
}

int main(){
    int n, *p;
    input_tools(&p, &n);
    show_tools(p, n);
    mdealloc(p);
    
    return 0;
}