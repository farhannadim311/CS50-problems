#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
int count_letters(string text);
int count_words(string text);
int count_sentence(string text);

int main(void)
{
    string text_user = get_string("Text: ");
    int letters = count_letters(text_user);
    int words = count_words(text_user);
    int sentence = count_sentence(text_user);
    double l = ((float)letters / (float)words) * 100;
    double s = ((float)sentence / (float)(words)) * 100;
    //Does the calculation for the index
    int index = round((float)0.0588 * (float)l - (float)0.296 * (float)s - (float)15.8);
    //Checks the index and matches it with the appropriate reading level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}
int count_letters(string text)
{
    //Counts the number of letters in the string
    int length = strlen(text);
    int letter_count = 0;
    for (int i = 0 ; i < length ; i++)
    {
        if (isalpha(text[i]) != 0) //Checks if the character is alphabetic
        {
            letter_count++;
        }
    }
    return letter_count;
}
int count_words(string text)
{
    //Counts the number of words in the string
    int length = strlen(text);
    int word_count = 0;
    for (int i = 0 ; i < length ; i++)
    {
        if (isblank(text[i]) != 0) //Checks spaces between the characters for indication of a different word
        {
            word_count++;
        }
    }
    return word_count + 1;

}
int count_sentence(string text)
{
    //Counts the number of sentences in the string
    int length = strlen(text);
    int sentence_count = 0;
    for (int i = 0 ; i < length ; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') //Checks these punctutation for an indication of a new sentence
        {
            sentence_count++;
        }
    }
    return sentence_count;
}
