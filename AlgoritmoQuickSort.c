#include <stdio.h>
#include <stdlib.h>

typedef struct nodo nodo;

struct nodo{
	int dato;
	int ordenado;
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
		nuevo->ordenado=0;
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

void quickSort(nodo* aux,nodo* aux2){
	int temp,x=0;
	while(aux!=aux2){
		while(x==0){
			if(aux!=aux2){
			if(aux->dato>=aux2->dato){
			temp=aux->dato;
			aux->dato=aux2->dato;
			aux2->dato=temp;
			nodo* piv=aux;
			aux=aux2;
			aux2=piv;
			//printf("\n%d\n",aux2->dato);
			x=1;
		}
		else{
				aux2=aux2->anterior;
		}
			}
			else{
				x=1;
			}
		}
		x=0;
		while(x==0){
			if(aux!=aux2){
			if(aux->dato<aux2->dato){
				temp=aux->dato;
				aux->dato=aux2->dato;
				aux2->dato=temp;
				nodo* piv=aux;
				aux=aux2;
				aux2=piv;
				//printf("\n%d\n",aux2->dato);
				x=1;
			}
			else{
					aux2=aux2->siguiente;
			}
			}
			else{
				x=1;
			}
		}
		x=0;
		}
	aux->ordenado=1;
	nodo* ant=aux->anterior;
	nodo* ini2=aux;
	nodo* pos=aux->siguiente;
	nodo* ult2=aux;
	while((ini2->anterior!=NULL)&&(ini2->anterior->ordenado!=1)){
		ini2=ini2->anterior;
	}
	while((ult2->siguiente!=NULL)&&(ult2->siguiente->ordenado!=1)){
		ult2=ult2->siguiente;
	}
	if((ini2!=ant)&&(ant!=NULL)&&(ant->ordenado==0)){
		ordenaquick(ini2,ant);
	}
	if((ult2!=aux->siguiente)&&(aux->siguiente!=NULL)&&(pos->ordenado==0)){
		quickSort(aux->siguiente,ult2);
	}
}

int main(int argc, char *argv[]) {
	int a;
	printf("Total de numeros a ingresar:\t");
	scanf("%d",&a);
	for(int i=0; i<a; i++){
		insertaini(rand());
	}
	printf("Lista Desordenada:\n");
	imprimirFI();
	quickSort(inicio,ultimo);
	printf("\nLista Ordenada:\n");
	imprimirFI();
	return 0;
}
