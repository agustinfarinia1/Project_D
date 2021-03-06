#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "TDA_Cancion.h"
#include "TDA_ListaCancion.h"
#include "TDA_registroPlaylist.h"
#include "TDA_Arbol.h"
#include "Tools.h"

const int DIM = 100;                ///dim responde a la cantidad de canciones cargadas en el archivo

nodoArbolCancion * inicArbol()
{
    return NULL;
}

nodoArbolCancion * crearNodoArbol(stCancion dato)
{
    nodoArbolCancion * nuevo = (nodoArbolCancion*)malloc(sizeof(nodoArbolCancion));
    nuevo->dato = dato;
    nuevo->der = NULL;
    nuevo->izq = NULL;

    return nuevo;
}

nodoArbolCancion * insertarNodoArbol(nodoArbolCancion * arbol, nodoArbolCancion * nuevo)
{
    if(arbol == NULL)
    {
        arbol = nuevo;
    } else {

        if(nuevo->dato.idCancion > arbol->dato.idCancion)
        {
            arbol->der = insertarNodoArbol(arbol->der, nuevo);

        } else {

            arbol->izq = insertarNodoArbol(arbol->izq, nuevo);
        }
    }
        return arbol;
}

void preOrder(nodoArbolCancion * arbol)
{
    if(arbol != NULL)
    {
        mostrar_cancion(arbol->dato);
        preOrder(arbol->izq);
        preOrder(arbol->der);
    }
}

void inOrder(nodoArbolCancion * arbol)
{
    if(arbol != NULL)
    {
        inOrder(arbol->izq);
        mostrar_cancion(arbol->dato);
        inOrder(arbol->der);
    }
}

void postOrder(nodoArbolCancion * arbol)
{
    if(arbol != NULL)
    {
        postOrder(arbol->izq);
        postOrder(arbol->der);
        mostrar_cancion(arbol->dato);
    }
}

nodoArbolCancion * buscarCancion(nodoArbolCancion * arbol, int idCancionFiltro)
{
    nodoArbolCancion * rta = inicArbol();
    if(arbol != NULL)
        {
            if(idCancionFiltro == arbol->dato.idCancion)
            {
                rta = arbol;
            } else {

                if(idCancionFiltro > arbol->dato.idCancion)
                {
                    rta = buscarCancion(arbol->der, idCancionFiltro);
                } else {

                    rta = buscarCancion(arbol->izq, idCancionFiltro);
                }
            }
        }
        return rta;
}

nodoArbolCancion * cargarArbolDesdeArchivo(nodoArbolCancion * arbol, int DIM)        ///Carga el Arbol bien mezclado
{
    int i = 0;
    DIM = ultimaid() + 1;
    nodoArbolCancion * nuevo = inicArbol();

    int arregloDesordenado[DIM];
    int arregloInf[DIM];
    int arregloSup[DIM];

    stCancion c;

    int validos = mezclarCanciones(arregloDesordenado, arregloInf, arregloSup, DIM);


    while(i < validos)
    {
        /// LE PONEMOS -1 PORQUE LAS CANCIONES SE CARGAN A PARTIR DE 1 Y ACA TRABAJA CON 0.
        /// PERO LO DEJE SIN -1 PARA PROBAR

        nuevo = crearNodoArbol(buscarCancionEnArchivo(arregloDesordenado[i]));
        arbol = insertarNodoArbol(arbol, nuevo);
        i++;
    }
    return arbol;

}

nodoArbolCancion * borrarUnNodoArbol(nodoArbolCancion * arbol, int idCancion)
{
    if(arbol != NULL)
    {
        if(idCancion == arbol->dato.idCancion)
        {
            if(arbol->izq != NULL)
            {
                nodoArbolCancion * masDer = nodoMasAlaDerecha(arbol->izq);
                arbol->dato = masDer->dato;
                arbol->izq = borrarUnNodoArbol(arbol->izq,masDer->dato.idCancion);

            }else if(arbol->der != NULL)
            {
                nodoArbolCancion * masIzq = nodoMasAlaIzquierda(arbol->der);
                arbol->dato = masIzq->dato;
                arbol->der = borrarUnNodoArbol(arbol->der,masIzq->dato.idCancion);
            }else
            {
                free(arbol);
                arbol = NULL;
            }
        }
        else if(idCancion > arbol->dato.idCancion)
        {
            arbol->der = borrarUnNodoArbol(arbol->der, idCancion);

        }else if(idCancion < arbol->dato.idCancion)
        {
            arbol->izq = borrarUnNodoArbol(arbol->izq, idCancion);
        }
    }

    return arbol;
}

nodoArbolCancion * nodoMasAlaIzquierda(nodoArbolCancion * arbol)
{
    nodoArbolCancion * resp = NULL;
    if(arbol != NULL)
    {
        if(arbol->izq == NULL)
        {
            resp = arbol;
        }else
        {
            resp = nodoMasAlaIzquierda(arbol->izq);
        }
    }

    return resp;
}

nodoArbolCancion * nodoMasAlaDerecha(nodoArbolCancion * arbol)
{
    nodoArbolCancion * resp = NULL;
    if(arbol != NULL)
    {
        if(arbol->der == NULL)
        {
            resp = arbol;
        }else
        {
            resp = nodoMasAlaDerecha(arbol->der);
        }
    }

    return resp;
}
