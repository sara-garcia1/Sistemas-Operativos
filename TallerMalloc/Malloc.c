/********************************************************************************************
Estudiante en formación: Sara Valentina García 
Materia: Sistemas Operativos
Fecha: 8/08/24
Tópico: Uso de malloc en codigo de c
 ********************************************************************************************/
//Librerías
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

main(){
  // Se reserva memoria para almacenar 4 números enteros usando diferentes formas de especificar el tamaño
  int *varptr1 = malloc(4*sizeof(int));
  int *varptr2 = malloc(sizeof(int[4]));
  int *varptr3 = malloc(4*sizeof *varptr3);

  //Se verifica si la memoria se asignó correctamente para varptr1
  if(varptr1){
    //Se rellena el espacio asignado a varptr1 
    for(int i =0 ;i<4; i++){
      varptr1[i]=i*i;
    }
    //Se imprimen los 4 numeros almacenados 
    for(int i =0 ;i<4; i++){
      //Muestra el valor almacenado en cada posición
      printf("varptr1[%d]\t == %d\n",i, varptr1[i]);
    }

    //se libera la memoria asignada de los 3 apuntadores
    free(varptr1);
    free(varptr2);
    free(varptr3);

    //Fin del programa
    return 0;
  }
}
