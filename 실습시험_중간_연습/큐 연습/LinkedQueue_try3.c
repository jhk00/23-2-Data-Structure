#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode {
    element item;
    struct QueueNode* link;
}QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
}QueueType;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(QueueType* q) {
    q->front = q->rear = NULL;
}

int is_empty(QueueType* q) {
    return (q->front == NULL);
}

void enqueue(QueueType* q, element item) {
    QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
    if (new_node == NULL) { error("memory allocation error!"); }
    else {
        new_node->item = item;
        if (is_empty(q)) { q->front = new_node; }
        else {
            q->rear->link = new_node;
        }
        new_node->link = NULL;
        q->rear = new_node;
    }
}

int dequeue(QueueType* q) {
    QueueNode* remove = q->front;
    element item;
    if (is_empty(q)) { error("queue is empty!"); }
    else {
        item = remove->item;
        q->front = remove->link;
        free(remove);
        if (q->front == NULL) q->rear == NULL;
        return item;
    }
}

int peek(QueueType* q) {
    if (is_empty(q)) { error("queue is empty!"); }
    else {
        return q->front->item;
    }
}

void PrintQueues(QueueType q) {
    QueueNode* temp = q.front;
    while (temp != NULL) {
        printf("%d ", temp->item);
        temp = temp->link;
    }
    printf("\n");
}

int main(void) {
    QueueType q;
    init(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    PrintQueues(q);

    printf("dequeue() = %d\n", dequeue(&q));
    printf("dequeue() = %d\n", dequeue(&q));
    printf("dequeue() = %d\n", dequeue(&q));
}

// is_full(&q), is_empty(&q) 안하는 실수 주의하기기


