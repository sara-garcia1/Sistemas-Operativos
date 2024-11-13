#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "publicador.h"

int main(int argc, char* argv[]) {
    const char* pipePSC = NULL;
    const char* archivoNoticias = NULL;
    int tiempo = 0;

    // Procesar los argumentos de la línea de comandos
    int opt;
    while ((opt = getopt(argc, argv, "p:f:t:")) != -1) {
        switch (opt) {
            case 'p':
                pipePSC = optarg;
                break;
            case 'f':
                archivoNoticias = optarg;
                break;
            case 't':
                tiempo = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Uso incorrecto de los argumentos.\n");
                return 1;
        }
    }

    // Verificar que los argumentos sean válidos
    if (pipePSC == NULL || archivoNoticias == NULL || tiempo <= 0) {
        fprintf(stderr, "Faltan argumentos necesarios.\n");
        return 1;
    }

    // Ejecutar el publicador con los argumentos proporcionados
    ejecutarPublicador(pipePSC, archivoNoticias, tiempo);

    return 0;
}

