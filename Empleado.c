#include "Empleado.h"
#include "lista.h"
#include "Local.h"

/******** Funcion: PagarGarzon ********************
Descripcion: Se encarga de pagar a todos los garzones contratados.
Parametros: Local *local, Lista *lista.
Retorno: Retorna 0 una vez hecha la transaccion.
************************************************/

int PagarGarzon(Local *local, Lista *lista){
	int sueldogarzones = contar( lista, 'G') * 200;
	local->dinerototal -= sueldogarzones;
	return 0;
}

/******** Funcion: PagarBarman ********************
Descripcion: Se encarga de pagar a todos los barmans contratados.
Parametros: Local *local, Lista *lista.
Retorno: Retorna 0 una vez hecha la transaccion.
************************************************/

int PagarBarman(Local *local, Lista *lista){
	int sueldobarmans = contar(lista, 'B') * 100;
	local->dinerototal -= sueldobarmans;
	return 0;
}
