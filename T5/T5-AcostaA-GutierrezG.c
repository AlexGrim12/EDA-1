#include <stdio.h>
#define STACKSIZE 5
typedef int item;

item stack[STACKSIZE];
int TOS = -1;

void push(item k)
{
    TOS ++;

    if (TOS >= STACKSIZE)
    {
        printf("*** Estacionamiento lleno, ya no hay espacio *** \n\n");
        TOS --;
    }
    else 
    {
        stack[TOS] = k;
        printf("Coche con placa %d insertado en el estacionamiento\n\n", k);
    }
}

item pop()
{
    item placa;

    if (TOS == -1)
    {
        printf(" *** Estacionamiento vacio *** \n");
        return -999;
    }

    placa = stack[TOS];
    TOS --;
    return placa;
}

void showStack()
{
    int k;

    printf("\n*** Top of Stack = %d ***\n", TOS);
    if (TOS == -1)
        printf("*** Estacionamiento vacio ***");
    else
    {
        for (k = TOS; k >= 0; k --)
            printf("%d\t", stack[k]);
    }
    printf("\n\n");
}

int main()
{
    item placa;
    int opcion;
    printf("*** Bienvenido al Estacionamiento 'Champs' ***\n");
    while (opcion != 4)
    {
        printf("\t1. Push\n");
        printf("\t2. Pop\n");
        printf("\t3. Mostrar Stack\n");
        printf("\t4. Salir\n");
        printf("\tOpcion? ");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1:
                printf("\nPlaca del auto? ");
                scanf("%d", &placa);
                push(placa);
                break;
            case 2:
                placa = pop();
                if (placa != -999)
                    printf("\nCoche con placa %d salio del estacionamiento\n\n");
                break;
            case 3:
                showStack();
            default:
                break;
        }
        
        if (opcion > 4)
            printf("\nOpcion no valida\n\n");   
    }

    printf("\n*********** Fin del Programa ********\n");
}
