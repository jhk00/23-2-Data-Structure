#include  <stdio.h>
#include <stdlib.h>

#define FASLE 0
#define TRUE 1

typedef struct ThreadedTree {

} Thread;

Thread* Tcreate() {
    Thread* newThread = (Thread* ) malloc(sizeof(Thread));

    newThread->leftChild = NULL;
    newThread->leftThread = FALSE;
    newThread->rightChild = NULL;
    newThread->rightThread = FALSE;

    return newThread;
} 

Thread* insucc(Thread* tree) {

}

Thread* inpred(Thread* tree) {
    Thread* temp = tree->leftChild;

    if(!tree->leftThread)
    while(!temp->rightThread)
    temp = temp -> rightChild;
    return temp;
}

void Tinorder(Thread* tree) {
    Thread* temp = tree;

    while(1) {
        printf("%c ", temp->data);
    }
    printf("\n");
}

void InsertRight(Thread* tree, Thread* rightTree) {

}

void insertLeft(Thread* tree, Thread* leftTree) {
    Thread* temp;

    leftTree->leftChild = tree->leftChild;
    leftTree->leftThread = tree->leftThread;
    leftTree-> rightChild = tree;
    leftTree->rightThread = TRUE;
    tree->leftChild = leftTree;
    tree->leftThread = FALSE;
}