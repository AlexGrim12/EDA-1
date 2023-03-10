#include <stdio.h>
#include <string.h>

// Variables globales
FILE *archivoB;

// Estructura Producto
struct Producto
{
    int codigoPrt;
    char descripcionPrt[20];
    float precioPrt;
    int existenciaPrt;
}P1, P2, P3, P4, arrayP[8]; // Definición de cuatro variables y un arreglo de 8 variables de tipo Producto

// Funciones
void rellenarPrt(int codigo, char descripcion[], float precio, int existencia, struct Producto *P) // Asgina los datos a una variable de tipo Producto 
{
    P->codigoPrt = codigo; 
    strcpy(P->descripcionPrt, descripcion);
    P->precioPrt = precio;
    P->existenciaPrt = existencia;
}

void mostrarPrt(struct Producto P) // Muestra los datos de una variable de tipo Producto en pantalla
{
    printf("  %d\t\t%s\t$%.2f\t\t    %d\n", P.codigoPrt, P.descripcionPrt, P.precioPrt, P.existenciaPrt);
}

void guardarArchivoB(struct Producto P) 
{
    fprintf(archivoB, "  %d \t\t%s  \t\t$%.2f    \t\t    %d\n", P.codigoPrt, P.descripcionPrt, P.precioPrt, P.existenciaPrt);
}

int main()
{
    struct Producto P5; // Definición de una quinta variable de tipo Producto
    
    // Asignación manual de datos a la quinta variable
    P5.codigoPrt = 10;
    strcpy(P5.descripcionPrt, "Conector");
    P5.precioPrt = 5;
    P5.existenciaPrt = 20;
    
    // Asignación de datos a las variables mediante la función rellenarPrt
    rellenarPrt(3,  "Camara  ", 250, 5, &P1);
    rellenarPrt(8,  "Hub     ", 60,  8, &P2);
    rellenarPrt(12, "Teclado ", 120, 6, &P3);
    rellenarPrt(15, "Mouse   ", 40, 10, &P4);
    
    // Impresión de los datos de las variables en pantalla
    printf("Codigo\t\tDescripcion\tPrecio\t\tExistencia\n");
    mostrarPrt(P1);
    mostrarPrt(P2);
    mostrarPrt(P3);
    mostrarPrt(P4);
    mostrarPrt(P5);
    
    // Asignación de las cinco variables existentes a un arreglo
    arrayP[0] = P1;
    arrayP[1] = P2;
    arrayP[2] = P3;
    arrayP[3] = P4;
    arrayP[4] = P5;
    
    // Rellenando dos espacios vacíos del arreglo de tipo Producto 
    rellenarPrt(18, "TV       ", 560, 4,  &arrayP[5]);
    rellenarPrt(20, "Laptop   ", 300, 12, &arrayP[6]);
    
    // Impresión del arreglo en pantalla
    printf("\n.::Arreglo::.\n");
    printf("Codigo\t\tDescripcion\tPrecio\t\tExistencia\n");
    for(int i = 0; i < 7; i ++)
        mostrarPrt(arrayP[i]);
    
    // Abriendo archivo binario en modo escritura
    archivoB = fopen("T3-AcostaP-GurierrezG.bin", "w");
    
    // Guardando el arreglo en el archivo binario
    fprintf(archivoB, "Codigo\tDescripcion\t\tPrecio\t\tExistencia\n");
    for(int i = 0; i < 7; i ++)
        guardarArchivoB(arrayP[i]);
        
    // Cerrando archivo binario
    fclose(archivoB);

    return 0;
}