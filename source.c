#include <malloc.h>		//Manejo de memoria dinamica
#include <stdio.h>		//Input y Output
#include <stdlib.h>		//Rutinas de utileria
#include "prototipos.h"
#include "pila.h"

int main()
{
	double resultado=0;
	char express[100];
	int value=0;

	//Pedir expresion
	fflush(stdin);
	gets(express);

	value = profundidad(express);
	if (value == 1)
	{
		printf("Esta bien la expresion\n");
		postfijo(express);
		resultado = evaluar(express);
		printf("%2.1f\n", resultado);
	}
	else
		printf("Esta mal y no se puede hacer la expresion\n");
	system("PAUSE");
	return 0;
}