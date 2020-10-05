#include <stdio.h>
#include <math.h>
#include <cs50.h>

int change_owed(int change);

int main(void)
{
    
    // Prompt user for input. get_float and check for only positive values.
    float change = 0;
    do
    {
        change = get_float("Change Owed: ");
        
    }
    while (change < 0.0);
    
    // Convert floating point value to int to avoid errors in calculations.
    int cents = round(change * 100);
    
    // Call change_owed function with the change already converted. It will return an int after it is done computing.
    int coins = change_owed(cents);
    
    // Print the number of coins the customer will receive
    printf("%i\n", coins);
    
    return 0;
}

int change_owed(change)
{
    
    int quarter = 25, dime = 10, nickel = 5, penny = 1, coins = 0, cents = change;
    
    // In case we have a user who is trying to be funny, we return a value of zero.
    if (cents == 0)
    {
        return 0;
    }
    
    // As long as the value of change is greater than 25, use a quarter
    while (cents >= quarter)
    {
        cents -= quarter;
        coins++;
    }
    
    // Greater than 10, use a dime
    while (cents >= dime)
    {
        cents -= dime;
        coins++;
    }
    
    // Greater than 5, use a nickel
    while (cents >= nickel)
    {
        cents -= nickel;
        coins++;
    }
    
    // Greater than 1, use a penny
    while (cents >= penny)
    {
        cents -= penny;
        coins++;
    }

    
    return coins;
    
    
    
}