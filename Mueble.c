#include "Mueble.h"
#include "lista.h"

/******** Funcion: bono ********************
Descripcion: Calcula la popularidad en base a las decoraciones compradas.
Parametros: Lista *lista, Mueble *r, Mueble *b, Mueble *e.
Retorno: Retorna la nueva popularidad.
************************************************/

double bono(Lista *lista, Mueble *r, Mueble *b, Mueble *e){
	double d1,d2,d3,i;
	d1 = contar(lista, 'D');
	d2 = contar(lista, 'E');
	d3 = contar(lista, 'F');
	i = (1 + (d1 * r->popularidad) + (d2 * b->popularidad) + (d3 * e->popularidad));
	return i;
}
