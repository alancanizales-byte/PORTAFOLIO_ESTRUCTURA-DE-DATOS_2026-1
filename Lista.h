// LISTA.h
#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

#include "Nodo.h"

typedef struct{
	Nodo *inicio;
	Nodo *fin;
	int cantidad;
	void (*imprimir)(void*); // APUNTADOR A FUNCION
	int (*comparar)(void*,void*);
}Lista;

typedef struct{
	Nodo *ante;
	Nodo *enco;
	void *dato;
}Resultado;

// BUSCAR
Resultado buscar(Lista lista, void *dato);

// IMPRIMIR
void imprimirResultado(Lista lista, Resultado resultado);
void imprimirLista(Lista lista);

// AGREGAR / INSERTAR
void agregarFinal(Lista *lista, void *dato);
void agregarEnOrden(Lista *lista, void *dato);
void insertarInicio(Lista *lista, void *dato); // TALLER 1
int insertarEn(Lista *lista, void *dato, int index); // TALLER 1

// ELIMINAR
void eliminarInicio(Lista *lista);
void eliminarFinal(Lista *lista);
void eliminarDato(Lista *lista, void *dato);
int eliminarEn(Lista *lista, int index); // TALLER 1

// REMOVER
void* removerInicio(Lista *lista);

// REORDENAR
void reordenar(Lista *lista, int (*comparar)(void*, void*));

#endif