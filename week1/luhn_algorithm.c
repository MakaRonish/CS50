#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int lastDigit(long long int number)
{
    return number % 10;
}

bool luhn(long long int credit, int length)
{

    int first_sum = 0;
    int second_sum = 0;

    for (int i = 0; i < length; i++)
    {
        int last_digit = lastDigit(credit);
        credit = credit / 10;
        if (i % 2 == 0)
        {
            first_sum += last_digit;
        }
        else
        {
            int twoMultiple = 2 * last_digit;
            if (twoMultiple > 9)
            {
                for (int i = 0; i < 2; i++)
                {
                    int last = lastDigit(twoMultiple);
                    twoMultiple = twoMultiple / 10;
                    second_sum += last;
                }
            }
            else
            {
                second_sum += twoMultiple;
            }
        }
    }
    return first_sum + second_sum == 20;
}

void company_determiner(long long int credit, int length)
{
    if (length > 12 && length < 17)
    {
        long long int firstTwo = credit;
        for (int i = 0; i < length - 2; i++)
        {
            firstTwo /= 10;
        }

        if ((firstTwo > 50 && firstTwo < 56) && length == 16)
        {
            printf("MASTERCARD");
        }
        else if ((firstTwo == 34 || firstTwo == 37) && length == 15)
        {
            printf("AMERICAN");
        }
        else if (firstTwo / 10 == 4 && (length == 13 || length == 16))
        {

            printf("VISA");
        }
        else
        {
            printf("INVALID");
        }
    }
    else
    {

        printf("INVALID");
    }
}
int main(void)
{
    long long int crd;
    int check;
    do
    {
        printf("Number: ");
        check = scanf("%lld", &crd);
        if (check == 0)
        {
            printf("Invalid input! Please enter digits only.\n");

            // clear leftover characters from the input buffer
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
        }

    } while (check == 0);

    char strCredit[30];
    sprintf(strCredit, "%lld", crd);
    int lenght = strlen(strCredit);
    bool status = luhn(crd, lenght);
    company_determiner(crd, lenght);
}