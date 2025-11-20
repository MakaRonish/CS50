#include <stdio.h>

int main(void)
{
    int numbers[] = {3, 1, 6, 8, 4, 2, 0};
    for (int z = 0; z < 7; z++)
    {
        printf("%i\n", numbers[z]);
    }
    printf("After \n");

    int j;
    int swap = -1;
    while (swap != 0)
    {
        int end_val = 6;
        swap = 0;
        for (int i = 0; i < end_val; i++)
        {
            j = i + 1;
            if (numbers[i] > numbers[j])
            {
                swap++;
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
        end_val--;
    }

    for (int z = 0; z < 7; z++)
    {
        printf("%i\n", numbers[z]);
    }
}