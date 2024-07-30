#include <stdio.h>
#include <cs50.h>

// Função para imprimir a pirâmide
void pyramid(int height) {
    // Itera sobre cada linha da pirâmide
    for (int i = 1; i <= height; i++) {
        // Define os espaços antes dos hashes
        for (int j = 0; j < height - i; j++) {
            printf(" ");
        }
        // Imprime os hashes do lado esquerdo5 
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        // Espaço entre os dois lados da pirâmide
        printf("  ");
        // Imprime os hashes do lado direito
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        // Vai para a próxima linha
        printf("\n");
    }
}

int main(void) {
    int height;
    // Solicita a altura da pirâmide
    do {
        height = get_int("Height: ");
    } while (height < 1 || height > 8); // Garantir que a altura seja entre 1 e 8

    // Chama a função que imprime a pirâmide
    pyramid(height);
    return 0;
}
