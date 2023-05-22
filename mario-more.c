#include <cs50.h>
#include <stdio.h>
void printhash(int height);
int main(void)
//Gets input from the user
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    printhash(height);
}
void printhash(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int h = 0; h <= (height - (i + 2)); h++)
        {
            printf(" ");//Prints the spaces
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");//Prints the hashes
        }
        printf(" ");
        printf(" ");
        for (int a = 0 ; a <= i; a++)
        {
            printf("#");
        }
        printf("\n");//Prints the newline after everyrow
    }

}
