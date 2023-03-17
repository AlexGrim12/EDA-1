#include <stdio.h>
#include <string.h>

// Variables globales
FILE *archivoB;

// Estructura Producto
typedef struct 
{
    int codigoPrt;
    char descripcionPrt[20];
    float precioPrt;
    int existenciaPrt;
} Producto;

Producto P1, P2, P3, P4, arrayP[8], datosArchivo[7]; // Definición de cuatro variables y un arreglo de 8 variables de tipo Producto

// Funciones
void rellenarPrt(int codigo, char descripcion[], float precio, int existencia, Producto *P) // Asgina los datos a una variable de tipo Producto 
{
    P->codigoPrt = codigo; 
    strcpy(P->descripcionPrt, descripcion);
    P->precioPrt = precio;
    P->existenciaPrt = existencia;
}

void mostrarPrt(Producto P) // Muestra los datos de una variable de tipo Producto en pantalla
{
    printf("  %d\t\t%s\t$%.2f\t\t    %d\n", P.codigoPrt, P.descripcionPrt, P.precioPrt, P.existenciaPrt);
}

int main()
{
    Producto P5; // Definición de una quinta variable de tipo Producto
    
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
    
    // Guardando los datos en archivo binario
    archivoB = fopen("T3-AcostaP-GurierrezG.bin", "wb");
    fwrite(arrayP, sizeof(Producto), 7, archivoB);
    fclose(archivoB);

    // Leyendo datos del archivo y guardandolos en array datosArchivo[]
    archivoB = fopen("T3-AcostaP-GurierrezG.bin", "rb");
    fread(datosArchivo, sizeof(Producto), 7, archivoB);
    fclose(archivoB);

    // Mostrando contenido del archivo
    printf("\n.::Archivo::.\n");
    printf("Codigo\t\tDescripcion\tPrecio\t\tExistencia\n");
    for(int i = 0; i < 7; i ++)
        mostrarPrt(datosArchivo[i]);

    return 0;
}