#include <stdio.h>
#include <string.h>

int main(void)
{
    struct candidates
    {
        char name[100];
        int votes;
    };
    struct candidates people[10];

    int count = 0;
    printf("Enter names seperated by space:");
    while (scanf("%99s", people[count].name) == 1)
    {
        people[count].votes = 0;
        count++;
        if (getchar() == '\n') // stop when Enter is pressed
            break;
    }
    int voters;
    printf("Voters:");
    scanf("%i", &voters);
    char voted_person[100];

    int found = 1;
    for (int j = 0; j < voters; j++)
    {
        do
        {
            found = 1;
            printf("Vote:");
            scanf("%s", voted_person);
            for (int i = 0; i < count; i++)
            {
                if (strcmp(people[i].name, voted_person) == 0)
                {
                    found = 0;
                    printf("vote casted\n");
                    people[i].votes++;
                    break;
                }
            }
            if (found == 1)
            {
                printf("Invalid\n");
            }
        } while (found != 0);
    }
    int larges = -1;
    int index;
    for (int i = 0; i < count; i++)
    {
        if (people[i].votes > larges)
        {
            index = i;
            larges = people[i].votes;
        }
    }
    printf("Highest voted person is %s with %i votes", people[index].name, people[index].votes);
    printf("\n");
    for (int i = 0; i < count; i++)
    {
        printf("%s: %d votes\n", people[i].name, people[i].votes);
    }

    // printf("Number of voters:");
    // int voters;
    // scanf("%i",&voters);

    // do
    // {

    // } while (condition);
}