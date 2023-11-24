#include <stdio.h> // clock_t를 이용하여 시간 차를 구해보기
#include <time.h>

int main()
{
    clock_t start, finish;
    double duration;
    unsigned int n;
    long res;

    printf("input a positive int : ");
    scanf("%d", &n);

    start = clock();

    res = n*n;

    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("res = %ld (%f seconds)\n", res, duration);

// res가 실행되는데 걸리는 시간 측정한 것
}
