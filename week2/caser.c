#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char word[1000];
    char encrypted[1000];
    long key;
    printf("Word: ");
    fgets(word, sizeof(word), stdin);

    printf("key: ");
    scanf("%ld", &key);
    key = key % 26;
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] != '\n')
        {

            int asci_val = word[i];
            int new_val = asci_val + key;
            if (isupper(word[i]))
            {
                if (new_val > 90)
                {
                    int new_key = new_val - 90;
                    encrypted[i] = asci_val + new_key;
                }
                else
                {
                    encrypted[i] = asci_val + key;
                }
            }
            else if (islower(word[i]))
            {
                if (new_val > 122)
                {
                    int new_key = new_val - 122;
                    encrypted[i] = asci_val + new_key;
                }
                else
                {
                    encrypted[i] = asci_val + key;
                }
            }
        }
    }
    printf("output: %s", encrypted);
}