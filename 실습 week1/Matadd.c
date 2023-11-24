#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

void matadd(int a[][N], int b[][N], int c[][N]);

int main()
{
    clock_t start, finish;
    double duration;
    int i, j;
    int a[N][N], b[N][N], c[N][N];

    for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
    a[i][j] = rand() % 10;
    b[i][j] = rand() % 10;
    }
    }
    // rand 연산자를 사용하면 나오는 난수는 너무 광범위하니 %10 으로
    // 범위 일의자리로 한정정

    start = clock();
    matadd(a,b,c);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", duration);
}

void matadd(int a[][N], int b[][N], int c[][N]) {

for(int i = 0; i < N; i ++) {
for(int j = 0; j < N; j ++) {
c[i][j] = a[i][j] + b[i][j];
}
}

}