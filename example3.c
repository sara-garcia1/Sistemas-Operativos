/***********************
  Materia: Sistemas Operativos
  Estudiante: Sara García
  Fecha: 01-07-24
************************/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main (){
  
  int n,i,*ptr,suma = 0;
  printf("Enter number of elements: ");
  scanf("%d",&n);
  ptr = (int*)calloc(n,sizeof(int));
  if(ptr == NULL){
    printf("Error! memory not allocated\n");
    exit(0);
  }
  
  printf("Enter elements: ");
  for(i = 0; i<n; i++){
    scanf("%d",ptr + i);
    suma += *(ptr + i);
  }
  
  printf("suma = %d\n",suma);
  free(ptr);
  
  return 0;
}

