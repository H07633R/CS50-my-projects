#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool digit(string argv);
char rotate(char c, int intargv);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
      for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (digit(argv[1]) != false)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else if (!isdigit(argv[1][i]))
        {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    }

    int intargv = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, size = strlen(plaintext); i < size; i++)
{
    char x = rotate(plaintext[i], intargv);
    printf("%c", x);
}
    printf("\n");
    return 0;
}
bool digit(string argv)
{
    for ( int i = 0, size = strlen(argv); i < size; i++)
    {
        if (!isdigit(argv[i]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return 0;
}
char rotate(char c, int intargv)
{
    for ( int i = 0, size = 1; i < size; i++)
    if (c >= 'a' && c <= 'z')
    {
        c = (((int)c - (int)'a' + intargv) % 26) + 'a';
    }
    else if (c >= 'A' && c <= 'Z')
    {
        c = (((int)c - (int)'A' + intargv) % 26) + 'A';
    }
      return c;
}