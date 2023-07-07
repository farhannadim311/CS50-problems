#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define BUFF_SIZE 1024
bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    //Checks whether there is more than one arguement and if the arguement is strictly a number
    if (argc != 2 || !(only_digits(argv[1])))
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
        exit(0);
    }
    //Converts the arguement to an integer for use
    int value = atoi(argv[1]);
    string plain_text;
    plain_text = get_string("Plain text: ");
    int length =  strlen(plain_text);
    char cipher_text[BUFF_SIZE];
    //Calls the function to encrypt the plaintext
    for (int i = 0 ; i < length ; i++)
    {
        cipher_text[i] =  rotate(plain_text[i], value);
    }
    printf("ciphertext: ");
    //Prints out the ciphertext looping through it each time
    for (int i = 0 ; i < length ; i++)
    {
        printf("%c", cipher_text[i]);
    }
    printf("\n");
    return 0;
}
bool only_digits(string s)
{
    //Function which checks that only digits are being input
    int length = strlen(s);
    int temp; //Temporary value which is used in the loop and returns true only when the entire string is numerical
    for (int i = 0 ; i < length ; i++)
    {
        if (isdigit(s[i]) != 0)
        {
            temp = true;
        }
        else
        {
            temp = false;
        }
    }
    return temp;
}
char rotate(char c, int n)
{
    //Function which encrypts the message using the key
    if (isupper(c) != 0)
    {
        c = c - 65;
        c = (c + n) % 26; //Formula which prevents it from going beyond 'Z' or 'z' and returns the character to 'A' or 'a' when doing so
        c = c + 65;
    }
    else if (islower(c) != 0)
    {
        c = c - 97;
        c = (c + n) % 26;
        c = c + 97;
    }
    return c;
}
