#include <stdio.h>

// void meow(int n)
// {
//     int i = 0;
//     while (i < n)
//     {
//         printf("function meow\n");
//         i++;
//     }
// }

// int main(void)
// {
//     int i = 0;
//     while (i < 3)
//     {
//         printf("meow\n");
//         i++;
//     }

//     for (int i = 0; i < 3; i++)
//     {
//         printf("for meow\n");
//     }
//     meow(9);

//     int number;
//     while (1 < 2)
//     {
//         printf("how many times do you want my cat to moew? ");
//         scanf("%d", &number);
//         if (number > 0)
//         {
//             meow(number);
//             break;
//         }
//         else
//         {
//             printf("Pls enter positive value ");
//         }
//     }
//     do
//     {
//         printf("how many times do you want my cat to moew? ");
//         scanf("%d", &number);
//         if (number > 0)
//         {
//             meow(number);
//             break;
//         }
//         else
//         {
//             printf("Pls enter positive value ");
//         }
//     } while (number < 0);
// }
int value_checker(void);
void how_many_time_meow(int times);
int main(void)
{

    int times = value_checker();
    how_many_time_meow(times);
}

void how_many_time_meow(int times)
{
    for (int i = 0; i < times; i++)
    {
        printf("meow\n");
    };
}

int value_checker(void)
{
    int times;
    do
    {
        printf("how many times to meow :");
        scanf("%d", &times);
    } while (times < 1);

    return times;
}