#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int count_letter = 0;
    int count_word = 0;
    int count_sentence = 0;

    string s = get_string("Text: ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            count_letter += 1;
        }
    }

    for (int j = 0, n = strlen(s); j < n; j++)
    {
        if (isspace(s[j]))
        {
            count_word++;
        }
    }

    for (int k = 0, n = strlen(s); k < n; k++)
    {
        if (s[k] == '.' || s[k] == '!' || s[k] == '?')
        {
            count_sentence++;
        }
    }

    //Count index number
    count_word++;
    float L = (100 * (float) count_letter) / (float) count_word;
    float S = (100 * (float) count_sentence) / (float) count_word;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade %d\n", index);
    }
}
