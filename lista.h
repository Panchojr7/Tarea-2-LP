#ifndef _LISTA_H_INCLUDED_
#define _LISTA_H_INCLUDED_


typedef struct ElementoLista{
    void* dato;
    int tipo;
    struct ElementoLista *siguiente;
}Elemento;
 
typedef struct ListaIdentificar{
    Elemento *inicio;
    Elemento *fin;
    Elemento *actual;
    int tamano;
}Lista;

void incializacion(Lista *lista);
/*inicializa la lista*/

int tamanolista(Lista *lista);

int contar(Lista *lista, char tip);

int InsertarVacia(Lista *lista, void *datot, char tip);
/*insertar en inicio de la lista vacia*/

int Insertar(Lista *lista, void *dato, char tip); 
/*insertar en fin de la lista*/

//int Eliminar(Lista *lista, char tipo);

//void borraux(Elemento* c, Elemento* cs);

void destruir(Lista * lista);
/*libera la memoria heap*/

#endif


