#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode {
    element item;
    struct StackNode* link;
} StackNode;

typedef struct {
    StackNode* top;
}LinkedStackType;

void init(LinkedStackType* s) {
    s->top = NULL;
}

int is_empty(LinkedStackType* s) {
    return (s->top == NULL);
}

void push(LinkedStackType* s, element item) {
    StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
    if (new_node == NULL) { fprintf(stderr, "memory allocation error!"); exit(1); }
    else {
        new_node->item = item;
        new_node->link = s->top;
        s->top = new_node;
    }
}

int pop(LinkedStackType* s) {
    StackNode* remove;
    element item;
    if (is_empty(s)) { fprintf(stderr, "Stack is empty!"); exit(1); }
    else {
        remove = s->top;
        item = remove->item;
        s->top = remove->link;
        free(remove);
        return item;
    }
}

void PrintStacks(LinkedStackType s) {
    StackNode* temp = s.top;
    while (temp != NULL) {
        printf("%d ", temp->item);
        temp = temp->link;
    }
    printf("\n");
}

int peek(LinkedStackType *s) {
    if(is_empty()) { fprintf(stderr, "Stack is empty"); exit(1);}
    else {
        return s->top->item;
    }
}

int main(void) {
    LinkedStackType s;

    init(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    PrintStacks(s);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", is_empty(&s));
}