#include <stdio.h>
#include <stdlib.h>
#include "gotoxy.h"
#include <windows.h>
#include "TDA_MENU.h"
#include "TDA_Usuario.h"

const int MARGEN = 3;

void VerificarExistencia()
{
    if(versieslaprimeravez(arUsuario)== 1)
    {
        Cases_project();
    }
    else
    {
        cargarUnUsuario();
    }
}

void textoMenuInicio()
{
    system("CLS");
    dibujarrectangulo();
    hidecursor(0);
    centrar_texto("<<Bienvenido al Sistema>>",1);
    centrar_texto("1. Registrar un Usuario",4);
    centrar_texto("2. Ingresar al sistema de Usuario.",6);
    centrar_texto("3. Ingresar al sistema Admin.",8);
    centrar_texto("0 para salir.\n\n\t",12);
}

void Cases_project()
{
    system("color 8F");

    int opcion;

    do
    {
        textoMenuInicio(8,10);
        opcion=getch();
        switch(opcion)
        {
            case 49:
                    system("cls");
                    cargarUnUsuario();
                    break;
            case 50:
                    system("cls");
                    Case_user();
                    system("pause");
                    //printf("saliod de aca");
                    break;
            case 51:
                    //Case_Admin ();
                    break;
        }
    }while(opcion!=27);
}

void Case_user ()
{
    int verif;
    char opc;
    FILE * archi;
    stUsuario a;
    verif = ingresarusuario(arUsuario);             ///verif tiene la id del useer
    if (verif > 0)                                  ///si el ingreso retorno una id de user
    {
        do{
            system("CLS");
            Screen_user_menu ();
            opc=getch();
            switch (opc)
            {
                case 49: /**< Muestra Usuario Activo */
                    system("CLS");
                    int aux= verif;
                    archi = fopen(arUsuario, "rb");
                    if (archi!= NULL)
                    {
                        while(fread(&a, sizeof(stUsuario), 1, archi)>0)
                        {
                            if(a.idUsuario == aux)
                            {
                                muestraUnUsuario(a);
                                system("pause");
                            }
                        }
                    fclose(archi);
                    }
                    break;
                case 50: /**< Muestra Top 10 de Canciones */
                break;
                case 51: /**< Escucha una cancion buscada */
                break;
                case 52: /**< Ingresa al menu playlist */
                break;
                case 53: /**< Sale al menu ppal */
                    system("CLS");
                break;
            }
          }while( opc != 27);
    }
    else{
        printf("\nNo se pudo acceder");
        exit(0);
    }
}

void Screen_user_menu ()
{
            printf("\n\n");
            printf ("\n (1)Ver mi Perfil");
            printf ("\n (2)Ver Top 10 de Canciones recomendadas");
            printf ("\n (3)Escuchar una Cancion");
            printf ("\n (4)Ingresar al Menu Playlist");
            printf ("\n (ESC)SALIR");
            printf( "\n\Introduzca opci%cn : ", 162);
}

void Screen_Playlist ()
{
            printf("\n\n");
            printf ("\n (1)Crear Playlist");
            printf ("\n (2)Agregar Cancion a la Playlist");
            printf ("\n (3)Ver todas mis Playlist");
            printf ("\n (3)Borrar Cancion de Playlist");
            printf ("\n (4)Escuchar Playlist");
            printf ("\n (0)SALIR");
            printf( "\n\Introduzca opci%cn : ", 162);
}


void dibujarrectangulo()
{
    int i=3;
    gotoxy(8,2);
    printf("%c",201);
    dibujarlinea(205,60);
    printf("%c",187);
    while(i<20)
    {
        gotoxy(8,i);
        printf("%c",186);
        dibujarlinea(0,60);
        printf("%c",186);
        i++;
    }
    gotoxy(8,20);
    printf("%c",200);
    dibujarlinea(205,60);
    printf("%c",188);
}

void dibujarlinea(char c, int n)
{
    int i=0;
    while (i<n)
    {
        printf("%c",c);
        i++;
    }
}

void centrar_texto(const char *texto, int y)
{
    int size_texto=strlen(texto);
    gotoxy(40-(size_texto/2),y);
    printf("%s",texto);
}
