#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct Queue {
    int size, start, end, total;
    int vector[MAX];
} Queue;

void initializeQueue(Queue *f) {
    f->start = 0;
    f->end = 0;
    f->total = 0;
    f->size = MAX;
}

bool isEmpty(Queue *f) {
    return (f->total == 0);
}

bool isFull(Queue *f) {
    return (f->total >= f->size);
}

void enQueue(Queue *f, int input) {
    if (!isFull(f)) {
        f->vector[f->end] = input;
        f->end++;
        f->total++;
        if (f->end >= f->size)
            f->end = 0;
        return;
    }
    printf("Queue is full!\n");
}

int deQueue(Queue *f) {
    int removed =  -1;

    if (isEmpty(f)) {
        printf("Queue is empty!\n");
    }
    else {
        removed = f->vector[f->start];
        f->start++;
        f->total--;
        if (f->start >= f->size) {
            f->start = 0;
        }
    }
    return removed;
}

void printStart(Queue *f) {
    printf("First element %d\n", f->vector[f->start]);
}

void showQueue(Queue *f) {
    if (isEmpty(f)) {
        printf("Queue is empty!\n");
        return;
    }
    for (int i = 0; i < f->total; i++) {
        printf("Data %d position %d\n", f->vector[i], i);
    }
}

int main() {
    Queue f;
    initializeQueue(&f);

    for (int i = 0; i < 5; i++) {
        int element;
        printf("Element %d: ", i+1);
        scanf("%d", &element);
        enQueue(&f, element);
    }

    printf("\n");

    showQueue(&f);
    return 0;
}