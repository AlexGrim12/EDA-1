#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

Nodo *lista = NULL;

void insertarLista(Nodo **lista, int n) { // Cambiar la firma de la función
    Nodo *nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    nuevoNodo->dato = n;

    Nodo *aux1 = *lista, *aux2 = NULL; // Inicializar aux2 como NULL

    while (aux1 != NULL && aux1->dato < n) {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    
    if(aux2 == NULL) *lista = nuevoNodo; // Si el nodo a insertar es el primero
    else aux2->siguiente = nuevoNodo;
    
    nuevoNodo->siguiente = aux1;

    printf("\tElemento %d insertado a la lista\n\n", n);
}

void mostrarLista(Nodo *lista) {
    Nodo *actual = lista; // No es necesario asignar memoria nueva

    if(actual != NULL) printf(".:Elementos de la lista:.\n");
    else printf("Lista Vacia");

    while (actual != NULL) {
        printf("%d \t", actual->dato);
        actual = actual->siguiente;
    }
}

void buscarLista(Nodo *lista, int n) {
    Nodo *actual = lista; // No es necesario asignar memoria nueva
    bool flag = false;

    while (actual != NULL && actual->dato <= n) {
        if(actual->dato == n) flag = true;
        actual = actual->siguiente;
    }
    
    if(flag == true) printf("\tSe encontro el elemento %d en la lista!!!\n", n);
    else printf("\tNo se encontro el elemento %d en la lista!!!\n", n);
}

void eliminarNodo(Nodo **lista, int n) // Cambiar la firma de la función
{
    if(*lista == NULL) {
        printf("\nLista Vacia\n");
        return;
    }

    Nodo *auxBorrar = *lista, *anterior = NULL;

    while (auxBorrar != NULL && auxBorrar->dato != n)    {
        anterior = auxBorrar;
        auxBorrar = auxBorrar->siguiente;
    }

    if(auxBorrar == NULL) printf("\tElemento no encontrado\n");
    else if(anterior == NULL) {   
        *lista = (*lista)->siguiente;
        free(auxBorrar);
        printf("\tElemento borrado con exito!!!\n");
    }
    else {
        anterior->siguiente = auxBorrar->siguiente;
        free(auxBorrar);
        printf("\tElemento borrado con exito!!!\n");
    }
}

int menu() {
    int op;

    printf("\t.::Menu::.\n");
    printf("1. Insertar un numero a la lista\n");
    printf("2. Mostrar los elementos de la lista\n");
    printf("3. Buscar elemento en la lista\n");
    printf("4. Eleminar elemento de la lista\n");
    printf("5. Salir\n\n");
    
    do {
        printf("Ingrese una opcion: ");
        scanf("%d", &op);
        printf("\n");
    } while(op < 1 || op > 6);

    return op;
}

int main() {
    int dato, op;
    
    do {
        op = menu();

        switch(op) {
            case 1:
                printf("Ingrese un numero: ");
                scanf("%d", &dato);
                insertarLista(&lista, dato);
                break;
            
            case 2:
                mostrarLista(lista);
                printf("\n");
                break;

            case 3:
                printf("Ingrese el elemento a buscar: "); 
                scanf("%d", &dato);
                buscarLista(lista, dato);
                printf("\n");
                break; 

            case 4:
                printf("Ingrese el elemento a elminar: "); 
                scanf("%d", &dato);
                eliminarNodo(&lista, dato);
                printf("\n");
                break;

            default:
                printf("Gracias por usar el programa!!!");
                break; 
        }
    } while(op != 5);

    return 0;
}