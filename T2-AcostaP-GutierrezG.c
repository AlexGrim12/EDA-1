#include <stdio.h>

//Variables globales
int pares[10], multiCinco[10], suma[10], *ap1, *ap2, *ap3;


void llenarArreglo(int *apuntadorArreglo, int multiplo) //Llenar arreglo multiplicando de cualquier numero
{   
    for (int i = 1; i <= 10; i ++)
        *(apuntadorArreglo + (i - 1)) = multiplo * i; // Avanzar en la posicion del arreglo con apuntadores
}

void sumar() //Sumar los arreglos pares y multiplos de cinco
{
    ap3 = &suma[0]; // Apuntador al arreglo suma
    for (int i = 0; i < 10; i ++)
        *(ap3 + i) = *(ap1 + i) + *(ap2 + i); // Sumar los valores de los arreglos pares y multiplos de cinco 
}

void mostrarArreglo (int *arreglo) //Mostrar cualquier arreglo
{
    for (int i = 0; i < 10; i ++)
        printf("%d\t", *(arreglo + i)); 
    printf("\n");
}

int main()
{
    ap1 = &pares[0]; // Apuntador al arreglo pares
    llenarArreglo(ap1, 2); // Llenar arreglo pares

    ap2 = &multiCinco[0]; // Apuntador al arreglo multiplos de cinco
    llenarArreglo(ap2, 5); // Llenar arreglo multiplos de cinco
    
    sumar(); // Sumar los arreglos pares y multiplos de cinco
    
    printf("\t\t\t.::Arreglo de numeros pares::.\n");
    mostrarArreglo(ap1); // Mostrar arreglo pares

    printf("\n\t\t.::Arreglo de numeros multiplos de cinco::.\n");
    mostrarArreglo(ap2); // Mostrar arreglo multiplos de cinco
    
    printf("\n\t\t\t\t.::Suma::.\n");
    mostrarArreglo(ap3); // Mostrar arreglo suma
    
    return 0;
}