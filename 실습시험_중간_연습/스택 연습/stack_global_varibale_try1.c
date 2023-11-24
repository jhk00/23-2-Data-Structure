#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
int top = -1;
element stack[MAX_STACK_SIZE];

// 공백 상태 검출 함수

int is_empty() {
   // if(top == -1); return을 안해줌!! if도 빼야 함
   return (top == -1);
}

// 포화 상태 검출 함수

int is_full() {
    // if(top == (MAX_STACK_SIZE-1)); return을 안해줌!! if도 빼야함
    return (top == (MAX_STACK_SIZE-1));
}

// 삽입 함수
void push (element item) {
    if(is_full())  {
        //fprintf(stderr,"%s\n","Stack is full");
        fprintf(stderr,"Stack is full");
        //exit(1); 이걸 사용하지 말고
        return; // return 사용
    }
    else {
        //return stack[top++] = item;    -> 증가되기 전에 top에 item 할당 그 이후 top 증가
        stack[++top] = item;   // -> top을 먼저 증가시키고 거기에 item 할당
    }
}

// 삭제 함수
element pop () {
    if(is_empty())  {
        //fprintf(stderr,"%s\n","Stack is empty!");
        fprintf(stderr,"Stack is empty\n");
        exit(1);
    }

    else {
        return stack[top--];
    }
}

// 피크 함수
element peek () {
    if(is_empty())  {
        fprintf(stderr,"Stack is empty!\n");
        exit(1);
    }
    else {
        return stack[top];
    }
}

int main(void) {
    push(1);
    push(2);
    push(3);

    printf("%d\n", pop()); // 스택에서 1을 삭제하세요
    printf("%d\n", pop()); // 스택에서 2를 삭제하세요
    printf("%d\n", pop()); // 스택에서 3을 삭제하세요
    //스택이 비었는지 확인하세요
    printf("%d\n", is_empty());
    return 0;
}