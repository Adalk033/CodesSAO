# CodesSAO
/*******************************************************
Cristhian Adal García Hernández
1 de Febrero de 2018
********************************************************/
//Librerias
#include <stdio.h>
/****************/
struct trabajador 
{
	char  nombre[50];
	int   sexo, edad;
	float ahorro;

};//Fin de la Estructura


//Inicio del Programa
int main ()
{
	//Declaracion de Constantes
	const int SIZE = 2;
	 
	//Declaracion de variables
	struct trabajador mon_pio[ SIZE ];
	int indice, cant = 0; // Cantidad de trabajador a dar de alta	
	float prom0=0, suma3=0, suma0=0, suma1=0;

	//Inicializacio del Grupo
	for( indice = 0; indice < SIZE; indice++)
	{
		mon_pio[indice].sexo =  -1; //Es para limpiar el arreglo del numero y que esta vacio
		mon_pio[indice].nombre[0] = '\0';
		mon_pio[indice].ahorro = 0.0;

	}//Fin del FOR

	//Datos de entrada

	for( indice = 0; indice < SIZE ; indice++)
	{
		printf("Para el Trabajador %2i dame su \n", indice);
		printf("Nombre: ");
		fflush( stdin );
		gets( mon_pio[indice].nombre );
		printf("Su sexo (Si es Hombre es '1', si es mujer es '0'): ");
		scanf("%i", &mon_pio[indice].sexo );
		printf("Edad que tiene: ");
		scanf("%i", &mon_pio[indice].edad );
		suma3 = suma3 + mon_pio[indice].edad;
		printf("Ahorro hasta ahora: ");
		scanf("%f", &mon_pio[indice].ahorro);
		if ( mon_pio[indice].sexo == 0)
			suma0 = suma0 + mon_pio[indice].ahorro;	
		else 
			suma1 = suma1 + mon_pio[indice].ahorro;	

	}//Fin del For
	
	//Proceso
	prom0 = suma3 / SIZE;

	//Datos de Salida 
	for( indice = 0; indice < SIZE; indice++)
	{
		printf("\n %30s  %i  %i  %4.2f \n", mon_pio[indice].nombre, 
			mon_pio[indice].sexo, mon_pio[indice].edad, mon_pio[indice].ahorro );

	}//Fin del For
	printf("La edad promedio es: %4.2f\n El ahorro de los hombres es: %4.2f\n El ahorro de las mujeres es: %4.2f\n", prom0, suma1, suma0);

	//Fin del Programa
	puts("Fin del programa V18");

	//Detener Pantalla
	scanf("%");

	//Dado a que es main
	return 0;
}//FIN DE MAIN
