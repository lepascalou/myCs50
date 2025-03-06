#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool is_valid_key(string key);
void encipher(string text, string key);

int main(int argc, string argv[])
{
    // Vérifie que la clé est fournie et valide
    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    string key = argv[1];
    string text = get_string("plaintext: ");

    encipher(text, key);

    printf("ciphertext: %s\n", text);
    return 0;
}

bool is_valid_key(string key)
{
    if (strlen(key) != 26)
    {
        return false;
    }

    int letter_count[26] = {0};

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = tolower(key[i]) - 'a';
        letter_count[index]++;

        if (letter_count[index] > 1)
        {
            return false;
        }
    }

    return true;
}

void encipher(string text, string key)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            char c = text[i];
            char offset = islower(c) ? 'a' : 'A';
            int index = tolower(c) - 'a';

            // Remplacer par la lettre correspondante de la clé
            char substituted_char = key[index];

            // Conserver la casse originale
            if (isupper(c))
            {
                substituted_char = toupper(substituted_char);
            }

            text[i] = substituted_char;
        }
    }
}

