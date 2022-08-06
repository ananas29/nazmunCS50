#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1; //karna ./plurality tdk dihitung
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1]; //ditambah satu agar ./plurality tdk terhitung
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{                                               // candidate_count adlh jumlah kandidat di list - 1 (argc - 1)
    for(int i = 0; i < candidate_count; i++) //menghitung jumlah vote masing2 kandidat
    {
        if(strcmp(candidates[i].name, name) == 0) //name yg kedua adalah get string name (kandidat yg divote)
        {                                       //membandingkan nama kandidat yg ditulis dengan yg di list command line
             candidates[i].votes++;
             return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int max_votes = -1; //umpamanya max vote adlh -1, nnti dibandingkan dgn jumlh masing2 kandidat yg diupdate terus smpai mencapai vote tertinggi

    for(int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes >= max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}

