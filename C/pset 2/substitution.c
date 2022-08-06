#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) //Prompt user for key
{
    int count_key_character = 0; //must be all letters  (global variable)
    int count_repeated_character = 0; //must not contained repeated character

        if (argc == 2)
        {
            for (int i = 0, n = strlen(argv[1]); i < n; i++) //must be all letters
            {
                if (isalpha(argv[1][i]))
                {
                    count_key_character += 1;
                }
            }

            for (int j = 0, n = strlen(argv[1]); j < n; j++) // must not contained repeated characters
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (toupper(argv[1][j]) == toupper(argv[1][k]))
                    {
                        count_repeated_character++;
                    }
                }
            }

            if  (strlen(argv[1]) != 26) // must be 26 characters
            {
                printf("Key must contain 26 characters. \n");
                return 1;
            }
            else if (count_key_character !=strlen(argv[1])) //must be all letter
            {
                 printf("Key must only contain alphabetic characters. \n");
                 return 1;
            }

            else if (count_repeated_character != 0) //must not contain repeated characters
            {
                printf("Key must not contain repeated character .\n");
                return 1;
            }

            else
            {
                string plain = get_string("plaintext: "); //prompt user for plaintext
                printf("ciphertext: ");

                for (int p = 0, x = strlen(plain); p < x; p++)
                {
                    if (isalpha(plain[p]) && isupper(plain[p]))
                    {
                        int upper = (plain[p] - 65);
                        printf("%c", toupper(argv[1][upper]));
                    }

                    else if (isalpha(plain[p]) && islower(plain[p]))
                    {
                        int lower = (plain[p] - 97);
                        printf("%c", tolower(argv[1][lower]));
                    }

                    else
                    {
                        printf("%c", plain[p]);
                    }
                }
                printf ("\n");
                return 0;
            }
        }
        else
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
}

