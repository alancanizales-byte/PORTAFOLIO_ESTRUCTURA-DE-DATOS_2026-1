// Nodo.c
#include "Nodo.h"

Nodo* crearNodo(void *dato){
	//RESERVAR ESPACIO PARA UN NODO
	Nodo *nuevo = calloc(1,sizeof(Nodo));
	//COLOCAR REFERENCIA DEL DATO EN EL NODO
	nuevo->dato = dato; 
	return nuevo;	
}