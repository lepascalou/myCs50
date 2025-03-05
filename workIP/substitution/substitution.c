#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Accept a single commandline argument key from the user
// Key must be 26 characters long only alphabetical and unique, case insensitive
//

int main(int argc, string argv[])
{
  // Check if only one argument
  if (argc != 2)
  {
      printf("Usage: ./substitution key\n");
      return 1;
  }

  // Check if key is 26 characters long
  if (strlen(argv[1]) != 26)
  {
      printf("Key *must* contain 26 unique alphabetical characters\n");
      return 1;
  }
  else

  // Check if key only contains alphabetical characters
  for (int i = 0; i < strlen(argv[1]); i++)
  {
      if (!isalpha(argv[1][i]))
      {
          printf("Key *must* contain 26 unique alphabetical characters\n");
          return 1;
      }
  }
  
  // Ask a text to cypher
  string text = get_string("plaintext: ");
}
