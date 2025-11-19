#include <stdio.h>

int main(void)
{
    int numbers[] = {3, 1, 6, 8, 4, 2, 0};
    for (int z = 0; z < 7; z++)
    {
        printf("%i\n", numbers[z]);
    }
    int i = 0;
    int j = sizeof(numbers) / sizeof(numbers[0]);
    int smallest_val;
    int mover = 0;
    int index = 0;

    while (i != j)
    {
        smallest_val = numbers[i];
        index = i;
        for (int k = i; k < j; k++)
        {

            if (numbers[k] < smallest_val)
            {
                smallest_val = numbers[k];
                index = k;
            }
        }
        int temp = numbers[i];
        numbers[i] = numbers[index];
        numbers[index] = temp;
        i++;
    }
    printf("after \n");
    for (int z = 0; z < 7; z++)
    {
        printf("%i\n", numbers[z]);
    }
}