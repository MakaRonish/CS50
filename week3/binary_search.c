#include <stdio.h>

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("Number: ");
    int uNum;
    scanf("%i", &uNum);

    int start = 0;
    int lenght = 9;
    int end = 8;
    int search_time = 0;
    while (start <= end)
    {
        search_time++;
        int middle = (start + end) / 2;
        if (numbers[middle] == uNum)
        {
            printf("index: %i\n", middle);
            printf("Search time: %i\n", search_time);
            return 0;
        }
        else if (numbers[middle] > uNum)
        {
            end = middle - 1;
        }
        else if (numbers[middle] < uNum)
        {
            start = middle + 1;
        }
    }
    printf("Search time: %i\n", search_time);
    printf("Not found");
}