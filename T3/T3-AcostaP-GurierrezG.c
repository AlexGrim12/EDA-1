#include <stdio.h>
#include <string.h>

FILE *archivoB;

struct Producto
{
    int codigoPrt;
    char descripcionPrt[100];
    float precioPrt;
    int existenciaPrt;
}P1, P2, P3, P4, arrayP[8];

void constructor(int codigo, char descripcion[], float precio, int existencia, struct Producto *P)
{
    P->codigoPrt = codigo;
    strcpy(P->descripcionPrt, descripcion);
    P->precioPrt = precio;
    P->existenciaPrt = existencia;
}

void mostrar(struct Producto P)
{
    printf("%d\t%s\t$%3.2f\t\t%d\n", P.codigoPrt, P.descripcionPrt, P.precioPrt, P.existenciaPrt);
}

void guardarArchBinario(struct Producto P)
{
    fprintf(archivoB, "%d\t\t%s  \t$%3.2f\t\t%d\n", P.codigoPrt, P.descripcionPrt, P.precioPrt, P.existenciaPrt);
}

int main()
{
    struct Producto P5;
    
    P5.codigoPrt = 10;
    strcpy(P5.descripcionPrt, "Conector");
    P5.precioPrt = 5;
    P5.existenciaPrt = 20;
    
    constructor(3, "Camara   ", 250, 5, &P1);
    constructor(8, "Hub      ", 60, 8, &P2);
    constructor(12, "Teclado ", 120, 6, &P3);
    constructor(15, "Mouse   ", 40, 10, &P4);
    
    mostrar(P1);
    mostrar(P2);
    mostrar(P3);
    mostrar(P4);
    mostrar(P5);
    
    arrayP[0] = P1;
    arrayP[1] = P2;
    arrayP[2] = P3;
    arrayP[3] = P4;
    arrayP[4] = P5;
    
    constructor(18, "TV       ", 560, 4, &arrayP[5]);
    constructor(20, "Laptop   ", 300, 10, &arrayP[6]);
    
    printf("\nArreglo:\n");
    for(int i = 0; i < 7; i ++)
        mostrar(arrayP[i]);
    
    archivoB = fopen("T3-AcostaP-GurierrezG.bin", "w");
    
    for(int i = 0; i < 7; i ++)
        guardarArchBinario(arrayP[i]);
        
    fclose(archivoB);
}