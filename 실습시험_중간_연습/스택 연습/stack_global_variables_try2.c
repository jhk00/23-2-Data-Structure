#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
int top = -1
element stack[MAX_STACK_SIZE];

int is_empty() {
    return (top == -1);
}

int is_full() {
    return (top == MAX_STACK_SIZE -1);
}

void push(element item) {
    if(is_full()) { fprintf(stderr,"Stack is full!"); return; }
    else {
        stack[++top] = item;
    }
}

int pop() {
    if(is_empty()) { fprintf(stderr, "Stack is empty!"); exit(1); }
    else {
        return stack[top--];
    }
}

int peek() {
    if(is_empty()) {fprintf(stderr, "Stack is empty!"); exit(1);}
    else {
        return stack[top];
    }
}

int main(void) {
    push(1);
    push(2);
    push(3);

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());

    printf("%d\n", is_empty());
}