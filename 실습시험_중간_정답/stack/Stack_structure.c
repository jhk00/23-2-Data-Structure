#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;

typedef struct {
    element stack[MAX_STACK_SIZE];
    int top; // top을 배열의 값이라고 생각하면 안되고 이건 인덱스임! top 인덱스
}StackType;

//초기화 함수
void init(StackType* s) {
    s->top = -1;
}

//공백 상태 검출 함수
int is_empty(StackType *s) {
    return (s->top == -1);
}


//포화 상태 검출 함수
int is_full(StackType *s) {
    // return (s->stack[MAX_STACK_SIZE] == s->top); top을 인덱스로 생각해야함.
    return (s->top == (MAX_STACK_SIZE-1));
}


//삽입 함수
void push(StackType* s, element item) {
    if(is_full(s)) {
        fprintf(stderr, "Stack is full\n");
        exit(1);
    }
    else 
       // s->stack[top++] = item; 증가 시킨 top인덱스에 push해줘야함
       // 그리고 top이 구조체 안에 선언되어 있기 때문에 구조체를 들어가서 가져와야함
       s->stack[++(s->top)] = item;
}

//삭제 함수
element pop(StackType* s) {
    if(is_empty(s)) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    else
    //return s->stack[top--];
    return s->stack[(s->top)--]; // 삭제하기전 top값을 리턴해주고 내려주기
}
// 피크 함수
element peek(StackType *s) {
    if(is_empty(s)) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
        //return s->stack[top];
        return s->stack[s->top];
}

int main() {
    StackType s;
    init(&s); // 스택을 초기화하세요

    //스택에 1,2,3을 추가하세요
    push(&s,1);
    push(&s,2);
    push(&s,3);

    // 스택에서 1,2,3을 삭제하고 스택이 비었는지 확인하세요.
    printf("%d\n",pop(&s));
    printf("%d\n",pop(&s));
    printf("%d\n",pop(&s));
    //printf("%d\n",pop(&s));
    printf("%d\n",is_empty(&s));

    return 0;
}