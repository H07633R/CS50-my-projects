// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
uint8_t header[44];

FILE *input = fopen("input.wav", "r");
    if (input == NULL)
    {
        return 1;
    }

    FILE *output = fopen("output.wav", "w");
    if (output == NULL)
    {
        fclose(input);
        return 1;
    }

    while (fread(header, sizeof(int), 44, input) != EOF)             // EOF?
    {
        fwrite(header, sizeof(int), 44, output);
    }

    fclose(input);
    fclose(output);


    // TODO: Read samples from input file and write updated data to output file

    // Close files
    fclose(input);
    fclose(output);
}