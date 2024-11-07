#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Declaración e inicialización de variable global 
int turno = 0;  

// Mutex para proteger la variable turno
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Función para ejecutar cada hilo
void *contar(void *arg) {
    // Se obtiene el id del hilo
    intptr_t hilo_id = (intptr_t)arg;  
    //Se imprime
    printf("Hilo %ld creado\n",hilo_id);

    // Bucle 
    while (1) {
        // Adquirir el mutex para acceder a turno
        pthread_mutex_lock(&mutex); 
 
        //El hilo inicia si es su turno
        if (turno == hilo_id - 1) {  
            //Imprime que se ha iniciado el hilo
            printf("Hilo %ld iniciado\n", hilo_id);

            // Bucle que cuenta hasta 300
            for (int i = 0; i < 300; i++) {
                // Se simulan 5 milisegundos de espera 
                usleep(500); 
                //Se imprime que el hilo esta en progreso
                printf("Hilo %ld en progreso\n",hilo_id);
            }

            //Se imprime cuando el hilo ha terminado
            printf("Hilo %ld finalizado\n", hilo_id);
            //Aumenta contador para dar paso al siguiente hilo
            turno++;  
            //Se libera mutex 
            pthread_mutex_unlock(&mutex);  
            //Fin hilo
            break;  
        }

        pthread_mutex_unlock(&mutex); 
        usleep(100);
    }

    return NULL;
}

int main() { 
  
    //Arreglo que almacena los hilos
    pthread_t hilos[5];  
    //Arreglo que almacena id de cada hilo
    intptr_t ids[5] = {1, 2, 3, 4, 5}; 

    //Se crean 5 hilos
    for (int i = 0; i < 5; i++) {
        if (pthread_create(&hilos[i], NULL, contar, &ids[i]) != 0) {
            printf("Error al crear el hilo\n");
            return 1;
        }
    }

    
    for (int i = 0; i < 5; i++) {
        pthread_join(hilos[i], NULL);
        printf("Hilo creado correctamente\n");
    }
  return 0;

}
