#include "listadoble.h"

void insertarFinalD(ListaD *lista,void *dato){
	NodoD *nuevo = crearNodoD(dato);
	//LISTA VACIA
	if(!lista->inicio){
		lista->inicio = lista->fin = nuevo;
	}
	//LISTA NO VACIA
	else{
		lista->fin->sig = nuevo;
		nuevo->ant = lista->fin;
		lista->fin = nuevo;
	}
	lista->cant++;
}

void imprimirListaDIF(ListaD lista){
	printf("\n [%d] LISTA:",lista.cant);
	if(!lista.inicio){
		printf("VACIA");
		return;
	}
	for(NodoD *aux = lista.inicio; aux!=NULL;  aux=aux->sig ){
		printf("\n");
		lista.imprimir( aux->dato);
	}	
}

void imprimirListaDFI(ListaD lista){
	printf("\n [%d] LISTA:",lista.cant);
	if(!lista.inicio){
		printf("VACIA");
		return;
	}
	for(NodoD *aux = lista.fin; aux!=NULL;  aux=aux->ant ){
		printf("\n");
		lista.imprimir( aux->dato);
	}
	
}

void borrarInicioD(ListaD *lista){
	NodoD *aux;
	if(!lista->inicio)
		return;	
	aux = lista->inicio;
	//UNICO NODO
	if( lista->inicio == lista->fin){
		lista->inicio = lista->fin = NULL;
	}	
	//MINIMO 2
	else{
		lista->inicio = aux->sig;
		lista->inicio->ant = NULL;
		
	}
	if(lista->liberar)
		lista->liberar( aux->dato);
	free(aux);	
	lista->cant--;	
}

void borrarListaD(ListaD *lista){
	while(lista->inicio){
		borrarInicioD(lista);
	}	
}

void borrarFinD(ListaD *lista){
    NodoD *aux;

    if(!lista->fin)
        return;

    aux = lista->fin;

    if(lista->inicio == lista->fin){
        lista->inicio = lista->fin = NULL;
    } else {
        lista->fin = aux->ant;
        lista->fin->sig = NULL;
    }

    if(lista->liberar)
        lista->liberar(aux->dato);

    free(aux);

    lista->cant--;
}


ListaD inicializarListaD(void){
	ListaD lista;
	
	lista.inicio = NULL;
	lista.fin = NULL;
	lista.cant = 0;
	lista.imprimir = NULL;
	lista.comparar = NULL;
	lista.liberar = free;
	
	return lista;
}

NodoD* buscarDatoD(ListaD lista, void *dato){
    for(NodoD *aux = lista.inicio; aux != NULL; aux = aux->sig){
        if(lista.comparar(aux->dato, dato) == 0)
            return aux;
    }

    return NULL;
}

NodoD* buscarDatoEspecificoD(ListaD lista, void *dato, int (*comparar)(void*,void*)){
	for(NodoD *aux = lista.inicio; aux != NULL; aux = aux->sig){
		if(comparar(aux->dato, dato) == 0){
			return aux;
		}
	}
	
	return NULL;
}

void insertEnOrdenD(ListaD *lista,void *dato){
	NodoD *nuevo = crearNodoD(dato);
	
	if(!lista->inicio){
		lista->inicio = lista->fin = nuevo;
		lista->cant++;
		return;
	}
	
	NodoD *aux = lista->inicio;
	
	while(aux && lista->comparar(aux->dato, dato) < 0){
		aux = aux->sig;
	}
	
	if(!aux){
		insertarFinalD(lista, dato);
		free(nuevo);
		return;
	}
	
	if(aux == lista->inicio){
		nuevo->sig = lista->inicio;
		lista->inicio->ant = nuevo;
		lista->inicio = nuevo;
	} else {
		nuevo->sig = aux;
		nuevo->ant = aux->ant;
		
		aux->ant->sig = nuevo;
		aux->ant = nuevo;
	}
	lista->cant++;
}

void borrarDatoD(ListaD *lista,void *dato){
	NodoD *aux = buscarDatoD(*lista,dato);
	
	if(!aux){
		return;
	}
	
	if(aux == lista->inicio){
		borrarInicioD(lista);
	}
	
	else if(aux == lista->fin){
		borrarFinD(lista);
	}
	
	else{
		aux->ant->sig = aux->sig;
		aux->sig->ant = aux->ant;
		
		if(lista->liberar){
			lista->liberar(aux->dato);
		}
		
		free(aux);
		lista->cant--;
	}
}

void reordenar(ListaD *lista, int (*comparar)(void*,void*)){
	ListaD aux = inicializarListaD();
	aux.imprimir = lista->imprimir;
	aux.comparar = comparar;
	
	NodoD *actual = lista->inicio;
	
	while(actual){
		insertEnOrdenD(&aux, actual->dato);
		actual = actual->sig;
	}
	
	lista->inicio = aux.inicio;
	lista->fin = aux.fin;
	lista->comparar = comparar;
}