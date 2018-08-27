#ifndef _MUEBLE_H_INCLUDED_
#define _MUEBLE_H_INCLUDED_

#include "lista.h"
/* Estructura Basica Mueble*/

typedef struct{
	char tipo; //Decoracion o Mesa
	double popularidad;
	int compra;
	int venta;  
}Mueble;

double bono( Lista *lista, Mueble *r, Mueble *b, Mueble *e);

#endif