#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define reservar_memoria (Nodo *)malloc(sizeof(Nodo))
?
struct Nodo{
	int dato;
	Nodo * siguiente;
};
?
void menu();
void generarDatos(Nodo *&, Nodo *&);
void insertarDatosCola(int, Nodo *&, Nodo *&);
void ordenarDatos(Nodo *);
void imprimirDatos(Nodo *);
?
int main(){
	menu();
	return 0;
}
?
void menu(){
	Nodo *inicio = NULL;
	Nodo *fin = NULL;
	int opcion;
	do{
		printf("MENU\n\n");
		printf("1. Generar Datos\n");
		printf("2. Ordenar Datos\n");
		printf("3. Imprimir Datos\n\n");
		printf("Ingrese una opcion\n");
		scanf("%d", &opcion);
		switch(opcion){
			case 0:
				exit(0);
				break;
			case 1:
				generarDatos(inicio, fin);
				break;
			case 2:
				ordenarDatos(inicio);
				break;
			case 3:
				imprimirDatos(inicio);
				break;
			default:
				printf("Opcion Invalida\n");
		}
	}while(opcion != 0);
}
?
void generarDatos(Nodo *&inicio, Nodo *&fin){
	int cantDatos, i, aleatorio;
	printf("Ingrese la cantidad de datos a generar\n");
	scanf("%d", &cantDatos);
	srand(time(NULL));
	for(i = 1; i <= cantDatos; i++){
		aleatorio = (rand() % (1999999 + 1)- 1000000);
		insertarDatosCola(aleatorio, inicio, fin);
	}
}
?
void insertarDatosCola(int n, Nodo *&inicio, Nodo *&fin){
	Nodo * nuevo_nodo = reservar_memoria;
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = NULL;
	if(inicio == NULL){
		inicio = nuevo_nodo;
	}else{
		fin -> siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;
}
?
void ordenarDatos(Nodo *inicio){
	int aux;
	Nodo * x = inicio;
	Nodo * y = NULL;
	if(inicio == NULL){
		printf("Me la gane suave\n");
	}else{
		while(x != NULL){
			y = x -> siguiente;
			while(y != NULL){
				if(x -> dato > y -> dato){
					aux = x -> dato;
					x -> dato = y -> dato;
					y -> dato = aux;
				}
				y = y -> siguiente;
			}
			x = x -> siguiente;
		}
	}
}
void imprimirDatos(Nodo *inicio){
	Nodo * aux = inicio;
	if(inicio == NULL){
		printf("Esta vacio\n");
	}else{
		while(aux != NULL){
			printf("%d ", aux -> dato);
			aux = aux -> siguiente;
		}
	}
}
void colas_txt()
