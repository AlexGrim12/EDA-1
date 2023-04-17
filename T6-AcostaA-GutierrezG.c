#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 6

typedef struct Nodo {
    int numPaciente;
    struct Nodo *siguiente;
} Nodo;

// Variables Globales
Nodo *HEAD = NULL, *TAIL = NULL;
int queueItems = 0, dato, opcion;

void QInsert () {
    if (queueItems >= MAXQUEUE) {
        printf ("*** Queue saturada, Limite alcanzado ***\n\n");
        return;
    }

    char op;
    Nodo *aux;
    aux = (Nodo *) malloc (sizeof (Nodo));

    printf("Ingrese la identificacion del paciente\n> ");
    scanf("%d", &dato);
    scanf("%*c");
    
    queueItems ++;

    printf("\n*** Tiempo estimado de atencion: %d min ***\n", queueItems - 1);
    printf("Desea ingresar al paciente a la queue? (S/N)\n> ");
    scanf("%c", &op);

    if (op == 's' || op == 'S') {
        aux->numPaciente = dato;
        aux->siguiente = NULL;

        if (HEAD == NULL)
            HEAD = aux;

        if (TAIL == NULL)
            TAIL = aux;
        else {
            TAIL->siguiente = aux;
            TAIL = aux;
        }

        printf("\n*** Paciente %d ingresado con exito ***\n\n", dato);
    }   
    else {
        printf("\n*** No se atendera al paciente ***\n\n");
        queueItems --;
    }
}

void QRemove ()
{
    if (HEAD == NULL)
    {
        printf ("*** Queue Vacia, Ingrese Pacientes ***\n\n");
        return;
    }

    Nodo *aux;
    
    dato = HEAD->numPaciente;

    aux = HEAD;
    HEAD = HEAD->siguiente;
    free (aux);

    queueItems --;

    printf("*** Paciente %d atendido con exito ***\n\n", dato);
}

void showQueue ()
{
    if (HEAD == NULL)
    {
        printf ("*** Queue Vacia, Ingrese Pacientes ***\n\n");
        return;
    }

    Nodo *aux;
    
    aux = HEAD;

    printf("*** Estado de la Queue ***\n");
    while (aux != NULL)
    {
        printf ("%d\n", aux->numPaciente);
        aux = aux->siguiente;
    }
    printf("\n\n");
}

int menu () {
    printf("*********** Queue de Pacientes ********\n");
    printf("1. Agregar\n2. Atender\n3. Mostrar\n4. Salir\n");
    do {
        printf("Opcion?\n> ");
        scanf("%d", &opcion);
    } while (opcion < 1 || opcion > 4);
    printf("\n");

    return opcion;
}

int main ()
{
    do
    {
        opcion = menu();

        switch (opcion)
        {
            case 1: QInsert(); break;
            case 2: QRemove ();break;
            case 3: showQueue (); break;
            default: printf("*** Fin del Programa ***"); break;
        }
    } while (opcion != 4);

    return 0;
}
