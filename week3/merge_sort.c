#include <stdio.h>
void merge_sort(int a[], int b[], int len_a, int len_b, int mainA[]);
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
    merge_sort(left, right, first_half, second_half, numbers);
}

void merge_sort(int a[], int b[], int len_a, int len_b, int mainA[])
{
    int fix_array[len_a + len_b];
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < len_a && j < len_b)
    {
        if (a[i] < b[j])
        {
            fix_array[k] = a[i];
            k++;
            i++;
        }
        else if (a[i] > b[j])
        {
            fix_array[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < len_a)
    {
        fix_array[k] = a[i];
        i++;
        k++;
    }
    while (j < len_b)
    {
        fix_array[k] = b[j];
        j++;
        k++;
    }
    printf("Merged array \n");
    for (int z = 0; z < len_a + len_b; z++)
    {
        mainA[z] = fix_array[z];
    }
    printf("\n");
}

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(numbers) / sizeof(numbers[0]);

    merge(numbers, len);
}
