#include <stdio.h>
#include <string.h>
struct Candidates
{
    char name[100];
    int first_choice;
    int second_choice;
    int third_choice;
};

struct Voters
{
    char first[100];
    char second[100];
    char third[100];
};

int check_if_name_there(struct Candidates people[], char name[100], int count);
void print_data(struct Candidates people[], int count);
void print_votes(struct Voters votes[], int voter_no);
int clear_majority(struct Candidates people[], int count, int num_voter);
int lowest_majority(struct Candidates people[], int count);
void runoff(struct Candidates people[], struct Voters votes[], char *name, int voter_no, int count);
int main(void)
{

    struct Candidates people[10];
    struct Voters votes[10];

    int count = 0;
    printf("Candidates :");
    while (scanf("%s", &people[count].name) == 1)
    {
        people[count].first_choice = 0;
        people[count].second_choice = 0;
        people[count].third_choice = 0;
        count++;
        if (getchar() == '\n') // stop when Enter is pressed
            break;
    }
    int voter_no;
    printf("number of voters :");
    scanf("%i", &voter_no);

    for (int i = 0; i < voter_no; i++)
    {
        for (size_t j = 0; j < count; j++)
        {
            int found = 0;
            do
            {

                char v_name[100];
                printf("Rank %i:", j + 1);
                scanf("%s", &v_name);
                int index = check_if_name_there(people, v_name, count);
                if (index == -1)
                {
                    printf("\nInvalid Person\n");
                }
                else
                {
                    found = 1;
                    if (j == 0)
                    {
                        people[index].first_choice++;
                        strcpy(votes[i].first, v_name);
                    }
                    else if (j == 1)
                    {
                        people[index].second_choice++;
                        strcpy(votes[i].second, v_name);
                    }
                    else if (j == 2)
                    {
                        people[index].third_choice++;
                        strcpy(votes[i].third, v_name);
                    }
                }
            } while (found == 0);
        }
        printf("\n");
    }
    print_data(people, count);
    print_votes(votes, voter_no);
    int result = clear_majority(people, count, voter_no);
    if (result == -1)
    {
        printf("there is no majority so we will go with runoff \n");
        int low_i = lowest_majority(people, count);
        char *low_name = people[low_i].name;
        runoff(people, votes, low_name, voter_no, count);
        int result = clear_majority(people, count, voter_no);
        printf("The winner after runoff is %s", people[result].name);
    }
    else
    {
        printf("The winner majority is %s", people[result].name);
    }
}
int check_if_name_there(struct Candidates people[], char name[100], int count)
{

    for (int i = 0; i < count; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {

            return i;
        }
    }
    return -1;
}
void print_data(struct Candidates people[], int count)
{

    for (int i = 0; i < count; i++)
    {
        printf("name :%s\n", people[i].name);
        printf("first choice :%i\n", people[i].first_choice);
        printf("second choice :%i\n", people[i].second_choice);
        printf("third choice :%i\n", people[i].third_choice);
        printf("\n");
    }
}
void print_votes(struct Voters votes[], int voter_no)
{

    for (int i = 0; i < voter_no; i++)
    {

        printf("first choice :%s\n", votes[i].first);
        printf("second choice :%s\n", votes[i].second);
        printf("third choice :%s\n", votes[i].third);
        printf("\n");
    }
}
int clear_majority(struct Candidates people[], int count, int num_voter)

{
    int majority = num_voter / 2 + 1;
    for (int i = 0; i < count; i++)
    {
        if (people[i].first_choice >= majority)
        {

            return i;
        }
    }
    return -1;
}
int lowest_majority(struct Candidates people[], int count)
{
    int low = 99999999;
    int index = 0;
    for (int i = 0; i < count; i++)
    {
        if (people[i].first_choice < low)
        {
            low = people[i].first_choice;
            index = i;
        }
    }
    return index;
}

void runoff(struct Candidates people[], struct Voters votes[], char *name, int voter_no, int count)
{
    for (int i = 0; i < voter_no; i++)
    {
        if (strcmp(votes[i].first, name) == 0)
        {
            int index_od_first = check_if_name_there(people, votes[i].first, count);
            people[index_od_first].first_choice--;
            char *second_vote = votes[i].second;
            int index_of_second = check_if_name_there(people, second_vote, count);
            people[index_of_second].first_choice++;
        }
    }
}