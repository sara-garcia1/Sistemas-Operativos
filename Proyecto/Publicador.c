#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "publicador.h"

// Función que verifica el formato de cada noticia
bool validarFormatoNoticia(const char* noticia) {
    if (noticia == NULL || strlen(noticia) == 0) return false;

    // El primer carácter es el tipo de la noticia (A, B, C, D, E)
    char tipo = noticia[0];
    if (tipo != 'A' && tipo != 'B' && tipo != 'C' && tipo != 'D' && tipo != 'E') {
        return false;
    }

    // Verifica que haya un ':' después del tipo
    char* pos = strchr(noticia, ':');
    if (pos == NULL || pos == noticia || *(pos + 1) == '\0') {
        return false;
    }

    return true;
}

// Función que publica una noticia en el pipe
void publicarNoticia(int pipe, const char* noticia) {
    write(pipe, noticia, strlen(noticia) + 1);  // +1 para incluir el terminador de cadena
}

// Función principal del publicador
void ejecutarPublicador(const char* pipePSC, const char* archivoNoticias, int tiempo) {
    // Abrir el archivo de noticias
    FILE* archivo = fopen(archivoNoticias, "r");
    if (archivo == NULL) {
        fprintf(stderr, "Error al abrir el archivo de noticias.\n");
        return;
    }

    // Abrir el pipe nominal
    int pipe = open(pipePSC, O_WRONLY);
    if (pipe == -1) {
        fprintf(stderr, "Error al abrir el pipe.\n");
        return;
    }

    char linea[256];
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        // Eliminar espacios al principio y al final
        char* start = linea;
        while (*start == ' ' || *start == '\t') start++;

        char* end = linea + strlen(linea) - 1;
        while (end > start && (*end == ' ' || *end == '\n' || *end == '\t')) end--;
        *(end + 1) = '\0';  // Terminar la cadena

        // Validar la noticia
        if (validarFormatoNoticia(start)) {
            // Publicar la noticia en el pipe
            publicarNoticia(pipe, start);
        } else {
            fprintf(stderr, "Formato incorrecto en la noticia: %s\n", start);
        }

        // Esperar el tiempo especificado entre noticias
        sleep(tiempo);
    }

    // Cerrar el archivo y el pipe
    fclose(archivo);
    close(pipe);
}

