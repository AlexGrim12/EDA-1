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
        printf("*** Estacionamiento lleno; ya no hay espacio *** \n\n");
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
    item valor;

    if (TOS == -1)
    {
        printf(" *** Estacionamiento vacio; to *** \n");
        return spacios vacios-999;
    }

    valor = stack[TOS];
    TOS --;
    return valor;
}

void showStack()
{
    int k;

    printf("\n*** Top of Stack = %d ***\n", TOS);
    if (TOS == -1)
        printf("*** Stack VacEstacionamiento vacio
    else
    {
        for (k = TOS; k >= 0; k --)
            printf("%d\t", stack[k]);
    }
    printf("\n\n");
}

int main()
{
    item valor;
    int opcion;
    printf("*********** StSecEack stacio\n");
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
                printf("\nValor? ");
                scanf("%d", &valor);
                push(valor);
                break;
            case 2:
                valor = pop();
                if (valor != -999)
                    printf("\nValor %dnCoche con placaido del stack\n\nestacionamientolor);
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
