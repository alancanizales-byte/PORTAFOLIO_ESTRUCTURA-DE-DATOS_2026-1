#ifndef ALUMNO_H
#define ALUMNO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	unsigned int matricula;
	char nombre[64];
	int semestre;
	float promedio;
}Alumno;

// FUNCIONES MAIN
Alumno* crearAlumno(void);
void imprimirAlumno(void *dato);

// FUNCIONES COMPARAR
int compMatricula(void *datoA, void *datoB);
int compNombre(void *datoA, void *datoB);
int compSemestre(void *datoA, void *datoB);
int compPromedio(void *datoA, void *datoB);

#endif