#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int element;
typedef struct DlistNode {
    element data;
    struct DlistNode* llink;
    struct DlistNode* rlink;
} DlistNode;

typedef struct DequeType {
    DlistNode* head;
    DlistNode* tail;
} DequeType;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(DequeType* dq) {
    dq->head = dq->tail = NULL;
}

DlistNode* create_node(DlistNode* llink, element item, DlistNode* rlink) {
    DlistNode* new_node = (DlistNode*)malloc(sizeof(DlistNode));
    if(new_node = NULL)
    error("Memory allocation error");

    new_node->llink = llink;
    new_node->data = item;
    new_node->rlink = rlink;

    return new_node;
}

int is_empty(DequeType* dq) {
    if (dq->head == NULL)
        return TRUE;
    else 
        return FALSE;
}

void add_rear(DequeType *dq, element item) {
    DlistNode* new_node = create_node(dq->tail, item, NULL);

    if(is_empty(dq))
    dq->head = new_node;
    else
    dq->tail->rlink = new_node;
    dq->tail=new_node;
}