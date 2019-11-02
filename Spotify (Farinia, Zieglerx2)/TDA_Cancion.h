#ifndef TDA_CANCION_H_INCLUDED
#define TDA_CANCION_H_INCLUDED

#define arCancion "cancion.dat"

typedef struct {
   int idCancion;
   char titulo[30];
   char artista[20];
   int duracion;
   char album[20];
   int anio;
   char genero[20];
   char comentario[100];
   int eliminado;  // indica 1 o 0 si la canción fue eliminada
} stCancion;

stCancion alta_cancion (stCancion a, char nombrearchi);
int ultimaid(char nombrearchi);
void mostrar_cancion (stCancion a);
void cargar_muchas ( char nombrearchi);
void mostrar_archi_canciones (char nombrearchi);

/*


Importar y adaptar las funciones de Alta, Baja, Modificación, Consulta y
Listados de Canciones que ya fueron desarrollados en el TP Final de Laboratorio 1.
*/



#endif // TDA_CANCION_H_INCLUDED
