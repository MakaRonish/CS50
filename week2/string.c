#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[100];
    printf("Input: ");
    scanf("%s", &input);
    printf("Output: ");
    int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        printf("%c", input[i]);
    }
}