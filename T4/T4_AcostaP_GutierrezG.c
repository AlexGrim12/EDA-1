#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura Producto
typedef struct 
{
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

    pP = (Producto *) malloc(sizeof(Producto)); // Asignación de memoria dinamica

    rellenarPrt(10,  "Conector  ", 5, 20, pP); // Asgnación de valores a primera variable 

    // Mostrando valores de primera variable 
    printf("Codigo\t\tDescripcion\tPrecio\t\tExistencia\n");
    mostrarPrt(pP);

    // Preguntar cuantos espacios del array dinamico pProds quiere usar el usuario 
    printf("\nCuantos productos?\n"); 
    do
    {
        printf("> "); 
        scanf("%s", nC); 
        n = atoi(nC); // Convertir de string a int para evitar errores 

        // Solo acepta entre 3 y 5
        if (n < 3 || n > 5)
            printf("Opcion invalida\n");
        fflush(stdin);
    } while (n < 3 || n > 5);
    
    pProds = (Producto *) calloc(n, sizeof(Producto)); // Asginación de memoria dinamica a array 

    // Rellenando primeros tres lugares del array
    rellenarPrt(3,  "Camara  ", 250, 5, pProds);
    rellenarPrt(8,  "Hub     ", 60,  8, pProds + 1);
    rellenarPrt(12, "Teclado ", 120, 6, pProds + 2);

    if (n >= 4)
    {
        // Rellenando el espacio 4 si el usuario lo decide
        rellenarPrt(15, "Mouse   ", 40, 10, pProds + 3);

        // Rellenando el espacio 5 si el usuario lo decide
        if (n == 5)
            rellenarPrt(18, "TV       ", 560, 4,  pProds + 4);
    }
        
    // Imprimiendo valores del array
    printf("\n\t\t    ..:::Arreglo:::..\n");
    printf("Codigo\t\tDescripcion\tPrecio\t\tExistencia\n");
    for (int i = 0; i < n; i ++)
        mostrarPrt(pProds + i);
    
    // Liberando memoria
    free(pP);
    free(pProds);

    return 0;
}