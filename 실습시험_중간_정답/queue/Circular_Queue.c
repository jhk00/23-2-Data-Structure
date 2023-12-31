#include <stdio.h>
#include <stdlib.h>
        
#define MAX_QUEUE_SIZE 100
typedef int element;

typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

//
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//초기화 함수
void init(QueueType *q) {
        q->front = q->rear = 0; // int type이니
}

// 공백 상태 검출 함수
int is_empty(QueueType *q) {
    return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void enqueue(QueueType* q, element item) {
    if (is_full(q)) error("Queue is full");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}


// 삭제 함수
element dequeue(QueueType* q) {
    if(is_empty(q)) error("Queue is empty");
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

//피크 함수
element peek(QueueType *q) {
    if(is_empty(q)) error("Queue is empty");
    return q->queue[(q->rear) % MAX_QUEUE_SIZE];   
}

int main(void) {
    QueueType q;
    init(&q);

    printf("front=%d rear=%d\n", q.front, q.rear);

    enqueue(&q,1); // element 1을 enqueue
    enqueue(&q,2); // element 2을 enqueue
    enqueue(&q,3); // element 3을 enqueue

    printf("dequeue() = %d\n", dequeue(&q)); // dequeue
    printf("dequeue() = %d\n", dequeue(&q)); // dequeue
    printf("dequeue() = %d\n", dequeue(&q)); // dequeue

    printf("front=%d rear=%d\n",q.front, q.rear);
    return 0;
}
// visual studio에서 컴파일 하면 됨