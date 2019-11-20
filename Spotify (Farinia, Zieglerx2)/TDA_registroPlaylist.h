#ifndef TDA_REGISTROPLAYLIST_H_INCLUDED
#define TDA_REGISTROPLAYLIST_H_INCLUDED
#include "TDA_ADLPlaylist.h"

#define arPlaylist "playlist.dat"

typedef struct{
    int idPlaylist;
    int idUsuario;
    int idCancion;
}registroPlaylist;

void guardarUnRegistro(registroPlaylist registro);
void mostrarArchivoPlaylist();
void muestraUnRegistro(registroPlaylist registro);

#endif // TDA_REGISTROPLAYLIST_H_INCLUDED
