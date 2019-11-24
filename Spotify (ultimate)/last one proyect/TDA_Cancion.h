#ifndef TDA_CANCION_H_INCLUDED
#define TDA_CANCION_H_INCLUDED

#define arCancion "cancion.dat"

typedef struct{
   int idCancion;
   char titulo[30];
   char artista[30];
   int duracion;
   char album[30];
   int anio;
   char genero[20];
   char comentario[100];
   int eliminado;  // indica 1 o 0 si la canción fue eliminada
}stCancion;

void buscarCancionPorNombre(char nombreArchi[],char nombreCancion[]);
void reproducir(char nombreArchi[]);
void alta_canciones();
int ultimaid();
void mostrar_cancion (stCancion a);
void guardarCancion(stCancion a);
void mostrar_archi_canciones();
void bajacancion();
void modificar_datos_cancion();
void muestra_tiempo(stCancion a);
int verificarExistenciaCancionEnArchivo(char nombreCancion[]);
stCancion obtenerCancionPorNombre(char archivoCancion[],char nombreCancion[]);
stCancion buscarCancionEnArchivo(int idFiltro);
void barritadecarga(char nombre[]);
void borrarUnaCancionArchivo(char archivo[], int idFiltroCancion);

/**


Importar y adaptar las funciones de Alta, Baja, Modificación, Consulta y
Listados de Canciones que ya fueron desarrollados en el TP Final de Laboratorio 1.
*/



#endif // TDA_CANCION_H_INCLUDED
