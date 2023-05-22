#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Gets username and says hello
    string name = get_string("What's your name?: ");
    printf("hello, %s\n", name);
}
