#ifndef TDA_MENU_H_INCLUDED
#define TDA_MENU_H_INCLUDED




void textoMenuInicio(); /// FUNCION MAESTRA QUE LLAMA A LAS DEMAS
void Case_user ();
void Case_admin ();
void Cases_project();
void Screen_Playlist ();
void Screen_user_menu ();
void VerificarExistencia();
void centrar_texto(const char *texto, int y);
void dibujarrectangulo();
void dibujarlinea(char c, int n);
void Screen_admin_menu ();
#endif // TDA_MENU_H_INCLUDED
