#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H

#include <stdio.h>
#include "../nodos/nododoble.h"

typedef struct 
{
	NodoD *inicio;
	NodoD *fin;
	int cant;
	void (*imprimir)(void *datoA);
	int (*comparar)(void *datoA,void *dataB);
	void (*liberar)(void *datoA);
}ListaD;

//IMPLEMENTADAS

// IMPRIMIR
void imprimirListaDIF(ListaD lista);
void imprimirListaDFI(ListaD lista);

// BORRAR
void borrarInicioD(ListaD *lista);
void borrarListaD(ListaD *);
void borrarDatoD(ListaD *lista,void *dato);
void borrarFinD(ListaD *lista);

// INICIALIZAR
ListaD inicializarListaD(void);

// BUSCAR
NodoD* buscarDatoD(ListaD lista,void *dato);
NodoD* buscarDatoEspecificoD(ListaD lista,void *dato,int (*comparar)(void*,void*));

// INSERTAR
void insertEnOrdenD(ListaD *lista,void *dato);
void insertarFinalD(ListaD*,void*);

// REORDENAR
void reordenar(ListaD *lista, int (*comparar)(void*,void*));

//NO IMPLEMENTADAS
//INSERTAR
void insertarInicioD(ListaD*,void*);
int insertarEn( ListaD * lista, void *dato,int index);

//ELIMINAR
int borrarEnD( ListaD *lista, int index);

#endif