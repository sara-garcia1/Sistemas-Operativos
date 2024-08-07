/***********************
  Materia: Sistemas Operativos
  Estudiante: Sara García
  Fecha: 01-07-24
************************/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main (){
  char *p;
  char *q = NULL;
  printf("Address of p = %s\n",p);
  
  strcpy(p,"Hello, I´m the best in Operating Systems!!!");
  printf("%s\n",p);
  printf("About to copy \"Goodbye\"to q\n");
  strcpy(q,"Goodbye\n");
  printf("%s\n",q);
  
 
  return 0;
}

