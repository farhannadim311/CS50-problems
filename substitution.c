#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define BUFF_SIZE 1024
bool validate_key(string s);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        //Checks if there is the correct number of arguements present in the CLI
        printf("Usage : %s key\n", argv[0]);
        return 1;
    }
    if (validate_key(argv[1]) == false)
    {
        //Calls the function which checks if the key is valid or not
        return 1;
    }
    string plain_text = get_string("plaintext: ");
    int length = strlen(plain_text);
    char alphabets[BUFF_SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; //Array which stores all the alphabets
    int index = 0;
    char temp_text[BUFF_SIZE];
    for (int i = 0 ; i < length ; i++)
    {
        temp_text[i] = tolower(plain_text[i]); //Made all the letters small in the temporary variable so it matches the alphabets array
    }
    printf("ciphertext: ");
    for (int i = 0 ; i < length ; i++)
    {
        while (temp_text[i] != alphabets[index] && isalpha(plain_text[i]) != 0)
            //Checks whether or not it is an alphabet and finds the index in which the alphabet matches with the plaintext
        {
            index++;
        }
        if (isupper(plain_text[i]) != 0)   //Keeps it uppercase if the original plaintext was uppercase
        {
            plain_text[i] = argv[1][index];
            plain_text[i] = toupper(plain_text[i]);
        }
        else if (islower(plain_text[i]) != 0)   //Keeps it lowercase if the original plaintext was lowercase
        {
            plain_text[i] = argv[1][index];
            plain_text[i] = tolower(plain_text[i]);
        }

        index = 0;
        printf("%c", plain_text[i]);
    }
    printf("\n");


}
bool validate_key(string s)
{
    int length = strlen(s);
    if (length != 26)   //Checks for the number of characters in the key
    {
        printf("Key must contain 26 characters\n");
        return false;
    }
    for (int i = 0 ; i < length ; i++)
    {
        if (isalpha(s[i]) == 0) //Checks whether the key only contains alphabets
        {
            printf("Key must contain 26 alphabets\n");
            return false;
        }
    }
    for (int i = 0 ; i < length ; i++)
    {
        for (int j = (i + 1) ; j < length ; j++)
            //Checks whether or not all the alphabets are different or not by looping through each of them
        {
            if (s [i] == s[j])
            {
                printf("Key cannot contain repeated characters\n");
                return false;
            }
        }
    }
    return true;

}
