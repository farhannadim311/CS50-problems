#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string message = get_string("Message: ");
    int binary[BITS_IN_BYTE];
    int length = strlen(message);
    int temp = 7;
    for (int i = 0 ; i < length ; i++)
    {
        while (((float)message[i] / (float) 2) != 0)
        {
            //Converts the string to binary
            binary[temp] = message[i] % 2;
            message[i] = message[i] / 2;
            temp--;
        }
        for (int j = 0 ; j < BITS_IN_BYTE; j++)
        {
            //Calls the function to print the string as light bulbs
            print_bulb(binary[j]);
        }
        printf("\n"); //Prints a newline for each character
        for (int k = 0 ; k < BITS_IN_BYTE; k++)
        {
            //Resets the array for the next character
            binary[k] = 0;
        }
        temp = 7;//Resets the temporary value to be used in the loop again
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
