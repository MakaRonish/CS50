
#include <stdio.h> /*header file*/

int main(void)
{
    char name[30];
    printf("Enter your name: ");
    scanf("%s", &name);
    printf("hello, %s\n", name);

    int age;
    printf("What is your age? ");
    scanf("%i", &age);
    printf("you are %i years old \n", age);
    if (age > 18)
    {
        printf("you can drink alcohol now %s", name);
    }
    else if (age < 0)
    {
        printf("wrong age");
    }
    else
    {
        printf("you cannot drink alcohol, %s", name);
    }
}