#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

//공백 상태 검출 함수
int is_empty() {
    return (top == -1); // 괄호안에 있는 조건이 맞을시 true 리턴 (true = 1), 틀리면 false
}

//포화 상태 검출 함수
int is_full() {
    return (top == (MAX_STACK_SIZE-1)); // 배열 인덱스는 0부터 MAX-1
} // 스택이 최대일때 1 리턴, 그렇지 않으면 0 리턴

//삽입 함수
void push(element item) {
    if(is_full()) {
        fprintf(stderr, "Stack is full\n");
        return; 
        // 이 함수를 즉시 종료시키는 역할 
        // -> 요소를 추가하려고 시도하면 메시지를 출력하고 함수 실행 중지
        // 함수를 종료하라는 의미
    }
    else stack[++top] = item;
}

//삭제 함수
element pop() {
    if(is_empty()) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    else return stack[top--];
}
// 피크 함수
element peek() {
    if( is_empty()) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
        // 스택이 비어 있을 때 pop() 함수를 호출하면 오류 메시지가 출력되고 프로그램이 비정상적으로 종료됩니다. 
        // 이렇게 하면 스택이 비어 있을 때 제거 작업이 수행되지 않도록 보장하며, 프로그램의 안정성을 유지합니다.
        // exit(1) -> 에러에 의한 강제종료 
        // exit(0) -> 정상종료 (프로그램 모두 실행 후)
    }
    else return stack[top];
}

// 주 함수

int main(void) {
    push(1); // 스택에 1추가
    push(2); // 스택에 2추가
    push(3); // 스택에 3추가

    printf("%d\n", pop()); // 스택에서 1을 삭제하세요
    printf("%d\n", pop()); // 스택에서 2를 삭제하세요
    printf("%d\n", pop()); // 스택에서 3을 삭제하세요
    //스택이 비었는지 확인하세요
    printf("%d\n", is_empty());
    return 0;
}