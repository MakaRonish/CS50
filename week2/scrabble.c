#include <stdio.h>
#include <string.h>
#include <ctype.h>

int score_calculator(char *word);
int main(void)
{

    char inputs[2][90];
    for (int i = 0; i < 2; i++)
    {
        printf("player %d:", i + 1);
        scanf("%s", inputs[i]);
    }
    int score1 = score_calculator(inputs[0]);
    int score2 = score_calculator(inputs[1]);
    if (score1 > score2)
    {
        printf("player 1 wins");
    }
    else if (score2 > score1)
    {
        printf("player 2 wins");
    }
    else
    {
        printf("Tie");
    }
}

int score_calculator(char *word)
{
    int value[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        int point = toupper(word[i]);
        score += value[point - 65];
    }
    return score;
}
