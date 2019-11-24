#include <stdio.h>
#include <stdlib.h>
#include "TDA_ADLPlaylist.h"

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
        int existencia = verificarExistenciaCancionEnArchivo(nombreCancion);
        if(existencia != 0)
        {
            stCancion cancion = obtenerCancionPorNombre(arCancion,nombreCancion);
            stUsuario usuario = buscarUsuarioEnArchivo(idUsuario);
            validos = guardarArreglo(adl,usuario,cancion,validos);
        }
        else
        {
            printf("la cancion que ingreso, no se encuentra en nuestro repertorio.");
        }
        printf("\n\tESC para salir");
        opcion = getch();
    }
    while((opcion != 27)&&(validos<dimension));
    return validos;
}
int guardarArreglo(celdaPlaylist adl[],stUsuario usuario,stCancion cancion,int validos)
{
    nodoListaCancion * nuevoNodo = inicLista();
    nuevoNodo = crearNodoLista(cancion);
    int posicion = buscaPosUsuario(adl,usuario.idUsuario,validos);  /// Busca si el user tiene playlist
    if(posicion == -1)  /// si el user no tiene playlist
    {
        validos = agregarIdUsuario(adl,usuario,validos);
        posicion = validos - 1;
    }
    adl[posicion].listaCancion = agregarAlPpio(adl[posicion].listaCancion,nuevoNodo);

    return validos;
}

int buscaPosUsuario(celdaPlaylist adl[],int idUsuario,int validos)
{
    int rta = -1;
    int i = 0;
    while((i < validos)&&(rta == -1))
    {
        if(adl[i].usuario.idUsuario == idUsuario){
            rta = i;
        }
        i++;
    }
    return rta;
}

int obtenerIdPlaylist(int idUsuario) /// PARA SOLUCIONAR LO DEL IDPLAYLIST
{
    registroPlaylist r;
    int flag = 0;
    int res = ultimaidPlaylist() + 1;
    FILE * archi = fopen(arPlaylist, "rb");
    if(archi)
    {
        while((flag == 0) && (fread(&r, sizeof(registroPlaylist), 1, archi)>0))
        {
            if(idUsuario == r.idUsuario)
            {
                res = r.idPlaylist;
                flag = 1;
            }
        }
    }
    fclose(archi);

    return res;

}

int agregarIdUsuario(celdaPlaylist adl[],stUsuario usuario,int validos)
{
    adl[validos].usuario = usuario;
    adl[validos].listaCancion = inicLista();
    adl[validos].idPlaylist = obtenerIdPlaylist(usuario.idUsuario);
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
        printf("\nId Usuario: %d\n",adl[i].usuario.idUsuario);
        muestraListaCanciones(adl[i].listaCancion);
        printf("\n\n_______________________________________\n\n");
        i++;
    }
}
int mostrarArregloListaUsuario(celdaPlaylist adl[],int idUsuario,int validos)
{
    int i = 0;
    int flag = 0;
    system("cls");
    while((flag == 0) && (i < validos))
    {
        if(adl[i].usuario.idUsuario == idUsuario)
        {
            printf("\n\Playlist %d\n",adl[i].idPlaylist);
            printf("_______________________________________");
            printf("\nId Usuario: %d\n",adl[i].usuario.idUsuario);
            muestraListaCanciones(adl[i].listaCancion);
            printf("\n\n_______________________________________\n\n");
            flag = 1;
        }
        i++;
    }
    return flag;
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


void guardarEnArchivo(celdaPlaylist adl[],int validos) /// PASA LOS ARREGLOS DE PLAYLIST A UNA PERSISTENCIA DE REGISTO
{
    registroPlaylist r;
    int respuesta = 0;
    int i = 0;
    nodoListaCancion * seg;

    while(i < validos)
        {
            r.idUsuario = adl[i].usuario.idUsuario;
            r.idPlaylist = adl[i].idPlaylist;
            seg = adl[i].listaCancion;
            while(seg != NULL)
            {
                r.idCancion = seg->datoCancion.idCancion;
                respuesta = verificarExistenciaRegistroEnArchivo(r);
                if(respuesta != 1)
                {
                    guardarUnRegistro(r);
                }
                seg = seg->siguiente;
            }
            i++;
        }
}
int archivoToADL(celdaPlaylist adl[])
{
    registroPlaylist registro;
    stCancion cancion;
    stUsuario  usuario;
    int validos = 0;
    FILE * archi = fopen(arPlaylist,"rb");
    if(archi != NULL)
    {
        while(fread(&registro,sizeof(registroPlaylist),1,archi) > 0)
        {
                cancion = buscarCancionEnArchivo(registro.idCancion);
                if(cancion.eliminado == 0)
                {
                    usuario = buscarUsuarioEnArchivo(registro.idUsuario);
                    validos = guardarArreglo(adl,usuario,cancion,validos);
                }
        }
    }
    fclose(archi);
    return validos;
}

