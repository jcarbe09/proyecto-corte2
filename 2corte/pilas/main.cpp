#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <iostream>

using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
};
nodo nodoo;
nodo *pila;

int cantidad=30000;
 FILE *archivo;
void generar_datos();
void crear_txt(nodo *pila);
void insertar_datos(nodo *&pila, int n);
void mostrar_pila(nodo *pila);
void ordenar_datos(nodo *pila);
void generar_datos_txt();
void mostrar_Archivo(nodo *pila);
void insertar_datos_txt(nodo *pila,int n);



void generar_datos(){
	int i;
	 srand((unsigned) time(NULL));
	 for (i=0;i<=cantidad;i++){
	 	  long long n =(rand() % (40000)-20000); 
	 	  insertar_datos(pila,n);
	 	  printf("%d ",n);
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
void crear_txt(nodo *pila){
	nodo *insertar=pila;
	archivo=fopen("pila.txt","w+b");
    while(insertar!=NULL){
	    
    	int x =insertar->dato;
    fwrite(&x,sizeof(x),1,archivo);
    insertar=insertar->siguiente;
}   
cout<<"datos guardados"<<endl;
	rewind(archivo);
    fclose(archivo);
    printf("datos agragados");
}
int dato;
void mostrar_archivo(nodo *pila){
	nodo *mostrar=pila;
	archivo=fopen("pila.txt","r");
	while(!feof(archivo)){
      fscanf(archivo,"%d ",&dato);
		insertar_datos(pila,dato);
		printf("%d ",dato);
	}cout<<"cargado"<<endl;
	fclose(archivo);
}

	 		

int main(int argc, char** argv) {
	int r;
do{
	cout<<"presione para ejecurar"<<endl;
	cout<<"1. generar datos"<<endl;
	cout<<"2. mostrar datos"<<endl;
	cout<<"3. ordenar datos"<<endl;
	cout<<"4. generar datos y mostrarlos "<<endl;
	cout<<"5. ordenar los datos"<<endl;
	cout<<"6. enviar los datos a un archivo txt"<<endl;
	cout<<"7. leer datos desde archivo txt"<<endl;
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
	system("cls");
	ordenar_datos(pila);
	break;
}
case 4:{
	 generar_datos();
	break;
}

case 5:{
	ordenar_datos(pila);
	break;
}
case 6:{
	crear_txt(pila);
	break;
}
case 7:{
	mostrar_archivo(pila);
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



