#ifndef _EMPLEADO_H_INCLUDED_
#define _EMPLEADO_H_INCLUDED_

#include "lista.h"
#include "Local.h"


/* Estructura Basica Empleado*/

typedef struct{
	char tipo; //Barman o Garzon
	void(*pagar)(void *);
	//El parametro entregado es el local.
}Empleado;

/* Pagos */
int PagarGarzon(Local *local, Lista *lista);
int PagarBarman(Local *local, Lista *lista);

#endif