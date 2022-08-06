#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, row;
    do
    {
        height = get_int("Height: ");
    }

    while (height < 1 || height > 8);

    for (row = 1; row <= height; row++)  //atau for (row= 0; row < height; row++)
    {
        //Print spasi
        for (int k = 1; k <= height - row; k++)
        {
            printf(" ");
        }

        //Print hashtag untuk kolom
        for (int j = 1; j <= row; j++)   //for (int j = 0; j < row; j++)
        {
            printf("#");
        }

        printf(" ");
        printf(" ");

        for (int j = 1; j <= row; j++)   //for (int j = 0; j < row; j++)
        {
            printf("#");
        }

        printf("\n");
    }

}