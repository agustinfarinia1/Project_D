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
int archivoToADL(celdaPlaylist adl[],int dim);
void guardarEnArchivo(celdaPlaylist adl[],int validos);
int verificarExistenciaCancionEnLista(celdaPlaylist arregloLista[],int idUsuario,char nombreCancion[],int validos);
#endif // TDA_ADLPLAYLIST_H_INCLUDED
