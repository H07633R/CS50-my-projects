#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Запрашивает имя пользователя
    string name = get_string("What's your name?\n");
    // Выводит на экран имя пользователя
    printf("Hello, %s\n", name);
}