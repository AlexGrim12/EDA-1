#include <stdio.h>

//Variables globales
int pares[10], multiCinco[10], suma[10], *ap1, *ap2, *ap3;


void llenarArreglo(int *apuntadorArreglo, int multiplo)
{   
    for (int i = 1; i <= 10; i ++)
        *(apuntadorArreglo + (i - 1)) = multiplo * i;
}

void sumar()
{
    ap3 = &suma[0];
    for (int i = 0; i < 10; i ++)
        *(ap3 + i) = *(ap1 + i) + *(ap2 + i);
}

void mostrarArreglo (int *arreglo)
{
    for (int i = 0; i < 10; i ++)
        printf("%d\t", *(arreglo + i));
    printf("\n");
}

int main()
{
    ap1 = &pares[0];
    llenarArreglo(ap1, 2);

    ap2 = &multiCinco[0];
    llenarArreglo(ap2, 5);
    
    sumar();
    
    printf("\t\t\t.::Arreglo de numeros pares::.\n");
    mostrarArreglo(ap1);

    printf("\n\t\t.::Arreglo de numeros multiplos de cinco::.\n");
    mostrarArreglo(ap2);
    
    printf("\n\t\t\t\t.::Suma::.\n");
    mostrarArreglo(ap3);
    
    return 0;
}