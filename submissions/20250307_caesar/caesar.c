#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
void rotate(string text, int key);

int main(int argc, string argv[])
{
    // Check if only one argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if key only contains digits
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!only_digits(argv[1]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert key to int
    int key = atoi(argv[1]);

    // Ask a text to cypher
    string text = get_string("plaintext: ");

    // Print cyphered text with rotate call
    rotate(text, key);
}

// Check if string only contains digits (not sure I should need to use a loop again?)
// Return true or false
bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Rotate text
void rotate(string text, int key)
{
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        // Check if char is a letter
        if (isalpha(text[i]))
        {
            char c = text[i];
            // keep case
            if (islower(c))
            {
                // Modulo 26 to cycle through the alphabet, substract 'a' to get the index, add key
                // and add 'a' again
                c = ((c - 'a' + key) % 26) + 'a';
            }
            else if (isupper(c))
            {
                c = ((c - 'A' + key) % 26) + 'A';
            }
            // Print char rotated
            printf("%c", c);
        }
        else
        {
            // Print char untouched
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
