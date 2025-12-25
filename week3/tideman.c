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
struct Score
{
    char name[100];
    int vote;
    char won_against[100];
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
struct Score find_score(struct Candidates candidate[], struct Votes votes[], int count, int no_voters, char name1[], char name2[])
{
    struct Candidates copy_candidate[10];
    memcpy(copy_candidate, candidate, count * sizeof(struct Candidates));
    int name1_ind = name_exist(copy_candidate, count, name1);
    int name2_ind = name_exist(copy_candidate, count, name2);
    for (int i = 0; i < no_voters; i++)
    {
        char found_name[100];
        strcpy(found_name, votes[i].first);
        if (strcmp(found_name, name1) == 0 || strcmp(found_name, name2) == 0)
        {
        }
        else
        {
            char sec_choice_found[100];
            strcpy(sec_choice_found, votes[i].second);
            int index_sec = name_exist(copy_candidate, count, sec_choice_found);
            copy_candidate[index_sec].first_choice++;
        }
    }

    printf("candidate %s total votes: %d\n", name1, copy_candidate[name1_ind].first_choice);
    printf("candidate %s total votes: %d\n", name2, copy_candidate[name2_ind].first_choice);
    int c1 = copy_candidate[name1_ind].first_choice;
    int c2 = copy_candidate[name2_ind].first_choice;
    print_candidates(copy_candidate, count);
    struct Score score;
    if (c1 > c2)
    {

        strcpy(score.name, name1);
        strcpy(score.won_against, name2);
        score.vote = c1;
    }
    else
    {
        strcpy(score.name, name2);
        strcpy(score.won_against, name1);
        score.vote = c2;
    }
    return score;
}

int main(void)
{
    struct Candidates candidate[10];
    struct Votes votes[10];
    char candi[10][100];

    int count = 0;
    printf("Candidates: ");
    while (scanf("%s", &candidate[count].name) == 1)
    {
        strcpy(candi[count], candidate[count].name);
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
    struct Score result[10];
    int unique_count = 0;
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            result[unique_count] = find_score(candidate, votes, count, no_voters, candi[i], candi[j]);
            unique_count++;
        }
    }
    printf("No of comb: %d", unique_count);
    for (int i = 0; i < unique_count; i++)
    {
        printf("Results\n");
        printf("vote won by %s against %s\nvotes total: %d\n ", result[i].name, result[i].won_against, result[i].vote);
    }
    struct Score arrange_result[10];
    memcpy(arrange_result, result, unique_count * sizeof(struct Score));
    for (int i = 0; i < unique_count - 1; i++)
    {
        for (int j = 0; j < unique_count - i - 1; j++)
        {
            if (arrange_result[j].vote < arrange_result[j + 1].vote)
            {

                struct Score temp = arrange_result[j];
                arrange_result[j] = arrange_result[j + 1];
                arrange_result[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < unique_count; i++)
    {
        printf("Results Sorted answer\n");
        printf("Results Sorted answer\n");
        printf("votes %s against %s\nvotes total number: %d\n ", arrange_result[i].name, arrange_result[i].won_against, arrange_result[i].vote);
    }
}
