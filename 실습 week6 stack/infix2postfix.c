#include "infix2postfix_Stack.h"

// 연산자의 우선순위를 반환한다.

int prec (char op) {
    switch (op) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

// 중위 표기 수식 -> 후위 표기 수식

void infix_to_postfix (char exp[]) {
    int i = 0;
    char ch, top_op;
    int len = strlen(exp);

    StackType s;
    init(&s);

    for(i=0; i <len; i++) {
        ch = exp[i];
        // 연산자이면
        switch (ch) {
            // 스택에 있는 연산자의 우선순위가 크거나 같으면 출력
            case '+': case '-': case '*': case '/':
            while(!is_empty(&s) && (prec(ch) <= prec(peek(&s)) ))
            printf("%c", pop(&s));
            push(&s, ch);
            break;
        case '(' : // 왼쪽 괄호
                push(&s,ch);
                break;

        case ')' : // 오른쪽 괄호
                    top_op = pop(&s);
                    //왼쪽 괄호를 만날때까지 출력
                    while(top_op != '(') {
                        printf("%c", top_op);
                        top_op = pop(&s);
                    }
                    break;
        default: // 피연산자
                printf("%c", ch);
                break;            
        
        }
    }
    while(!is_empty(&s)) // 스택에 저장된 연산자들 출력
            printf("%c", pop(&s));
    printf("\n");
}

int main(void) {
    
    char infix[100];

    printf("input infix: ");
    scanf("%s", infix);

    infix_to_postfix(infix);
}


