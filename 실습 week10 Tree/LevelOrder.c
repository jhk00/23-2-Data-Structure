#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct TreeNode {
    int data;
    struct TreeNode* left, *right;
}TreeNode;

typedef TreeNode* element;

typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {26, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode* root = &n6;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(QueueType* q) {
    q->front = q->rear = NULL;
}

int is_empty(QueueType* q) {
    return (q->front == NULL);
}

int is_full(QueueType* q) {
    return (q->rear == MAX_STACK_SIZE-1);
}

void enqueue(QueueType* q, element item) {
    if (is_full(q))
    error("Queue is full");
    

}