#include <stdio.h>
#include <string.h>

struct Candidates
{
    char name[100];
    int first_choice;
    int second_choice;
    int third_choice;
};
struct Votes
{
    char first[100];
    char second[100];
    char third[100];
};
void print_candidates(struct Candidates candidate[], int count)
{
    printf("\n--- Candidates ---\n");
    for (int i = 0; i < count; i++)
    {
        printf("Name: %s | 1st: %d | 2nd: %d | 3rd: %d\n",
               candidate[i].name,
               candidate[i].first_choice,
               candidate[i].second_choice,
               candidate[i].third_choice);
    }
}
void print_votes(struct Votes votes[], int no_voters)
{
    printf("\n--- Votes ---\n");
    for (int i = 0; i < no_voters; i++)
    {
        printf("Voter %d -> 1st: %s | 2nd: %s | 3rd: %s\n",
               i + 1,
               votes[i].first,
               votes[i].second,
               votes[i].third);
    }
}

int name_exist(struct Candidates candidate[], int count, char name[])
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(candidate[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    struct Candidates candidate[10];
    struct Votes votes[10];

    int count = 0;
    printf("Candidates: ");
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
    for (int i = 0; i < no_voters; i++)
    {
        int j = 0;
        printf("Vote no %d\n", i + 1);
        for (size_t k = 0; k < count; k++)
        {
            int found = 0;
            while (found == 0)
            {
                char name[100];
                printf("Rank %d: ", j + 1);
                scanf("%s", &name);
                int index = name_exist(candidate, count, name);
                if (index != -1)
                {
                    found = 1;
                    if (j == 0)
                    {
                        strcpy(votes[i].first, name);
                        candidate[index].first_choice++;
                    }
                    else if (j == 1)
                    {
                        candidate[index].second_choice++;

                        strcpy(votes[i].second, name);
                    }
                    else if (j == 2)
                    {
                        candidate[index].third_choice++;
                        strcpy(votes[i].third, name);
                    }
                }
                else
                {
                    printf("Invalid candidate\n");
                }
            }
            j++;
        }
        printf("\n");
    }
    print_candidates(candidate, count);
    print_votes(votes, no_voters);
}