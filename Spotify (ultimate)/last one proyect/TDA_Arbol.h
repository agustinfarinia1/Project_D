#ifndef TDA_ARBOL_H_INCLUDED
#define TDA_ARBOL_H_INCLUDED

#include "TDA_Cancion.h"
#include "TDA_ListaCancion.h"

typedef struct
{
    stCancion dato;
    struct nodoArbolCancion * izq;
    struct nodoArbolCancion * der;
}nodoArbolCancion;

/// PROTOTIPADO ARBOL

nodoArbolCancion * inicArbol();
nodoArbolCancion * crearNodoArbol(stCancion dato);
nodoArbolCancion * insertarNodoArbol(nodoArbolCancion * arbol, nodoArbolCancion * nuevo);

void preOrder(nodoArbolCancion * arbol);
void inOrder(nodoArbolCancion * arbol);
void postOrder(nodoArbolCancion * arbol);


/// hacer despues !!! borrarUnNodoArbol (buscarlo por idCancion)
nodoArbolCancion * borrarUnNodoArbol(nodoArbolCancion * arbol, int idCancion);
nodoArbolCancion * nodoMasAlaIzquierda(nodoArbolCancion * arbol);
nodoArbolCancion * nodoMasAlaDerecha(nodoArbolCancion * arbol);


nodoArbolCancion * buscarCancion(nodoArbolCancion * arbol, int idCancionFiltro);

/// FUNCIONES AUXILIARES


#endif // TDA_ARBOL_H_INCLUDED
