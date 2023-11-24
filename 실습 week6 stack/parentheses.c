#include "stack.h"

int check_matching(char *in) {
    StackType s;
    char ch, open_ch;
    int i,n = strlen(in);
    init(&s);
    for(i = 0; i<n; i++) {
        ch = in[i];
        switch (ch) {
            case '{':
            case '(':
            case '[':
            push(&s, ch);
            break;
            case ')': 
            case '}':
            case ']':
            if(is_empty(&s)) return FALSE;
            else {
                open_ch = pop(&s);
                if ( (open_ch == '('  && ch != ')') ||
                     (open_ch == '{'  && ch != '}') ||
                     (open_ch == '['  && ch != ']')   )
                     return FALSE;
                break; 
            }
        }
    }
    if(!is_empty(&s)) return FALSE; // 검사가 끝난 후 스택이 비어있지 않으면 FALSE를 리턴
    return TRUE;
}

int main(void) {
    StackType s;
    char ch[] = "{(8+2)*3+1}+2";
    if(check_matching(ch) == TRUE) { printf("True");}
    else {printf("false");}
    return 0;
}