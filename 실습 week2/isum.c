#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isum(int list[], int n) {
    int sum = 0;
    for(int i = 0; i<n ; i++) sum +=list[i];
    return sum;
}

int main(void) {
    clock_t start, finish;
    double duration;

    int i;
    int *list;
    int length, result;

    printf("The size of list : ");
    scanf("%d", &length);

    list = (int*)malloc(sizeof(int)*length);

    for(i = 0; i<length; i++) list[i] = i+1;

    start = clock();
    result = isum(list, length);
    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("The total sum(iteration) : %d\n", result);
    printf("%f seconds\n", duration);
}