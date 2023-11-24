#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int element;        // 요소의 타입
typedef struct DlistNode { // 노드의 타입
    struct DlistNode* llink;
    struct DlistNode* rlink;
    element item;
} DlistNode;

typedef struct DequeType { // 덱의 타입
    DlistNode* tail; 
    DlistNode* head;
} DequeType;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(DequeType *dq) {
    dq->head = dq->tail = NULL;
}

// DlistNode create_node(DequeType *dq, DlistNode* llink, DlistNode* rlink, element item) {
    DlistNode* create_node(DlistNode* llink, element item, DlistNode* rlink ) { 
        // new_node를 포인터형 구조체로 선언할꺼니 함수형도 포인터로 받아주기
    DlistNode* new_node = (DlistNode*)malloc(sizeof(DlistNode));
    if(new_node == NULL) error("memory allocation error!");
    else {
        new_node -> llink = llink;
        new_node -> rlink = rlink;
        new_node -> item = item;
    }
    return new_node;
}
int is_empty(DequeType *dq) {
    if(dq->head == NULL) return TRUE;
    else return FALSE;
}

void add_rear (DequeType *dq, element item) {
    DlistNode* new_node = create_node(dq->tail,item,NULL);
    if(is_empty(dq)) {
        dq->head = new_node;
    }
    else {
        dq->tail->rlink = new_node;
    }
        dq->tail = new_node;
}

void add_front (DequeType *dq, element item) {
    DlistNode* new_node = create_node(NULL,item,dq->head);
    if(is_empty(dq)) {
        dq->tail = new_node;
       // new_node->rlink = NULL; 이미 is_empty 조건에 포함되어 있는 식임
    }
    else {
        dq->head->llink = new_node;
    }
    dq->head = new_node;
}

element delete_front(DequeType *dq) {
    element item;
    DlistNode* removed_node;
    if(is_empty(dq)) { error("Deque is empty"); }
    else {
        item = dq->head->item;
        removed_node = dq->head;
        dq->head = dq->head->rlink;
        free(removed_node);
        if(dq->head == NULL) dq->tail = NULL;
        else dq->head->llink = NULL; // 이걸 해줘야 함
    }
    return item;
    
}

element delete_rear(DequeType *dq) {
    element item;
    DlistNode* removed_node;
    if(is_empty(dq)) { error("Deque is empty"); }
    else {
        removed_node = dq->tail;
        item = removed_node->item;
        dq->tail = dq->tail->llink;
        free(removed_node);
        if(dq->tail == NULL) dq->head = NULL;
        else dq->tail->rlink = NULL;
    }
    return item;
}

void display(DequeType* dq) {
    DlistNode* p;
    printf("( ");
    for(p = dq->head; p != NULL; p = p->rlink)
    printf("%d ", p->item);
    printf(")\n");
}

int main(void) {
    DequeType dq;
    init(&dq);

    add_front(&dq,10);
    add_front(&dq,20);     
    add_rear(&dq,30);
    display(&dq); // deque를 display

printf("%d\n", delete_front(&dq) );
printf("%d\n", delete_rear(&dq) );
    display(&dq);
// front에서 dequeue
return 0;
}