#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int element; // 요소의 타입
typedef struct QueueNode { // 큐의 노드의 타입 
    element item;
    //QueueNode* link;
    struct QueueNode* link;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} QueueType;

// 오류 함수
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    // exit(1); 빼먹음
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

// 삽입 함수
void enqueue(QueueType* q, element item) {
    QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
    // malloc은 바로 생성됬는지 체크부터 !
    if (new_node == NULL) { error("memory allocation error!"); }
    if (is_empty(q)) {
        //new_node-> item = item; 
        q->front = new_node;
        q->rear = new_node;
    }
    else {
        q->rear->link = new_node;
        q->rear = new_node;
        // else문에 new_node에 item 넣는거 깜박함
        // new_node에 item 넣는것과 new_node link가 null이 되는건
        // 공통적인 거임. 그런건 밑에 빼거나 위에 놔서 한번에 처리
    }
    new_node->link = NULL;
    new_node->item = item;
}

int dequeue(QueueType* q) {
    element data;
   // QueueNode* remove_node = (QueueNode*)malloc(sizeof(QueueNode));
   // 이것도 맞는거 같긴 한데 안전빵으로 deque에선 그냥 어차피
   // 다른 노드들이 다 동적할당 되어있으니까
   // QueueNode* temp = q->front로 안전하게 가자
    if (is_empty(q)) { error("queue is empty!\n"); }

    else {
        data = q->front->item;
        remove_node = q->front;
        q->front = q->front->link;
        // if (q->front->link == NULL) q->rear = NULL; 
        // 이렇게 하면 오류가 떴던게 q->front가 NULL이 되면 NULL->link가 되어
        // dequeue과정에서 오류가 발생함. 그래서 안됐던거
         if (q->front == NULL) q->rear = NULL;
        free(remove_node);
        //return문 이전에 동적 할당 해제
        return data;
    }
    //free(remove_node); 여기에 free를 하면 return data하고 함수가
    // 끝나니 안됨. return 위에 둬야함
}

int peek(QueueType* q, element item) {
    if (is_empty(q)) error("queue is empty!\n");
    else {
        return q->front->item;
    }
}

void PrintQueues(QueueType* q) { 
    /* for (q->front->link; q->link == NULL; q = q->link) {
         printf("%d\n", q->item);
     } 왜 안되는지는 정확히 모르겠지만 일단 pass 앞에 printstack이나
     이 문제나 print가 있는 거는 while로 제어함
     */
    printf("printing all queue datas..\n");
        while (/*!q->front == NULL*/ q->front != NULL) {
            printf("%d ", q->front->item);
            q->front = q->front->link;
        }
}
/*
void PrintQueues(QueueType q) {
    QueueNode* temp = q.front;
    while(temp != NULL) {
        printf("%d",temp->item);
        temp = temp->link;
    }
}
*/

int main(void) {
    QueueType q;
    init(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    PrintQueues(&q);

    printf("dequeue()=%d\n", dequeue(&q));
    printf("dequeue()=%d\n", dequeue(&q));
    printf("dequeue()=%d\n", dequeue(&q));
}