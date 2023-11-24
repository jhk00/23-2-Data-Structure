#include <stdio.h>
#include <time.h>
// for문을 이용하여 임의의 숫자 n을 n번 더했을 때 걸리는 시간을 구하는 프로그램입니다.
int main()
{
    clock_t start, finish;
    double duration;
    int i;
    unsigned int n;
    long res;

    printf("input a positive int : ");
    scanf("%d", &n);

    start = clock();
    
    res = 0; // 이거 res 초기화 시켜줬어야함 여기서 res=0 안써주면 이상한 값 나옴 초기화 꼭 시켜주기
    for(int i = 0; i < n; i++) res =res+n;

    finish = clock();

    printf("%ld\n", res);
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("res = %ld (%f seconds)\n", res, duration);
}