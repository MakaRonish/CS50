#include <stdio.h>

void merge(int numbers[], int len)
{
    printf("Array: ");
    for (int i = 0; i < len; i++)
        printf("%d ", numbers[i]);
    printf("\n");

    if (len <= 1)
        return;

    int first_half = len / 2; // smaller half when odd
    int second_half = len - first_half;

    int left[first_half];
    int right[second_half];

    // Copy left half
    for (int i = 0; i < first_half; i++)
        left[i] = numbers[i];

    // Copy right half
    for (int i = 0; i < second_half; i++)
        right[i] = numbers[first_half + i];

    printf("Left: ");
    for (int i = 0; i < first_half; i++)
        printf("%d ", left[i]);
    printf("\n");

    printf("Right: ");
    for (int i = 0; i < second_half; i++)
        printf("%d ", right[i]);
    printf("\n");

    merge(left, first_half);
    merge(right, second_half);
}

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(numbers) / sizeof(numbers[0]);

    merge(numbers, len);
}
