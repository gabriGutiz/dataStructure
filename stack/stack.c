#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct Stack {
    int top;
    int stack[MAX];
} Stack;

void initializeStack(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return (s->top < 0);
}

bool isFull(Stack *s) {
    return !(p->top < MAX-1);
}

void push(Stack *s, int data) {
    
    if (!isFull(s)) {
        s->top++;
        s->stack[s->top] = data;
    }
    else
        printf("Full Stack!\n");
}

int pop(Stack *s) {
    int unstacked = -1;

    if (isEmpty(s))
        printf("Empty Stack!\n");
    else {
        unstacked = s->stack[s->top];
        s->top = s->top - 1;
    }
}

int topData(Stack *s) {
    if (!isEmpty(s))
        return s->stack[s->top];
    else {
        printf("Empty stack!\n");
        return -1;
    }
}

void showStack(Stack *s) {
    int i;

    for (i = s->top; i >= 0; i--) {
        printf("Data %d posição %d\n", s->stack[i], i);
    }
}

int main() {
    return 0;
}
