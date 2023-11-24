#include <stdio.h>
#include <stdlib.h>

typedef int element; // 요소의 타입
typedef struct QueueNode { // 큐의 노드의 타입
    element item; 
    struct QueueNode* link;        
} QueueNode;

typedef struct { // 큐 ADT 구현
    QueueNode* front, *rear;
} QueueType;

// 오류 함수
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 초기화 함수
void init(QueueType* q) {
    q->front = q->rear = NULL;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q) {
    return (q->front == NULL);
}

/*
// 포화 상태 검출 함수
int is_full(QueueType* q) {
    return 0;
}  굳이 구현하지 않아도 됨!
*/


// 삽입 함수
void enqueue(QueueType* q, element item) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    if( temp == NULL) error("memory allocation error");
    else {
        temp->item = item; // 데이터 저장
        temp->link = NULL; // 링크 필드를 NULL
        if(is_empty(q)) { //큐가 공백이면
            q->front = temp;
            q->rear = temp;
        }
        else { // 큐가 공백이 아니면
            //q->front->link = temp; 이렇게 하면 안되는게 내가 큐에 두칸밖에 없는 그림보고 코드 짜서 그럼.
            // rear의 링크에 연결해야지 올바름. 왜냐면 데이터의 삽입은 rear에서 이루어지니.
            q->rear->link = temp;
            q->rear = temp; 
        }
    }
}
    // 삭제 함수
    element dequeue(QueueType* q) {
        QueueNode* temp = q->front;
        element item;
        if(is_empty(q)) // 공백상태
        error("Queue is empty");
        else {
            item = temp->item; // 데이터를 꺼낸다.
            // item = temp->item; 과 동일
            //front가 다음노드를 가르키도록 한다.
            q->front = q->front->link;

            
        
        if         // (q->front->link == NULL )  큐에 하나만 있을때
            (q->front == NULL) {
                q->rear = NULL;
            free(temp); // 동적 메모리 해제

            return item; // 데이터 반환
        }
    }

// peek 함수 -> front의 item 가져오는거
element peek(QueueType* q) {
    element item;
    if(is_empty(q)) error("Queue is empty");
    else {
        item = q->front->item;
        return item;
    }
}

void PrintQueues(QueueType q) {
    QueueNode* temp = q.front;

    printf("printing all queue items: ");
    while(temp != NULL) {
        printf("%d", temp->item);
        temp = temp->link;
    }
    printf("\n");
}

int main(void)
{
    QueueType q;
    init(&q);

    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);

    PrintQueues(q);

    printf("dequeue() = %d\n", dequeue(&q));
    printf("dequeue() = %d\n", dequeue(&q));
    printf("dequeue() = %d\n", dequeue(&q));
}


