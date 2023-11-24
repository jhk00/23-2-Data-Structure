#include <stdio.h>
#include <time.h>


int main(void) {
    clock_t start, finish;
    double duration, x, result;
    int n,i;

    printf("input x : ");
    scanf(%lf, &x);
    printf("input n : ");
    scanf("%d", &n);

    start = clock();

    result = power_recur(x, n);
    printf("%2.lf^%d = %.2lf\n", x, n, result);

    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", duration);
}


double power_recur(double x, int n)
{
if ( n == 0 ) return 1;
else if ( n%2 == 1) x*power_recur(x,(n-1)/2)*power_recur(x,(n-1)/2);
else power_recur(x, n/2)* power_recur(x, n/2);
}