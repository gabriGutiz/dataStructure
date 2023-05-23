#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void printList(Node *start){
    for (Node *aux = start; aux != NULL; aux = aux->next){
        printf("%d ", aux->data);
    }
    printf("\n");
}

int main(){
    printf("############## Init ##############\n");
    Node n1, n2, n3;

    n1.data = 5;
    n1.next = &n2;

    n2.data = 3;
    n2.next = &n3;
    
    n3.data = 9;
    n3.next = NULL;
    
    imprime(&n1);

    return 0;
}