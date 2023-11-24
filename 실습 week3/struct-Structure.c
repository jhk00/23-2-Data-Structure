#include <stdio.h>
#include <string.h>


void compare (person a, person b)
{

}

int main(void) {
    person a,b;

    strcpy(a.name, "Alice");
    a.age = 15;
    a.height = 50.5;

    printf("enter b's age : ");
    scanf("%d", &b.age);
    compare(a,b);

    b = a;
    printf("a.age = %d, b.age = %d\n", a.age, b.age);
}