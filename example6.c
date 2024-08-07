/***********************
  Materia: Sistemas Operativos
  Estudiante: Sara García
  Fecha: 01-07-24
************************/

#include<stdlib.h>
#include<stdio.h>

int main (int argc,char *argv[]){
  /******** Suma de dos valores ingresados por pantalla utilizando punteros *********/
  
  int valor1, valor2;
  int *ptrV1, *ptrV2;
  ptrV1 = &valor1;
  ptrV2 = &valor2;
  
  printf("\nIngrese los dos valores a ser sumados:\n ");
  scanf("%d %d",&valor1,&valor2);
  
  printf("\nLa suma es: %d\n",*ptrV1 + *ptrV2);
         
  return 0;
}

