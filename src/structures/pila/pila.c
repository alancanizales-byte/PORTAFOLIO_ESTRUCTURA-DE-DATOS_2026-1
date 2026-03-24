#include "pila.h"

// PEEK
void* peekPila(Pila pila){
	if(pilaVacia(pila))
		return NULL;
	else
		return pila.cima->dato;
}

//VERIFICIACION
int pilaVacia(Pila pila){
	return pila.cima == NULL && pila.cantidad==0;
}

int pilaLlena(Pila pila){
	return pila.cantidad == pila.capacidad;
}

//DATOS
void pushDato(Pila *pila,void *dato){
	if(pilaLlena(*pila)){
		printf("\nOVERFLOW");
		return;
	}
	Nodo *nuevaCima = crearNodo(dato);
	nuevaCima->sig = pila->cima;	
	pila->cima = nuevaCima; 
	pila->cantidad++;
}

void* popDato(Pila *pila){
	void *dato = NULL;
	if(pilaVacia(*pila)){
		printf("\nUNDERFLOW");
		return dato;	
	}
	Nodo *cimaVieja = pila->cima;
	pila->cima = pila->cima->sig;	
	dato = cimaVieja->dato;
	free(cimaVieja);
	pila->cantidad--;	
	return dato;
}

//NODOS
void pushNodo(Pila *pila,Nodo *nodo){
	if(pilaLlena(*pila)){
		printf("\nOVERFLOW");
		return;
	}
	nodo->sig = pila->cima;	
	pila->cima = nodo; 
	pila->cantidad++;
}

Nodo* popNodo(Pila *pila){
	Nodo *cimaVieja = NULL;
	if(pilaVacia(*pila)){
		printf("\nUNDERFLOW");
		return cimaVieja;	
	}
	cimaVieja = pila->cima;
	pila->cima = pila->cima->sig;	
	pila->cantidad--;	
	cimaVieja->sig = NULL;
	return cimaVieja;
}

//VACIAR/ELIMINAR PILA
void vaciarPila(Pila *pila){
	while(!pilaVacia(*pila)){
		popDato(pila);
	}
}

void eliminarPila(Pila *pila){
	while(!pilaVacia(*pila)){
		void * dato = popDato(pila);
		if(pila->liberar)
			pila->liberar(dato);
	}	
}

//IMPRIMIR RESPETAR LIFO
void imprimirPila(Pila pila){	
	Pila aux = {NULL,0,-1,NULL,NULL};	
	printf("\n [%d]PILA:",pila.cantidad);
	//IMPRIMIR CIMAS ORIGINAL
	//REMOVER LOS NODOS DE LA ORIGINAL
	//PASARLOS A LA AUX
	while(!pilaVacia(pila)){
		printf("\n");
		pila.imprimir( pila.cima->dato);
		pushNodo( &aux , popNodo(&pila) );
	}	
	//RESTAURAR
	//REMOVER LOS NODOS DE LA AUX
	//PASARLOS A LA ORIGINAL
	while( !pilaVacia(aux)){
		pushNodo( &pila , popNodo(&aux) );
	}	
}

// TALLER 2
// ORDENAR PILA
void ordenarPila(Pila *pila, int (*comparar)(void *, void *)){
	Pila aux = {NULL, 0, pila->capacidad, pila->imprimir, pila->liberar};

	while(!pilaVacia(*pila)){
		void *actual = popDato(pila);

		// Mover elementos mayores de aux de vuelta a pila
		while(!pilaVacia(aux) && comparar(aux.cima->dato, actual) < 0){
			pushDato(pila, popDato(&aux));
		}

		pushDato(&aux, actual);
	}

	// Restaurar a la pila original
	while(!pilaVacia(aux)){
		pushDato(pila, popDato(&aux));
	}
}