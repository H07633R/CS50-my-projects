#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n; // Создаём переменную для высоты
    do // Создаём наш do while loop
    {
        n = get_int("Height: "); // Запрашиваем высоту у пользователя
    }
    while (n < 1 || n > 8); // Создаём условие для формата пирамиды
    for (int i = 0; i < n; i++) // Строим её высоту и for loop (for loop сокращает do while loop до кода в одну строку)
    {
        for (int j = 0; j < n; j++) // Здесь for loop для строк
        {
            if (i + j < n - 1) // Формула для пустых пробелов
            {
                printf(" ");
            }
            else // Принт для кирпичиков где нету пробелов
            {
                printf("#");
            }
        }
        printf("\n"); // Принт для каждой новой строки пирамиды
    }
}