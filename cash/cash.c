#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}
int get_cents(void)
{
    // Создаём значение "центы"
    int cents;
    do // Создаём луп
    {
        cents = get_int("Переведу твои центы в количество монеток без смс и регистрации: "); // Вопрос к пользователю о наличии при нём бабок
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    // Фунция для четвертаков
    int quarters = 0; // Изначальное количество
    while (cents >= 25)
    {
        cents = cents - 25;
        quarters++; // ++ значит что значение будет добавляться, пока не нарушит "while"
    }
    return quarters; // Выходные данные
}

int calculate_dimes(int cents)
{
    // Функция для червонцев
    int dimes = 0;
    while (cents >= 10)
    {
        cents = cents - 10;
        dimes++; // ++ значит, что каждые 10 значений (10 центов) переводятся в 1 монетку червонца
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    // Функция для пятаков
    int nickels = 0;
    while (cents >= 5)
    {
        cents = cents - 5;
        nickels++;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    // Функция для пенни
    int pennies = 0;
    while (cents >= 1)
    {
        cents = cents - 1;
        pennies++;
    }
    return pennies;
}