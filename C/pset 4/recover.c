#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover ...");
        return 1;
    }

     // Open file for reading/ buka memory card
    FILE *input_file = fopen(argv[1], "r");

    if (input_file == NULL) // atau if (!input_file)
    {
        printf("Error: cannot open the file");
        return 2;
    }

    //siapakan buffer sebesar 512 bytes untuk cadangan
    unsigned char buffer[512]; //memiliki nilai 0-255 atau sm dgn tipe data byte, nilai awalnya -1

    //untuk meghitung image selanjutnya dari loop
    int count_image = 0;

    //Penunjuk file yg digunakan untuk mengeluarkan data yang didapat dari file input (input_file)
    FILE *output_file = NULL;

    char *filename = malloc(8 * sizeof(char));  //char filename[8]; / emg rata2 pake 8 bit/1 byte

    //Membaca 512 byte dari input_file lalu disimpan di buffer
    while(fread(buffer, sizeof(char), 512, input_file))
    {
        //cek apakah bytes dimulai dgn aturan JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // stlh image didapat, tulis setiap file jpg dgn format 001.jpg, 002.jpg, dst...
            sprintf(filename, "%03i.jpg", count_image);

            //open output_file untuk writing (membuka lokasi output file untuk image terlebih dahulu)
            output_file = fopen(filename, "w"); //im opening output_file using filename (dgn memory yg ada di filename)

            // menghitung julah image yg ditemukan
            count_image++;
        }

        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
            // i'm writing from that buffer, size of buffer char, yaitu 512 bytes ke output file
        }

    }
    free(filename);
    fclose(output_file);
    fclose(input_file);

    return 0;
}







