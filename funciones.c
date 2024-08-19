#include <stdio.h>
#include <math.h>
#include "funciones.h"

void suma() {
    int a, b;
    printf("Ingrese el primer valor\n");
    scanf("%d", &a);

    printf("Ingrese el segundo valor\n");
    scanf("%d", &b);

    int suma = a + b;
    printf("La suma de %d + %d = %d\n\n", a, b, suma);
}

void area() {
    float r;
    float p = 3.1416;

    printf("Ingrese el valor del radio del circulo\n");
    scanf("%f", &r);

    float area = p * (r * r);
    printf("El area del circulo es: %f\n\n", area);
}

void volumenCircunferencia() {
    float s = 4.0 / 3.0;
    float rc;
    float p = 3.1416;

    printf("Ingrese el radio de la circunferencia\n");
    scanf("%f", &rc);

    float volumen_cir = s * p * (rc * rc * rc);
    printf("El volumen de la circunferencia es: %f\n", volumen_cir);
}

void volumenCono() {
    float r_cono;
    float h;
    float x = 1.0 / 3.0;
    float p = 3.1416;

    printf("Ingrese el radio del cono\n");
    scanf("%f", &r_cono);

    printf("Ingrese la altura del cono\n");
    scanf("%f", &h);

    float volumen_cono = ((p * (r_cono * r_cono) * h) * x);
    printf("El volumen del cono es: %f\n\n", volumen_cono);
}

void hipotenusa() {
    float l, t;
    printf("Ingrese el cateto A\n");
    scanf("%f", &l);

    printf("Ingrese el cateto B\n");
    scanf("%f", &t);

    float hip = sqrt((l * l) + (t * t));
    printf("La hipotenusa es: %f\n", hip);
}




