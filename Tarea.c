/*************************
 * Materia: Sistemas Operativos
 * Estudiante: Sara García
 * Fecha: 15-08-24
 * Tema: Gestion de memoria
 *********************/

#include <stdio.h>
#include <stdlib.h>

void imprimirMatriz(int *matriz, int n){
  if (n<6){
  for(int i=0; i<n*n;i++){
      if (i%n==0)
        printf("\n");
      printf(" %d", *(matriz+1));
    }
    printf("\n----------\n");
  }  
}

int main (int argc, char* argv[]){
  if (argc<2){
    printf("\nArgumentos validos: $ejecutable sizeOfMatriz\n");
    exit(0);
  }
  int n=atoi(argv[1]);
  int size = n * n;
  int mA[size];
  int mB[size];
  int mC[size];

  // inicializacion
  for(int i = 0; i < size; i++){
    mA[i]=1;
    mB[i]=2;
    mC[i]=0;

  }
  printf("Matriz A:\n");
  imprimirMatriz(mA, n);

  printf("Matriz B:\n");
  imprimirMatriz(mB, n);
  
  printf("Matriz C inicial:\n");
  imprimirMatriz(mC, n);

  //VERSIÓN CLÁSICA DE MULTIPLICACIÓN DE MATRICES: mA * mB = mC
  for (int i = 0; i < n; i++) { // filas
    for (int j = 0; j < n; j++) { // columnas
      int suma = 0;
      int *pA = mA;
      int *pB = mB;
      for (int h = 0; h < n; h++) { // filas * columnas
        suma += *pA * *pB;
      }
      mC[i + j] = suma;
    }
  }

  //MULTIPLICACIÓN DE MATRICES VERSIÓN AUTOMATIZADA
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      int suma = 0;
      int *pA = mA;
      int *pB = mB;
      suma += ((*pA)*(*pB))*n;
      suma = mC[i + j];
    }
  }
  
  printf("\nMatriz C multiplicada:\n");
  imprimirMatriz(mC, n);


  printf("\n");
  printf("Fin del programa!! \n");
  return 0;
}
