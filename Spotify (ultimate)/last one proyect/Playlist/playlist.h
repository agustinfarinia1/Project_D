#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct{
   int idCancion;
   char titulo[30];
   char artista[20];
   int duracion;
   char album[20];
   int anio;
   char genero[20];
   char comentario[100];
   int eliminado;  // indica 1 o 0 si la canción fue eliminada
}stCancion;

typedef struct _nodoArbol{
    stCancion dato;
    struct _nodoArbol* izq;
    struct _nodoArbol* der;
}nodoArbol;

typedef struct{
    int idUsuario;
    char nombreUsuario[30];
    char pass[20];
    int anioNacimiento;
    char genero;
    char pais[20];
    int eliminado;   // indica 1 o 0 si el cliente fue eliminado
}stUsuario;

typedef struct _nodoListaCancion{
    stCancion c;
    struct _nodoListaCancion * sig;
}nodoListaCancion;

typedef struct{
    stUsuario usr;
    nodoListaCancion* listaCanciones;
}stCelda;

typedef struct{
    int idPlaylist;
    int idUsuario;
    int idCancion;
}stPlaylist;

void guardarRegistroPlaylist(char arPlaylist[],int idUser,int idCancion);
int ultimoIdPlaylist(char arPlaylist[]);
void mostrarRegistrosPlaylist(char archivo[]);
void mostrarUnRegistroPlaylist(stPlaylist a);
int existeRegistroPlaylist(char arPlaylist[],stPlaylist a);
int pasarDeArchivoPlaylistToADLUser(stCelda ADLUser[],char arPlaylist[],char arUsuarios[],nodoArbol* arbolC,int valid,int dimension);
int copiarDataPlaylistToADLUser(stCelda ADLUser[],stPlaylist data,char arUsuarios[],nodoArbol* arbolC,int valid,int dimension);
void cargarUsuario(char arUsuarios[],stUsuario a);
void mostrarRegistrosUsuarios(char arUsuarios[]);
void mostrarUnRegistroUsuario(stUsuario a);
nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stCancion valor);
nodoArbol* insertarNodoArbol(nodoArbol* arbol,nodoArbol* nuevo);
void mostrarArbolPreOrd(nodoArbol* arbol);
void mostrarArbolInOrd(nodoArbol* arbol);
void mostrarArbolPosOrd(nodoArbol* arbol);
void mostrarCancion(stCancion a);
nodoArbol* buscarNodoArbolById(nodoArbol* arbol,int valor);
void mostrarADLUser(stCelda ADLUser[],int valid);
void mostrarListaCancion(nodoListaCancion* lista);
stUsuario buscarUsuarioById(char arUsuarios[],int idUser);
int existeRegistroUsuario(char arUsuarios[],int idUser);
int buscarPosUsuarioEnADL(stCelda ADLUser[],int idUser,int valid);
int agregarUsuarioToADLUser(stCelda ADLUser[],stUsuario user, int valid);
nodoListaCancion* crearNodoListaCancion(stCancion a);
nodoListaCancion* agregarFinLista(nodoListaCancion* lista,nodoListaCancion* nuevo);
nodoListaCancion* buscarUltimoNodo(nodoListaCancion* lista);
nodoListaCancion* inicLista();

#endif // PLAYLIST_H_INCLUDED
