#include <stdio.h>
#include <stdlib.h>

typedef int element; // 요소의 타입
typedef struct QueueNode { // 큐의 노드의 타입
    element item;
    QueueNode* link;
} QueueNode;

typedef struct { // 큐 ADT 구현
    QueueNode* front, *rear;
} QueueType;

void error(char *message) {
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init(QueueType *q) {
    q->front = q->rear = NULL;
}

int is_empty(QueueType* q) {
    return (q->front ==NULL);
}

void enqueue(QueueType* q, element item) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    if(temp == NULL) error("memory allocation error!");
    else {
        temp->item = item;
        temp->link = NULL;
    if(is_empty(q)) { q->front = temp; q->rear = temp;}
    else {
        q->rear->link = temp;
        q->rear = temp;
    }
    }
}


element dequeue(QueueType* q) {
    QueueNode* temp = q->front;
    element item;
    if(is_empty(q)) { error("queue is empty!"); }
    else {
        item = temp->item;
        q->front = q->front->link;
        if(q->front == NULL) { q->rear = NULL; }
        free(temp);
        return item;
    }
}

element peek(QueueType* q) {
    element item;
    if(is_empty(q)) { error("queue is empty!");}
    else {
        item = q->front->item;
        return item;
    }
}

void PrintQueues(QueueType q) {
    QueueNode* temp = q.front;
    while(temp != NULL) {
        printf("%d ", temp->item);
        temp = temp->link;
    }
    printf("\n");
}

int main(void)
{
    QueueType q;
    init(&q);

    enqueue(&q,1)
    enqueue(&q,2)
    enqueue(&q,3)

    PrintQueues(q);

    dequeue("dequeue() = %d\n",dequeue(&q));
    dequeue("dequeue() = %d\n",dequeue(&q));
    dequeue("dequeue() = %d\n",dequeue(&q));

    return 0;
}
