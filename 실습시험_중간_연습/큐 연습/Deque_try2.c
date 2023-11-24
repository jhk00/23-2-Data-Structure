#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int element;            // 요소의 타입
typedef struct DlistNode {      // 노드의 타입
   // element item;
   element data;
   struct DlistNode *llink;
   struct DlistNode *rlink;
} DlistNode;

typedef struct DequeType {
   DlistNode *head;
   DlistNode *tail;
} DequeType;

void error(char* message) {
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init(DequeType *dq) {
    // dq->llink = dq->rlink = NULL;
    dq->head = dq->tail = NULL;
}

DlistNode* create_node (DlistNode *llink, element item, DlistNode *rlink) {
    DlistNode* new_node = (DlistNode*)malloc(sizeof(DlistNode));
    if(new_node == NULL) { error("memory allocation error!"); }
    else {
        new_node -> llink = llink;
        new_node -> rlink = rlink;
        new_node -> data = item;
    }
    return new_node;
}

int is_empty(DequeType *dq) {
    if(dq->head==NULL) return TRUE;
    return FALSE;
}

void add_front(DequeType *dq, element item){ //DequeType *rlink) {
    DlistNode* new_node = create_node(NULL,item,dq->head);//rlink);
    if(is_empty(dq)) {  dq->tail = new_node; } 
    //dq->head->rlink = NULL; 이미 is_empty 조건에 head==NULL일때 조건 포함}
    // dq->head는 밑에 정의되어있음
    else {
        dq->head->llink = new_node;
        //new_node->rlink = dq->head; 이미 create_node 조건식에 포함
    }
    dq->head = new_node;
}

void add_rear(DequeType *dq, element item) { //DequeType *llink ) {
    DlistNode* new_node = create_node(dq->tail,item,NULL);
    if(is_empty(dq)) { dq->head = new_node; }
    //new_node->llink = NULL;} 좀잇다
    else {
        dq->tail->rlink = new_node;
        // new_node->llink = dq->rear; 이미 new_node에서 정의된 것
    }
    dq->tail = new_node;
}

int delete_front(DequeType *dq) {
    DlistNode* remove_node = dq->head;
    element item;
    if(is_empty(dq)) { error("deque is empty!"); }
    else {
       /* item = remove_node->item;
        if(remove_node->rlink == NULL) 
        { dq->head == NULL; dq->rear == NULL;}
        else {
            remove_node->rlink = dq->head;
            remove_node->rlink->llink = NULL;
        }
        free(remove_node);
        return item;
        }   완전 틀림
        delete 알고리즘의 순서 정립
        
        1. 삭제할 데이터를 저장하고
        2. 헤드노드를 바꾼다
        3. remove 노드의 메모리를 해제한다. 
        (remove 노드의 llink, rlink를 굳이 NULL로 만들어주는
        작업을 할 필요는 없음. 그냥 헤드노드만 옮기고 바로 free
        시켜주면 됨)
        4. remove노드가 삭제된 후 케이스를 나눈다
        (1) head node가 NULL일때 : ( remove후 empty일때) dq->tail = NULL;
        (2) 그렇지 않을때 : dq->head->llink = NULL; 

        중요한 point -> remove 는 free 시킬거니 
        굳이 llink, rlink를 따로 신경 쓸 필요 없다.
        얘는 그냥 헤드포인터 옮기는 용도로만 쓰고 
        용도를 다 했으면 주소관리는 안해줘도 됨

        */
       item = dq->head->data;
       dq->head = dq->head->rlink;
       free(remove_node);
       if(dq->head == NULL)  dq->tail == NULL;
       else dq->head->llink == NULL;

        
        return item;
    }
}

int delete_rear(DequeType *dq) {
    DlistNode* remove_node;
    element item;
    if(is_empty(dq)) { error("deque is empty!"); }
    else {
        item = dq->tail->data;
        remove_node = dq->tail;
        dq->tail = dq->tail->llink;
        free(remove_node);
        if(dq->tail == NULL) dq->head == NULL;
        else { dq->tail->rlink == NULL; }
        }
        
        return item;
    }





void display(DequeType dq) {
    DlistNode *temp = dq.head;
    while(dq.head != NULL) {
        printf("%d ", temp->data);
        temp = temp->rlink;
    }
}


int main(void) {
    DequeType dq;
    init(&dq);

    add_front(&dq,10);
    add_front(&dq,20);
    add_front(&dq,30);
    display(dq);
    printf("%d\n",delete_front(&dq));
    printf("%d\n",delete_rear(&dq));
    display(dq);

}