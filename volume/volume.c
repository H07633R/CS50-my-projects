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

    uint8_t header[44];            // Буфер куда будет помещаться считаная информация с функции fread, для последующей передачи в буфер читающего файла
    fread(header, 44, 1, input);   // Функция для чтения файла и сохранения инфы в буфер
    fwrite(header, 44, 1, output); // Функция записи из буфера в новый файл

    // TODO: Read samples from input file and write updated data to output file

    int16_t buffer;                                   // Буфер, в данном случае это диапазон громкости состоящий из битов
    while (fread(&buffer, sizeof(int16_t), 1, input)) // Функция из библиотеки
    {
        buffer *= factor;                            // буфер умножаем на значение фактора, значит повышаем или уменьшаем громкость файла
        fwrite(&buffer, sizeof(int16_t), 1, output); // записываем это в исходящий файл
    }

    // Close files
    fclose(input);
    fclose(output);
}
