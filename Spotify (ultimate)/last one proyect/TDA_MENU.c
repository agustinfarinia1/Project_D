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
        printf("\n\nPara empezar necesitara registrar un administrador\n\n");
        system("pause");
        cargarUnUsuario();
    }
}

void Screen_user_menu()
{
    system("cls");
    hidecursor(0);
    dibujarrectangulo();
    centrar_texto ("<<<Menu de Usuario>>>",1);
    centrar_texto (" (1)Ver mi Perfil",3);
    centrar_texto (" (2)Ver Top 10 de Canciones recomendadas",5);
    centrar_texto (" (3)Escuchar una Cancion",7);
    centrar_texto (" (4)Ingresar al Menu Playlist",9);
    centrar_texto (" (ESC)SALIR",11);
    centrar_texto( " Introduzca opcion : ", 14);
}

void Screen_admin_menu()
{
    system("cls");
    hidecursor(0);
    dibujarrectangulo();
    centrar_texto ("(1)Dar de Alta un Usuario",3);
    centrar_texto ("(2)Dar de Baja un Usuario",5);
    centrar_texto ("(3)Modificar Datos de Usuario",7);
    centrar_texto ("(4)Consulta Datos de Usuario",9);
    centrar_texto ("(5)Consultar Listado de Usuarios",11);
    centrar_texto ("(6)Sub-Menu Administrar Canciones",13);
    centrar_texto ("(ESC)SALIR",15);
    centrar_texto( "Introduzca opcion : ", 17);
}

void Screen_Playlist ()
{
    system("cls");
    hidecursor(0);
    dibujarrectangulo();
    centrar_texto("<<<Menu Playlist>>>",1);
    centrar_texto (" (1)Crear Playlist",3);
    centrar_texto (" (2)Agregar Cancion a la Playlist",5);
    centrar_texto (" (3)Ver todas mis Playlist",7);
    centrar_texto (" (4)Borrar Cancion de Playlist",9);
    centrar_texto (" (5)Escuchar Playlist",11);
    centrar_texto (" (ESC)SALIR",13);
    centrar_texto( "  Introduzca opcion : ",15);
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

void Screen_SubMenu_Administracion_Canciones()
{
    system("CLS");
    dibujarrectangulo();
    hidecursor(0);
    centrar_texto("<<Menu Para Administrar Canciones>>",1);
    centrar_texto("1. Alta Cancion en Archivo",4);
    centrar_texto("2. Baja Cancion en Archivo.",6);
    centrar_texto("3. Modificar Cancion en Archivo.",8);
    centrar_texto("4. Buscar Cancion en Archivo.",10);
    centrar_texto("5. Mostrar Listado de Canciones en Archivo.",12);
    centrar_texto("6. Volver Atras.",14);
    centrar_texto("0 para salir.\n\n\t",18);
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
                    top10 (arCancion);
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


    if (verificacion == 1)
    {
        printf("INGRESO EXITOSO\n\n");
        do{
             Sleep(1000);
             system("CLS");
             Screen_admin_menu();
             int dimArregloUsuario = buscaUltimoID() + 1;
             stCancion arregloUsuarios[dimArregloUsuario];
             int validosUsuarios = cargarArregloUsuarioDesdeArchivo(arregloUsuarios,dimArregloUsuario);
             opc = getch();
             switch (opc)
             {
                case 49: /**< Funcion auxiliar que si se lo quiere registra un usuario */
                         system("CLS");
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
                         system("cls");
                         printf("ingrese el usuario a Modificar.\n");
                         gets(nombre);
                         modificacionUsuario(nombre);
                         break;
                case 52: /**< Consulta un Usuario  */
                         system("cls");
                         printf("Ingrese el Nombre del Usuario a Buscar.\n");
                         fflush(stdin);
                         gets(nombre);
                         a = consultaUsuario(nombre);
                         muestraUnUsuario(a);
                         system("pause");
                         break;
                case 53: /**< Muestra un listado de usuarios Ordenado */
                        ordenarArregloUsuario(arregloUsuarios,validosUsuarios);
                        mostrarArregloUsuario(arregloUsuarios,validosUsuarios);
                        system("pause");
                         break;
                case 54: /**<  Sub-Menu Administración de Canciones */
                         system("cls");
                         Case_administrarcanciones();

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

void Case_administrarcanciones()     /// Switch menu que administra las canciones en un archivo
{
    system("color 8F");
    int opcion;
    int id=0;
    char nombre[30];
    int f = 0;
    stCancion c;
    nodoArbolCancion * arbol = inicLista();

    do
    {
        Screen_SubMenu_Administracion_Canciones();
        int dimArregloCancion = ultimaid() + 1;
        stCancion arregloCancion[dimArregloCancion];
        int validosCancion = cargarArregloCancionDesdeArchivo(arregloCancion,dimArregloCancion);
        int op = -1;
        opcion = getch();
        switch(opcion)
        {
            case 49:    /**< Carga canciones al archivo tantas como quiera el administrador */
                    system("cls");
                    system("color 8F");
                    alta_canciones();
                    break;
            case 50:    /**< Da de Baja una Cancion en Archivo, Playlist o Arbol */
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
            case 51: /**< Modifica los datos de Canciones por campo */
                    modificar_datos_cancion(arCancion);
                    break;
            case 52:        ///Consulta Cancion
                    do
                    {
                        system("cls");
                        printf("Desea buscar la cancion por:  (1)Nombre o (2)ID");
                        printf("\nIngrese la opcion: ");
                        scanf("%d", &op);
                        if (op == 1)
                        {
                            printf("Ingrese el Nombre de la Cancion: ");
                            fflush(stdin);
                            gets(nombre);
                            printf("\n");
                            buscarCancionPorNombre(arCancion, nombre);
                            f = 1;
                        }
                        if (op == 2)
                        {
                            printf("Ingrese el ID de la Cancion: ");
                            scanf("%d", &id);
                            c = buscarCancionEnArchivo(id);
                            printf("\n");
                            mostrar_cancion(c);
                            f = 1;
                        }
                    }while(op > 0 && f == 0);
                    system("pause");
                    break;
            case 53:       ///Listados de Canciones
                    do
                    {
                        system("cls");
                        printf("Desea ordenar la cancion por:  (1)Titulo o (2)Genero");
                        printf("\nIngrese la opcion: ");
                        scanf("%d", &op);
                        if (op == 1)    // POR TITULO()
                        {
                            ordenarArregloPorSeleccionCancion(arregloCancion,validosCancion);
                            f = 1;
                        }
                        if (op == 2)    // POR GENERO()
                        {
                            ordenarcionPorInsercionCancion(arregloCancion,validosCancion);
                            f = 1;
                        }
                    }while(op > 0 && f == 0);
                    mostrarArregloCancion(arregloCancion,validosCancion);
                    system("pause");
                    break;
            case 54:        ///Volver Atras
                    Case_admin();
                    break;
            case 55:        ///Salir
                    exit(0);
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
                case 52: /**< Borrar una cancion de la playlist */

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
