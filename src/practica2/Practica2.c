#include <stdio.h>
#include <stdlib.h>
#include <iostring.h>
#include <listadoble.h>
#include "Alumno.h"

int main(void){
	int opcion;
	ListaD lista = inicializarListaD();
	lista.imprimir = imprimirAlumno;
	lista.comparar = compararMatricula;
	lista.liberar = free;
	
	do{
		printf("\nSeleccione una opcion:");
		printf("\n[1] Registrar Alumno");
		printf("\n[2] Desplegar Alumnos");
		printf("\n[3] Reordenar");
		printf("\n[4] Buscar Alumno");
		printf("\n[5] Borrar Alumno");
		printf("\n[6] Finalizar programa\n");
		scanf("%d", &opcion);
		
		switch(opcion){
			case 1:{
				Alumno *nuevo = crearAlumno();
				NodoD *res;

				res = buscarDatoEspecificoD(lista, nuevo, compararMatricula);

				if(res){
					printf("\nLa matricula ya existe\n");
					free(nuevo);
				}
				else{
					insertEnOrdenD(&lista, nuevo);
					printf("\nAlumno agregado\n");
				}

				break;
			}
			
			case 2:{
				int op;
				
				printf("\nDesplegar alumnos:");
				printf("\n[1] ASCENDENTE");
				printf("\n[2] DESCENDENTE\n");
				scanf("%d", &op);
				
				switch(op){
					case 1:
					imprimirListaDIF(lista);
					printf("\n");
					break;
					
					case 2:
					imprimirListaDFI(lista);
					printf("\n");
					break;
					
					default:
					printf("\nOpcion invalida\n");
				}
				break;
			}
			
			case 3:{
				int op;
				
				printf("\nReordenar por: ");
				printf("\n[1] Matricula");
				printf("\n[2] Nombre");
				printf("\n[3] Semestres");
				printf("\n[4] Promedio\n");
				scanf("%d", &op);
				
				switch(op){
					case 1:
					reordenar(&lista, compararMatricula);
					break;
					
					case 2:
					reordenar(&lista, compararNombre);
					break;
					
					case 3:
					reordenar(&lista, compararSemestre);
					break;
					
					case 4:
					reordenar(&lista, compararPromedio);
					break;
					
					default:
					printf("\nOpcion invalida\n");
				}
				break;
			}
			
			case 4:{
				int op;
				Alumno temp;
				NodoD *res = NULL;
				
				printf("\nBuscar por:");
				printf("\n[1] Matricula");
				printf("\n[2] Nombre");
				printf("\n[3] Semestres");
				printf("\n[4] Promedio\n");
				scanf("%d",&op);

				switch(op){
					case 1:
						printf("\nMatricula: ");
						scanf("%u",&temp.matricula);
						res = buscarDatoEspecificoD(lista, &temp, compararMatricula);
						break;

					case 2:
						printf("\nNombre: ");
						scanf("%s",temp.nombre);
						res = buscarDatoEspecificoD(lista, &temp, compararNombre);
						break;

					case 3:
						printf("\nSemestres: ");
						scanf("%d",&temp.semestre);
						res = buscarDatoEspecificoD(lista, &temp, compararSemestre);
						break;

					case 4:
						printf("\nPromedio: ");
						scanf("%f",&temp.promedio);
						res = buscarDatoEspecificoD(lista, &temp, compararPromedio);
						break;
				}
				
				if(res){
					printf("\nAlumno encontrado\n");
					imprimirAlumno(res->dato);
					printf("\n");
				} else {
					printf("\nAlumno no encontrado\n");
				}
				break;
			}
			
			case 5:{
				Alumno temp;
				
				printf("\nMatricula a borrar: ");
				scanf("%u", &temp.matricula);
				
				borrarDatoD(&lista, &temp);
				
				break;
			}
			
			case 6:{
				break;
			}
			
			default:{
				printf("\nOpcion invalida\n");
			}
		}
	}while(opcion != 6);
		
	return 0;
}