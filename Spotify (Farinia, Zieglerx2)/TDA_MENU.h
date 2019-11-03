#ifndef TDA_MENU_H_INCLUDED
#define TDA_MENU_H_INCLUDED



int textoMenuInicio(int x,int y);  /// DIBUJA MENU Y DEVUELVE EL Y
int sumar(int numero);  /// INTERLINEADO
void encuadrar(int inicioX,int inicioY,int finX,int finY);
void menuInicio(); /// FUNCION MAESTRA QUE LLAMA A LAS DEMAS
void switchMenu_Inicio (int opcion);
void Case_user ();
void Cases_project();
void Screen_Playlist ();
void Screen_user_menu ();
void VerificarExistencia();

#endif // TDA_MENU_H_INCLUDED
