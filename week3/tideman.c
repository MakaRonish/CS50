#include <stdio.h>

struct Candidates
{
    char name[100];
    int first_choice;
    int second_choice;
    int third_choice;
};

int main(void)
{
    struct Candidates candidate[10];
    printf("Candidates: ");
    int count = 0;
    while (scanf("%s", &candidate[count].name) == 1)
    {
        candidate[count].first_choice = 0;
        candidate[count].second_choice = 0;
        candidate[count].third_choice = 0;
        count++;
        if (getchar() == '\n')
        {
            break;
        }
    }
    int no_voters;
    printf("Number of Voters: ");
    scanf("%d", &no_voters);
    printf("name: %s\n", candidate[count].name);
    printf("count: %d\n", count);
}