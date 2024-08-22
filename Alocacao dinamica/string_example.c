#include <stdio.h>
#include <stdlib.h>

void exemplo_string();
void getstring();
void printstrings();

void getstring(char **strings, int n){

    for (size_t i = 0; i < n; i++)
    {
        printf("String %d: ", i + 1);
        scanf(" %[^\n]", strings[i]);
    }
    
}

void printstrings(char **strings, int n){

    for (size_t i = 0; i < n; i++)
    {
        printf("%s\n", strings[i]);
    }
    
}

void exemplo_string(){
    char **strings;
    int n, size;

    printf("Quantidade de strings\n");
    scanf("%d", &n);

    strings = malloc(n*sizeof(char*));

    printf("Tamnho de cada string\n");
    scanf("%d", &size);

    for (size_t i = 0; i < n; i++)
    {
        strings[i] = malloc(size*sizeof(char));
    }

    getstring(strings, n);
    printstrings(strings, n);

    for (size_t i = 0; i < n; i++)
        free(strings[i]);
    free(strings);
}

int main(){

    exemplo_string();

    return 0;
}