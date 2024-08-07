/***********************
  Materia: Sistemas Operativos
  Estudiante: Sara García
  Fecha: 01-07-24
************************/

#include<stdlib.h>
#include<stdio.h>

int main (int argc, char *argv[]){
  printf("hola, si funciona");
  int x;
  int suma = 0;
  
  do{
    scanf("%d",&x);
    suma += x;
    
  } while (x!=0);
  printf("La suma es: %d \n",suma);
  return 0;
}

