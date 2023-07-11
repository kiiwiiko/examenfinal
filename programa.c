#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//funcion para corregir la falta
int CorregirOrtografia(FILE *archivoEntrada, FILE *archivoSalida) {
    char palabra[100];
    int conteoCorrecciones = 0;
//una secuencia para que el programa busque la palabra y la cambie
    while (fscanf(archivoEntrada, "%s", palabra) != EOF) {
        if (strcmp(palabra, "ecuador") == 0) {
            palabra[0] = toupper(palabra[0]);
            //se imprime la palabra Ecuador 
            fprintf(archivoSalida, "%s ", palabra);
            //contador de las faltas ortograficas
            conteoCorrecciones++;
        } else {
            fprintf(archivoSalida, "%s ", palabra);
        }
    }
//se retorna a la variable conteo de correcciones
    return conteoCorrecciones;
}

//funcion main del programa
int main() 
{
    char nombreArchivoEntrada[] = "tricolor.txt";
    char nombreArchivoSalida[] = "tricolor corregido.txt";
//Abrimos el archivo
    FILE *archivoEntrada = fopen(nombreArchivoEntrada, "r");
    FILE *archivoSalida = fopen(nombreArchivoSalida, "w");

//sentencia condicional por si hay un error al abrir el archivo XD
    if (archivoEntrada == NULL || archivoSalida == NULL) {
        printf("Error al abrir los archivos.\n");
        return 1;
    }

    int conteoTotal = CorregirOrtografia(archivoEntrada, archivoSalida);

//en esta sentencia de imprecion se puede ver que tantas faltas ortograficas ubo
    printf("Se corrigieron un total de %d palabras.\n", conteoTotal);

//Cierre del archivo
    fclose(archivoEntrada);
    fclose(archivoSalida);
    
    getch();
    return 0;
}
