// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE; //mendefinisikan satu byte
typedef int16_t SAMPLE; // mendefinisikan 2 byte
// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]); //converting that factor to floating point number like 2.0, 0.5

    // TODO: Copy header from input file to output file
    BYTE header_buffer[HEADER_SIZE]; //nama buffer / nama array sementara adalah header_buffer
    fread(header_buffer, sizeof(BYTE), HEADER_SIZE, input); //bacalah file yg brnama: input, sebanyak HEADER_SIZE(44 bytes) -
                                                            // sizenya dalam BYTE(spesifik 44 bytes) ke header_buffer
    fwrite(header_buffer, sizeof(BYTE), HEADER_SIZE, output);

    // TODO: Read samples from input file and write updated data to output file
    SAMPLE buffer;
    while (fread(&buffer, sizeof(SAMPLE), 1, input)) //karna buffer adalah variable maka ada ampersand (&) untk menuju address
    {
        //update volume
        buffer = buffer * factor; //buffer dikalikan factor untuk update volume sesuai factor
        fwrite(&buffer, sizeof(SAMPLE), 1, output);
    }


    // Close files
    fclose(input);
    fclose(output);
}
