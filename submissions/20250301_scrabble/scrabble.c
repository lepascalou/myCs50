#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Array assigning a value to each letter
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Prototype scroe function
int calculate_score(string word);

int main(void)
{
    // Prompt 2 players for a word
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Calculate scores
    int score1 = calculate_score(word1);
    int score2 = calculate_score(word2);

    // Who wins ?
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int calculate_score(string word)
{
    int score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Only calculate score if we have a letter
        if (isalpha(word[i]))
        {
            // Lower every letter to avoid checking every char (a = 97 in ASCII)
            score += POINTS[tolower(word[i]) - 'a'];
        }
    }
    return score;
}
