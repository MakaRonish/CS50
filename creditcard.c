#include <stdio.h>
#include <string.h>

void valid_creditcar(char credit_card[])
{
    int length = strlen(credit_card);
    char first[90] = "";
    char second[90] = "";
    if (length > 16 || length < 13)
    {
    }
    else
    {
        int lene = 0;
        for (int i = 0; i < length; i++)
        {
            if (i % 2 == 0)
            {
                first[lene] = credit_card[i];
            }
            else
            {
                second[lene] = credit_card[i];
                lene++;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < strlen(second); i++)
    {
        int sec_num = second[i] - '0';
        if ((2 * sec_num) > 9)
        {
            int new_num = 2 * sec_num;
            char str[3];
            sprintf(str, "%d", new_num);
            printf("string %s", str);
            int gg = 0;
            for (int i = 0; i < strlen(str); i++)
            {
                int sec_num = second[i] - '0';
                printf("sec sum;%d\n", sec_num);
                gg += sec_num;
                sum += sec_num;
            }
            printf("gg sum;%d\n", gg);
            printf("gg ;%d\n", strlen(str));
        }
        else
        {

            sum = sum + (2 * sec_num);
        }
    }
    printf("total second: %d\n", sum);
    for (int i = 0; i < strlen(first); i++)
    {
        int sec_num = second[i] - '0';

        sum = sum + sec_num;
    }
    printf("%s", first);
    printf("\n");
    printf("%s", second);
    printf("total sum: %d", sum);
}

char *reverse_string(char stringrev[])
{
    int length = strlen(stringrev);
    int i = 0;
    int j = length - 1;
    while (i < j)
    {
        char temp = stringrev[i];
        stringrev[i] = stringrev[j];
        stringrev[j] = temp;
        i++;
        j--;
    }
    return stringrev;
}

int main(void)
{
    char name[] = "ronish";
    // // printf("%d", strlen(name));
    // // printf("%c", name[0]);
    // valid_creditcar("12345678912345");
    // char *rev = reverse_string(name);
    // printf("%s", rev);

    char number[] = "4003600000000014";
    char *rev = reverse_string(number);
    valid_creditcar(rev);
}