#include <stdio.h>
#include <iostring.h>
#include <pila.h>

void imprimirEntero(void *dato);
int compEnteros(void *a, void *b);

int main(void){
	Pila pila = {NULL,0,10,imprimirEntero,NULL};
	int arreglo[] = {8,5,6,10,2,3,9};
	for(int i=0; i<7;i++)
		pushDato(&pila,&arreglo[i]);
	
	printf("\nPila original");
	imprimirPila(pila);
	
	ordenarPila(&pila, compEnteros);
	
	printf("\n");
	
	printf("\nPila ordenada");
	imprimirPila(pila);
	
	return 0;
}

void imprimirEntero(void *dato){
	int *datoA = dato;
	printf(" %d",*datoA);
}

int compEnteros(void *a, void *b){
	int *pA, *pB;
	pA = a;
	pB = b;
	return *pA - *pB;
}