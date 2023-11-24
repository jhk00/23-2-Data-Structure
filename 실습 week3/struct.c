#include <stdio.h>
#include <string.h>
typedef struct person {
    char name;
    int age;
    float height;
} person;


void compare(person a, person b)
{
    if(a.age > b.age) printf("a is older than b\n");
    else if (a.age = b.age) printf("a is he same age as b\n");
    else printf("a is younger than b\n");
}


int main(void) 
{
    person a,b;

    strcpy(a.name, "Alice");
    a.age = 15;
    a.height = 50.5;

    printf("enter b's age: ");
    scanf("%d", &b.age);
    compare(a,b);

    b = a;

    printf("a.age = %d, b.age = %d\n", a.age, b.age);


}