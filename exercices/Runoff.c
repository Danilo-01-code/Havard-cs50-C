#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Max voters and candidates
#define MAX_CANDIDATES 9
#define MAX_VOTERS 100

// Preferences[i][j]
int preferences[MAX_VOTERS][MAX_CANDIDATES];

typedef struct
{
    string name;
    int vote;
    bool eliminated;
} candidate;

candidate candidates[MAX_CANDIDATES];

int voters_count;
int candidates_count;

void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);
bool vote(int voter, int rank, string name);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    candidates_count = argc - 1;
    if (candidates_count > MAX_CANDIDATES)
    {
        printf("The max number of candidates is %d\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidates_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].vote = 0;
        candidates[i].eliminated = false;
    }

    voters_count = get_int("Number of voters: ");
    if (voters_count > MAX_VOTERS)
    {
        printf("The max number of voters is %d\n", MAX_VOTERS);
        return 3;
    }
    for (int i = 0; i < voters_count; i++)
    {
        for (int j = 0; j < candidates_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(i, j, name))
            {
                printf("Invalid vote\n");
                return 4;
            }
        }
        printf("\n");
    }
    while (true)
    {
        tabulate();
        bool won = print_winner();
        if (won)
        {
            break;
        }
        // Eliminate last place candidates
        int min = find_min();
        bool tie = is_tie(min);
        if (tie)
        {
            for (int i = 0; i < candidates_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break; // Adicionado para sair do loop em caso de empate
        }
        eliminate(min);
    }

    return 0;
}

int find_min(void)
{
    int min_votes = MAX_VOTERS;
    for (int i = 0; i < candidates_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].vote < min_votes)
        {
            min_votes = candidates[i].vote;
        }
    }
    return min_votes;
}

bool is_tie(int min)
{
    for (int i = 0; i < candidates_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].vote != min)
        {
            return false;
        }
    }
    return true;
}

void eliminate(int min)
{
    for (int i = 0; i < candidates_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].vote == min)
        {
            candidates[i].eliminated = true;
        }
    }
}

bool print_winner(void)
{
    int majority = voters_count / 2;
    for (int i = 0; i < candidates_count; i++)
    {
        if (candidates[i].vote > majority)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

void tabulate(void)
{
    for (int voter = 0; voter < voters_count; voter++)
    {
        for (int rank = 0; rank < candidates_count; rank++)
        {
            int voter_preference = preferences[voter][rank];
            if (!candidates[voter_preference].eliminated)
            {
                candidates[voter_preference].vote++;
                break;
            }
        }
    }
}

bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidates_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}
