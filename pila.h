
// A esto sirve para evitar la recompilacion y haya redefiniciones del archivo

#ifndef pila //Esto sirve para compilar solo si alguna macro pila no esta definida

//Cuando se define la macro pila, el codigo ya no lo vuelve a compilar
#define pila 
union tipos
{
	double numeros;
	char inf;
};

//Definicion de Estructuras
struct nodo
{
	union tipos info;
	struct nodo *sig;	//sig - Siguiente nodo de informacion
};

_declspec(selectany) struct nodo *raiz = 0;

//Definiciones de funciones
inline void push( union tipos dato )
{
	struct nodo *nuevo;
	if (raiz == 0)
	{
		//Lo que hace es convertir la direccion de memoria
		nuevo = (struct nodo *) malloc( sizeof(struct nodo) );
		raiz = nuevo;
		nuevo -> info = dato;
		nuevo -> sig = 0;
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

inline union tipos pop()
{
	union tipos temp;
	if ( isEmpty() == 1)
		printf("No se puede, la pila esta vacia\n");
	else
	{
		temp = raiz -> info;
		raiz = raiz -> sig;
	}
	return temp;
}

inline int isEmpty()
{
	if (raiz == 0)
		return 1;
	else 
		return 0;
}

inline union tipos stackTop()
{
	union tipos num;
	if ( isEmpty() == 1)
	{
		num.inf = '-';
		printf("No hay datos\n");
		return num;
	}
	else
		return (raiz -> info);
}

inline void imprime()
{
	struct nodo *recorre = raiz;
	while (recorre != 0)
	{
		printf("Dato = %c\n", recorre -> info);
		printf("Dato = %f\n", recorre -> info);
		recorre = recorre->sig;
	}
	printf("\n\n");
}


#endif // Esto es cuando termina la macro