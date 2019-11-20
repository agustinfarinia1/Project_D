#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

int main()
{
    char arPlaylist[] = {"playlist.dat"};
    char arUsuarios[] = {"usuarios.dat"};

    nodoArbol* arbolC = inicArbol();


    int dimensionADLUser = 5;
    stCelda ADLUser[dimensionADLUser];
    int validADLUser = 0;


    ///Usuarios de prueba
    stUsuario userA;
    userA.idUsuario = 0;
    strcpy(userA.nombreUsuario,"userA");
    strcpy(userA.pass,"123456");
    userA.anioNacimiento = 2000;
    userA.genero = 'M';
    strcpy(userA.pais,"Argentina");
    userA.eliminado = 0;

    stUsuario userB;
    userB.idUsuario = 1;
    strcpy(userB.nombreUsuario,"userB");
    strcpy(userB.pass,"123456");
    userB.anioNacimiento = 1998;
    userB.genero = 'M';
    strcpy(userB.pais,"Argentina");
    userB.eliminado = 0;

    stUsuario userC;
    userC.idUsuario = 2;
    strcpy(userC.nombreUsuario,"userC");
    strcpy(userC.pass,"123456");
    userC.anioNacimiento = 2004;
    userC.genero = 'F';
    strcpy(userC.pais,"Peru");
    userC.eliminado = 0;

    stUsuario userD;
    userD.idUsuario = 3;
    strcpy(userD.nombreUsuario,"userD");
    strcpy(userD.pass,"123456");
    userD.anioNacimiento = 2000;
    userD.genero = 'F';
    strcpy(userD.pais,"Chile");
    userD.eliminado = 0;

    stUsuario userE;
    userE.idUsuario = 4;
    strcpy(userE.nombreUsuario,"userE");
    strcpy(userE.pass,"123456");
    userE.anioNacimiento = 1997;
    userE.genero = 'M';
    strcpy(userE.pais,"Argentina");
    userE.eliminado = 0;

    ///Canciones de prueba
    stCancion songA;
    songA.idCancion = 0;
    strcpy(songA.titulo,"songA");
    strcpy(songA.artista,"A");
    songA.duracion = 300;
    strcpy(songA.album,"albumA");
    songA.anio = 1987;
    strcpy(songA.genero,"Pop");
    strcpy(songA.comentario,"Esta es la cancion A");
    songA.eliminado = 0;

    stCancion songB;
    songB.idCancion = 1;
    strcpy(songB.titulo,"songB");
    strcpy(songB.artista,"B");
    songB.duracion = 257;
    strcpy(songB.album,"albumB");
    songB.anio = 2000;
    strcpy(songB.genero,"Pop");
    strcpy(songB.comentario,"Esta es la cancion B");
    songB.eliminado = 0;

    stCancion songC;
    songC.idCancion = 2;
    strcpy(songC.titulo,"songC");
    strcpy(songC.artista,"C");
    songC.duracion = 307;
    strcpy(songC.album,"albumC");
    songC.anio = 1998;
    strcpy(songC.genero,"Pop");
    strcpy(songC.comentario,"Esta es la cancion C");
    songC.eliminado = 0;

    stCancion songD;
    songD.idCancion = 3;
    strcpy(songD.titulo,"songD");
    strcpy(songD.artista,"D");
    songD.duracion = 412;
    strcpy(songD.album,"albumD");
    songD.anio = 1997;
    strcpy(songD.genero,"Rap");
    strcpy(songD.comentario,"Esta es la cancion D");
    songD.eliminado = 0;

    stCancion songE;
    songE.idCancion = 4;
    strcpy(songE.titulo,"songE");
    strcpy(songE.artista,"E");
    songE.duracion = 254;
    strcpy(songE.album,"albumE");
    songE.anio = 1996;
    strcpy(songE.genero,"Rap");
    strcpy(songE.comentario,"Esta es la cancion E");
    songE.eliminado = 0;

    stCancion songF;
    songF.idCancion = 5;
    strcpy(songF.titulo,"songF");
    strcpy(songF.artista,"F");
    songF.duracion = 563;
    strcpy(songF.album,"albumF");
    songF.anio = 1995;
    strcpy(songF.genero,"Cumbia");
    strcpy(songF.comentario,"Esta es la cancion F");
    songF.eliminado = 0;

    stCancion songG;
    songG.idCancion = 6;
    strcpy(songG.titulo,"songG");
    strcpy(songG.artista,"G");
    songG.duracion = 392;
    strcpy(songG.album,"albumG");
    songG.anio = 2000;
    strcpy(songG.genero,"Salsa");
    strcpy(songG.comentario,"Esta es la cancion G");
    songG.eliminado = 0;

    stCancion songH;
    songH.idCancion = 7;
    strcpy(songH.titulo,"songH");
    strcpy(songH.artista,"H");
    songH.duracion = 402;
    strcpy(songH.album,"albumH");
    songH.anio = 1985;
    strcpy(songH.genero,"Rock");
    strcpy(songH.comentario,"Esta es la cancion H");
    songH.eliminado = 0;

    stCancion songI;
    songI.idCancion = 8;
    strcpy(songI.titulo,"songI");
    strcpy(songI.artista,"I");
    songI.duracion = 345;
    strcpy(songI.album,"albumI");
    songI.anio = 2002;
    strcpy(songI.genero,"Rock");
    strcpy(songI.comentario,"Esta es la cancion I");
    songI.eliminado = 0;

    stCancion songJ;
    songJ.idCancion = 9;
    strcpy(songJ.titulo,"songJ");
    strcpy(songJ.artista,"J");
    songJ.duracion = 298;
    strcpy(songJ.album,"albumJ");
    songJ.anio = 2007;
    strcpy(songJ.genero,"Cumbia");
    strcpy(songJ.comentario,"Esta es la cancion J");
    songJ.eliminado = 0;

    arbolC = insertarNodoArbol(arbolC,crearNodoArbol(songA));
    arbolC = insertarNodoArbol(arbolC,crearNodoArbol(songB));
    arbolC = insertarNodoArbol(arbolC,crearNodoArbol(songC));
    arbolC = insertarNodoArbol(arbolC,crearNodoArbol(songD));
    arbolC = insertarNodoArbol(arbolC,crearNodoArbol(songE));
    arbolC = insertarNodoArbol(arbolC,crearNodoArbol(songF));
    arbolC = insertarNodoArbol(arbolC,crearNodoArbol(songG));
    arbolC = insertarNodoArbol(arbolC,crearNodoArbol(songH));
    arbolC = insertarNodoArbol(arbolC,crearNodoArbol(songI));
    arbolC = insertarNodoArbol(arbolC,crearNodoArbol(songJ));

    printf("Arbol de canciones:\n");
    mostrarArbolInOrd(arbolC);

    printf("\n\nArchivo de usuarios:\n");
    mostrarRegistrosUsuarios(arUsuarios);

    printf("\n\nArchivo de playlist:\n");
    mostrarRegistrosPlaylist(arPlaylist);


    validADLUser = pasarDeArchivoPlaylistToADLUser(ADLUser,arPlaylist,arUsuarios,arbolC,validADLUser,dimensionADLUser);

    printf("\n\nADLUser:\n");
    mostrarADLUser(ADLUser,validADLUser);


    return 0;
}
