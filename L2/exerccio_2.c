#include <stdio.h>
# include <stdlib.h>

typedef struct Node
{
    double data;
    struct Node *next;
}Node; 

Node* create_node();
void append();
void show_lists(Node *head1, Node *head2);
void read_csv();



int main(){
    Node *head1 = NULL;
    Node *head2 = NULL;

    append(&head1, 1.1);
    append(&head1, 2.2);
    append(&head2, 3.3);

    show_lists(head1, head2);

    return 0;
}

void read_csv(){

    FILE *file = fopen("acelerometro.csv", "r");
   
    
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

void show_lists(Node *head1, Node *head2) {
    printf("Lista 1: \n");
    Node *aux = head1;
    while (aux != NULL) {
        printf("%.2f     \n", aux->data);
        aux = aux->next;
    }
    printf("=========\n");

    printf("Lista 2: \n");
    aux = head2;
    while (aux != NULL) {
        printf("%.2f     \n", aux->data);
        aux = aux->next;
    }
    printf("=========\n");
}

