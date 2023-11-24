typedef int element;
typedef struct
{
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;
// stack initialization
void init(StackType *s)
{
    s->top = -1;
}
// check empty state of stack
int is_empty(StackType *s)
{
    return (s->top == -1);
}
// check full state of stack
int is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}
// add an item
void push(StackType *s, element item)
{
    if (is_full(s))
    {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else
        s->stack[++(s->top)] = item;
}
// delete top item
element pop(StackType *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return s->stack[(s->top)--];
}
// peek
element peek(StackType *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return s->stack[s->top];
}

int check_matching(char *in)
{
    StackType s;
    char ch, open_ch;
    int i, n = strlen(in);
    init(&s);
    for (i = 0; i < n; i++)
    {
        ch = in[i];
        switch (ch)
        {
        case '(':
        case '[':
        case '{':
            push(&s, ch);
            break;
        case ')':
        case ']':
        case '}':
            if (is_empty(&s))
                return FALSE;
            else
            {
                open_ch = pop(&s);
                if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') ||
                    (open_ch == '{' && ch != '}'))
                {
                    return FALSE;
                }
                break;
            }
        }
    }
    if (!is_empty(&s))
        return FALSE;
    return TRUE;
}
int main(void)
{
    if (check_matching("{ A[(i+1)]=0; }") == TRUE)
printf(“Success\n");
else
printf(“Fail\n");
return 0;
}
