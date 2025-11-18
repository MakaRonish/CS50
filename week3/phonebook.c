#include <stdio.h>
#include <string.h>

typedef struct
{
    char *name;
    char *number;
} person;

int main(void)
{
    // char *names[] = {"Yuliia", "David", "john"};
    // char *numbers[] = {"+1-647-495-1000", "+2", "+3"};
    // char name[100];

    // printf("Name: ");
    // scanf("%s", &name);

    // for (int i = 0; i < 3; i++)
    // {
    //     if (strcmp(names[i], name) == 0)
    //     {
    //         printf("found %s\n", names[i]);
    //         printf("number %s\n", numbers[i]);
    //         return 0;
    //     }
    // }
    // printf("Not found %s\n", name);
    // return 1;

    person people[3];
    people[0].name = "Ronish";
    people[0].number = "1-1-1-1-1";
    people[1].name = "john";
    people[1].number = "2-2-2-2";
    people[2].name = "david";
    people[2].number = "3-3-3-3";

    char name[100];

    printf("Name: ");
    scanf("%s", &name);

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("found %s\n", people[i].name);
            printf("number %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found %s\n", name);
    return 1;
}