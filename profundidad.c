#include "pila.h"

int profundidad(char expresion[]) 
{
	char symb, temp;
	union tipos tet;
	int index=0;
	while( expresion[index] != '\0' )
	{
		symb = expresion[index];
		
		if (symb == '(' || symb == '{' || symb == '[')
		{
			tet.inf = symb;
			push(tet);
		}
		else if (symb == ')' || symb == ']' || symb == '}')
		{
			if (isEmpty())
				return 0;
			else
			{
				tet = pop();
				temp = tet.inf;
				if (!((temp == '(' && symb == ')') || (temp == '[' && symb == ']') || (temp == '{' && symb == '}')))
					return 0;
			}
		}
		index++;
	}
	if (!isEmpty())
		return 0;
	else
		return 1;
}