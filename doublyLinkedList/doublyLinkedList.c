// 05/23/2023 class

#include <stdio.h>
#include <stdlib.h>

typedef struct TNode {
    int data;
    struct TNode* next;
    struct TNode* previous;
} Node;

Node* initialize(void) {
    return NULL;
}

Node* add_start(Node* l, int i) {
    Node* new = (Node*)malloc(sizeof(Node));
    
    new->data = i;
    new->next = l;

    if (l != NULL)
        l->previous = new;
    return new;
}

void printList(Node* l) {
    Node* s;
    for (s = l; s != NULL; s = s->next) {
        printf("%d ", s->data);
    }
    printf("\n");
}

int main() {
    Node* list;
    list = initialize();
    list = add_start(list, 42);
    list = add_start(list, 21);
    printList(list);

    return 0;
}
