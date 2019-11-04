#ifndef TDA_USUARIO_H_INCLUDED
#define TDA_USUARIO_H_INCLUDED

#define arUsuario "usuario.dat"

typedef struct{
    int idUsuario;
    char nombreUsuario[30];
    char pass[20];
    int anioNacimiento;
    char sexo[30];
    char pais[20];
    int eliminado;
    int admin; /// GENERA ADMIN (1) AL PRIMER INGRESO, Y LUEGO VALE 0.
}stUsuario;

int ingresar_admin(char nombarchi);
int retorna_id (char nombrearchi, char name[]);
stUsuario cargarUnUsuario();
void guardarUsuario(stUsuario a);
void muestraUnUsuario(stUsuario a);
int retorna_admin_lvl (char nombrearchi, char name[]);
void muestraTodosLosUsuarios();
void BajaUsuario(char nombreFiltro[]);
stUsuario opcionCampo(stUsuario a);
void modificacionUsuario(char nombreFiltro);
int buscaUltimoID();
int versieslaprimeravez(char nombarchius);

#endif // TDA_USUARIO_H_INCLUDED
