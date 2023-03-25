#include <stdio.h>
#define MAXSTACK 5 // Máximo tamaño del stack

int stack[MAXSTACK], stackCopia[MAXSTACK], TOS = -1, TOSC = -1;

void push(int dato)
{
    TOS ++;

    if (TOS >= MAXSTACK) // Comprobar si el stack esta lleno
    {
        printf("\t*** Estacionamiento lleno, ya no hay espacio *** \n\n");
        TOS --;
        return;
    }
    
    stack[TOS] = dato; // Agregar dato al stack
    printf("\t*** El coche con placa %d ingreso en el estacionamiento ***\n\n", dato);
}

void pop()
{
    if (TOS == -1) // Comprobar si el stack esta vacio
    {
        printf("\n\t*** Estacionamiento vacio ***\n\n");
        return;
    }

    printf("\n\t*** El coche con placa %d salio del estacionamiento ***\n\n", stack[TOS]);
    TOS --; // Eliminar dato del stack
}

void popDato(int dato)
{
    int flag = 0;

    while (TOS != -1 && flag == 0)
    {
        if (stack[TOS] == dato) // Comprobar que el dato exista en el stack
        {
            printf("\t*** El coche con placa %d salio del estacionamiento ***\n\n", dato);
            flag = 1;
        }
        else // Si en esa posicion no esta el dato, se transpasa a otro stack y se avanza la posicion
        {
            TOSC ++;
            stackCopia[TOSC] = stack[TOS];
            TOS --;
        }
    }

    while (TOSC != -1) // Devolver datos del stack copia al stack original
    {
        stack[TOS] = stackCopia[TOSC];
        TOS ++;
        TOSC --;
    }
    
    if (flag == 0) 
        printf("\t*** No se encontro el coche con placa %d en el estacionamiento ***\n\n", dato);
    else
        TOS --;
}

void showStack()
{
    if (TOS == -1) // Comprobar si hay elementos
        printf("\n\t*** Estacionamiento vacio ***");
    else // Imprimir datos
    {
        printf("\n\t*** Lugares ocupados = %d ***\n", TOS + 1);
        for (int i = TOS; i > -1; i --)
            printf("%d\t", stack[i]);
    }
    printf("\n\n");
}

int main()
{
    int placa, opcion;

    printf("\t*** Bienvenido al Estacionamiento 'Champs' ***\n");
    while (opcion != 5)
    {
        printf("1. Push\n2. Pop\n3. Pop de placa especifica\n4. Mostrar Stack\n5. Salir\nOpcion? "); // Menu 
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1: 
                printf("\n\tPlaca del auto? ");
                scanf("%d", &placa);
                push(placa);
                break;
            case 2: pop(); break;
            case 3: 
                printf("\n\tPlaca del auto? ");
                scanf("%d", &placa);
                popDato(placa);
                break;
            case 4: showStack();
            default: break;
        }
        
        if (opcion > 5) // Si la opcion es mayor a 5 se repite el menu
            printf("\n\t*** Opcion no valida ***\n\n");   
    }

    printf("\n*** Fin del Programa ***\n"); // Cuando la opcion es 5 se acaba la ejecución

    return 0;
}