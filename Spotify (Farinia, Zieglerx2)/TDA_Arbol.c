#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "TDA_Arbol.h"

nodoArbolCancion * inicArbol()
{
    return NULL;
}

nodoArbolCancion * crearNodoArbol(stCancion dato)
{
    nodoArbolCancion * nuevo = (nodoArbolCancion*)malloc(sizeof(nodoArbolCancion));
    nuevo->dato = dato;
    //nuev
}
