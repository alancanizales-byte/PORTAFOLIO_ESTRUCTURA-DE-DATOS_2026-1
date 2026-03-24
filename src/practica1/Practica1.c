#include <stdio.h>
#include <iostring.h>
#include "lista.h"
#include "Alumno.h"

int main(void){
	int opcion;
	Lista lista = {NULL, NULL, 0, imprimirAlumno, compMatricula, free};
	
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
				agregarEnOrden(&lista, nuevo);
				printf("\nAlumno agregado\n");
				break;
			}
			
			case 2:{
				imprimirLista(lista);
				break;
			}
			
			case 3:{
				int op;
				
				printf("\nOrdenar por: ");
				printf("\n[1] Matricula");
				printf("\n[2] Nombre");
				printf("\n[3] Semestres");
				printf("\n[4] Promedio\n");
				scanf("%d", &op);
				
				switch(op){
					case 1:
					reordenar(&lista, compMatricula);
					lista.comparar = compMatricula;
					break;
					
					case 2:
					reordenar(&lista, compNombre);
					lista.comparar = compNombre;
					break;
					
					case 3:
					reordenar(&lista, compSemestre);
					lista.comparar = compSemestre;
					break;
					
					case 4:
					reordenar(&lista, compPromedio);
					lista.comparar = compPromedio;
					break;
				}
				break;
			}
			
			case 4:{
				int op;
				Alumno temp;
				Resultado res;
				Lista listaTemp = lista;

				printf("\nBuscar por:");
				printf("\n[1] Matricula");
				printf("\n[2] Nombre");
				printf("\n[3] Semestres");
				printf("\n[4] Promedio\n");
				scanf("%d",&op);

				switch(op){
					case 1:
						listaTemp.comparar = compMatricula;
						printf("\nMatricula: ");
						scanf("%d",&temp.matricula);
						break;

					case 2:
						listaTemp.comparar = compNombre;
						printf("\nNombre: ");
						scanf("%s",temp.nombre);
						break;

					case 3:
						listaTemp.comparar = compSemestre;
						printf("\nSemestres: ");
						scanf("%d",&temp.semestre);
						break;

					case 4:
						listaTemp.comparar = compPromedio;
						printf("\nPromedio: ");
						scanf("%f",&temp.promedio);
						break;
				}

				res = buscar(listaTemp,&temp);
				if(res.enco){
					printf("\nAlumno encontrado\n");
					imprimirAlumno(res.dato);
					printf("\n");
				} else {
					printf("\nAlumno no encontrado\n");
				}

				break;
			}
			
			case 5:{
				Alumno temp;
				printf("\nMatricula a eliminar: ");
				scanf("%u", &temp.matricula);
				
				lista.comparar = compMatricula;
				eliminarDato(&lista, &temp);
				printf("\nAlumno eliminado\n");
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