#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)   // dollars, cents, coins
{
    float dollars;
    do 
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars <= 0);

    int cents = round(dollars * 100);
    int coins = 0;

    while (cents > 0) //not equal to zero  while (cents != 0)
    {
        //25
        coins = coins + cents / 25;
        cents = cents % 25;    //misal 75 cent habis dibagi 25 (modulo= %)  

        //10
        coins += cents / 10;
        cents %= 10;

        //5
        coins += cents / 5;
        cents %= 5;

        //1
        coins += cents / 1;
        cents %= 1;
    }
    printf("Coins: %i\n", coins);

    //printf("Coins: %i, Cent now: %i\n", coins, cents);
}