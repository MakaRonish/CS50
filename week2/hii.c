#include <stdio.h>

int main(void)
{
    char c1 = 'h';
    char c2 = 'i';
    char c3 = '!';

    char *words[2];
    words[0] = "Hii!";
    words[1] = "Bye";
    printf("%c\n", words[0][0]);
    printf("%s\n", words[1]);
}