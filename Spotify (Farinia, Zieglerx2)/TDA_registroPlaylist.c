#include <stdio.h>
#include <stdlib.h>
#include "TDA_registroPlaylist.h"

void mostrarArchivoPlaylist()
{
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
