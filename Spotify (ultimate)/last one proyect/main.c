#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include "TDA_MENU.h"
#include "TDA_Usuario.h"

const int verqueonda = 69;

int main()
{

    /**< Primer funcion se ejecuta, si no hay archi crea un admin y no se ejecuta mas; si existe archivo solo carga usuarios */
    //VerificarExistencia();
    /**< Funcion auxiliar para comprobar lo anterior, ya que aparte de verificar existencia pasa al men principal (cases_project)
         donde registra e ingresa, pero esta incompleta*/
    //cargarUnUsuario();
   //Cases_project(); /// SEGUIR TRABAJANDO EL MENU !


   /// FUNCIONES DE CONSULTA Y LISTADO
    stUsuario a;
    char nombre[30];

    printf("Ingrese el nombre del usuario: \n");
    fflush(stdin);
    gets(nombre);
    a = consultaUsuario(nombre);
    muestraUnUsuario(a);
    listadoUsuarios();

}
