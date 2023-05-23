#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long div = 0;
    long digits = 0;
    long credit_card = get_long("Number: ");
    int mod = 0;
    int n = 10;
    int checksum = 0;
    int c = 0;
    int last_digit = 0;
    int first_digit = 0;
    long temp = 0;
    int sum = 0;
    long check_card = 0;
    long check_visa = 0;

    div = credit_card; //Calculates the digits of the credit card number
    while (div != 0)
    {
        div = div / 10;
        digits++;
    }
    temp = credit_card;
    for (int i = 0; i < digits; i++)  //Calculates the intermediate checksum
    {
        temp = temp / 10;
        mod = temp % 10;
        if (mod * 2 >= 10)
        {
            c = mod * 2;
            last_digit = c % 10;
            c = c / 10;
            first_digit = c % 10;
            mod = 0;
        }
        checksum = mod * 2 + checksum + last_digit + first_digit;
        last_digit = 0;
        first_digit = 0;
        temp = temp / 10;

    }
    temp = credit_card;
    for (int i = 0; i < digits; i++)  //Calculates the final checksum
    {
        mod = temp % 10;
        temp = temp / 100;
        sum = sum + mod;
    }
    checksum = sum + checksum;
    check_card = credit_card;
    for (int i = 0; i < (digits - 2) ; i++) //Isolates the final two digits of the card to check for AMEX or Mastercard
    {
        check_card = check_card / 10;

    }
    check_visa = credit_card;
    for (int i = 0 ; i < (digits - 1); i++)  //Isolates the final digit to check for VISA
    {
        check_visa = check_visa / 10;
    }
    if (checksum % 10 != 0 || (digits < 13 || digits > 16)) // Checks if the card is INVALID OR NOT
    {
        printf("INVALID\n");
    }
    else if (checksum % 10 == 0 && (check_card == 34 || check_card == 37)) //Checks if the card is AMEX or not
    {
        printf("AMEX\n");
    }
    else if (checksum % 10 == 0 && (check_card >= 51 && check_card <= 55)) //Checks if the card is MASTERCARD OR NOT
    {
        printf("MASTERCARD\n");
    }
    else if (checksum % 10 == 0 && check_visa == 4)  //CHECKS IF THE CARD IS VISA OR NOT
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
