#include "Local.h"
#include "lista.h"

/******** Funcion: stars ********************
Descripcion: Asigna las estrellas al local segun los dias seguidos y la popularidad.
Parametros: Local *local, double pop, int diaseg.
Retorno: Nada.
************************************************/

void stars(Local *local, double pop, int diaseg){
	if (diaseg >= 5 && pop/5 >= 1){
		if (local->estrellas == 0)
			local->estrellas = 1;
	}
	if (diaseg >= 10 && pop/10 >= 2){
		if (local->estrellas == 1)
			local->estrellas = 2;
	}
	if (diaseg >= 15 && pop/15 >= 4){
		if (local->estrellas == 2)
			local->estrellas = 3;
	}
	if (diaseg >= 20 && pop/20 >= 8){
		if (local->estrellas == 3)
			local->estrellas = 4;
	}
	if (diaseg >= 25 && pop/25 >= 16){
		if (local->estrellas == 4)
			local->estrellas = 5;
	}
}

