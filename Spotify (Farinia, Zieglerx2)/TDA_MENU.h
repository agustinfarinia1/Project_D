#ifndef TDA_MENU_H_INCLUDED
#define TDA_MENU_H_INCLUDED



int textoMenuInicio(int x,int y);  /// DIBUJA MENU Y DEVUELVE EL Y
int sumar(int numero);  /// INTERLINEADO
void encuadrar(int inicioX,int inicioY,int finX,int finY);
void menuInicio(); /// FUNCION MAESTRA QUE LLAMA A LAS DEMAS
void switchMenu_Inicio (int opcion);

#endif // TDA_MENU_H_INCLUDED
