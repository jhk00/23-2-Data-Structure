#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_DEGREE 101

typedef struct
{
                            // Declare polynomial struct type
    int degree;             // Order(degree->차수) of a polynomial(다항식)
    float coef[MAX_DEGREE]; // Coefficients(계수) of a polynomial(다항식)

} polynomial;

// C = A+B, where A and B are polynomials.
polynomial poly_add1(polynomial A, polynomial B)
{
    polynomial C;                     // a Polynomial which contains the result of A+B
    int Apos = 0, Bpos = 0, Cpos = 0; // array index (coef index)
    int degree_a = A.degree;
    int degree_b = B.degree;
    C.degree = MAX(A.degree, B.degree); // degree of a polynomial C
    while (Apos <= A.degree && Bpos <= B.degree)
    {
        if (degree_a > degree_b)
        { // degree of terms in A > degree
          // of terms in B
            C.coef[Cpos++] = A.coef[Apos++];
            degree_a--;
        }
        else if (degree_a == degree_b)
        { // degree of terms in A == degree of
          // terms in B
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
            degree_a--;
            degree_b--;
        }
        else
        { // degree of terms in B > degree of
            // terms in A
            C.coef[Cpos++] = B.coef[Bpos++];
            degree_b--;
        }
    }
    return C;
}

int main(void) {
    polynomial a = {5, {3,6,0,0,0,10}};
    polynomial b = {4, {7,0,5,0,1}};
    polynomial c;
    c = poly_add1(a,b);



    for (int i = 0; i <= c.degree; i++) {
    printf("%.2fx^%d ", c.coef[i], c.degree-i);
    if(i < c.degree) printf("+ ");
    }

    
}