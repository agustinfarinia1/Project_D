#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "TDA_ListaCancion.h"
#include "TDA_Cancion.h"

nodoListaCancion * inicLista(){
    return NULL;
}

nodoListaCancion * crearNodoLista(stCancion c)
{
    nodoListaCancion * nuevo = (nodoListaCancion*)malloc(sizeof(nodoListaCancion));
    nuevo->datoCancion = c;
    nuevo->siguiente = NULL;

    return nuevo;
}

nodoListaCancion * agregarAlPpio(nodoListaCancion * lista, nodoListaCancion * nuevoNodo)
{
   if(lista == NULL)
   {
       lista = nuevoNodo;
   }
   else
   {
       nuevoNodo->siguiente = lista;
       lista = nuevoNodo;
   }
   return lista;
}

nodoListaCancion * buscarUltimo(nodoListaCancion * lista)
{
    nodoListaCancion * seguidora = lista;
    if(seguidora != NULL)
    {
        while(seguidora->siguiente != NULL)
        {
            seguidora = seguidora->siguiente;
        }
    }
    return seguidora;
}

nodoListaCancion * agregarAlFinal(nodoListaCancion * lista, nodoListaCancion * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }else{
        nodoListaCancion * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevoNodo;
    }
}

nodoListaCancion * agregarEnOrdenPorNombreCancion(nodoListaCancion * lista, nodoListaCancion * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo; /// SI LA LISTA ESTA VACIA, AGREGAMOS EL PRIMERO.
    }
    else {

        if(strcmp(nuevoNodo->datoCancion.titulo, lista->datoCancion.titulo)<0)
        {
            lista = agregarAlPpio(lista, nuevoNodo); /// SI EL NUEVO ES MENOR QUE EL PRIMERO, AGREGAMOS AL PRINCIPIO
        } else {

            /// SINO BUSCAMOS DONDE INSERTAR EL NUEVO ELEMENTO.
            nodoListaCancion * ante = lista;
            nodoListaCancion * seg = lista->siguiente;

            while((seg != NULL) && (strcmp(nuevoNodo->datoCancion.titulo, seg->datoCancion.titulo)>0))
            {
                ante = seg;
                seg = seg->siguiente;
            }
            /// INSERTAMOS EL NUEVO NODO EN EL LUGAR INDICADO.
            nuevoNodo->siguiente = seg;
            ante->siguiente = nuevoNodo;
        }

    }
    return lista;
}

nodoListaCancion * borrarNodoPorID(nodoListaCancion * lista, int IDfiltro)
{
    nodoListaCancion * seg;
    nodoListaCancion * ante;

    if((lista != NULL) && (IDfiltro == lista->datoCancion.idCancion))
    {
        nodoListaCancion * aux = lista;
        lista = lista->siguiente;
        free(aux);
        /// SALTEAMOS EL PRIMER NODO
        /// ELIMINAMOS EL PRIMER NODO
    } else {
        seg = lista;
        while((seg != NULL) && IDfiltro != lista->datoCancion.idCancion)
        {
            ante = seg;
            seg = seg->siguiente; /// AVANZAMOS
        }
        /// AHORA TENEMOS EN LA VARIABLE ANTE LA DIRECCION DE MEMORIA ANTERIOR AL NODO BUSCADO
        /// Y EN LA VARIABLE SEG LA DIRECCION DEL QUE QUEREMOS BORRAR
        if(seg != NULL)
        {
            ante->siguiente = seg->siguiente;
            /// SALTEAMOS EL NODO QUE QUEREMOS ELIMINAR.
            free(seg);
            /// ELIMINAMOS EL NODO BUSCADO.
        }
    }
    return lista;
}

void muestraListaCanciones(nodoListaCancion * lista)
{
    nodoListaCancion * seg = lista;
    while(seg != NULL)
    {
        mostrar_cancion(seg->datoCancion); /// USAR FUNCION REAL DESPUES !!
        seg = seg->siguiente;
    }
}
