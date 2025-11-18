#include <stdio.h>

int main(void)
{
    int x, y;
    printf("What is x? ");
    scanf("%i", x);
    printf("What is y? ");
    scanf("%i", y);
    if (x > y)
    {
        printf("x is greater than y\n");
    }
    else if (x < y)
    {
        printf("x is not greater than y");
    }
    else
    {
        printf("x is equal to y");
    }
    if (x)
    {
    }
}