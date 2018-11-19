#include <stdio.h>
#include <stdlib.h>

typedef struct nodo nodo;

struct nodo{
	int dato;
	struct nodo *siguiente;
	struct nodo *anterior;
};

nodo *inicio=NULL;
nodo *ultimo=NULL;
nodo *inicio2=NULL;
nodo *ultimo2=NULL;

nodo *crearnodo(int dato){
	nodo *nuevo=NULL;
	nuevo=(nodo *)malloc(sizeof(nodo));
	if(nuevo!=NULL){
		nuevo->dato=dato;
		nuevo->siguiente=NULL;
		nuevo->anterior=NULL;
	}
	return nuevo;
}

void insertaini(int dato){
	nodo *nuevo=NULL;
	nuevo= crearnodo(dato);
	if(inicio == NULL){
		inicio=nuevo;
		ultimo=nuevo;
	}
	else{
		ultimo->siguiente=nuevo;
		nuevo->anterior=ultimo;
		ultimo=nuevo;
	}
}

void imprimirFI(){
	nodo *aux=inicio;
	while(aux!=NULL){
		printf("%d-",aux->dato);
		aux=aux->siguiente;
	}
}

void Shell(int a){
	int temp,x=0;
	a=a/2;
	nodo *aux=inicio;
	nodo *aux2=inicio;
	nodo *aux3=inicio;
	for(int i=0;i<a;i++){
		aux2=aux2->siguiente;
	}
	while(aux2!=NULL){
		if((aux->dato)>(aux2->dato)){
			temp=aux->dato;
			aux->dato=aux2->dato;
			aux2->dato=temp;
		}
		if(x>=a){
			if((aux->dato)<(aux3->dato)){
				temp=aux->dato;
				aux->dato=aux3->dato;
				aux3->dato=temp;
			}
			aux3=aux3->siguiente;
		}
		aux=aux->siguiente;
		aux2=aux2->siguiente;
		x+=1;
	}
	if(a>1){
		Shell(a);
	}
}

int main(int argc, char *argv[]) {
	int a;
	printf("Total de numeros  ingresar\t");
	scanf("%d",&a);
	for(int i=0; i<a; i++){
		insertaini(rand());
	}
	printf("Lista Desordenada: "\n");
	imprimirFI();
	Shell(a);
	printf("\nLista Ordenada\n");
	imprimirFI();
	return 0;
}
