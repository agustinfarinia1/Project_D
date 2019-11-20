#ifndef TDA_ADLPLAYLIST_H_INCLUDED
#define TDA_ADLPLAYLIST_H_INCLUDED
#include "TDA_ListaCancion.h"
#include "TDA_registroPlaylist.h"

typedef struct{
    int idUsuario;
    int idPlaylist;
    nodoListaCancion * listaCancion;
}celdaPlaylist;

int cargarArreglo(celdaPlaylist adl[],int idUsuario,int validos,int dimension);
int guardarArreglo(celdaPlaylist adl[],int idUsuario,stCancion cancion,int validos);
int buscaPosUsuario(celdaPlaylist adl[],int idUsuario,int validos);
int agregarIdUsuario(celdaPlaylist adl[],int idUsuario,int validos);
void mostrarArregloLista(celdaPlaylist adl[],int validos);

void guardarEnArchivo(celdaPlaylist adl[],int validos);
int archivoToADL(celdaPlaylist adl[]);
#endif // TDA_ADLPLAYLIST_H_INCLUDED
