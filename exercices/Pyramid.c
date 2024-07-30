#include <stdio.h>
#include <cs50.h>

// Function to print pyramid
void pyramid(int height) {
    // Itera each pyramid row
    for (int i = 1; i <= height; i++) {
        // Spaces before Hashs
        for (int j = 0; j < height - i; j++) {
            printf(" ");
        }
        // Print hashes from the left side
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        //Space between the two pyramid sides
        printf("  ");
        // Print hashes from the right side
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        // Go to the next row
        printf("\n");
    }
}

int main(void) {
    int height;
    // Asks piramid Height
    do {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);

    // Call function 
    pyramid(height);
    return 0;
}
