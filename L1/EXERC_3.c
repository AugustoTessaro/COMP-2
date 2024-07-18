#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char* filtro(const char* s1) {
    static char s2[sizeof(s1)];

    for (size_t i = 0; i < strlen(s1); i++) {
        if (isalnum(s1[i]) || isspace(s1[i])) {
            s2[i] = s1[i];
        } else {
            s2[i] = '_';
        }
    }
    s2[strlen(s1)] = '\0'; 

    return s2;
}


int main(){

    char s1[255];
    
    printf("Digite qualquer coisa e ao terminar tecle Enter \n");
    fgets(s1, sizeof(s1), stdin);

    const char* s2 = filtro(s1);

    printf("String filtrada: %s", s2);



    return 0;
}