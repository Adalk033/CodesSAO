/*
	Nombre : Cristhian Adal Garcia Hernandez
	Matricula: 24500557
	SML
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define SIZE	   1000
#define READ	   10
#define WRITE	   11
#define LOAD	   20
#define STORE	   21
#define ADD		   30
#define SUBTRACT   31
#define DIVIDE     32
#define MULTIPLY   33
#define RESIDUO	   34
#define	POTENCIA   35
#define SALTO	   36
#define CADENA	   37
#define IMPRIMIR   38
#define BRANCH     40
#define BRANCHNEG  41
#define BRANCHZERO 42
#define HALT       43

FILE* archivo;
float bloon;
int in;

int conversor(float tem)
{
	int dos;
	dos = (int)tem;
	return tem;
}

int leerDisco(float mem[]) 
{
	int dep=0;
	char caracter, temp[5];
	archivo = fopen("programa.simp.txt", "r");
	if ( archivo == NULL )
	{	
		printf("El archivo no existe\n");
		return 1;
	}
	in = 0;
	while (!feof(archivo))
	{
		caracter = fgetc(archivo);
		temp[dep] = caracter;
		if (dep == 4 && temp[dep-3] != '9')
		{
			mem[in] = (float) atoi(temp);
			dep = -1;
			bloon = mem[in];
			in++;
		}
		dep++;
	}
	fclose(archivo);
	return 0;
}

int verifPal(float palabra, int size)
{
	//verificar si la palabra es correcta de acuerdo a las operaciones
	int index = 0, temp;
	temp = (int) palabra;
	if ( conversor(palabra) < 0 || conversor(palabra) % 100 >= size || conversor(palabra) % 1000 >= size)
		return 1;
	(temp < 10000) ? (index = ( conversor(palabra) / 100 ) ) : (index = ( conversor(palabra) / 1000) );
	switch (index) 
	{
		case READ:
		case WRITE:
		case LOAD:
		case STORE:
		case ADD:
		case SUBTRACT:
		case DIVIDE:
		case MULTIPLY:
		case RESIDUO:
		case POTENCIA:
		case SALTO:
		case CADENA:
		case IMPRIMIR:
		case BRANCH:
		case BRANCHNEG:
		case BRANCHZERO:
		case HALT:
		case 0:
			break;
		default:
			return 1;
	}
	return 0;
}

void registro(float acum, int icounter, float mem[], int insc, int finish)
{
	int index, two;

	printf("\n	REGISTROS:\n");
	printf("\tAcumulador:\t\t%2.1f\n\tInstructionCounter:\t%d", acum, insc-1); 
	printf("\n\tInstructionRegister:\t%d\n\tOperationCode:\t\t%d\n\tOperando:\t\t%d\n", finish,
		finish < 10000 ? finish / 100 : finish / 1000,
		finish < 10000 ? finish % 100 : finish % 1000 );

	printf("\nMEMORIA:\n");

	//Imprimir las el numero de las comlumnas
	printf("%3c", ' ');
	for (index = 0; index < 10; index++)
		printf("%7d ", index);
	printf("\n");

	//Impresion de cada numero que hay en la memoria
	for (index = 0; index < SIZE; index += 10) 
	{
		printf("%.3d", index);
		for (two = index; two < index + 10; two++) 
			printf(" %c%6.1f", mem[two] < 0 ? '-' : '+', mem[two] < 0 ? - mem[two] : mem[two]);
		printf("\n");
	}
} //registro

void menu()
{
	printf("\n\t*** Bienvenido a Simpletron! ***\n\t*** Introduzca su programa una instruccion ***\n\t*** (o palabra de datos) a la vez en la linea");
	printf("***\n\t*** de texto de entrada.Yo indicare el numero ***\n\t*** de posicion y una interrogacion(? ).Usted ***\n\t***");
	printf(" tecleara entonces la palabra para esa ***\n\t*** posicion.Haga clic en el boton LISTO para ***\n\t*** dejar de introducir su programa. ***\n");
}

int main()
{
	int index, fin = 0, operationCode = 0, instructionRegister = 0, operando = 0, fos, dep, two;
	int ins=0, finish;
	float acumulador = 0, memory[SIZE] = { 0 };
	menu();

	//Esta seccion hace que se busque si hay archivo y tal caso que no que se meta instrucciones manualmente
	if ( leerDisco(memory) )
		for (index = 0; index < SIZE; index++) 
		{
			while (1) 
			{
				printf("%.2d ? ", index);
				scanf("%f", &memory[index]);
				bloon = memory[ins-1];
				if (conversor(memory[index]) == 9999)
				{
					memory[index] = 0;
					index = SIZE; 
					break;
				}
				if (verifPal(memory[index], SIZE))
					printf("La instruccion no es valida\nReescribala:\n");
				else
					break;
			}
			ins++;
		}
	finish = conversor(bloon);

	//Impresion de los numero cuando son extraidos de un archivo
	for (index = 0; index < in; index++)
		printf("+%4.0f\n", memory[index]);
	printf("*  Se termino de cargar el programa  *\n*  Comienza la ejecucion del programa  *\n");

	if (ins == 0)
		ins = in;
	
	//Inicio del programa simulado
	for (index = 0; index < ins; index++) 
	{
		instructionRegister = (int) memory[index];

		//Este apartado revisa de donde se ubica la memoria
		(instructionRegister < 10000) ? (operationCode = instructionRegister / 100) : (operationCode = instructionRegister / 1000);
		(instructionRegister < 10000) ? (operando = instructionRegister % 100) : (operando = instructionRegister % 1000);

		if (operationCode >= BRANCH)
			--operando;
		//Poder usar las diferentes acciones
		switch (operationCode)
		{
		case READ:
			printf("Inserte a leer: ");
			scanf("%f", &memory[operando]);
			break;
		case WRITE:
			printf("\nPosicion de memoria: %.2d\nPalabra: %2.0f\n", operando, memory[operando]);
			break;
		case LOAD:
			acumulador = memory[operando];
			break;
		case STORE:
			memory[operando] = acumulador;
			break;
		case ADD:
			acumulador += memory[operando];
			if (!(acumulador > +9999 || acumulador - 9999))
				fin = 1;
			break;
		case SUBTRACT:
			acumulador -= memory[operando];
			if (!(acumulador > +9999 || acumulador - 9999))
				fin = 1;
			break;
		case DIVIDE:
			acumulador /= memory[operando];
			if (!memory[operando])
				fin = 2;
			break;
		case MULTIPLY:
			acumulador *= memory[operando];
			if (!(acumulador > +9999 || acumulador - 9999))
				fin = 1;
			break;
		case RESIDUO:
			fos = (int)acumulador;
			dep = (int)memory[operando];
			fos %= dep;
			acumulador = (float)fos;
			if (!memory[operando])
				fin = 2;
			break;
		case POTENCIA:
			acumulador = pow(acumulador, memory[operando]);
			break;
		case SALTO:
			printf("\n");
			break;
		case CADENA:
			printf("Inserte a leer: ");
			scanf("%f", &memory[operando]);
			for (two = (operando + 1); two <= memory[operando]+operando; two++)
			{
				printf("Inserte a leer: ");
				scanf("%f", &memory[two]);
			}
			break;
	    case IMPRIMIR:
			for (two = (operando); memory[two] != 0; two++)
				printf("%c", conversor(memory[two]) % 1000 );
			break;
		case BRANCH:
			index = operando;
			break;
		case BRANCHNEG:
			if (acumulador < 0)
				index = operando;
			break;
		case BRANCHZERO:
			if (!acumulador)
				index = operando;
			break;
		case HALT:
			printf("* Terminó la ejecución de Simpletron *\n");
			registro(acumulador, index, memory, ins, finish);
			return 0;
			break;
		case 0:
			break;
		default:
			printf("* ERROR: %d\n", instructionRegister);
			exit(-1);
		}
		//Este apartado revisa ciertos casos particulares como 0/0 u otros
		if (fin == 1 || fin == 2) 
		{
			switch (fin) 
			{
				case 1:
					printf("* Se desparramo el limite del acomulador *\n");
					break;
				case 2:
					printf("* Intento de dividir entre cero *\n");
					break;
			}
			printf("*  La ejecucion de Simpletron termino anormalmente *\n");
			registro(acumulador, index, memory, ins, finish);
			exit(-1);
		}
	}
	//Manda todos los datos a una funcion para imprimir los datos finales
	registro(acumulador, index, memory, ins, finish);
	printf("\nPRODUCTO LICENCIADO POR Cristhian Industry A.C.\n");
	system("PAUSE");
	return 0;
}