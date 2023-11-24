#include <stdio.h>
#include <time.h>

int fib_iter(int n);

int main()
{
    clock_t start, finish;
    double duration;
    int n, i, result;

    printf("input n : ");
    scanf("%d", &n);

    start = clock();
    result = fib_iter(n);
    printf("fib(%d) = %d\n", n, result);

    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", duration);
}

int fib_iter (int n)
{
int n1 = 1;
int n2 = 1;
int n3;
for(int i = 0; i < n; i++)
n3 = n1 + n2;
n1 += n2 + n3;
n2 += n3 + n1;
}