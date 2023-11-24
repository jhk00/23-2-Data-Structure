#include <stdio.h>
#include <time.h>
// 이중 for문을 이용하여 1을 n의 제곱번 더했을 때 걸리는 시간을 구하는 프로그램 입니다.
int main()
{
    clock_t start, finish;
    double duration;
    int i, j;
    unsigned int n;
    long res;

    printf("input a positive int : ");
    scanf("%d", &n);

    start = clock();

    res = 0;

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    res += 1;


    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("res = %ld (%f seconds)\n", res, duration);

}