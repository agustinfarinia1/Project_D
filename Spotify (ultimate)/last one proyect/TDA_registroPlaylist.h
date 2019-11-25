#ifndef TDA_REGISTROPLAYLIST_H_INCLUDED
#define TDA_REGISTROPLAYLIST_H_INCLUDED
#include "TDA_ADLPlaylist.h"

#define arPlaylist "playlist.dat"

typedef struct{
    int idPlaylist;
    int idUsuario;
    int idCancion;
    int eliminado;  /// FALTA AGREGAR ELIMINAR CANCION DE PLAYLIST, MODIFICANDO EL CAMPOEN EL ARCHIVO
}registroPlaylist;

void guardarUnRegistro(registroPlaylist registro);
void mostrarArchivoPlaylist();
void muestraUnRegistro(registroPlaylist registro);
void eliminarRegistroPlaylist(int idUsuario,int idCancion);
#endif // TDA_REGISTROPLAYLIST_H_INCLUDED
