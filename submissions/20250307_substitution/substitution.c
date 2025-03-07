#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool isvalid(string key);
void cypher(string text, string key);

int main(int argc, string argv[]) 
{
    // Check if only one argument, if not print error message
    if (argc != 2) 
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Check if key is valid, if not print explicit error message
    if (!isvalid(argv[1])) 
    {
        printf("Key must contain 26 unique alphabetical characters\n");
        return 1;
    }
    // Ask a text to cypher
    string text = get_string("plaintext: ");
    
    string key = argv[1];

    // Print cyphered text with cypher call
    cypher(text, key);
}

bool isvalid(string key) 
{
    // We need 26 characters
    if (strlen(key) != 26) 
    {
        return false;
    }
    // Only alphabetical characters
    for (int i = 0; i < 26; i++) 
    {
        if (!isalpha(key[i])) 
        {
            return false;
        }
    }
    // Check if all characters are different, there must be a more efficient way
    char lower_key[26];
    for (int i = 0; i < 26; i++) 
    {
        // Make all characters lowercase to effectively compare
        lower_key[i] = tolower(key[i]);
    }
    for (int i = 0; i < 26; i++) 
    {
        for (int j = i + 1; j < 26; j++) 
        {
            if (lower_key[i] == lower_key[j]) 
            {
                return false;
            }
        }
    }
    return true; 
}
void cypher(string text, string key) 
{
    // Print cyphered text
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++) 
    {
        if (isalpha(text[i])) 
        {
            char c = text[i];
            // Get the position of the letter in the key
            if (islower(c)) 
            {
                printf("%c", tolower(key[c - 'a']));
            }
            else if (isupper(c))
            {
                printf("%c", toupper(key[c - 'A']));
            }
        }
        else 
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
