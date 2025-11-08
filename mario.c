#include <stdio.h>
void questionmarks_horizon(int times);
void questionmarks_vertical(int times);
void wall(int length, int breath);
int main(void)
{
    questionmarks_horizon(5);
    questionmarks_vertical(5);

    wall(3, 5);
}

void questionmarks_horizon(int times)
{
    for (int i = 0; i < times; i++)
    {
        printf(" ? ");
    }
    printf("\n");
}
void questionmarks_vertical(int times)
{
    for (int i = 0; i < times; i++)
    {
        printf("*");
        printf("\n");
    }
}

void wall(int length, int breath)
{
    for (int j = 0; j < length; j++)
    {
        questionmarks_horizon(breath);
    }
}