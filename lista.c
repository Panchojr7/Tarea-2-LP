#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mueble.h"
#include "Empleado.h"
#include "Local.h"
#include "lista.h"

/******** Funcion: inicializacion ********************
Descripcion: Inicia la lista.
Parametros: Lista *lista.
Retorno: Nada.
************************************************/
void incializacion(Lista *lista){
    lista->inicio = NULL;
    lista->fin= NULL;
    lista->tamano = 0;
}

/******** Funcion: tamanolista ********************
Descripcion: Cuenta todos los elementos de la lista.
Parametros: Lista *lista.
Retorno: Retorna el largo de la lista.
************************************************/

int tamanolista(Lista *lista){
    return lista->tamano;
}

/******** Funcion: contar ********************
Descripcion: Cuenta los elementos de la lista del tipo deseado.
Parametros: Lista *lista.
Retorno: Retorna la cantidad de elementos del mismo tipo.
************************************************/

int contar(Lista *lista, char tip){
    int i, cont=0;
    lista->actual = lista->inicio;
    for (i = 0; i < tamanolista(lista); ++i){
        if (lista->actual->tipo == tip){ 
            cont+=1;
        }
        if (lista->actual->siguiente != NULL ){
        lista->actual = lista->actual->siguiente;
        }
    }
    return cont;
}


/******** Funcion: InsertarVacia ********************
Descripcion:Inserta un elemento cuando la lista esta vacia.
Parametros:Lista *lista, void *datot, char tip.
Retorno: retorna 0 al momento de haber agregado el elemento. 
************************************************/
int InsertarVacia(Lista *lista, void *datot, char tip){
    Elemento *nuevo_elemento;
    if((nuevo_elemento = (Elemento *)malloc(sizeof(Elemento)))==NULL)
        return -1;
    nuevo_elemento->tipo = tip;
    nuevo_elemento->dato= datot;
    nuevo_elemento->siguiente = NULL;
    lista->inicio = nuevo_elemento;
    lista->fin = nuevo_elemento;
    lista->actual = nuevo_elemento;
    lista->tamano++;
    return 0;
}


/******** Funcion:Insertar ********************
Descripcion: Inserta un elemento al final de la lista.
Parametros:Lista *lista , void *datot, char tip.
Retorno: retorna 0 al momento de haber agregado el elemento.
************************************************/
int Insertar(Lista *lista, void *datot, char tip){

    if (lista->tamano == 0){
        InsertarVacia(lista, datot, tip);
        return 0;
    }
    else{
        Elemento *nuevo_elemento;
        if((nuevo_elemento = (Elemento *)malloc(sizeof(Elemento)))==NULL)
            return -1;
        lista->actual->siguiente = nuevo_elemento;
        nuevo_elemento->siguiente = NULL;
        nuevo_elemento->dato=datot;
        nuevo_elemento->tipo=tip;
        lista->fin = nuevo_elemento;
        lista->actual = nuevo_elemento;
        lista->tamano++;
        return 0;
    }
}


/******** Funcion: Eliminar ********************
Descripcion: Elimina el elemento de un tipo deseado mas proximo al inicio.
Parametros: Lista *lista, char tipo.
Retorno: Retorna 0 cuando se elimina el elemento.
************************************************/


int Eliminar(Lista *lista, char tipo){
	int i;
	if(lista->inicio->tipo == tipo){
        Elemento *aux;
        aux = lista->inicio->siguiente;
        
	
		lista->actual = lista->inicio->siguiente;
		lista->tamano--;
		free(lista->inicio);
        lista->inicio = aux;
        return 1;
	}

	lista->actual= lista->inicio;
    Elemento *anterior;
	for(i=1; i < (tamanolista(lista));i++){
        if( i==1)   anterior = lista->inicio;
		if(lista->actual->tipo == tipo){
            Elemento *aux;
            aux= lista->actual->siguiente;
            
			lista->tamano--;
            free(lista->actual);
            anterior->siguiente = aux;
            i=tamanolista(lista) +1;
            return 1 ;
		}
        anterior= lista->actual;
        lista->actual = lista->actual->siguiente;
	}
	return -1;
}

/******** Funcion: destruir ********************
Descripcion: Liberamos memoria utilizada por la lista.
Parametros: Lista *lista.
Retorno: Nada , solo aplica free.
************************************************/
void destruir(Lista * lista){
  	lista->actual= lista->inicio;
    Elemento *aux;
    int i;
    for(i = 0; i < tamanolista(lista);i++){
        if (i< tamanolista(lista)) aux= lista->actual->siguiente;
       // free(lista->actual->dato);
        free(lista->actual);
        if (i< tamanolista(lista)) lista->actual=aux;
    }   
}

