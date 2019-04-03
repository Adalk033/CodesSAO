#include <math.h>
#include "pila.h"

double convierte(char c)
{
	double operador;
	operador = (double) c - '0';
	return operador;
}

double evalua(double ope2, char sing, double ope1)
{
	switch (sing)
	{
	case '+':
		return ope1 + ope2;
	case '-':
		return ope1 - ope2;
	case '*':
		return ope1 * ope2;
	case '/':
		return ope1 / ope2;
	case '^':
		return pow(ope1,ope2);
	default:
		return 0;
	}
}

double evaluar(char express[])
{
	char symb, in;
	double op1, op2, value, f, respuesta;
	int index;
	union tipos manejador;
	union tipos manejador2;

	index = 0;
	while (express[index] != '\0')
	{
		symb = express[index];
		if (!(symb == '^' || symb == '/' || symb == '*' || symb == '+' || symb == '-' || symb == '(' || symb == ')'))
		{
			manejador.numeros = convierte(symb);
			push( manejador );
		}
		else
		{
			manejador = pop();
			manejador2 = pop();
			op1 = manejador.numeros;
			op2 = manejador2.numeros;
			value = evalua(op1, symb, op2);

			manejador.numeros = value;
			push(manejador);
		}
		index++;
	}

	manejador = pop();
	respuesta = manejador.numeros;
	return respuesta;
}