#ifndef _LOCAL_H_INCLUDED_
#define _LOCAL_H_INCLUDED_

#include "lista.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* Estructura Basica Local*/

typedef struct{
	int dinerototal;
	int estrellas;
	Lista empleados;
	Lista muebles;  
}Local;

void stars(Local *local, double pop, int diaseg);

#endif