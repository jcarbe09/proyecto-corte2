#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <iostream>

using namespace std;
struct nodo{
	int dato;
	nodo *siguiente;
};nodo *pila=NULL;


void insertar_datos(nodo *&pila, int n);
int cantidad=10000;
void generar_datos(){
	int i;
	 srand((unsigned) time(NULL));
	 for (i=0;i<=cantidad;i++){
	 	  long long n =(rand() % (40000)-20000); 
	 	  insertar_datos(pila,n);
		  }
	 }
	 
void insertar_datos(nodo *&pila, int n){
		nodo *nuevo_nodo=(nodo*)malloc(sizeof(nodo));
		nuevo_nodo->dato=n;
		nuevo_nodo->siguiente=pila;
		pila=nuevo_nodo;	
	
}

void mostrar_pila(nodo *pila){
	nodo *pilita =pila;
	while(pilita!=NULL){
		printf("%d ",pilita->dato);
		pilita=pilita->siguiente;
	}
}

void ordenar_datos(nodo *pila){
	int aux;
	 nodo *x=pila;
	 nodo *y=pila;
	while(x!=NULL){
	y=x->siguiente;	
	    while(y!=NULL){
	    	if ( x->dato > y->dato){
			aux=x->dato;
			x->dato=y->dato;
			y->dato=aux;	
		}
		y=y->siguiente;
		}
	x=x->siguiente;
	}
}


void generar_datos_txt(){
	int i;
	 srand((unsigned) time(NULL));
	 for (i=0;i<=cantidad;i++){
	 	  long long n =(rand() % (40000)-20000); 
	 	  insertar_datos(pila,n);
		  }
	 }
	 		

int main(int argc, char** argv) {
	int r;
do{
	cout<<"presione para ejecurar"<<endl;
	cout<<"1. generar datos"<<endl;
	cout<<"2. mostrar datos"<<endl;
	cout<<"3. ordenar datos"<<endl;
	cout<<"4. generar datos y enviarlos a archivo txt"<endl;
	cout<<"5. leer los datos desde archivo txt"<<endl;
	cout<<"6. ordenar datos en archivo txt"<<endl;
	cin>>r;
	switch(r){
case 0:{
	exit(0);
	break;
}
case 1:{
	generar_datos();
	break;
}

case 2:{
		mostrar_pila(pila);
	break;
}
case 3 :{
	ordenar_datos(pila);
	break;
}
default:{
	printf("opcion no valida");
	break;
}
}		
}while (r!=0);
	return 0;
}



