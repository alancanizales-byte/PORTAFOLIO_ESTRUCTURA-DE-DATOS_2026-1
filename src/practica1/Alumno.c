#include "Alumno.h"
#include <iostring.h> 
#include <string.h>

Alumno* crearAlumno(void){
	Alumno *nuevo = calloc(1, sizeof(Alumno));
	inputEnteroSinSigno("\n Matricula: ", &nuevo->matricula);
	inputCadena("\n Nombre: ", nuevo->nombre, 64);
	inputEntero("\n Semestres: ", &nuevo->semestre);
	inputFloat("\n Promedio: ", &nuevo->promedio);
	return nuevo;
}

void imprimirAlumno(void *dato){
	Alumno *alumno = dato;
	printf("\n %-7u | ", alumno->matricula);
	printf("%-40s | ", alumno->nombre);
	printf("%-2d | ", alumno->semestre);
	printf("%.2f | ", alumno->promedio);
}

// comparar
// NEGATIVO si datoA < datoB
// CERO si datoA == datoB
// POSITIVO si datoA > datoB

int compMatricula(void *datoA, void *datoB){
	Alumno *alumA = datoA, *alumB = datoB;
	return alumA->matricula - alumB->matricula;
}

int compNombre(void *datoA, void *datoB){
	Alumno *alumA = datoA, *alumB = datoB;
	return strcmp(alumA->nombre, alumB->nombre);
}

int compSemestre(void *datoA, void *datoB){
	Alumno *alumA = datoA, *alumB = datoB;
	return alumA->semestre - alumB->semestre;
}

int compPromedio(void *datoA, void *datoB){
	Alumno *alumA = datoA, *alumB = datoB;
	if(alumA->promedio < alumB->promedio) return -1;
	else if(alumA->promedio > alumB->promedio) return 1;
	else return 0;
}
