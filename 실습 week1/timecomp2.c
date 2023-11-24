#include <stdio.h>
#include <time.h>

int main() {
    unsigned int n;
    long res = 0;
    double dur;
    clock_t start, finish;
    printf("input a positive int : ");
    scanf("%d",&n);
    start = clock();
    res = (n*(n+1))/2;
    finish = clock();

    dur = (double)(finish-start)/CLOCKS_PER_SEC;
    printf("res = %ld (%f seconds)\n", res, dur); // %ld -> long 자료형
    

}