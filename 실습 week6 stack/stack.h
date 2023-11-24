
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define FALSE 0
#define TRUE 1


typedef char element;
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