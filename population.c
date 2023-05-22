#include <stdio.h>
#include <cs50.h>
int main(void)
{
    //Gets the initial size
    int initial_size, target;
    do
    {
        initial_size = get_int("Start size: ");
    }
    while (initial_size < 9);
    //Gets the target size
    do
    {
        target = get_int("End size: ");
    }
    //The math for the years it will take to reach the desired population
    while (target < initial_size);
    int age = 0;
    while (initial_size < target)
    {
        initial_size = (initial_size / 3 + initial_size) - initial_size / 4;
        age++;
    }
    printf("Years: %i\n", age);
}
