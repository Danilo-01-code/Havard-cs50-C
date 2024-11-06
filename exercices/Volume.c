#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// One 44 byte header
// Many 2 byte samples

const int HEADER_SIZE = 44;

typedef uint8_t BYTE;
typedef int16_t SAMPLE_AUDIO; //16 bits integer
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        printf("Could not open the input file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        printf("Could not open the output file.\n");
        fclose(input);
        return 1;
    }

    float factor = atof(argv[3]);

    BYTE headerBuffer[HEADER_SIZE];
    fread(headerBuffer, sizeof(BYTE), HEADER_SIZE, input);
    fwrite(headerBuffer, sizeof(BYTE), HEADER_SIZE, output);

    SAMPLE_AUDIO buffer;
    while (fread(&buffer, sizeof(SAMPLE_AUDIO), 1, input) == 1) {
        buffer = (SAMPLE_AUDIO)(buffer * factor);
        fwrite(&buffer, sizeof(SAMPLE_AUDIO), 1, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}
