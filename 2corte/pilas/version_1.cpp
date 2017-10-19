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

void generar_datos(){
	int n;
	 int i;
	 srand((unsigned) time(NULL));
	 for (i=0;i<=999;i++){
	 	  n =(rand() % 10000-5000); 
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
		printf("%d",pilita->dato);
		pilita=pilita->siguiente;
	}
}	 		

int main(int argc, char** argv) {
	int r;
do{
	cout<<"presione para ejecurar"<<endl;
	cout<<"1. generar datos"<<endl;
	cout<<"2. mostrar datos"<<endl;
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
default:{
	printf("opcion no valida");
	break;
}
}		
}while (r!=0);
	return 0;
}



