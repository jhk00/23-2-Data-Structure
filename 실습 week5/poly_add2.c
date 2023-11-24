#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101

struct {
    float coef;
    int expon;
} terms[MAX_TERMS] = { {8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0}};

int avail = 6;

// compare between a and b

char compare(int a, int b) {
    if (a>b) return '>' ;
    else if (a == b) return '= ';
    else return '< ';
}