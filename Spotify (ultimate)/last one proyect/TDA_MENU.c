#include <stdio.h>
#include <stdlib.h>
#include "gotoxy.h"
#include <windows.h>
#include "TDA_MENU.h"
#include "TDA_Usuario.h"
#include "TDA_Cancion.h"
#include "TDA_ADLPlaylist.h"
#include "TDA_Arbol.h"
#include "TDA_registroPlaylist.h"

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

void Screen_user_menu()
{
            printf("\n\n");
            printf ("\n (1)Ver mi Perfil");
            printf ("\n (2)Ver Top 10 de Canciones recomendadas");
            printf ("\n (3)Escuchar una Cancion");
            printf ("\n (4)Ingresar al Menu Playlist");
            printf ("\n (ESC)SALIR");
            printf( "\n\Introduzca opci%cn : ", 162);
}

void Screen_admin_menu()
{
    system("cls");
    hidecursor(0);
    dibujarrectangulo();
    centrar_texto ("(1)Dar de Alta un Usuario",3);
    centrar_texto ("(2)Dar de Baja un Usuario",5);
    centrar_texto ("(3)Modificar Datos de Usuario",7);
    centrar_texto ("(4)Cargar Canciones al Archivo",9);
    centrar_texto ("(5)Modificar datos de Canciones",11);
    centrar_texto ("(6)Borrar una Cancion del Archivo", 13);
    centrar_texto ("(ESC)SALIR",15);
    centrar_texto( "Introduzca opcion : ", 17);
}

void Screen_Playlist ()
{

            printf("\n\n");
            printf ("\n (1)Crear Playlist");
            printf ("\n (2)Agregar Cancion a la Playlist");
            printf ("\n (3)Ver todas mis Playlist");
            printf ("\n (4)Borrar Cancion de Playlist");
            printf ("\n (5)Escuchar Playlist");
            printf ("\n (ESC)SALIR");
            printf( "\n\Introduzca opci%cn : ", 162);
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

void Case_user()
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
            Screen_user_menu();
            int dimArreglo = 100; // FALTA FUNCION PARA SACAR  DIM DINAMICA, CONTANDO TODOS LOS USERS DEL ARRAY
            celdaPlaylist arregloLista[dimArreglo];
            int validos = archivoToADL(arregloLista);   // INGRESA TODOS LOS DATOS DEL ARCHIVO EN ARREGLO PARA PODER EMPEZAR A TRABAJAR
            opc = getch();
            switch (opc)
            {
                case 49: /**< Muestra Usuario Activo */
                    system("CLS");
                    int aux = verif;
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
                    system("cls");
                    mostrar_archi_canciones();
                    system("pause");
                break;
                case 51: /**< Escucha una cancion buscada */
                        reproducir(arCancion);
                break;
                case 52: /**< Ingresa al menu playlist */

                    Screen_usuario_playlist(verif,arregloLista,validos,dimArreglo);

                break;
                case 53: /**< Sale al menu ppal y se cierra*/
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

void Case_admin()
{
    FILE * archi;
    stUsuario a;
    char opc;
    char nombre[20];
    int verificacion=0;

    verificacion= ingresar_admin(arUsuario);
    nodoArbolCancion * arbol = inicLista();

    if (verificacion == 1)
    {
        do{
             printf("INGRESO EXITOSO\n\n");
             Sleep(1000);
             system("CLS");
             Screen_admin_menu();
             opc = getch();
             switch (opc)
             {
                case 49: /**< Funcion auxiliar que si se lo quiere registra un usuario */
                         cargarUnUsuario();
                         break;
                case 50: /**< Da de baja un usuario modificando user.eliminado = 1 */
                         system("cls");
                         printf("ingrese el usuario a dar de baja.\n");
                         gets(&nombre);
                         BajaUsuario(nombre);
                         printf("lo elimino");
                         break;
                case 51: /**< Modifica los datos del usuario eligiendo el campo */
                         printf("ingrese el usuario a Modificar.\n");
                         gets(nombre);
                         modificacionUsuario(nombre);
                         break;
                case 52: /**< Carga canciones al archivo tantas como quiera el administrador */
                         system("cls");
                         system("color 8F");
                         alta_canciones();
                         break;
                case 53: /**< Modifica los datos de Canciones por campo */
                         modificar_datos_cancion(arCancion);
                         break;
                case 54:

                        system("cls");
                        arbol = cargarArbolDesdeArchivo(arbol);
                        int idFiltro = 0;
                        printf("Ingrese el ID de la Cancion que desea eliminar: \n");
                        scanf("%d", &idFiltro);

                        arbol = borrarUnNodoArbol(arbol, idFiltro);

                        borrarUnaCancionArchivo(arCancion, idFiltro);
                        borrarUnaCancionArchivo(arPlaylist, idFiltro);
                        mostrar_archi_canciones();
                        system("pause");

                         break;
                case 55:
                         exit(0);
                         break;
             }

        }while (opc != 27);
    }
    else
    {
        printf("Usted no tiene o permisos para acceder aqui (U.U)\n");
        exit(0);
    }
}

void Cases_project()
{
    system("color 8F");

    int opcion;

    do
    {
        textoMenuInicio();
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
                    //system("pause");
                    //printf("saliod de aca");
                    break;
            case 51:
                    Case_admin();
                    break;
        }
    }while(opcion!=27);
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

void centrar_texto(const char *texto, int y)
{
    int size_texto=strlen(texto);
    gotoxy(40-(size_texto/2),y);
    printf("%s",texto);
}

void Screen_usuario_playlist(int idUsuario,celdaPlaylist arregloLista[],int validos,int dim)
{
    char opcionMenu;
    do
    {
        system("cls");
        Screen_Playlist();
        opcionMenu = getch();
        int posicion = -1;
        int existencia = 0;
        char nombreCancion[30];
        stCancion a; /// PARA ESCUCHAR
        Sleep(200);
        switch(opcionMenu)
            {
                case 49: // CREA PLAYLIST,SI EL USUARIO NO TIENE
                    system("cls");
                    posicion = buscaPosUsuario(arregloLista,idUsuario,validos);
                    if(posicion == -1)
                    {
                        stUsuario usuario = buscarUsuarioEnArchivo(idUsuario);
                        validos = agregarIdUsuario(arregloLista,usuario,validos);
                        printf("Se creo la playlist exitosamente.");
                    }
                    else
                    {
                        printf("El usuario ya tiene una playlist");
                    }
                    Sleep(700);
                break;
                case 50: // AGREGA CANCIONES A LA PLAYLIST CON UN BUCLE
                    validos = cargarArreglo(arregloLista,idUsuario,validos,dim);
                    guardarEnArchivo(arregloLista,validos);
                    system("cls");
                break;
                case 51:
                        guardarEnArchivo(arregloLista, validos);
                        mostrarArregloLista(arregloLista, validos);
                        system("pause");
                break;
                case 52:
                break;
                case 53:
                    system("cls");
                    existencia = mostrarArregloListaUsuario(arregloLista,idUsuario,validos);
                    Sleep(700);
                    if(existencia != 0)
                    {
                        reproducir(arCancion);
                    }
                    else
                    {
                        printf("Usted no tiene playlist");
                    }
                    Sleep(700);
                break;
            }
    }while(opcionMenu != 27);
}
