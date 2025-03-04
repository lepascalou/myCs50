#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>



int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Provide a word !\n");
        return 1;
    }

    // User's input
    string text = argv[1];
    int len = strlen(text);

    // Check only letters


    // Iterate string
    for (int i = 1; i < len; i++)
    {
        if (!isalpha(text[i]))
        {
            printf("Only letters\n");
            return 2;
        }
        if (text[i] < text[i -1])
        {
            printf("No\n");
            return 0;
        }
    }

    // Print out yes or no
    printf("Yes\n");
}
