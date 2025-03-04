#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);
int calculate_coins(int cents, int coin_value);

int main(void)
{
    // Prompt user for positive integer
    int cents = get_positive_int();

    // Calculate number of coins for each denomination and update value of cents
    // There might be a way to update this value from within the function  calculate_coins ?
    int quarters = calculate_coins(cents, 25);
    cents = cents - quarters * 25;
    int dimes = calculate_coins(cents, 10);
    cents = cents - dimes * 10;
    int nickels = calculate_coins(cents, 5);
    cents = cents - nickels * 5;
    int pennies = calculate_coins(cents, 1);

    // Sum up number of coins
    printf("%i\n", quarters + dimes + nickels + pennies);
}

int get_positive_int(void)
{
    int c;
    do
    {
        c = get_int("Change owed: ");
    }
    while (c < 0);
    return c;
}

int calculate_coins(int cents, int coin_value)
{
    int coins = 0;
    while (cents >= coin_value)
    {
        coins++;
        cents = cents - coin_value;
    }
    return coins;
}
