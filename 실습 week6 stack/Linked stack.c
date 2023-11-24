#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode {
    element item;
    struct StackNode* link;
} StackNode;

typedef struct {
    StackNode* top;
} LinkedStackType;

// 초기화 함수
void init(LinkedStackType *s) {
    s->top = NULL;
}

// 공백 상태 검출 함수
int is_empty(LinkedStackType *s) {
    return (s->top = NULL);
}

//포화 상태 검출 함수 (필요x)
int is_full(LinkedStackType *s) {
    return 0;
}

void push(LinkedStackType *s, element item) {
    StackNode* temp = (StackNode*)malloce(sizeof(StackNode));
    if(temp == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        return;
    }
    else {

        
    }
}