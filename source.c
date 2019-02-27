#include <malloc.h>		//Manejo de memoria dinamica
#include <stdio.h>		//Input y Output
#include <stdlib.h>		//Rutinas de utileria

struct nodo
{
	char info;			//info - dato a preservar
	struct nodo *sig;	//sig - Siguiente nodo de informacion
};

struct nodo *raiz = NULL;

void push (char dato)
{
	struct nodo *nuevo;
	if (raiz == NULL)
	{

		//Lo que hace es convertir la direccion de memoria
		nuevo = (struct nodo *) malloc( sizeof(struct nodo) );
		raiz = nuevo;
		nuevo -> info = dato;
		nuevo -> sig = NULL;
	}
	else
	{
		struct nodo *ultimo = raiz;
		nuevo = (struct nodo *) malloc( sizeof(struct nodo) );
		nuevo -> info = dato;
		nuevo -> sig = raiz;
		raiz = nuevo;
	}
}

char pop()
{
	char temp;
	if ( isEmpty() == 1)
		printf("No se puede, la pila esta vacia\n");
	else
	{
		temp = raiz -> info;
		raiz = raiz -> sig;
	}
	return temp;
}

int isEmpty()
{
	if (raiz == NULL)
		return 1;
	else 
		return 0;
}

char stackTop()
{
	if ( isEmpty() == 1)
	{
		printf("No hay datos\n");
		return '-';
	}
	else
		return raiz ->info;
	
}

void imprime()
{
	struct nodo *recorre = raiz;
	while (recorre != NULL)
	{
		printf("Dato = %c\n", recorre -> info);
		recorre = recorre->sig;
	}
	printf("\n\n");
}

int main()
{
	push('L');
	push('A');
	push('D');
	push('A');
	imprime();
	printf("Sale el dato: %c\n", pop());
	imprime();
	printf("El dato de arriba es: %c\n", stackTop());
	imprime();
	system("pause");
	return 0;
}