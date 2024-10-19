/**********************************************************
Estudiante en formación: Sara Valentina García 
Materia: Sistemas Operativos
Fecha: 8/08/24
Tópico: Uso de calloc en codigo de c
 *********************************************************/

//Librerías 
#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char *argv){

  // Se presentaan 3 formas diferentes para reservar espacio en memoria de 4 números enteros
  int *varptr1 = calloc(4, sizeof(int));
  int *varptr2 = calloc(4, sizeof(int));
  int *varptr3 = calloc(4, sizeof *varptr3);

  //Se verifica si varptr1 fue asignado correctamente
  if(varptr1){
    //se rellana el espacio en memoria 
    for(int i=0;i<4;i++){
      //Se imprimen los valores asignados 
      varptr1[i]=i*i;
    }
    
    for(int i=0;i<4;i++){
      //Se imprime el contenido de varptr1 en cada posición
      printf("varptr1[%d]\t == %d\n",i,varptr1[i]);
    }
  }
  
  // se indica que se va a liberar memoria
  printf("Se libera memoria\n");

  //Si no esta vacío se libera memoria para cada puntero 
  if (varptr1) free(varptr1);  
  if (varptr2) free(varptr2);    
  if (varptr3) free(varptr3);
  
  //Fin del programa 
  return 0;
}
