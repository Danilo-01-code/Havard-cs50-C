#include <stdio.h>
#include <ctype.h>
#include <cs50.h>  

#define BUFFER_SIZE 256

// Function to cipher using the key
void cipher(int key, const char *texto, char *resultado) {
    for (int i = 0; texto[i] != '\0'; i++) {
        char char_at = texto[i];
        if (isalpha(char_at)) {
            char offset = isupper(char_at) ? 'A' : 'a';
            resultado[i] = (char)((char_at - offset + key) % 26 + offset);
        } else {
            resultado[i] = char_at;
        }
    }
    resultado[strlen(texto)] = '\0'; 
}

int main() {
    int key = get_int("Key: ");
    char *texto = get_string("Text: ");
    char resultado[BUFFER_SIZE];

    cipher(key, texto, resultado);
    printf("%s\n", resultado);

    return 0;
}
