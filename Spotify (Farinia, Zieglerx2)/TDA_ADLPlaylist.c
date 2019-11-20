#include <stdio.h>
#include <stdlib.h>
#include "TDA_ADLPlaylist.h"
#include "TDA_ListaCancion.h"

int cargarArreglo(celdaPlaylist adl[],int idUsuario,int validos,int dimension)    /// pide datos de cancion y del usuario para cargar al arreglo
{
    char nombreCancion[20];
    char opcion;
    do
    {
        system("cls");
        printf("\nIngrese Nombre de Cancion: ");    /// ESTO SERIA PARA BUSCARLA EN EL ARCHIVO
        fflush(stdin);
        gets(nombreCancion);
        stCancion cancion = obtenerCancionPorNombre(arCancion,nombreCancion);
        validos = guardarArreglo(adl,idUsuario,cancion,validos);
        printf("\n\tESC para salir");
        opcion = getch();
    }
    while((opcion != 27)&&(validos<dimension));
    return validos;
}
int guardarArreglo(celdaPlaylist adl[],int idUsuario,stCancion cancion,int validos)
{
    nodoListaCancion * nuevoNodo = inicLista();
    nuevoNodo = crearNodoLista(cancion);
    int posicion = buscaPosUsuario(adl,idUsuario,validos);  /// Busca si el user tiene playlist
    if(posicion == -1)  /// si el user no tiene playlist
    {
        validos = agregarIdUsuario(adl,idUsuario,validos);
        posicion = validos - 1;
    }
    adl[posicion].listaCancion = agregarAlPpio(adl[posicion].listaCancion,nuevoNodo);
    adl[posicion].idPlaylist = ultimaidPlaylist() + 1;
    return validos;
}

int buscaPosUsuario(celdaPlaylist adl[],int idUsuario,int validos)
{
    int rta = -1;
    int i = 0;
    while((i < validos)&&(rta == -1))
    {
        if(adl[i].idUsuario == idUsuario){
            rta = i;
        }
        i++;
    }
    return rta;
}
int agregarIdUsuario(celdaPlaylist adl[],int idUsuario,int validos)
{
    adl[validos].idUsuario = idUsuario;
    adl[validos].listaCancion = inicLista();
    adl[validos].idPlaylist = 0;
    validos++;


    return validos;
}
void mostrarArregloLista(celdaPlaylist adl[],int validos)
{
    int i = 0;
    system("cls");
    while(i < validos)
    {
        printf("\n\Playlist %d\n",adl[i].idPlaylist);
        printf("_______________________________________");
        printf("\nId Usuario: %d",adl[i].idUsuario);
        muestraListaCanciones(adl[i].listaCancion);
        printf("\n_______________________________________\n\n");
        i++;
    }
}
int ultimaidPlaylist()
{
    int id = 0;
    registroPlaylist a;
    FILE * archi = fopen(arPlaylist, "rb");
    if(archi != NULL)
    {
        while(fread(&a, sizeof(registroPlaylist), 1, archi)>0)
        {
            id = a.idPlaylist;
        }
    }
    fclose(archi);

    return id;

}


void guardarEnArchivo(celdaPlaylist adl[],int validos)
{
    registroPlaylist registro;
    int i = 0;
    FILE * pArchivo = fopen(arPlaylist,"ab");
    if(pArchivo == NULL){
        pArchivo = fopen(arPlaylist,"w+b");
    }
    while(i<validos){
        registro.idPlaylist = adl[i].idPlaylist;
        while(adl[i].listaCancion != NULL){
            registro.idCancion = adl[i].listaCancion->datoCancion.idCancion;
            registro.idUsuario = adl[i].idUsuario;
            adl[i].listaCancion = adl[i].listaCancion->siguiente;
            guardarUnRegistro(registro);
        }
        i++;
    }
    fclose(pArchivo);
}
void guardarUnRegistro(registroPlaylist registro)
{
    FILE * parchi = fopen(arPlaylist, "ab");
    if(parchi != NULL)
    {
        fwrite(&registro, sizeof(registroPlaylist),1, parchi);
    }
    fclose(parchi);
}
int archivoToADL(celdaPlaylist adl[])
{
    registroPlaylist registro;
    stCancion cancion;
    int validos = 0;
    FILE * archi = fopen(arPlaylist,"rb");
    if(archi != NULL)
    {
        while(fread(&registro,sizeof(registroPlaylist),1,archi) > 0)
        {
            cancion = buscarCancionEnArchivo(registro.idCancion);
            validos = guardarArreglo(adl,registro.idUsuario,cancion,validos);
        }
    }
    fclose(archi);
    return validos;
}

