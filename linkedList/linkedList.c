#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* initialize() {
    return NULL;
}

Node* push(Node *init, int i) {
    Node* new = (Node*) malloc(sizeof(Node));
    new->data = i;
    new->next = init;
}

void printList(Node *init) {
    for (Node *aux = init; aux != NULL; aux = aux->next) {
        printf("%d ", aux->data);
    }
    printf("\n");
}

Node* searchByValue(Node *init, int x) {
    for (Node *aux = init; aux != NULL; aux = aux->next) {
        if (aux->data == x)
            return aux;
    }
    return NULL;
}

Node* removeByValue(Node *init, int x) {
    if (init->data == x) {
        init = init->next;
        return init;
    }
    
    for (Node *p = init; p->next != NULL; p = p->next) {
        if (p->next->data == x) {
            if (p->next->next == NULL) {
                p->next = NULL;
            } else {
                Node *next = p->next->next;
                p->next = next;
            }
            break;
        }
    }
    return init;
}

Node* insertEnd(Node *init, int val) {
    Node *i = init;
    while (i->next != NULL) {
        i = i->next;
    }

    Node *next = (Node*) malloc(sizeof(Node));
    next->data = val;
    next->next = NULL;
    i->next = next;

    return init;
}

Node* min(Node* init) {
    Node *min = init;
    for (Node *i=init; i != NULL; i=i->next) {
        if (i->data < min->data)
            min = i;
    }
    return min;
}

Node* insert(Node *init, int n, int x) {
    // insert x after n nodes on init
    int count = 1;
    Node *anterior = NULL;
    Node *i = init;

    while (i != NULL && count!=n) {
        anterior = i;
        i = i->next;
        count++;
    }

    Node *next = (Node*) malloc(sizeof(Node));
    next->data = x;

    if (i == NULL) {
        next->next = anterior->next;
        anterior->next = next;
    } else {
        next->next = i->next;
        i->next = next;
    }
    return init;
}

int main() {
    Node* list = initialize();
    list = push(list, 1);
    list = push(list, 42);
    list = push(list, 3);
    list = push(list, 10);
    list = push(list, 15);
    list = push(list, 24);
    list = push(list, 32);
    list = push(list, 80);
    Node *search = searchByValue(list, 42);
    printList(search);

    printList(list);

    list = removeByValue(list, 80);
    printList(list);

    list = removeByValue(list, 3);
    printList(list);

    list = insertEnd(list, 100);
    printList(list);

    Node *lower = min(list);
    printList(lower);

    list = insert(list, 2, 500);
    printList(list);

    return 0;
}