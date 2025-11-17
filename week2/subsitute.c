#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char key[30];
    char plaintext[100];
    char cypertext[100];
    printf("Key: ");
    fgets(key, sizeof(key), stdin);

    key[strcspn(key, "\n")] = '\0';

    printf("Plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            int ascii = plaintext[i] - 65;
            cypertext[i] = toupper(key[ascii]);
        }
        else if (islower(plaintext[i]))
        {
            int ascii = plaintext[i] - 97;
            cypertext[i] = tolower(key[ascii]);
        }
        else
        {
            cypertext[i] = plaintext[i];
        }
    }
    printf("cypertext: %s", cypertext);
}