#include <stdio.h>

int main(void)
{
    const int N = 3;
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        printf("Score %d: ", i + 1);
        scanf("%d", &scores[i]);
    }

    printf("Average: %f", (scores[0] + scores[1] + scores[2]) / (float)N);
}