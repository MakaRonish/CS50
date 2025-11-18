#include <stdio.h>
void piramid(int height);
int main(void)
{
    int height;

    do
    {
        printf("Height: ");
        scanf("%d", &height);
    } while (height < 1 || height > 8);
    piramid(height);
}

void piramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = height; j > i; j--)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("x");
        }

        printf(" ");
        for (int l = 0; l <= i; l++)
        {
            printf("x");
        }
        printf("\n");
    }
}
