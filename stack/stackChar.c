#include <stdio.h>
#include <stdbool.h>

#define MAX 1000000

typedef struct Stack {
    int top;
    char stack[MAX];
} Stack;

void initializeStack(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return (s->top < 0);
}

bool isFull(Stack *s) {
    return !(s->top < MAX-1);
}

void push(Stack *s, char data) {
    
    if (!isFull(s)) {
        s->top++;
        s->stack[s->top] = data;
    }
    else
        printf("Full Stack!\n");
}

char pop(Stack *s) {
    char unstacked = '_';

    if (isEmpty(s))
        printf("Empty Stack!\n");
    else {
        unstacked = s->stack[s->top];
        s->top = s->top - 1;
    }
    return unstacked;
}

char topData(Stack *s) {
    if (!isEmpty(s))
        return s->stack[s->top];
    else {
        printf("Empty stack!\n");
        return '_';
    }
}

void showStack(Stack *s) {
    int i;

    for (i = s->top; i >= 0; i--) {
        printf("Data %c position %d\n", s->stack[i], i);
    }
}


// Exercise: verify if all parenthesis on the passed string was closed
bool isCorrect(char equation[], int size) {
    // verify if all parenthesis on equation were properly closed
    Stack parentheses;
    initializeStack(&parentheses);

    for (int i = 0; i < size; i++) {
        if (equation[i] == '(')
            push(&parentheses, '(');
        else if (equation[i] == ')') {
            if (isEmpty(&parentheses))
                return false;
            else
                pop(&parentheses);
        }
    }
    return (isEmpty(&parentheses));
}

int main() {
    int strSize;

    printf("Equation size: ");
    scanf("%d", &strSize);

    if (strSize > MAX) {
        printf("Equation size %d invalid, must be smaller thane %d!", strSize, MAX);
        return 0;
    }

    char equation[strSize];
    printf("\nEquation: ");
    scanf("%s", &equation);

    if (isCorrect(equation, strSize))
        printf("\nCorrect expression!\n");
    else
        printf("\nIncorrect expression!\n");

    return 0;
}