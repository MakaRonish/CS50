#include <stdio.h>

int main(void)
{

    int change;
    do
    {
        printf("Due change: $");
        scanf("%d", &change);
    } while (change < 1);

    int num25 = 0;
    int num10 = 0;
    int num5 = 0;
    int num1 = 0;
    while (change >= 25)
    {
        change -= 25;
        num25++;
    }
    while (change >= 10)
    {
        change -= 10;
        num10++;
    }
    while (change >= 5)
    {
        change -= 5;
        num5++;
    }
    while (change >= 1)
    {
        change -= 1;
        num1++;
    }
    int total_coin = num25 + num10 + num5 + num1;
    printf("%d", total_coin);
}