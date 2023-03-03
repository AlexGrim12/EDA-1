#include <stdio.h>

//Variables Globales
int autos[5][3], sumaFilas[5], sumaColumnas[3];
int porcentajes[5][3], sumaPoFilas[5], sumaPoColumnas[3];
int menorMarca, menorPeriodo, mayorMarca, mayorPeriodo;
char marcas[5][10] = {"Ford", "BMW ", "Toyota", "Tesla", "Nissan"};
char periodos[4][10] = {"Oct.", "Nov.", "Dic.", "Total"};

//Funciones
void llenarMatriz() //Llenar la matriz con datos que ingrese el usario
{
    int flag = 0;
    printf("Ingrese los valores: \n");
    for(int i = 0; i < 5; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            do 
            {
                printf("[%d][%d]: ", i, j);
                scanf("%d", &autos[i][j]);

                if (autos[i][j] < 0 || autos[i][j] > 10)
                    printf("Valor invalido, vuelva a ingresarlo\n");
                else 
                    flag = 1;
            } while (flag == 0);
            flag = 0;
        }
        printf("\n");
    }
}

void sumarFiCo(int matriz[5][3], int sumaF[], int sumaC[]) //Obtener el total de autos por marca y por mes
{
    for(int i = 0; i < 5; i ++)
    {
        sumaF[i] = 0;
        for(int j = 0; j < 3; j ++)
            sumaF[i] += matriz[i][j];
    }

    for(int i = 0; i < 3; i ++) 
    {
        sumaC[i] = 0;
        for(int j = 0; j < 5; j ++)
            sumaC[i] += matriz[j][i];
    }
}

void mostrarMatriz(int matriz[5][3], int sumaF[], int sumaC[]) //Mostrar cualquier matriz que se le mande
{
    for (int i = 0; i < 4; i++)
        printf("\t%s", periodos[i]);

    printf("\n");
    for(int i = 0; i < 5; i ++)
    {
        printf("%s", marcas[i]);
        for(int j = 0; j < 3; j ++)
            printf("\t%d", matriz[i][j]);
        printf("\t  %d", sumaF[i]);
        printf("\n");
    }

    printf("\nTotal");
    for (int i = 0; i < 3; i++)
        printf("\t%d", sumaC[i]); 
}

void matrizPorcentaje1() 
{
    for(int i = 0; i < 5; i ++)
    {
        for(int j = 0; j < 3; j ++)
            porcentajes[i][j] = (autos[i][j] * 100) / sumaColumnas[j];
    }
}

void matrizPorcentaje2()
{
    for(int i = 0; i < 5; i ++)
    {
        for(int j = 0; j < 3; j ++)
            porcentajes[i][j] = (autos[i][j] * 100) / sumaFilas[i];
    }
}

void ventaBajaAlta() //Obtener la venta mas baja y alta
{
    int menor = 11, mayor = -1;

    for(int i = 0; i < 5; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            if (autos[i][j] < menor)
            {
                menorMarca = i;
                menorPeriodo = j;
                menor = autos[i][j];
            }

            if (autos[i][j] > mayor)
            {
                mayorMarca = i;
                mayorPeriodo = j;
                mayor = autos[i][j];
            }
        }
    }
}

void crearArchivo()
{
    FILE *archivo;
    archivo = fopen("T1-AcostaA-GurierrezA.txt", "w");

    fprintf(archivo, "..::::Matriz Original::::..\n\t");
    for (int i = 0; i < 4; i++)
        fprintf(archivo, "\t%s", periodos[i]);

    fprintf(archivo, "\n");
    for(int i = 0; i < 5; i ++)
    {
        fprintf(archivo, "%s", marcas[i]);
        for(int j = 0; j < 3; j ++)
            fprintf(archivo, "\t%d\t", autos[i][j]);
        fprintf(archivo, "\t  %d", sumaFilas[i]);
        fprintf( archivo, "\n");
    }

    fprintf(archivo, "\nTotal");
    for (int i = 0; i < 3; i++)
        fprintf(archivo, "\t%d\t", sumaColumnas[i]); 
    
    fclose(archivo);

    printf("\n\nEl archivo se creo con exito");
}

//Funcion principal
int main()
{
    //Matriz Inicial
    llenarMatriz();
    sumarFiCo(autos, sumaFilas, sumaColumnas);
    printf("..::::Matriz::::..\n");
    mostrarMatriz(autos, sumaFilas, sumaColumnas);

    //Matriz porcentaje marca por mes
    matrizPorcentaje1();
    sumarFiCo(porcentajes, sumaPoFilas, sumaPoColumnas);
    printf("\n\n..::::Porcentaje de contribucion de cada marca en cada mes::::..\n");
    mostrarMatriz(porcentajes, sumaPoFilas, sumaPoColumnas);

    //Matriz porcentaje mes por marca
    matrizPorcentaje2();
    sumarFiCo(porcentajes, sumaPoFilas, sumaPoColumnas);
    printf("\n\n..::::Porcentaje de contribucion de cada mes al total de la marca::::..\n");
    mostrarMatriz(porcentajes, sumaPoFilas, sumaPoColumnas);    

    //Venta mayor y menor
    ventaBajaAlta();
    printf("\n\n..::::Venta mas baja::::..\n");
    printf("Marca: %s\nMes: %s", marcas[menorMarca], periodos[menorPeriodo]);
    printf("\n\n..::::Venta mas alta::::..\n");
    printf("Marca: %s\nMes: %s", marcas[mayorMarca], periodos[mayorPeriodo]);

    //Guardar matriz original en archivo
    crearArchivo();

    return 0;
}