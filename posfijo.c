#include "pila.h"

int prec(union tipos cad, char ope2)
{
	char ope1;
	int primer = 0, segundo = 0;
	ope1 = cad.inf;

		if (ope1 == '(')
			primer = 0;
		if (ope1 == ')')
			primer = 4;
		if (ope1 == '^')
			primer = 3;
		if (ope1 == '*' || ope1 == '/')
			primer = 2;
		if (ope1 == '+' || ope1 == '-')
			primer = 1;

		if (ope2 == '(')
			segundo = 4;
		if (ope2 == ')')
			segundo = 0;
		if (ope2 == '^')
			segundo = 3;
		if (ope2 == '*' || ope2 == '/')
			segundo = 2;
		if (ope2 == '+' || ope2 == '-')
			segundo = 1;

		if ((primer == 4 && segundo == 4) || (primer == 0 && segundo == 0))
			return 0;
		else if (primer >= segundo)
			return 1;
		else if (primer < segundo)
			return 0;
}

void postfijo(char express[])
{
	char symb, topSymb, c;
	int index, two;
	union tipos cadena;

	index = two = 0;

	while ( express[index] != '\0' )
	{
		symb = express[index];
		
		if ( !(symb ==  '^' || symb == '/' || symb == '*' || symb == '+' || symb == '-' || symb == '(' || symb == ')' ) )
		{
			express[two] = symb;
			two++;
		}
		else
		{
			while ( !( isEmpty()) && prec( stackTop(), symb) )
			{
				cadena = pop();
				topSymb = cadena.inf;
				express[two] = topSymb;
				two++;
			}
			if (isEmpty() || symb != ')')
			{
				cadena.inf = symb;
				push(cadena);
			}
			else
				cadena = pop();
		}
		index++;
	}
	while ( !( isEmpty() ) )
	{
		cadena = pop();
		topSymb = cadena.inf;
		express[two] = topSymb;
		two++;
	}
	express[two] = '\0';

	printf("%s\n", express);
}