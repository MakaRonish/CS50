#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char input[100];
    printf("Input: ");
    scanf("%s", &input);
    printf("After: ");
    int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        // printf("%c", input[i] - 32);
        printf("%c", toupper(input[i]));
    }
}