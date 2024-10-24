/****************************************************************
Nombre: Sara García
Materia: Sistemas Operativos
Fecha: 24 de Octubre de 2024
Tópico: productor-consumidor POSIX
****************************************************************/
//Librerías
#include <stdio.h>      
#include <stdlib.h>     
#include <unistd.h>     
#include <sys/types.h>  
#include <pthread.h>    

// Variables compartidas
int counter = 0;        
int max = 4;            

// Inicialización de mutex y variables de condición
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;  
pthread_mutex_t condp_mutex = PTHREAD_MUTEX_INITIALIZER;    
pthread_mutex_t condc_mutex = PTHREAD_MUTEX_INITIALIZER;    
pthread_cond_t condVarProd = PTHREAD_COND_INITIALIZER;      
pthread_cond_t condVarCons = PTHREAD_COND_INITIALIZER;     

// Declaración de funciones para el productor y el consumidor
void *productor();
void *consumidor();

int main() {
    // Arreglos para almacenar identificadores de hilos productores y consumidores
    pthread_t proHilo[max], conHilo[max];  
    int i;

    // Creación de hilos productores y consumidores
    for (i = 0; i < max; i++) {
        // Creación hilos productores
        pthread_create(&proHilo[i], NULL, &productor, NULL);
        // Crear hilos consumidores
        pthread_create(&conHilo[i], NULL, &consumidor, NULL);
    }

    // Se espera a que los hilos terminen
    for (i = 0; i < max; i++) {
        pthread_join(proHilo[i], NULL);  
        pthread_join(conHilo[i], NULL); 
    }

    return 0;
}

void *productor() {
    // Bucle infinito para los productores
    while (1) {  
        pthread_mutex_lock(&condp_mutex); 
        // Si el contador es 10 o más, el productor espera
        while (counter >= 10) {            
            pthread_cond_wait(&condVarProd, &condp_mutex);  
        }
        pthread_mutex_unlock(&condp_mutex);  

        pthread_mutex_lock(&counter_mutex);  
        // Incrementar el contador
        counter++;                           
        pthread_cond_signal(&condVarCons);   
        printf("Soy productor %lu valor contador = %d\n", (unsigned long)pthread_self(), counter); 
        pthread_mutex_unlock(&counter_mutex);  

        // Si el contador alcanza 5, el productor duerme por 1 segundo
        if (counter == 5) {  
            sleep(1);
        }
    }
}

void *consumidor() {
    // Bucle infinito para los consumidores
    while (1) {  
        sleep(1);  
        pthread_mutex_lock(&condc_mutex);  
        pthread_cond_signal(&condVarProd); 
        pthread_cond_wait(&condVarCons, &condc_mutex);  
        pthread_mutex_unlock(&condc_mutex);  
        pthread_mutex_lock(&counter_mutex); 

        // Si el contador es mayor que 0, el consumidor puede consumir
        if (counter > 0) {  
            // Se muestra el estado del contador
            printf("Soy consumidor %lu valor contador = %d\n", (unsigned long)pthread_self(), counter); 
            // Se decrementa el contador
            counter--;  
            pthread_cond_signal(&condVarProd);  
        }
        pthread_mutex_unlock(&counter_mutex);  
    }
}

