#include <stdio.h>
#include <string.h>

int main(void)
{
    char sentence[999];
    double letter = 0, word = 1, sen = 0;
    printf("Text: ");
    fgets(sentence, sizeof(sentence), stdin);
    for (int i = 0; i < strlen(sentence); i++)
    {
        char s = sentence[i];
        if (sentence[i] == ' ')
        {
            word++;
        }
        else if ((sentence[i] >= 'A' && sentence[i] <= 'Z') || (sentence[i] >= 'a' && sentence[i] <= 'z'))
        {
            letter++;
        }
        else if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
        {
            sen++;
        }
    }
    printf("text: %s", sentence);
    printf("word :%f\n", word);
    printf("sen :%f\n", sen);
    printf("letter :%f\n", letter);
    double index = 0.0588 * ((letter / word) * 100) - 0.296 * ((sen / word) * 100) - 15.8;
    printf("%f\n", index);
}