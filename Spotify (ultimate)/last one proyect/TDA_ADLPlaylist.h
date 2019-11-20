#ifndef TDA_ADLPLAYLIST_H_INCLUDED
#define TDA_ADLPLAYLIST_H_INCLUDED
#include "TDA_Usuario.h"
#include "TDA_ListaCancion.h"
#include "TDA_registroPlaylist.h"

typedef struct{
    stUsuario usuario;
    int idPlaylist;
    nodoListaCancion * listaCancion;
}celdaPlaylist;

int cargarArreglo(celdaPlaylist adl[],int idUsuario,int validos,int dimension);
int guardarArreglo(celdaPlaylist adl[],stUsuario usuario,stCancion cancion,int validos);
int buscaPosUsuario(celdaPlaylist adl[],int idUsuario,int validos);
int agregarIdUsuario(celdaPlaylist adl[],stUsuario usuario,int validos);
void mostrarArregloLista(celdaPlaylist adl[],int validos);
int mostrarArregloListaUsuario(celdaPlaylist adl[],int idUsuario,int validos);
int obtenerIdPlaylist(int idUsuario);

void guardarEnArchivo(celdaPlaylist adl[],int validos);
int archivoToADL(celdaPlaylist adl[]);
#endif // TDA_ADLPLAYLIST_H_INCLUDED
