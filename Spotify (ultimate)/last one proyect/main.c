#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include "TDA_MENU.h"
#include "TDA_Usuario.h"
#include "TDA_Arbol.h"
#include "TDA_Cancion.h"



int main()
{

    /**< Primer funcion se ejecuta, si no hay archi crea un admin y no se ejecuta mas; si existe archivo solo carga usuarios */
   VerificarExistencia();
    /**< Funcion auxiliar para comprobar lo anterior, ya que aparte de verificar existencia pasa al men principal (cases_project)
         donde registra e ingresa, pero esta incompleta*/
   //cargarUnUsuario();
   Cases_project(); /// SEGUIR TRABAJANDO EL MENU !


   /// FUNCIONES DE CONSULTA Y LISTADO



}
