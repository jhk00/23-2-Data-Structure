#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;


TreeNode n1 = {'B', NULL, NULL};
TreeNode n2 = {'A', NULL, NULL};
TreeNode n3 = {'C', NULL, NULL};
TreeNode n4 = {'/', &n2, &n1};
TreeNode n5 = {'D', NULL, NULL};
TreeNode n6 = {'*', &n4, &n3};
TreeNode n7 = {'E', NULL, NULL};
TreeNode n8 = {'-', &n6, &n5};
TreeNode n9 = {'+', &n8, &n7};
TreeNode* root = &n9;

TreeNode* stack[MAX_STACK_SIZE];

typedef TreeNode* element;
int top = -1;

int is_empty() {
    return (top == -1);
}

int is_full(StackType *s) {
    return (s->top == MAX_STACK_SIZE -1);
}

void push(StackType *s, element item) {
    if(is_full()) {
        fprintf(stderr, "stack is full\n");
        return;
    }
    else {

    }
        
}

element pop() {
    if(is_empty()) {
        fprintf(stderr, "stack is empty\n");
        exit(1);
    }
    else

}

element peek() {
    if(is_empty()) {
        fprintf(stderr, "stack is empty\n");
        exit(1);
    }
    else
}

void iterinorder(TreeNode* root) {
    TreeNode* node = root;
    do {
        for (; node; node = node -> left)
        push(node);
    node = pop();
    printf("%c", node-data);
    node = node->right;
    } while(!is_empty() || node != NULL);
    printf("\n");
}

int main(void) {
    iterinorder(root);
}