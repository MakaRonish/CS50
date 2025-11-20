#include <stdio.h>

int fibo(int num)
{
    if (num == 0 || num == 1)
    {
        return 0;
    }
    else if (num % 2 == 0)
    {
        num /= 2;
    }
    else if (num % 2 != 0)
    {
        num = 3 * num + 1;
    }
}

int main(void)
{
}