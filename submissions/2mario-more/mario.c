#include <cs50.h>
#include <stdio.h>

// Declare function draw_pyramid
void draw_pyramid(int height);

// Declare function to limit input to integers between 1 and 8
int get_positive_int(void);

int main(void)
{
    // Prompt the user with the help of get_int, integer must be within 1-8
    int height = get_positive_int();

    // Draw the pyramid with a self made function
    draw_pyramid(height);
}

void draw_pyramid(int height)
{
    // Draw row and iterate : [spaces - hashes] - [2 spaces] - [hashes], problem of blank line when
    // starting index i at 0
    for (int i = 1; i < height + 1; i++)
    {
        // Number of spaces == height minus the number of the row we're printing
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        // Hashes
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        // Two spaces
        printf("  ");
        // Right part of the pyramid
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_positive_int(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    return h;
}
