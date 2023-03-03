#include <stdio.h>

//Variables globales
int pares[10], multiCinco[10], suma[10], *apuntador1, *apuntador2, *apuntador3;


void llenarPares()
{   
    int j = 1, flag = 0;
    apuntador1 = &pares[0];
    
    for (int i = 0; i < 10; i ++)
    {
        do 
        {
            *(apuntador1 + i) = j ++;
            
            if (*(apuntador1 + i) % 2 != 0)
                flag = 0;
            else
                flag = 1;
        } while (flag == 0);
    }
}

void llenarMultiCinco()
{
    int j = 1, flag = 0;
    apuntador2 = &multiCinco[0];
    
    for (int i = 0; i < 10; i ++)
    {
        do 
        {
            *(apuntador2 + i) = j ++;
            
            if (*(apuntador2 + i) % 5 != 0)
                flag = 0;
            else
                flag = 1;
        } while (flag == 0);
    }
}

void sumar ()
{
    apuntador3 = &suma[0];
    for (int i = 0; i < 10; i ++)
        *(apuntador3 + i) = *(apuntador1 + i) + *(apuntador2 + i);
}

void mostrarArreglo (int *arreglo)
{
    for (int i = 0; i < 10; i ++)
        printf("%d\t", *(arreglo + i));
    printf("\n");
}

int main()
{
    llenarPares();
    llenarMultiCinco();
    
    sumar();
    
    printf("\n\t\t\t.::Arreglo de numeros pares::.\n");
    mostrarArreglo(apuntador1);
    printf("\n\t\t.::Arreglo de numeros multiplos de cinco::.\n");
    mostrarArreglo(apuntador2);
    printf("\n\t\t\t\t.::Suma::.\n");
    mostrarArreglo(apuntador3);
    
    return 0;
}