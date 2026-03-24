#include <stdio.h>
#include <stdlib.h>
#include <pila.h>
#include <iostring.h>
#include "Laberinto.h"

int main(void){
    Laberinto lab = crear_laberinto();
	Coordenada *punto;
	//Movimientos mov;
	Coordenada origen = {1,1}; 
	Coordenada destino = {25,24};
	unsigned int nuevasCoor = 0;	
	inputEnteroSinSigno("\n Nuevas coordenadas? (1:SI 0:NO) : ",&nuevasCoor);
	if(nuevasCoor){
		inputEntero("\n Captura Origen X: ",&origen.x);
		inputEntero(" Captura Origen Y: ",&origen.y);
		inputEntero("\n Captura Destino X: ",&destino.x);
		inputEntero(" Captura Destino Y: ",&destino.y);
	}
	setOrigen(lab,origen);
	setDestino(lab,destino);
	Pila pila = {NULL,0,-1,imprimirCoordenada,free};
	//PUSH INICIAL DEL ORIGEN
	punto = crearCoordenada(origen.x,origen.y);
	pushDato(&pila,punto);
	
	//CICLO
	while(!pilaVacia(pila)){
		punto = peekPila(pila);
		
		if(lab[punto->x][punto->y] == 'B'){
			printf("\nCAMINO ENCONTRADO\n");
			break;
		}
		
		Movimientos mov = movimientosPosibles(lab,*punto);		
		
		if(mov.right){
			Coordenada *nuevo = crearCoordenada(punto->x, punto->y + 1);
			if(lab[nuevo->x][nuevo->y] != 'B')
				lab[nuevo->x][nuevo->y] = '.';
			pushDato(&pila, nuevo);
		}
		
		else if(mov.left){
			Coordenada *nuevo = crearCoordenada(punto->x, punto->y - 1);
			if(lab[nuevo->x][nuevo->y] != 'B')
				lab[nuevo->x][nuevo->y] = '.';
			pushDato(&pila, nuevo);
		}
		
		else if(mov.down){
			Coordenada *nuevo = crearCoordenada(punto->x + 1, punto->y);
			if(lab[nuevo->x][nuevo->y] != 'B')
				lab[nuevo->x][nuevo->y] = '.';
			pushDato(&pila, nuevo);
		}
		
		else if(mov.up){
			Coordenada *nuevo = crearCoordenada(punto->x - 1, punto->y);
			if(lab[nuevo->x][nuevo->y] != 'B')
				lab[nuevo->x][nuevo->y] = '.';
			pushDato(&pila, nuevo);
		}
		
		else{
			if(lab[punto->x][punto->y] != 'A')
				lab[punto->x][punto->y] = 'o';
			free(popDato(&pila));
		}
	}
	
	imprimirLab(lab);
	liberarLaberinto(lab);
    return 0;
}