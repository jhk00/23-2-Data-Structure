#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int element;
typedef struct DlistNode {
	element item;
	struct DlistNode* llink;
	struct DlistNode* rlink;
} DlistNode;

typedef struct DequeType {
	DlistNode* head;
	DlistNode* tail;
} DequeType;


void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(DequeType* dq) {
	dq->head = dq->tail = NULL;
}

DlistNode* create_node(DlistNode* llink, element item, DlistNode* rlink) {
	DlistNode* new_node = (DlistNode*)malloc(sizeof(DlistNode));
	if (new_node == NULL) { error("memory allocation error!"); }
	else {
		new_node->llink = llink;
		new_node->rlink = rlink;
		new_node->item = item;
	}
	return new_node;
}

int is_empty(DequeType* dq) {
	if (dq->head == NULL) { return TRUE; }
	else return FALSE;
}

/*
void add_rear(element item, DequeType* dq) {
	DlistNode* new_node = create_node(dq->tail, item, NULL);
	//new_node->item = item;
	new_node->llink = dq->tail;
	dq->tail = new_node;
	if (new_node->llink == NULL) dq->head = new_node;
}*/

void add_rear(DequeType* dq, element item) {
	DlistNode* new_node = create_node(dq->tail, item, NULL);
	if (is_empty(dq)) {
		dq->head = new_node;
	}
	else {
		dq->tail->rlink = new_node;
	}
	dq->tail = new_node;
}

/*
void add_front(element item, DequeType* dq) {
	DlistNode* new_node = create_node(NULL, item, dq->head);
	// new_node->item = item; 두번 정의됨
	new_node->rlink = dq->head;
	dq->head = new_node;
	if (new_node->rlink == NULL)
		dq->tail = new_node;
}
*/
// add algorithm : 
// 1. create newnode 
// 2. is_empty로 tail, head 적절한곳에 할당 -> 이게 포인트. 이걸 자꾸 놓침
// 3. head와 tail의 llink, rlink 적절한 곳에 할당
// 4. head와 tail에 new_node 할당 
// 5. head와 tail에 new_node 할당
void add_front(DequeType* dq, element item) {
	DlistNode* new_node = create_node(NULL, item, dq->head);
	if (is_empty(dq)) {
		dq->tail = new_node;
		// new_node->rlink = NULL; 이미 is_empty 조건에 포함되어 있는 식임
	}
	else {
		dq->head->llink = new_node;
	}
	dq->head = new_node;
}

int delete_front(DequeType* dq) {
	DlistNode* remove = dq->head;
	element item;
	if (is_empty(dq)) { error("deque is empty!"); }

	else {
		item = remove->item;
		dq->head = remove->rlink;
		free(remove);
		if (dq->head == NULL) 
			dq->tail = NULL; // dq->tail == NULL; 엄청난 실수 : 비교연산자와 대입연산자 디버깅할때 꼭 체크
		else 
			dq->head->llink = NULL; //dq->head->llink == NULL; // 위와동일 
		return item;
	}

}

int delete_rear(DequeType* dq) {
	DlistNode* remove = dq->tail;
	element item;
	if (is_empty(dq)) { error("deque is empty!"); }
	else {
		item = remove->item;
		dq->tail = remove->llink;
		free(remove);
		if (dq->tail == NULL) 
			dq->head = NULL;// dq->head == NULL;
		else 
			dq->tail->rlink = NULL; // dq->tail->rlink == NULL;
		return item;
	}
}

void display(DequeType dq) {
	DlistNode* temp = dq.head;
	while (temp != NULL) {
		printf("%d  ", temp->item);
		temp = temp->rlink;
	}
	printf("\n");
}


int main(void) {

	DequeType dq;

	init(&dq);

	add_front(&dq, 10);
	add_front(&dq, 20);
	add_front(&dq, 30);


	display(dq);


	printf("%d\n", delete_front(&dq));
	printf("%d\n", delete_rear(&dq));


	display(dq);


	return 0;
}
