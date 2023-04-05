#include <stdio.h>
#define MAXSTACK 10 // Máximo tamaño del stack

int stack[MAXSTACK], stackC[MAXSTACK], TOS = -1, TOSC = -1;

void push(int dato) { // Agregar dato al stack
    TOS ++; // Avanzar una posición en el stack para agregar el dato

    if (TOS >= MAXSTACK) { // Comprobar si el stack esta lleno
        printf("\t*** Estacionamiento lleno, ya no hay espacio *** \n\n");
        TOS --; // Retroceder una posición en el stack para no pasar el limite
    } else {
        printf("\t*** Estacionamiento con espacio ***\n");
        stack[TOS] = dato; // Agregar dato al stack
        printf("\t*** El coche con placa %d ingreso en el estacionamiento ***\n\n", dato); 
    }
}

void pop() { // Eliminar el último dato en entrar al stack
    if (TOS == -1) // Comprobar si el stack esta vacio
        printf("\n\t*** Estacionamiento vacio ***\n\n");
    else {
        printf("\n\t*** El coche con placa %d salio del estacionamiento ***\n\n", stack[TOS]);
        TOS --; // Retroceder una posición en el stack para sobreescribir el dato
    }
}

void popDato(int dato) { // Eliminar un dato especifico del stack
    int movimientos = 0, i = 0;

    if (TOS == -1) { // Comprobar si el stack esta vacio
        printf("\n\t*** Estacionamiento vacio ***\n\n");
        return; // Terminar la función
    }

    // Buscar el dato en el stack y agregar los otros datos a un stack copia
    while (stack[TOS] != dato && i < MAXSTACK) { // Mientras el dato no sea el que se busca y no se haya recorrido todo el stack
        TOSC ++; // Avanzar una posición en el stack copia para agregar el dato
        stackC[TOSC] = stack[TOS]; // Agregar dato al stack copia
        TOS --; // Retroceder una posición en el stack
        movimientos ++; // Contador de movimientos del stack
        i ++; // Contador de iteraciones
    }

    if (i >= MAXSTACK) // Si se recorrio todo el stack y no se encontro el dato
        printf("\t*** No se encontro el coche en el estacionamiento ***\n\n");
    else {
        printf("\n\t*** El coche con placa %d salio del estacionamiento ***\n", dato);
        TOS --; // Liberar el espacio del dato eliminado
        printf("\t*** Movimientos del estacionamiento: %d ***\n\n", movimientos);
    }

    while (TOSC != -1) { // Mientras el stack copia no este vacio
        TOS ++; // Avanzar una posición en el stack original para agregar el dato
        stack[TOS] = stackC[TOSC]; // Agregar dato al stack original
        TOSC --; // Retroceder una posición en el stack copia
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

    printf("\t*** Bienvenido al Registro del Estacionamiento***\n");
    while (opcion != 5) { // Mientras la opcion no sea 5 se repite el menu
        printf("1. Push\n2. Pop\n3. Pop de placa especifica\n4. Mostrar Stack\n5. Salir\nOpcion? "); // Menu 
        scanf("%d", &opcion);
        switch (opcion) {
            case 1: // Agregar dato al stack
                printf("\n\tPlaca del auto? ");
                scanf("%d", &placa);
                push(placa);
                break;
            case 2: // Eliminar el último dato en entrar al stack
                pop(); 
                break; 
            case 3: // Eliminar un dato especifico del stack
                printf("\n\tPlaca del auto? ");
                scanf("%d", &placa);
                popDato(placa);
                break;
            case 4: // Mostrar el stack
                showStack();
            default: 
                break;
        }
        
        if (opcion < 1 || opcion > 5) // Si la opcion es menor a 1 o mayor a 5 se muestra un mensaje de error
            printf("\n\t*** Opcion no valida ***\n\n");   
    }

    printf("\n*** Fin del Programa ***\n"); // Cuando la opcion es 5 se acaba la ejecución

    return 0;
}