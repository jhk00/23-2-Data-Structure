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
void init(QueueType* q) {
    q->front = q->rear = 0;
}

//공백 상태 검출 함수
int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

//포화 상태 검출 함수
int is_full(QueueType* q) {
   // return (q->(rear+1) % MAX_QUEUE_SIZE == 0)
   return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
   // 포화 상태의 정의가 front가 rear보다 한칸 앞에 있는거
}

//삽입 함수
void enqueue(QueueType* q, element item) {
    if (is_full(q)) error("Queue is full");
    //q->queue[q->rear] = q->queue[q->(rear+1)] % MAX_QUEUE_SIZE;
    // 자꾸 비슷한 실수하는데, front와 rear은 그냥 인덱스 넘버임.
    // 원형 큐에선 인덱스 넘버가지고 나눠서 비교하는 것
   q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
     // enqueue도 0으로 초기화 되었으니 1 증가시켜서 enqueue -> 1번 인덱스부터 값 입력됨
    q->queue[q->rear] = item;
    
}

//삭제 함수
element dequeue(QueueType* q) {
    if(is_empty(q)) error("Queue is empty");
    //q->queue[q->front] = q->queue[q->(front+1)] % MAX_QUEUE_SIZE;
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    return q->queue[q->front]; 
    // q->front의 초기값이 0으로 초기화 되었으니 위 식처럼 front에 +1을 해주고 리턴해야
    // enqueue의 순서에 맞게 리턴이 되는거 1번 인덱스부터 값이 입력됨
// 1번 인덱스부터 입력하고 빼내야 원형큐의 의도에 맞는거.
// 일부러 하나 크게 선언하고 0번인덱스는 % MAX_QUEUE_SIZE로 컨트롤 하는거임

//피크 함수
element peek(QueueType* q) {
    if(is_empty(q)) error("Queue is empty");
    // return q->queue[q->rear];
    return q->queue[(q->rear) % MAX_QUEUE_SIZE]; // 그냥 마지막에 위치에 있는 값 리턴해주는거임
    // 이거 물어보기
}

int main(void) {
    QueueType q;
    init(&q); // circular queue 초기화

    printf("front=%d rear=%d\n",q.front, q.rear);
    enqueue(&q,1); // element 1을 enqueue
    enqueue(&q,2); // element 2를 enqueue
    enqueue(&q,3); // element 3을 enqueue

    printf("dequeue()=%d\n",dequeue(&q)); // dequeue    
    printf("dequeue()=%d\n",dequeue(&q)); // dequeue
    printf("dequeue()=%d\n",dequeue(&q)); // dequeue

    printf("front=%d rear=%d\n",q.front,q.rear);  
}