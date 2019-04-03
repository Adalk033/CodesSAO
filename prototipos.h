

//Prototipos de funcion

void push(union tipos dato);
union tipos pop();
int isEmpty();
union tipos stackTop();
void imprime();


int profundidad(char express[]);
int prec(union tipos cad, char ope2);
void postfijo(char express[]);
double evaluar(char express[]);