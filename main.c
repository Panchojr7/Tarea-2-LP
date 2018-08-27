#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mueble.h"
#include "Empleado.h"
#include "lista.h"
#include "Local.h"

/* Definimos los Colores para usar en la Consola */
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m" //Vuelve a Blanco

/*Funcion encargada de calcular los Clientes Potenciales */

int Cp(double popularidad){
	return 2 * 15 * popularidad;
}

/*Funcion encargada de calcular los Clientes Sentados */

int Cs(int cp, int mesas){
	int cs = mesas * 15 * 6;
	if (cp < cs){
		return cp;
	}
	return cs;
}

/*Funcion encargada de calcular los Clientes Atendidos */

int Ca(int cs, int garzones){
	int ca = 18 * 15 * garzones;
	if (cs < ca){
		return cs;
	}
	return ca;
}

/*Funcion encargada de calcular los Clientes Felices */

int Cf(int ca, int barmans){
	int cf = 9 * 15 * barmans;
	if (ca < cf){
		return ca;
	}
	return cf;
}

int Ingreso(int cf, int preciotragos){
	return cf * preciotragos;
}

int Costo(int ca, int costotragos, int sueldos){
	return (ca* costotragos)+sueldos;
}

int GananciaoPerdida(int Ingreso, int Costo){
	return Ingreso - Costo;
}



/* Funcion que printea el menú y retorna el número elegido por el usuario*/

int mostrar_menu(){
	int o;
    printf("\n\nMenú:\n=====\n\n");
    printf("1.- Contratar Garzon 	"RED"-$200"RESET" diario\n");
    printf("2.- Contratar Barman    "RED"-$100"RESET" diario\n");
    printf("3.- Comprar Decoracion 	"RED"-$100/-$200/-$300"RESET"\n");
    printf("4.- Vender Decoracion 	"GREEN"+$50/+$100/+$150"RESET"\n");
    printf("5.- Comprar Mesa        "RED"-$50"RESET"\n");
    printf("6.- Vender Mesa         "GREEN"+$50"RESET"\n");
    printf("7.- Despedir Garzon\n");
    printf("8.- Despedir Barman\n");
    printf("9.- Pagar Sueldos (concluir el día)\n");
    printf("Porfavor escoge una opción: \n");
    scanf( "%d", &o);
    return o;
}



int main(){

/***** Definiciones *****/

int dia = 0,diaseg=0;
double popularidad = 1, prompop = 1;
int cp, cs, ca, cf;
int opcion, ingreso, costo, garzones, barmans, mesas, decos1, decos2, decos3;
int preciotragos, costotragos;

//Empleados
Lista *empleados;
empleados = (Lista *) malloc (sizeof (Lista));
incializacion(empleados);

//Muebles
Lista *muebles;
muebles = (Lista *) malloc (sizeof (Lista));
incializacion(muebles);

//Local
Local barsinso={5000, 0, &empleados, &muebles};

//Tragos
preciotragos = 150;
costotragos = 100;

//Barman por defecto
Empleado barman={'B', (int *) PagarBarman(&barsinso, empleados)};

//Garzon por defecto
Empleado garzon={'G', (int *) PagarGarzon(&barsinso, empleados)};

//Mesa por defecto
Mueble mesa={'M', 0, 50, 50};

//Decoraciones por defecto
Mueble deco1={'D', 0.25, 100, 50};//Regular
Mueble deco2={'D', 0.5, 200, 100};//Bonita
Mueble deco3={'D', 1, 300, 150};//Espectacular

//El local empieza con 1 garzon, 1 barman y 1 mesa.
Insertar(empleados, &garzon, 'G');
Insertar(empleados, &barman, 'B');
Insertar(muebles, &mesa, 'M');

printf(MAGENTA"\n Bienvenido A BarSinso!!\n"RESET);
//While del juego
while(barsinso.dinerototal > 0 ){

	/*Se recorren las listas despues de cada accion */
	barmans = contar(empleados, 'B');
	garzones = contar(empleados, 'G');
	mesas = contar(muebles, 'M');
	decos1 = contar(muebles, 'D');
	decos2 = contar(muebles, 'E');
	decos3 = contar(muebles, 'F');

	/*Se calcula el bono despues de cada accion */
	popularidad = bono(muebles,&deco1,&deco2,&deco3);

		/*Calculo de clientes por dia*/
	cp = Cp(popularidad); //Clientes Potenciales
	cs = Cs(cp, mesas); //Clientes Sentados
	ca = Ca(cs, garzones); //Clientes Atendidos
	cf = Cf(ca, barmans); //Clientes Felices
	
	//Estadisticas de control
	printf(YELLOW"=====ESTADISTICAS DE JUEGO=====\n");
	printf("Capital:			"GREEN"$%d\n"RESET, barsinso.dinerototal); 
	printf(YELLOW"Popularidad:			"CYAN"%lf\n"RESET,popularidad );
	printf(YELLOW"Estrellas:			"CYAN"★%d★\n",barsinso.estrellas);
	printf(YELLOW"Día:				"CYAN"%d\n"RESET,dia);
	printf(YELLOW"Garzones Contratados:		"CYAN"%d\n",garzones );
	printf(YELLOW"Barmans Contratados:		"CYAN"%d\n",barmans );
	printf(YELLOW"Clientes Potenciales:		"CYAN"%d\n",cp );
	printf(YELLOW"Clientes Sentados:		"CYAN"%d\n",cs );
	printf(YELLOW"Clientes Atendidos:		"CYAN"%d\n",ca );
	printf(YELLOW"Clientes Felices:		"CYAN"%d\n",cf );
	printf(YELLOW"Mesas:				"CYAN"%d\n",mesas);
	printf(YELLOW"Decoraciones 1:			"CYAN"%d\n",decos1);
	printf(YELLOW"Decoraciones 2:			"CYAN"%d\n",decos2);
	printf(YELLOW"Decoraciones 3:			"CYAN"%d\n",decos3);
	printf(YELLOW"==============================="RESET);

	opcion = mostrar_menu(); //opcion elegida por el usuario

	/* Contratar Garzon */
	if (opcion == 1){
		Insertar(empleados, (int *)dia, 'G');
	}
	
	/* Contratar Barman */
	if (opcion == 2){
		Insertar(empleados, (int *)dia, 'B');
	}
	
	/* Comprar Decoracion */
	if (opcion == 3){
		printf("\n\n Elija una Decoracion\n=====\n\n");
    	printf("1.- Regular 		"RED"-$100"RESET"\n");
    	printf("2.- Bonita 			"RED"-$200"RESET"\n");
    	printf("3.- Espectacular 	"RED"-$300"RESET"\n");
    	scanf("%d",&opcion);
    	if (opcion == 1){ //Regular
    		Insertar(muebles, &deco1, 'D');
    		barsinso.dinerototal -= deco1.compra;
    	}
    	if (opcion == 2){ //Bonita
    		Insertar(muebles, &deco2, 'E');
    		barsinso.dinerototal -= deco2.compra;
    	}
    	if (opcion == 3){ //Espectacular
    		Insertar(muebles, &deco3, 'F');
    		barsinso.dinerototal -= deco3.compra;
    	}
	}	

	
	/* Vender Decoracion */
	if (opcion == 4){
		printf("\n\n Elija una Decoracion\n=====\n\n");
    	printf("1.- Regular 		"GREEN"+$50"RESET"\n");
    	printf("2.- Bonita 			"GREEN"+$100"RESET"\n");
    	printf("3.- Espectacular 	"GREEN"+$150"RESET"\n");
    	scanf("%d",&opcion);
    	if (opcion == 1 && decos1 > 0){ //Regular
    		Eliminar(muebles, &deco1, 'D');
    		barsinso.dinerototal += deco1.venta;
    	}
    	else if (opcion == 2 && decos2 > 0){ //Bonita
    		Eliminar(muebles, &deco2, 'E');
    		barsinso.dinerototal += deco2.venta;
    	}
    	else if (opcion == 3 && decos3 > 0){ //Espectacular
    		Eliminar(muebles, &deco3, 'F');
    		barsinso.dinerototal += deco3.venta;
    	}
    	else{
    		printf(RED"ERROR!! No te quedan decoraciones de ese tipo por vender !!\n"RESET);
    	}
	}
	
	/* Comprar Mesa*/
	if (opcion == 5){
		Insertar(muebles, &mesa, 'M');
		barsinso.dinerototal -= mesa.compra;
	}
	
	/* Vender Mesa */
	if (opcion == 6){
		if (mesas == 0){
			printf(RED"ERROR!! No te quedan mesas por vender !!\n"RESET);
		}
		else{
		Eliminar(muebles, 'M');
		barsinso.dinerototal += mesa.venta;
		}
	}

	/* Despedir Garzon */
	if (opcion == 7){
		if (garzones == 0){
			printf(RED"ERROR!! No te quedan Garzones contratados!!\n"RESET);
		}
		else{
		Eliminar(empleados, 'G');
		}
	}

	/* Despedir Barman */
	if (opcion == 8){
		if (barmans == 0){
			printf(RED"ERROR!! No te quedan Barmans contratados!!\n"RESET);
		}
		else{
		Eliminar(empleados, 'B');
		}
	}

	/*Fin del dia y pago */
	if (opcion == 9){
		dia += 1;

		/* Calculo de Ganancias */
		ingreso = Ingreso(cf, preciotragos);
		costo= Costo(ca, costotragos, 300);
		barsinso.dinerototal += GananciaoPerdida(ingreso,costo);

		prompop=+popularidad; //popularidad auxiliar segun dias seguidos

		if (cf > (cp*0.75) ){
			diaseg+=1;
			stars(&barsinso, prompop, diaseg);
		}
		else{
			diaseg=0; //se resetea la cuenta de dias seguidos
		}
		PagarBarman(&barsinso, empleados);
		PagarGarzon(&barsinso, empleados);

	}

	// Game over
	if (barsinso.dinerototal<=0){
		printf("\n\n        "RED"GAME OVER"RESET"\n");
		printf(YELLOW "Has Perdido Todo Tu Capital :(\n"RESET);
		printf(YELLOW"Capital Final:  "RED"$%d\n\n\n"RESET,barsinso.dinerototal);
	}
}
	destruir(empleados);
	destruir(muebles);
	return 0;

}