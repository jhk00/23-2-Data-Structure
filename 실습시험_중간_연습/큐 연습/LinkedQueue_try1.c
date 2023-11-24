#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int element; // 요소의 타입
typedef sturct QueueNode { // 큐의 노드의 타입
    element item;
    struct QueueNode *link; // 큐 노드의 주소 저장
} QueueNode;

typedef struct { // 큐 ADT 구현
    //QueueNode *top, 
    QueueNode *rear; 
    QueueNode *front;
} QueueType;

// 오류 함수
void error(char* message) {
    //fprintf(stder,message);
    fprintf(stderr,"%s\n",message);
    exit(1);
}

// 초기화 함수
void init(QueueType* q) {
    q->front = q->rear = NULL;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q) {
    if(q->front==NULL);
}

// 삽입 함수
void enqueue(QueueType* q, element item) {
    //QueueNode* temp = (QueueNode*)malloc(sizeof(temp));
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    if(temp == NULL) error("Memory allocation error!");  // malloc 은 생성검사 해주기
    else {
        temp->item = item;
        temp->link = NULL;
        if(q->front == NULL) {
            q->front = temp;
            q->rear = temp;
        }
        else {
           // q->front->link = temp; 똑같은 실수. 두칸이 있는 큐를 자꾸 생각하지 말기 3칸의 링크 생각하기
           q->rear->link = temp;
            // temp = q->rear; 그림 그려보면 반대가 맞다는걸 단박에 알 수 있음
            q->rear = temp;
        }
    }
}

// 삭제 함수
    element dequeue(QueueType* q) {
        QueueNode* temp = q->front;
        element item;

    if(q->front ==NULL) error("Queue is empty!");
    else {
        item = temp->item;
        q->front = q->front->link;
        if(q->front->link == NULL)
        //q->front = NULL; front는 이미 위에서 한칸 옮겨줌
        q->rear = NULL;
        free(temp);
        return item;
    }
}

// peek 함수 -> front에 있는 값 출력

element peek (QueueType* q) {
    element item;
    if(is_empty(q)) error("Queue is empty!");
    else {
        item = q->front->item;
        return item;
    }
}

void PrintQueues (QueueType q) {
    //QueueNode *temp;
    QueueNode *temp = q.front;
    printf("Printing all Queue items : ")
    while(!temp == NULL) {
        printf("%d",temp->item);
        temp = temp->link;
    }
    printf("\n");
}

int main(void) {
    QueueType q;
    init(&q);

    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,2);

    PrintQueues(q);

    printf("dequeue() = %d\n", dequeue(&q));
    printf("dequeue() = %d\n", dequeue(&q));
    printf("dequeue() = %d\n", dequeue(&q));
}
