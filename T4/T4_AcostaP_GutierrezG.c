#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigoPrt;
    char descripcionPrt[20];
    float precioPrt;
    int existenciaPrt;
} Producto;

void mostrarPrt(Producto *P) // Muestra los datos de una variable de tipo Producto en pantalla
{
    printf("  %d\t\t%s\t$%.2f\t\t    %d\n", P->codigoPrt, P->descripcionPrt, P->precioPrt, P->existenciaPrt);
}

void rellenarPrt(int codigo, char descripcion[], float precio, int existencia, Producto *P) // Asgina los datos a una variable de tipo Producto 
{
    P->codigoPrt = codigo; 
    strcpy(P->descripcionPrt, descripcion);
    P->precioPrt = precio;
    P->existenciaPrt = existencia;
}

int main()
{
    Producto *pP, *pProds;
    char nC[2];
    int n;

    pP = (Producto *) malloc(sizeof(Producto));

    pP->codigoPrt = 10;
    strcpy(pP->descripcionPrt, "Conector");
    pP->precioPrt = 5; 
    pP->existenciaPrt = 20; 

    printf("Codigo\t\tDescripcion\tPrecio\t\tExistencia\n");
    mostrarPrt(pP);

    printf("\nCuantos productos?\n"); 
    do
    {
        printf("> "); 
        scanf("%s", nC);
        n = atoi(nC);

        if (n < 3 || n > 5)
            printf("Vuelvelo a escribir\n");
        fflush(stdin);
    } while (n < 3 || n > 5);
    
    pProds = (Producto *) calloc(n, sizeof(Producto));

    rellenarPrt(3,  "Camara  ", 250, 5, pProds);
    rellenarPrt(8,  "Hub     ", 60,  8, pProds + 1);
    rellenarPrt(12, "Teclado ", 120, 6, pProds + 2);

    if (n >= 4)
    {
        rellenarPrt(15, "Mouse   ", 40, 10, pProds + 3);
        
        if (n == 5)
            rellenarPrt(18, "TV       ", 560, 4,  pProds + 4);
    }
        
    printf("\n\t\t    ..:::Arreglo:::..\n");
    printf("Codigo\t\tDescripcion\tPrecio\t\tExistencia\n");
    for (int i = 0; i < n; i ++)
        mostrarPrt(pProds + i);
    
    return 0;
}