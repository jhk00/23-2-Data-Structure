#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
typedef int element;

typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int rear;
    int front;
}QueueType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(QueueType *q) {
    q->rear = q->front = 0;
}

int is_empty(QueueType *q) {
    return (q->rear == q->front);
}

int is_full(QueueType *q) {
    return (q->front == (q->rear+1) % MAX_QUEUE_SIZE);
}

void enqueue(QueueType *q, element item) {
    if(is_full()) { error("queue is full!");}
    else {
        q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
        // 0으로 시작하니 마찬가지로 1더해주고 인큐(1부터 채워짐)
        // -> 그다음 것도 1 더해주고 인큐
        // 이런식으로 채워지는거
        q->queue[q->rear] = item;
    }
}

int dequeue(QueueType *q) {
    if(is_empty()) { error("queue is empty!");}
    else {
        q->front = (q->front+1) % MAX_QUEUE_SIZE; 
        // front = 0 으로 시작이니 +1을 더해줘야 입력된 곳부터 디큐 시작
        // 그리고 1씩 더해가면서 디큐
        return q->queue[q->front];
    }
}

int peek(QueueType *q) {
    if(is_empty()) { error("queue is empty!");}
    else {
        return q->queue[q->rear];
    }
}

int main(void) {
    QueueType q;
    init(&q);

    printf("front = %d rear = %d\n", q.front,q.rear);

    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);

    printf("dequeue() = %d\n", dequeue(&q));
    printf("dequeue() = %d\n", dequeue(&q));
    printf("dequeue() = %d\n", dequeue(&q));

    printf("front = %d rear = %d\n", q.front, q.rear);
}