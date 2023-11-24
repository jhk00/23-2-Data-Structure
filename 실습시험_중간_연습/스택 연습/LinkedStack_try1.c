#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode {
    element item;
    struct StackNode* link;
} StackNode;

typedef struct {
    StackNode *top;
} LinkedStackType;

// 초기화 함수

void init (LinkedStackType *s) {
    s->top = NULL;
}

int is_empty(LinkedStackType *s) {
    return(s->top == NULL);
}

// 삽입 함수

void push (LinkedStackType *s, element item) {
    StackNode * new_node = (StackNode*)malloc(sizeof(StackNode)); 
    // malloc 해줬으니 생성검사 해줘야함
    if(new_node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        return;
    }
    else {
    /*

    if (is_empty(s)) {
        new_node->item = item;
        new_node->link = NULL;
        s->top = new_node;
    }
    else {
        new_node->item = item;
        new_node->link = s->top;
        s->top = new_node;       
    }
    이거도 맞긴 한데 링크드 스택에서 푸쉬는 굳이 empty case
    고려 안해줘도 됨. 왜냐면 이미 init에서 empty일떄 s->top
    인 case를 써놨기 때문에 그냥 밑에처럼 작성해도 똑같음( 답지코드 )
    */
    new_node->item = item;
    new_node->link = s->top;
    s->top = new_node;   
  

    }
}

// 삭제 함수

element pop (LinkedStackType *s) {
    // element popitem; 이거도 되긴 하는데 굳이 메모리 낭비 안하려면
    if(is_empty(s)) {
        fprintf(stderr,"Stack is empty!\n");
        exit(1);
    }
    else {
      /*  item = s->top->item;
        s->top = s->top->link;
        return item; 틀림 !!
        왜냐하면 이렇게 되면 pop된 노드의 메모리를 반납을 할 수가 없음
        새로운 temp 노드 선언해서 pop될 노드의 주소를 받고 그거를 free시켜줘야함
        */
       StackNode* temp = s->top;
       element popitem = temp->item;
       s->top = temp->link;
       free(temp);
       return popitem;

    }
}

int peek(LinkedStackType *s) {
    element item;
    if(is_empty(s)) {
        fprintf(stderr, "Stack is empty!\n");
        exit(1);
    }
    else {
        return s->top->item;
    }
}

int main(void) {
    LinkedStackType s;

    init(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", is_empty(&s));
}