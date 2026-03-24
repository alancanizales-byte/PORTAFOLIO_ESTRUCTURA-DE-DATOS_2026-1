#include <stdio.h>
#include <iostring.h>
#include <pila.h>

#define MAX 100

int palindromo(char *cadena);
int verificarParentesis(char *cadena);

int main(void){
	char *cadena = NULL;
	int opcion;
	
	do{
		printf("\n[1] Palindromo");
		printf("\n[2] Verificacion de parentesis");
		printf("\n[3] Terminar programa");
		inputEntero("\nSeleccione una opcion: ", &opcion);
		
		switch(opcion){
			case 1:
			inputCadenaDinamica("\n Captura cadena: ",&cadena,MAX);
			printf(" Es palindromo: %s", palindromo(cadena) ? "SI\n" : "NO\n");
			break;
			
			case 2:
			inputCadenaDinamica("\n\n Captura expresion: ",&cadena,MAX);
			printf(" Parentesis correctos : %s", verificarParentesis(cadena) ? "SI\n" : "NO\n");
			break;
			
			case 3:
			free(cadena);
			break;
			
			default:
			printf("\nOpcion invalida\n");
		}
	}while(opcion != 3);
	
	return 0;
}

int palindromo(char *cadena){
	if(cadena == NULL){
		return 0;
	}
	
	//Pila pila = {NULL,0,-1,NULL,NULL};
	Pila pila = {NULL, 0, -1, NULL, NULL};
	int i = 0;
	
	while(cadena[i] != '\0'){
		if(cadena[i] != ' '){
			char *letra = (char *)malloc(sizeof(char));
			*letra = cadena[i];
			pushDato(&pila, letra);
		}
		i++;
	}
	
	i = 0;
	while(cadena[i] != '\0'){
		if(cadena[i] != ' '){
			char *letra = (char *)popDato(&pila);
			
			if(*letra != (cadena[i])){
				free(letra);
				eliminarPila(&pila);
				return 0;
			}
			free(letra);
		}
		i++;
	}

	return 1;
}

int verificarParentesis(char *cadena){
	if(cadena == NULL){
		return 0;
	}

	//Pila pila = {NULL,0,-1,NULL,NULL};
	Pila pila = {NULL, 0, -1, NULL, NULL};
	int i = 0;
	
	while(cadena[i] != '\0'){
		char c = cadena[i];
		
		if(c == '(' || c == '{' || c == '['){
			char *simbolo = (char *)malloc(sizeof(char));
			*simbolo = c;
			pushDato(&pila, simbolo);
		}
		
		if(c == ')' || c == '}' || c == ']'){
			if(pilaVacia(pila)){
				return 0;
			}
			
			char *ultimo = (char *)popDato(&pila);
			
			if((c == ')' && *ultimo != '(') || (c == '}' && *ultimo != '{') || (c == ']' && *ultimo != '[')){
				free(ultimo);
				eliminarPila(&pila);
				return 0;
			}
			free(ultimo);
		}
		i++;
	}
	
	if(!pilaVacia(pila)){
		return 0;
	}
	
	return 1;	
}