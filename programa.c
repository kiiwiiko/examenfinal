#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//funcion para corregir la falta
int CorregirOrtografia(FILE *archivoEntrada, FILE *archivoSalida) {
    char palabra[100];
    int conteoCorrecciones = 0;

    while (fscanf(archivoEntrada, "%s", palabra) != EOF) {
        if (strcmp(palabra, "ecuador") == 0) {
            palabra[0] = toupper(palabra[0]);
            fprintf(archivoSalida, "%s ", palabra);
            conteoCorrecciones++;
        } else {
            fprintf(archivoSalida, "%s ", palabra);
        }
    }

    return conteoCorrecciones;
}

//funcion main del programa
int main() 
{
    getch();
    return 0;
}
