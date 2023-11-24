#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
typedef int element;

typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;
// 스택, 큐가 링크드 리스트가 아니면 애초에 다 배열을 기저로 하는 것.
// 그리고 링크드 스택,큐가 아니니 링크필드를 저장할 필요가 없음 -> 포인터 선언도 불필요


void error(char *message) {
    fprintf(stderr,"%s\n",message);
    exit(1);
}

// 초기화 함수
void init(QueueType *q) {
    // q->front = q->rear; int type이라 NULL은 안되니 0으로 초기화 그리고 뭐 애초에 주소형도 아니라 NULL도 넣을수가 없음                                                
    q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q) {
return(q->front == q->rear); 
}

// 포화 상태 검출 함수
int is_full(QueueType* q) {
    //return (q->rear+1 % MAX_QUEUE_SIZE == q-> front);
    return ((q->rear+1) % MAX_QUEUE_SIZE == q-> front);
}

// 삽입 함수
void enqueue (QueueType* q, element item) {
    if(is_full(q))  error("Queue is full!");
    else {
        // q->queue[q->(rear+1 % MAX_QUEUE_SIZE)] = item; 이렇게 선언하면 절대 안됨
        q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
        q->queue[q->rear] = item;
        
    }    
}

// 삭제 함수
int dequeue(QueueType *q) {
    if(is_empty(q)) error("Queue is empty!");
    else {
        // element item = q->queue[q->front];
        // q->queue[q->(front+1%MAX_QUEUE_SIZE)];
        // return item;
        // q->front와 q->rear가 0으로 초기화 된다는 사실을 잊으면 안됨
        // 그래서 front에 1을 더해주고 나눠주는거
        q->front = (q->front+1) % MAX_QUEUE_SIZE;
        return q->queue[q->front];
    }
}

// 피크 함수
int peek(QueueType *q) {
    if(is_empty(q)) error("Queue is empty!");
    else {
        return q->queue[ (q->rear) % MAX_QUEUE_SIZE ];
    }
}

int main(void) {
    QueueType q;
    init(&q);

    printf("front = %d rear = %d\n", q.front, q.rear);

    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);

    printf("dequeue()=%d\n", dequeue(&q) ); // element 1를 enqueue
    printf("dequeue()=%d\n", dequeue(&q) ); // element 2를 enqueue
    printf("dequeue()=%d\n", dequeue(&q) ); // element 3을 enqueue

printf("front = %d rear = %d\n", q.front, q.rear);

}

