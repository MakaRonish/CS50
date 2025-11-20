#include <stdio.h>

int numbers(int n)
{
    if (n < 0)
    {

        return 0;
    }
    numbers(n - 1);
    printf("%i ", n);
}
int reverse_numbers(int n)
{
    if (n < 0)
    {

        return 0;
    }
    printf("%i ", n);
    reverse_numbers(n - 1);
}
int main(void)
{
    numbers(10);
    printf("\n");
    reverse_numbers(10);
}