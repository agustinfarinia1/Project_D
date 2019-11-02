#ifndef TDA_ARBOL_H_INCLUDED
#define TDA_ARBOL_H_INCLUDED
#include "TDA_Cancion.h"
typedef struct
{
    stCancion dato;
    struct nodoArbolCancion * izq;
    struct nodoArbolCancion * der;
} nodoArbolCancion;

nodoArbolCancion * inicArbol();
nodoArbolCancion * crearNodoArbol(stCancion dato);
nodoArbolCancion * insertarNodoArbol(nodoArbolCancion * arbol, nodoArbolCancion * nuevo);
nodoArbolCancion * preOrder(nodoArbolCancion * arbol);
nodoArbolCancion * inOrder(nodoArbolCancion * arbol);
nodoArbolCancion * postOrder(nodoArbolCancion * arbol);

/// hacer despues !!! borrarUnNodoArbol (buscarlo por idCancion)
nodoArbolCancion * buscarCancion(nodoArbolCancion * arbol, int idCancion);
void cargarArbolDesdeArchivo(); /// HACER LUEGO!



#endif // TDA_ARBOL_H_INCLUDED
