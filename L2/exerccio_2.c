#include <stdio.h>
# include <stdlib.h>

typedef struct Node
{
    double data;
    struct Node *next;
}Node; 

Node* create_node();
void append();
void show_lists();
void read_csv();
void calculate_percentual_variation();
double find_higher_value();

int main(){
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *head3 = NULL;

    read_csv(&head1, &head2);
    calculate_percentual_variation(head1, head2, &head3);

    show_lists(head1, head2, head3);
    // show_higher_value(head3);

    return 0;
}

double find_higher_value(Node *head3){
    Node *aux = head3;
    double value = aux->data;
    while(aux != NULL){
        if(aux->data > value){
            value = aux->data;
        }
        aux = aux->next;
    }

    return value;
}


void calculate_percentual_variation(Node *head1, Node *head2, Node **head3){
    Node *aux1 = head1;
    Node *aux2 = head2;
    Node *aux3 = *head3;

    while( aux1 != NULL && aux2 != NULL){
        double data = ((aux1->data - aux2->data)/aux2->data)*(100);
        append(head3, data);
        aux1 = aux1->next;
        aux2 = aux2->next;
    }
}

void read_csv(Node **head1, Node **head2){

    FILE *file = fopen("acelerometro.csv", "r");
   
    double data1;
    double data2;
  
    while (fscanf(file, "%lf;%lf", &data1, &data2) == 2) {
        append(head1, data1);
        append(head2, data2);
    }

    fclose(file);
}
    
Node *create_node(double data){
    Node *new_node = (Node*) malloc(sizeof(Node)); // aloca memoria para um novo nó
    new_node->next = NULL; // inicializa o novo nó 
    new_node->data = data; //

    return new_node;
}

void append(Node **head, double data) {
    Node *new_node = create_node(data);

    if (*head == NULL) { // Se a lista estiver vazia, o novo nó será o primeiro
        *head = new_node;
    } else {
        Node *aux = *head; // cria um nó auxiliar para iterar em toda a lista até chegar no ultimo nó (aka nó com next == NULL)
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = new_node; // quando encontou o ultimo nó encadeia o nó (new) ao atual ultimo nó
    }
}

void show_lists(Node *head1, Node *head2, Node *head3) {
    printf("Coluna 1: \n");
    Node *aux = head1;
    double i = 0;
    while (aux != NULL) {
        printf("t = %.2f s : %.9f     \n", i, aux->data);
        aux = aux->next;
        i += 0.5;
    }
    printf("=====================\n");

    printf("Coluna 2: \n");
    aux = head2;
    double k = 0;
    while (aux != NULL) {
        printf("t = %.2f s : %.9f     \n", k, aux->data);
        aux = aux->next;
        k += 0.5;
    }
    printf("=====================\n");

    printf("Resultados da variacao percentual: \n");

    double higher_value = find_higher_value(head3);

    aux = head3;
    double j = 0;
    while (aux != NULL) {
        if (aux->data == higher_value)
        {
            printf("t = %.2f s : %.9f     ==> Maior valor\n", j, aux->data);
        }else{
            printf("t = %.2f s : %.9f     \n", j, aux->data);
        }
        
        
        aux = aux->next;
        j += 0.5;
    }
    printf("=====================\n");
}