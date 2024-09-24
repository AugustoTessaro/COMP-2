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
void free_list();

int main(){
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *head3 = NULL;

    read_csv(&head1, &head2);
    calculate_percentual_variation(head1, head2, &head3);

    show_lists(head1, head2, head3);
    
    free_list(head1);
    free_list(head2);
    free_list(head3);

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

void free_list(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
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

    if (*head == NULL) { 
        *head = new_node;
    } else {
        Node *aux = *head; 
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = new_node;
    }
}

void show_lists(Node *head1, Node *head2, Node *head3) {
    printf("=================================================================\n");
    printf("Tempo     | Coluna 1:       | Coluna 2:       | Coluna 3:       |\n");
    printf("----------+-----------------+-----------------+------------------\n");

    Node *aux1 = head1;
    Node *aux2 = head2;
    Node *aux3 = head3;
    double higher_value = find_higher_value(head3);

    double i = 0;
    while (aux1 != NULL && aux2 != NULL && aux3 != NULL) {
        if (aux3->data == higher_value)
        {
            printf("t = %.1fs  | %-15.9f | %-15.9f | (%-12.9f)  | ==> Maior variacao percentual\n", i, aux1->data, aux2->data, aux3->data);
        }else{
            printf("t = %.1fs  | %-15.9f | %-15.9f | %-15.9f |\n", i, aux1->data, aux2->data, aux3->data);
        }
        
        aux1 = aux1->next;
        aux2 = aux2->next;
        aux3 = aux3->next;

        i += 0.5;
    }
    printf("=================================================================\n");
}