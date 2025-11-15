#include <stdio.h>
#include <string.h>

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
            encrypted[i] = asci_val + key;
        }
    }
    printf("output: %s", encrypted);
}