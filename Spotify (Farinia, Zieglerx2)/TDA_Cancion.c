#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "TDA_Cancion.h"


stCancion alta_cancion (stCancion a, char nombrearchi)
{
    char opc = 's';
    int anio = 1800;
    srand(time(NULL));

    printf("Cargando Nueva Cancion....\n\n");
    a.idCancion = ultimaid(arCancion) + 1;
    printf("Ingrese el nombre del Artista: ");
    fflush(stdin);
    gets(&a.artista);
    printf("\nIngrese el nombre de la Cancion: ");
    fflush(stdin);
    gets(&a.titulo);
    printf("\nIngrese el nombre del Album: ");
    fflush(stdin);
    gets(&a.album);
    printf("\nIngrese el Genero Musical: ");
    fflush(stdin);
    gets(&a.genero);
    printf("\nDesea agregar algun comentario ? (s/n): ");
    fflush(stdin);
    scanf("%c", &opc);
    if (opc == 's')
    {
        fflush(stdin);
        printf("\nIngrese el comentario aqui: ");
        gets(&a.comentario);
    }
    fflush(stdin);
    a.anio = anio + rand() % 219;
    fflush(stdin);
    a.duracion = rand() % 900 ;                  ///aca buscar manera de tener tiempo
    fflush(stdin);
    a.eliminado = 0;

    printf("\nCancion cargada correctamente... \n");
    Sleep(1000);
    system("CLS");
return a;
}

int ultimaid(char nombrearchi)
{
    int id = 0;
    FILE * archi;
    archi = fopen(arCancion,"rb");
    if(archi != NULL)
    {
        fseek(archi,0,2);
        id = ftell(archi)/sizeof (stCancion);
    }
    fclose(archi);
    return id;
}

void mostrar_cancion (stCancion a)
{
    printf("ID Cancion: %d\n", a.idCancion);
    printf("Artista:    %s \n", a.artista);
    printf("Album:      %s\n", a.album);
    printf("Cancion:    %s \n", a.titulo);
    printf("Genero:     %s\n", a.genero);
    printf("Anio:       %d\n", a.anio);
    muestra_tiempo(a);
    //printf("Duracion:   %d\n", a.duracion);
    printf("Eliminado:  %d\n", a.eliminado);
    printf("****************************************\n");

}

void cargar_muchas (char nombrearchi)
{
    FILE * archi;
    char opc;
    stCancion a;
    archi = fopen(arCancion, "ab");
    if (archi == NULL)
    {
        archi = fopen(arCancion, "w+b");
    }
    do
    {
        system("CLS");
        a = alta_cancion(a, arCancion);
        fwrite(&a, sizeof (stCancion), 1, archi);

        printf("Presiones ESC para salir\n");
        opc = getch();
    }while (opc != 27);

    fclose(archi);
}

void mostrar_archi_canciones (char nombrearchi)
{
    FILE * archi;
    stCancion a;
    archi = fopen(arCancion, "rb");
    if (archi != NULL)
    {
        while (fread(&a, sizeof(stCancion), 1, archi) > 0)
        {
            mostrar_cancion(a);
        }
    }
    fclose(archi);
}

void bajacancion (char nombarchi)
{
    FILE* archi ;
    int idaux=0;
    int selec;
    char resultadocancion ;
    archi = fopen(nombarchi,"r+b");
    stCancion cancion ;
    printf( "\n ¿Que ID  queres Modificar?: " );
    scanf( "%i", &idaux);
    selec = idaux;

    resultadocancion = fseek(archi,sizeof(stCancion)*(idaux-1),0);  ///me desplazo para modificar

    fread(&cancion, sizeof (stCancion), 1, archi);
    if (!resultadocancion)
    {
        fseek(archi,sizeof(stCancion)*(idaux-1),0);
        cancion.eliminado = 1;
        fwrite (&cancion, sizeof (stCancion), 1, archi);
    }
    fclose (archi);
}
void modificar_datos_cancion (char nombarchi)
{
    int idaux=0,datonuevoint;
    char datonuevo [30],resultado,opcion;
    FILE* archi;
    stCancion cancion;
    archi = fopen(nombarchi, "r+b");
    printf( "\n ¿Que ID estas buscando?: " );
	scanf( "%i", &idaux);
	resultado = fseek(archi,sizeof(cancion)*(idaux-1),0);
	fread(&cancion, sizeof (stCancion), 1, archi);
    if (!resultado)
    {
        system("CLS");
        printf ("Esta es la cancion buscada: \n");
        mostrar_cancion(cancion);
        do
        {
            printf("\n\n");
            printf ("\n (1)Nombre del Artista");
            printf ("\n (2)Nombre de la cancion");
            printf ("\n (3)Nombre del album");
            printf ("\n (4)Comentario");
            printf ("\n (5)Genero musical");
            printf ("\n (6)Anio");
            printf ("\n (7)Duracion");
            printf ("\n (0)SALIR");
            printf( "\n\Introduzca opci%cn : ", 162);
            fflush(stdin);
            opcion = getch();
            switch ( opcion )
            {
                case 49:
                    fseek(archi,sizeof(cancion)*(idaux-1),0);
                    printf("\n Ingrese su nuevo Artista: ");
                    fflush(stdin);
                    gets (datonuevo);
                    strcpy (cancion.artista, datonuevo);
                    fwrite (&cancion, sizeof (stCancion), 1, archi);
                break;
                case 50:
                    fseek(archi,sizeof(cancion)*(idaux-1),0);
                    printf("\n Ingrese su nuevo Nombre de Cancion: ");
                    fflush(stdin);
                    gets (datonuevo);
                    strcpy (cancion.titulo, datonuevo);
                    fwrite (&cancion, sizeof (stCancion), 1, archi);
                break;
                case 51:
                    fseek(archi,sizeof(cancion)*(idaux-1),0);
                    printf("\n Ingrese su nuevo Nombre del Album: ");
                    fflush(stdin);
                    gets (datonuevo);
                    strcpy (cancion.album, datonuevo);
                    fwrite (&cancion, sizeof (stCancion), 1, archi);
                break;
                case 52:
                    fseek(archi,sizeof(cancion)*(idaux-1),0);
                    printf("\n Ingrese su nuevo Comentario: ");
                    fflush(stdin);
                    gets (datonuevo);
                    strcpy (cancion.comentario, datonuevo);
                    fwrite (&cancion, sizeof (stCancion), 1, archi);
                break;
                case 53:
                    fseek(archi,sizeof(cancion)*(idaux-1),0);
                    printf("\n Ingrese su nuevo Genero: ");
                    fflush(stdin);
                    gets (datonuevo);
                    strcpy (cancion.genero, datonuevo);
                    fwrite (&cancion, sizeof (stCancion), 1, archi);
                break;
                case 54:
                    fseek(archi,sizeof(cancion)*(idaux-1),0);
                    printf("\n Ingrese su nuevo Anio: ");
                    fflush(stdin);
                    scanf("%d", &datonuevoint);
                    cancion.anio = datonuevoint;
                    fwrite (&cancion, sizeof (stCancion), 1, archi);
                break;
                case 55:
                    fseek(archi,sizeof(cancion)*(idaux-1),0);
                    printf("\n Ingrese su nueva Duracion: ");
                    fflush(stdin);
                    scanf("%d", &datonuevoint);
                    cancion.duracion=datonuevoint;
                    fwrite (&cancion, sizeof (stCancion), 1, archi);
                break;
            }
        }while (opcion !=48);
    }
    fclose (archi);
}

void muestra_tiempo (stCancion a)
{
 float x = a.duracion;
 float y = 60;
 float f = (x / y);
 int entero = (int)f;
 float decimal = f - entero;
 int decimal_entero = decimal * 100;
 printf("Duracion:   %dmin : %dseg \n", entero, decimal_entero);

}

void reproducir(char nombreArchi[])
{
    system("cls");
    char nombreCancion[20];
    printf("Introduzca nombre de cancion a buscar:");
    gets(nombreCancion);
    buscarCancionPorNombre(nombreArchi,nombreCancion);

}

void buscarCancionPorNombre(char nombreArchi[],char nombreCancion[])
{
    FILE * archi;
    stCancion cancion;
    archi = fopen(arCancion,"rb");
    if(archi != NULL)
    {
        while(fread(&cancion,sizeof(stCancion),1,archi) > 0) /// RECORRE HASTA ENCONTRAR A UNA CANCION CON EL MISMO TITULO O TERMINE EL ARCHIVO
        {
            if(strcmp(nombreCancion,cancion.titulo) == 0) /// COMPARA EL NOMBRE
            {
                mostrar_cancion(cancion);  /// CORTA EL CICLO
            }
            else
            {
                printf("La CAncion buscada no existe.\n");
            }
        }
    }
    fclose(archi);
}
