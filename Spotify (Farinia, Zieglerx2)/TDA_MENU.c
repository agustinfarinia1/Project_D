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

int textoMenuInicio(int x,int y)
{
    y = sumar(y);   /// CREA MARGEN SUPERIOR
    x = sumar(x);   /// CREA MARGEN IZQUIERDO
    gotoxy(x,y);
    printf("Bienvenido al Sistema");
    y = sumar(y);       /// SUMA Y PARA QUE NO SE AMONTONE SUCESIVAMENTE
    gotoxy(x,y);
    printf("1. Registrar un Usuario");
    y = sumar(y);
    gotoxy(x,y);
    printf("2. Ingresar al sistema de Usuario.");
    y = sumar(y);
    gotoxy(x,y);
    printf("3. Ingresar al sistema Admin.");
    y = sumar(y);
    gotoxy(x,y);
    printf("0 para salir.\n\n\t");
    y = sumar(y);   /// CREA MARGEN INFERIOR
    return y;
}

int sumar(int numero)   /// crea el interlineado
{
    numero = numero + MARGEN;
    return numero;
}

void encuadrar(int inicioX,int inicioY,int finX,int finY)
{
    int auxX;
    int auxY;
    for(auxX = inicioX - 1 ; auxX < finX + 2 ; auxX++){
        for(auxY = inicioY - 1 ; auxY < finY + 2 ; auxY++){
            if(auxY < inicioY){ /// RELLENO ARRIBA
                if((auxX >= inicioX)&&(auxX <= finX)){
                    gotoxy(auxX,auxY);  /// RELLENO
                    printf("%c",205);
                }
                if(auxX < inicioX){
                    gotoxy(auxX,auxY);  /// DIAGONAL IZQUIERDA
                    printf("%c",201);
                }
                if(auxX > finX){
                    gotoxy(auxX,auxY);  /// DIAGONAL DERECHA
                    printf("%c",187);
                }
            }
            if((auxY >= inicioY)&&(auxY <= finY)){
                if(auxX < inicioX){
                    gotoxy(auxX,auxY);
                    printf("%c",186);
                }
                if(auxX > finX){
                    gotoxy(auxX,auxY);
                    printf("%c",186);
                }
            }
            if(auxY > finY){ /// RELLENO ARRIBA
                if((auxX >= inicioX)&&(auxX <= finX)){
                    gotoxy(auxX,auxY);
                    printf("%c",205);
                }
                if(auxX < inicioX){
                    gotoxy(auxX,auxY);
                    printf("%c",200);
                }
                if(auxX > finX){
                    gotoxy(auxX,auxY);
                    printf("%c",188);
                }
            }
        }
    }
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
                    printf("saliod de aca");
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
                case 49:
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
                case 50:
                break;
                case 51:
                break;
                case 52:
                break;
                case 53:
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
            printf ("\n (0)SALIR");
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
