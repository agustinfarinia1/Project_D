#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "TDA_Cancion.h"

#define arCancion "cancion.dat"

void alta_canciones()
{
    stCancion a;
    char op;
    int anio = 1800;
    srand(time(NULL));
    do{
       char Artista[] = {"La Renga"};
        char Album[] = {"La Esquina del Infinito"};
        char Genero[] = {"Rock"};
        printf("Cargando Nueva Cancion....\n\n");
        a.idCancion = ultimaid(arCancion) + 1;
        //printf("Ingrese el nombre del Artista: ");
        fflush(stdin);
        strcpy(a.artista,Artista);
        printf("\nIngrese el nombre de la Cancion: ");
        fflush(stdin);
        gets(&a.titulo);
        //printf("\nIngrese el nombre del Album: ");
        fflush(stdin);
        strcpy(a.album , Album);
        //printf("\nIngrese el Genero Musical: ");
        fflush(stdin);
        strcpy(a.genero, Genero);
        /*
        printf("\nDesea agregar algun comentario ? (s/n): ");
        fflush(stdin);
        scanf("%c", &opc);
        if (opc == 's')
        {
        fflush(stdin);
        printf("\nIngrese el comentario aqui: ");
        gets(&a.comentario);
        }
        */
        fflush(stdin);
        a.anio = 2000;
        fflush(stdin);
        a.duracion = rand() % 900 ;
        fflush(stdin);
        a.eliminado = 0;

        guardarCancion(a);

        printf("\nCancion cargada correctamente... \n");
        Sleep(1000);
        system("CLS");

        printf("PRESIONE ESC PARA SALIR... \n");

        op = getch();

    }while(op!=27);
}

int ultimaid()
{
    int id = 0;
    stCancion a;
    FILE * archi = fopen(arCancion, "rb");
    if(archi != NULL)
    {
        while(fread(&a, sizeof(stCancion), 1, archi)>0)
        {
            id = a.idCancion;
        }
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
    printf("Eliminado:  %d\n", a.eliminado);
    printf("****************************************\n");

}

void guardarCancion(stCancion a)
{
  FILE * archi = fopen(arCancion, "ab");
  if(archi != NULL)
  {
      fwrite(&a, sizeof(stCancion), 1, archi);
  }
    fclose(archi);
}

void mostrar_archi_canciones()
{
    stCancion a;
    FILE * archi = fopen(arCancion, "rb");
    if (archi != NULL)
    {
        while(fread(&a, sizeof(stCancion), 1, archi) > 0)
        {
            mostrar_cancion(a);
        }
    }
    fclose(archi);
}

void bajacancion()      /// Da de baja una funcion por ID
{
    int idaux=0;
    int selec;
    char resultadocancion ;
    FILE * archi = fopen(arCancion,"r+b");
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

void modificar_datos_cancion()
{
    int idaux=0,datonuevoint;
    char datonuevo [30],resultado,opcion;

    stCancion cancion;
    FILE * archi = fopen(arCancion, "r+b");
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
int verificarExistenciaCancionEnArchivo(char nombreCancion[]) /// PREGUNTAR ERICK SI CAMBIO PARA QUE EL ID ARRANQUE EN 0
{
    stCancion c;

    int flag = 0;
    FILE * archi = fopen(arCancion, "rb");
    if(archi != NULL)
    {
        while(fread(&c, sizeof(stCancion), 1, archi)>0 && (flag == 0))
        {
            if(strcmp(c.titulo,nombreCancion) == 0)
            {
                flag = 1;
            }
        }
    }
    fclose(archi);

    return flag;

}
stCancion buscarCancionEnArchivo(int idFiltro) /// BUSCA LA CANCION QUE QUEREMOS EN EL ARCHIVO Y LA DEVUELVE
{
    stCancion c;
    stCancion cancion;
    int flag = 0;
    FILE * archi = fopen(arCancion, "rb");
    if(archi != NULL)
    {
        while(fread(&c, sizeof(stCancion), 1, archi)>0 && (flag == 0))
        {
            if(c.idCancion == idFiltro)
            {
                cancion = c;
                flag = 1;
            }
        }
    }
    fclose(archi);

    return cancion;

}

void muestra_tiempo (stCancion a)
{
 float x = a.duracion;
 float y = 60;
 float f = (x/y);
 int entero = (int)f;
 float decimal = f - entero;
 int decimal_entero = decimal * 60;
 printf("Duracion:   %d min : %d seg \n", entero, decimal_entero);
}

void buscarCancionPorNombre(char nombreArchi[],char nombreCancion[])
{
    FILE * archi;
    stCancion cancion;
    int flag = 0;
    archi = fopen(arCancion,"rb");
    if(archi != NULL)
    {
        while(fread(&cancion,sizeof(stCancion),1,archi) > 0 && flag == 0) /// RECORRE HASTA ENCONTRAR A UNA CANCION CON EL MISMO TITULO O TERMINE EL ARCHIVO
        {
            if(strcmp(nombreCancion,cancion.titulo) == 0) /// COMPARA EL NOMBRE
            {
                flag = 1;
                mostrar_cancion(cancion);  /// CORTA EL CICLO
                Sleep(900);
            }
        }
        if(flag == 0)
        {
            printf("La cancion buscada no existe... \n");
        }
    }
    fclose(archi);
}

void reproducir(char nombreArchi[])
{
    system("cls");
    char nombreCancion[20];
    printf("Introduzca nombre de cancion a buscar:");
    gets(nombreCancion);
    system("cls");
    buscarCancionPorNombre(nombreArchi,nombreCancion);
    printf("Reproduciendo cancion...\n");
    barritadecarga("/");
}

void barritadecarga(char nombre[])
{

   SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),138);
   int segundos=5;
   int i=0;
   for(i=0; i<33; i++)                  ///cambiando el valor 33 hace la barra mas chica
   {
   gotoxy(i,12);
   printf("%c",219);
   Sleep(30);
   }
   SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),143);
   gotoxy(12,20);
}

stCancion obtenerCancionPorNombre(char nombreArchi[],char nombreCancion[])
{
    FILE * archi;
    stCancion cancion;
    archi = fopen(arCancion,"rb");
    int flag = 0;
    if(archi != NULL)
    {
        while((flag == 0)&&(fread(&cancion,sizeof(stCancion),1,archi) > 0)) /// RECORRE HASTA ENCONTRAR A UNA CANCION CON EL MISMO TITULO O TERMINE EL ARCHIVO
        {
            if(strcmp(nombreCancion,cancion.titulo) == 0) /// COMPARA EL NOMBRE
            {
                flag = 1;
            }
        }
        if(flag == 0)
            {
                printf("La CAncion buscada no existe.\n");
            }
    }
    fclose(archi);
    return cancion;
}
