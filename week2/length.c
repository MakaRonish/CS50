#include <stdio.h>
#include <string.h>

int length_calculator(char name[])
{
    int i = 0;
    char a = name[i];
    while (name[i] != 0)
    {
        i++;
    }
    return i;
}

int main(void)
{
    char name[100];
    printf("Enter your name: ");
    scanf("%s", &name);
    int length = length_calculator(name);
    printf("THe number of char in your name is %i\n", length);
}