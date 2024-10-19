/********************************************************************************************
autor: jorge Sierra
materia; Sistemas Operativos
fecha: 8/08/2024
tema: uso de calloc en un codigo de c.
 ********************************************************************************************/


  
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv){

  // presenta 3 formas diferentes de reservar espacio de memoria de 4 enteros
  int *varptr1=calloc(4*sizeof(int));
  int *varptr2=calloc(sizeof(int[4]));
  int *varptr3=calloc(4*sizeof*varptr3);

  
  if(varptr1){
    //se rellana el espacio en memoria y se imprime con lo que se lleno
    for(int i=0;i<4;i++)
      varptr1[i]=i*i;
    for(int i=0;i<4;i++)
      printf("varptr1[%d]\t == %d\n",i,varptr1[i]);
  }
  // se libera la memoria
  printf("Se libera memoria\n");


  free(varptr1);
  free(varptr2);
  free(varptr3); 
  return 0;
