#include <cs50.h>

#include <stdio.h>

#include <string.h>

#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) // Правильность ввода
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = i + 1; j < strlen(key); j++)
        {
            if (toupper(key[i]) == (key[j]))
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }
        }
    }

    string plaintext = get_string("Plaintext: ");
    for (int i = 0; i < strlen(key); i++) // Конвертирование всех букв в большие
    {
        if (islower(key[i]))
        {
            key[i] = key[i] - 32;
        }
    }

    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++) // Работа с большими и маленькими буквами
    {
        if (isupper(plaintext[i])) // В случае, если буквы большие
        {
            int letter = plaintext[i] - 65; // 65 это порядкой номер первой большой буквы в ASCII
            printf("%c", key[letter]);
        }
        else if (islower(plaintext[i]))
        {
            int letter = plaintext[i] - 97; // 97 номер первой маленькой буквы
            printf("%c", key[letter] +
                   32); // 32 здесь для того, чтобы обратно вернуть в lower case (65 + 32 = 97)
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}