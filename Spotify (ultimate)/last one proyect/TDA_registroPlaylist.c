#include <stdio.h>
#include <stdlib.h>
#include "TDA_registroPlaylist.h"

void mostrarArchivoPlaylist()
{
    stCancion cancion;
    registroPlaylist registro;
    FILE * archi = fopen(arPlaylist,"rb");
    if(archi != NULL)
    {
        while(fread(&registro,sizeof(registroPlaylist),1,archi) > 0)
        {
            muestraUnRegistro(registro);
        }
    }
    fclose(archi);
}
void muestraUnRegistro(registroPlaylist registro)
{
    printf("\n");
    printf("IdUsuario: %d \n\n",registro.idUsuario);
    printf("IdPlaylist: %d \n\n",registro.idPlaylist);
    printf("IdCancion: %d \n",registro.idCancion);
    printf("\n");
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
int verificarExistenciaRegistroEnArchivo(registroPlaylist registro)
{
    registroPlaylist r;
    int respuesta = 0;
    FILE * archi = fopen(arPlaylist,"rb");
    if(archi != NULL)
    {
        while((respuesta == 0)&&(fread(&r,sizeof(registroPlaylist),1,archi) > 0))
        {
            if(registro.idUsuario == r.idUsuario)
            {
                if(r.idCancion == registro.idCancion)
                {
                    respuesta = 1;
                }
            }
        }
    }
    return respuesta;
}
