#include "helpers.h"  //  ./filter -s images/yard.bmp sepiayard.bmp . TAMBAHIN IMAGES UNTUK BUKA GAMBAR
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) //2 dimensional array
{
    for (int i = 0; i < height; i++)    //RGBTRIPLE adalah nama struct nya
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            //calculate the average value of each pixel, rounded
            int average = round(((float)red + (float)blue + (float)green) / 3);

            //set the calculated average to be the new value of each pixel
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
            int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
            int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);
            {
                image[i][j].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;
                image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
                image[i][j].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
            }
        }
    }

    return;
}

// Reflect image horizontally //  yang dibalik adalah width
void reflect(int height, int width, RGBTRIPLE image[height][width])  //int temp = image[i][j];
                                                                    // image[i][j] = image[total - (i + 1)];
                                                                    // image[i][total - (i + 1)] = temp;
{
    for (int i = 0; i < height; i++)
    {
        // iterate through the array until you get to the mid-point
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            //swap half of image dengan width - j + 1
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //membuat temporary image yg berisi blur image dari original image
    RGBTRIPLE temp[height][width];

   for (int i = 0; i < height; i++)
   {
       for (int j = 0; j < width; j++)
       {
           float totalRed, totalGreen, totalBlue;
           totalRed = totalGreen = totalBlue = 0;
           float counter = 0.00;

           //get neighbour pixels (pake tanda nbr)
           for (int x = -1; x < 2; x++)
           {
               for (int y = -1; y < 2; y++)
               {
                   int nbrX = i + x; //ini adalah rumus untuk menemukan apakah pixel itu ada di dalam atau diluar box image
                   int nbrY = j + y;

                   //check for valid neighbouring pixels
                   if (nbrX < 0 || nbrX > (height - 1) || nbrY < 0 || nbrY > (width - 1)) //ketika ada diluar box maka continue
                   {
                       continue; //skip
                   }
                   //get the image value (menambah total red,blue,green dgn pixel diluar box)

                   totalRed = totalRed + image[nbrX][nbrY].rgbtRed;
                   totalGreen += image[nbrX][nbrY].rgbtGreen;
                   totalBlue += image[nbrX][nbrY].rgbtBlue;

                   counter++;
               }

               //menghitung rata2 image temporary menjadi blur (sdh ditambah dgn pixel diluar box/ neighbour pixel)
                temp[i][j].rgbtRed = round(totalRed / counter);
                temp[i][j].rgbtGreen = round(totalGreen / counter);
                temp[i][j].rgbtBlue = round(totalBlue / counter);
           }
       }
   }

   // memindahkan temporary blur image ke original image
   for (int i = 0; i < height; i++)
   {
       for (int j = 0; j < width; j++)
       {
           image[i][j].rgbtRed = temp[i][j].rgbtRed;
           image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
           image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
       }
   }
    return;
}
