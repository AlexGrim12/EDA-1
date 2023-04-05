#include <stdio.h>
#define MAXSTACK 10 // Máximo tamaño del stack

int stack[MAXSTACK], stackCopia[MAXSTACK], TOS = -1, TOSC = -1;

void push(int dato) {
    TOS ++;

    if (TOS >= MAXSTACK) { // Comprobar si el stack esta lleno
        printf("\t*** Estacionamiento lleno, ya no hay espacio *** \n\n");
        TOS --;
    } else {
        printf("\t*** Estacionamiento con espacio ***\n");
        stack[TOS] = dato; // Agregar dato al stack
        printf("\t*** El coche con placa %d ingreso en el estacionamiento ***\n\n", dato);
    }
}

void pop() {
    if (TOS == -1) // Comprobar si el stack esta vacio
        printf("\n\t*** Estacionamiento vacio ***\n\n");
    else {
        printf("\n\t*** El coche con placa %d salio del estacionamiento ***\n\n", stack[TOS]);
        TOS --; // Eliminar dato del stack
    }
}

void popDato(int dato) {
    int movimientos = 0, i = 0;

    if (TOS == -1) {// Comprobar si el stack esta vacio
        printf("\n\t*** Estacionamiento vacio ***\n\n");
        return;
    }

    while (stack[TOS] != dato && i < MAXSTACK) { // Mientras el dato no sea el que se busca
        TOSC ++; 
        stackCopia[TOSC] = stack[TOS]; // Agregar dato al stack copia
        TOS --; 
        movimientos ++; // Aumentar el numero de movimientos
        i ++;
    }

    if (i >= MAXSTACK)
        printf("\t*** No se encontro el coche en el estacionamiento ***\n\n");
    else {
        printf("\n\t*** El coche con placa %d salio del estacionamiento ***\n", dato);
        TOS --; // Eliminar dato del stack
        printf("\t*** Movimientos del estacionamiento: %d ***\n\n", movimientos);
    }

    while (TOSC != -1) { // Mientras el stack copia no este vacio
        TOS ++;
        stack[TOS] = stackCopia[TOSC]; // Agregar dato al stack
        TOSC --; // Eliminar dato del stack copia
    }
}


void showStack() {
    if (TOS == -1) // Comprobar si hay elementos
        printf("\n\t*** Estacionamiento vacio ***");
    else { // Imprimir datos
        printf("\n\t*** Lugares ocupados = %d ***\n", TOS + 1);
        for (int i = TOS; i > -1; i --)
            printf("%d\t", stack[i]);
    }
    printf("\n\n");
}

int main() {
    int placa, opcion;

    printf("\t*** Bienvenido al Estacionamiento 'Champs' ***\n");
    while (opcion != 5) {
        printf("1. Push\n2. Pop\n3. Pop de placa especifica\n4. Mostrar Stack\n5. Salir\nOpcion? "); // Menu 
        scanf("%d", &opcion);
        switch (opcion) {
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
        
        if (opcion < 1 || opcion > 5) // Si la opcion es mayor a 5 se repite el menu
            printf("\n\t*** Opcion no valida ***\n\n");   
    }

    printf("\n*** Fin del Programa ***\n"); // Cuando la opcion es 5 se acaba la ejecución

    return 0;
}