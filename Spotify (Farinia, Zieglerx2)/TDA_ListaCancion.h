#ifndef TDA_LISTACANCION_H_INCLUDED
#define TDA_LISTACANCION_H_INCLUDED

#include "TDA_Cancion.h"

/// ESTRUCTURA CANCION

typedef struct{
    stCancion datoCancion; /// DATOS
    struct nodoListaCancion * siguiente;
}nodoListaCancion;

/// PROTOTIPADO FUNCIONES

nodoListaCancion * inicLista();
nodoListaCancion * crearNodoLista(stCancion c);

nodoListaCancion * agregarAlPpio(nodoListaCancion * lista, nodoListaCancion * nuevoNodo);
nodoListaCancion * agregarAlFinal(nodoListaCancion * lista, nodoListaCancion * nuevoNodo);
nodoListaCancion * agregarEnOrdenPorNombreCancion(nodoListaCancion * lista, nodoListaCancion * nuevoNodo);

nodoListaCancion * borrarNodoPorID(nodoListaCancion * lista, int IDfiltro);
nodoListaCancion * buscarUltimo(nodoListaCancion * lista);

void muestraListaCanciones(nodoListaCancion * lista);

#endif // TDA_LISTACANCION_H_INCLUDED
