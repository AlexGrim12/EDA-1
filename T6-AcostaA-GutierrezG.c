#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 5
typedef int item;

typedef struct
{
  item dato;
  Nodo *link;
  int emergencia;
} Nodo;

Nodo *HEAD = NULL, *TAIL = NULL;
int queueItems = 0;

void QInsert (item valor)
{
  Nodo *pN;
  if (queueItems >= MAXQUEUE)
    {
      printf ("*** Queue saturada; ya no hay espacio ***\n");
      return;
    }
  pN = (Nodo *) malloc (sizeof (Nodo));
  pN->dato = valor;
  pN->emergencia = 0;
  pN->link = NULL;
  if (HEAD == NULL)
      HEAD = pN;
  if (TAIL == NULL)
      TAIL = pN;
  else
    {
      TAIL->link = pN;
      TAIL = pN;
    }
  queueItems ++;
  printf ("pN=%p\tHead=%p\tTail=%p\n\n", pN, HEAD, TAIL);
}

item QRemove ()
{
  item valor;
  Nodo *pN;
  if (HEAD == NULL)
    {
      printf ("*** Queue Underflow - Cola vacia ***\n");
      return -999;
    }
   
  if (HEAD->emergencia = 0) 
    queueItems --;
  valor = HEAD->dato;
  pN = HEAD;
  HEAD = HEAD->link;
  free (pN);
  
  return valor;
}

void abandonQueue (item valor)
{
    Nodo *p1, *p2;
    int found = 0;
  
    if (HEAD == NULL)
    {
      printf ("*** Queue Underflow; Cola vacia ***\n");
      return;
    }
    
    if (HEAD->dato == valor)	// Es el primero
    {
        HEAD = p1->link;
        free (p1);
        found = 1;
      queueItems--;
      return;
    }
    
    p1 = HEAD;
    p2 = p1->link;
  
    while (1)
    {
        if (p2->dato == valor)
	    {
	        p1->link = p2->link;
            found = 1;
	        queueItems--;
	        
	        return;
	    }
        else
	    {
	        p1 = p2;
	        p2 = p2->link;
	    }
	    
        if (p2 == NULL)
	        break;
    }
}

void emergencia (item valor)
{
  Nodo *pN;
  pN = (Nodo *) malloc (sizeof (Nodo));
  pN->dato = valor;
  pN->link = HEAD;
  pN->emergencia = 1;
  HEAD = pN;
}

void showQueue ()
{
  int k;
  Nodo *pN;
  
  printf ("*** Estado de Queue \tHEAD=%p\tTAIL=%p ***\n", HEAD, TAIL);
  if (HEAD == NULL)
    {
      printf ("*** Empty Queue ***\n\n");
      return;
    }
  pN = HEAD;
  while (pN != NULL)
    {
      printf ("%d %p\n", pN->dato, pN->link);
      pN = pN->link;
    }
    printf("\n");
}

int main ()
{
  item valor;
  int opcion;
  
  printf ("*********** Linked Queue ********\n");
  
  while (1)
  {
    printf ("\t1. QInsert\n");
    printf ("\t2. QRemove\n");
    printf ("\t3. Mostrar Queue\n");
    printf ("\t4. Abandonar Queue\n");
    printf ("\t5. Emergencia\n");
    printf ("\t6. Salir\n");
    printf ("\tOpcion? ");
    scanf ("%d", &opcion);
    switch (opcion)
    {
      case 1:
	    printf ("Valor? ");
	    scanf ("%d", &valor);
	    QInsert (valor);
	    break;
	    
      case 2:
	    valor = QRemove ();
	    if (valor != -999)
	    printf ("Valor removido del Queue = %d\n\n", valor);
    	break;
    	
      case 3:
	    showQueue ();
    	break;
    	
      case 4:
	    printf ("Quien se retira? ");
    	scanf ("%d", &valor);
	    abandonQueue (valor);
	    break;
	    
      case 5:
    	printf ("Quien llega de emergencia? ");
	    scanf ("%d", &valor);
	    emergencia (valor);
	    printf("Valor %d agregado de emergencia\n\n", valor);
	    break;
    }
    
    if (opcion == 6)
      break;
  }
}
