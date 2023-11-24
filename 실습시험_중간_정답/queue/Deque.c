#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int element;        // 요소의 타입
typedef struct DListNode {  // 노드의 타입
    element data;
    struct DlistNode* llink;
    struct DlistNode* rlink;
} DlistNode;

typedef struct DequeType { // 덱의 타입
    DlistNode* head;
    DlistNode* tail;
} DequeType;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(DequeType* dq) {
    dq->head = dq -> tail = NULL;
}

DlistNode* create_node(DlistNode* llink, element item, DlistNode* rlink) {
    DlistNode* new_node = (DlistNode*)malloc(sizeof(DlistNode));
    if (new_node == NULL) error("Memory allocation error");
    new_node -> llink = llink;
    new_node -> data = item;
    new_node -> rlink = rlink;
    
    return new_node;
}

int is_empty(DequeType* dq) {
    if(dq->head == NULL) return TRUE;
    else return FALSE;
}

void add_rear(DequeType* dq, element item) {
    DlistNode* new_node = create_node(dq->tail, item, NULL);

    if(is_empty(dq))
    dq->head = new_node;

    else
    dq->tail->rlink = new_node;
    dq->tail = new_node;
}

void add_front(DequeType* dq, element item) {
    DlistNode* new_node = create_node(NULL, item, dq->head);

    if(is_empty(dq)) 
    dq->tail = new_node;
    
    else
    dq->head->llink = new_node;
    dq->head = new_node;
}

element delete_front(DequeType *dq) {
    element item;
    DlistNode* removed_node;

    if(is_empty(dq)) error("Deque is empty");
    else {
        removed_node = dq->head;
        item = removed_node->data;
        dq->head = dq->head->rlink;
        free(removed_node);
        // 덱에서 삭제 한 후 노드 주소 조정
        if(dq->head == NULL) dq->tail = NULL; // 다 비었을때
        else dq->head->llink = NULL; 
        // 이걸 안해주면 free한 노드가 그대로 헤드노드가 됨
        // free해주면 할당된 메모리가 반납되는 거지 NULL이 되는게 아님
        // 그러므로 이렇게 llink를 NULL로 해줘야함
    }
    return item;
}

element delete_rear (DequeType* dq) {
    element item;
    DlistNode* removed_node;

    if(is_empty(dq)) error("Deque is empty");
    else {
        removed_node = dq->tail;
        item = removed_node->data;
        dq->tail = dq->tail->llink;
        free(removed_node); // 모든 노드가 create 노드에 의해 동적할당으로 생성되었으니 free로 터트려주는게 맞음

        if(dq->tail == NULL) dq->head = NULL;
        else dq->tail->rlink = NULL;
    }
    return item;
}

void display(DequeType* dq) {
    DlistNode* p;
    printf("( ");
    for(p = dq->head; p != NULL; p = p->rlink)
    printf("%d ", p->data);
    printf(")\n");
}

int main(void) {
    DequeType deque;
    init(&deque); // deque 초기화

    add_front(&deque, 10); // front에 10 enqueue
    add_front(&deque, 20); // front에 20 enqueue
    add_rear(&deque, 30); // rear에 30 enqueue
    display(&deque); // deque를 display

    printf("%d\n", delete_front(&deque));
    //front에서 deque
     printf("%d\n", delete_rear(&deque));
    //rear에서 deque

    display(&deque);
    return 0;
}