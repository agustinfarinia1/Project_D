#include "playlist.h"

void guardarRegistroPlaylist(char arPlaylist[],int idUser,int idSong){
    stPlaylist aux;

    aux.idCancion = idSong;
    aux.idUsuario = idUser;
    aux.idPlaylist = ultimoIdPlaylist(arPlaylist) + 1;

    if(!existeRegistroPlaylist(arPlaylist,aux)){
        FILE* pArch = fopen(arPlaylist,"ab");
        if(pArch){
            fwrite(&aux,sizeof(stPlaylist),1,pArch);

            fclose(pArch);
        }
    }
}

int ultimoIdPlaylist(char arPlaylist[]){
    stPlaylist aux;
    int res = -1;

    FILE* pArch = fopen(arPlaylist,"rb");
    if(pArch){
        fseek(pArch,(sizeof(stPlaylist)*-1),SEEK_END);

        if(fread(&aux,sizeof(stPlaylist),1,pArch) > 0){
            res = aux.idPlaylist;
        }

        fclose(pArch);
    }

    return res;
}

void mostrarRegistrosPlaylist(char arPlaylist[]){
    stPlaylist a;

    FILE* pArch = fopen(arPlaylist,"rb");
    if(pArch){
        while(fread(&a,sizeof(stPlaylist),1,pArch) > 0){
            mostrarUnRegistroPlaylist(a);
        }

        fclose(pArch);
    }
}

void mostrarUnRegistroPlaylist(stPlaylist a){
    printf("--------------------\n");
    printf("ID Playlist...: %d\n",a.idPlaylist);
    printf("ID Usuario....: %d\n",a.idUsuario);
    printf("ID Cancion....: %d\n",a.idCancion);
}

int existeRegistroPlaylist(char arPlaylist[],stPlaylist a){
    int res = 0;
    stPlaylist aux;

    FILE* pArch = fopen(arPlaylist,"rb");
    if(pArch){
        while((res == 0) && (fread(&aux,sizeof(stPlaylist),1,pArch) > 0)){
            if((a.idUsuario == aux.idUsuario) && (a.idCancion == aux.idCancion)){
                res = 1;
            }
        }

        fclose(pArch);
    }

    return res;
}

void cargarUsuario(char arUsuarios[],stUsuario a){
    FILE* pArch = fopen(arUsuarios,"ab");
    if(pArch){
        fwrite(&a,sizeof(stUsuario),1,pArch);

        fclose(pArch);
    }
}

void mostrarRegistrosUsuarios(char arUsuarios[]){
    stUsuario a;

    FILE* pArch = fopen(arUsuarios,"rb");
    if(pArch){
        while(fread(&a,sizeof(stUsuario),1,pArch) > 0){
            mostrarUnRegistroUsuario(a);
        }

        fclose(pArch);
    }
}

void mostrarUnRegistroUsuario(stUsuario a){
    printf("----------------------------\n");
    printf("ID Usuario..........: %d\n",a.idUsuario);
    printf("Nombre de Usuario...: %s\n",a.nombreUsuario);
    printf("Contrasenia.........: ******\n");
    printf("Anio................: %d\n",a.anioNacimiento);
    printf("Genero..............: %c\n",a.genero);
    printf("Nacionalidad........: %s\n",a.pais);
}

nodoArbol* inicArbol(){
    return NULL;
}

nodoArbol* crearNodoArbol(stCancion valor){
    nodoArbol* nuevo = malloc(sizeof(nodoArbol));

    nuevo->dato = valor;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

nodoArbol* insertarNodoArbol(nodoArbol* arbol,nodoArbol* nuevo){
    if(arbol == NULL){
        arbol = nuevo;
    }
    else{
        if(nuevo->dato.idCancion > arbol->dato.idCancion){
            arbol->der = insertarNodoArbol(arbol->der,nuevo);
        }
        else{
            arbol->izq = insertarNodoArbol(arbol->izq,nuevo);
        }
    }

    return arbol;
}

void mostrarArbolPreOrd(nodoArbol* arbol){
    if(arbol != NULL){
        mostrarCancion(arbol->dato);
        mostrarArbolPreOrd(arbol->izq);
        mostrarArbolPreOrd(arbol->der);
    }
}

void mostrarArbolInOrd(nodoArbol* arbol){
    if(arbol != NULL){
        mostrarArbolInOrd(arbol->izq);
        mostrarCancion(arbol->dato);
        mostrarArbolInOrd(arbol->der);
    }
}

void mostrarArbolPosOrd(nodoArbol* arbol){
    if(arbol != NULL){
        mostrarArbolPosOrd(arbol->izq);
        mostrarArbolPosOrd(arbol->der);
        mostrarCancion(arbol->dato);
    }
}

void mostrarCancion(stCancion a){
    printf("----------------------\n");
    printf("ID Cancion...: %d\n",a.idCancion);
    printf("Titulo.......: %s\n",a.titulo);
    printf("Artista......: %s\n",a.artista);
    printf("Album........: %s\n",a.album);
    printf("Duracion.....: %d\n",a.duracion);
    printf("Anio.........: %d\n",a.anio);
    printf("Genero.......: %s\n",a.genero);
    printf("Comentario...: %s\n",a.comentario);
}

nodoArbol* buscarNodoArbolById(nodoArbol* arbol,int valor){
    nodoArbol* obj = NULL;

    if(arbol != NULL){
        if(arbol->dato.idCancion == valor){
            obj = arbol;
        }
        else if(arbol->dato.idCancion > valor){
            obj = buscarNodoArbolById(arbol->izq,valor);
        }
        else{
            obj = buscarNodoArbolById(arbol->der,valor);
        }
    }

    return obj;
}

void mostrarADLUser(stCelda ADLUser[],int valid){
    for(int i=0;i<valid;i++){
        printf("Usuario %d\n",(i+1));
        mostrarUnRegistroUsuario(ADLUser[i].usr);

        printf("\nPlaylist del usuario:\n");
        mostrarListaCancion(ADLUser[i].listaCanciones);
        printf("\n\n");
    }
}

void mostrarListaCancion(nodoListaCancion* lista){
    while(lista!=NULL){
        mostrarCancion(lista->c);
        lista = lista->sig;
    }
}

stUsuario buscarUsuarioById(char arUsuarios[],int idUser){
    int flag = 0;

    stUsuario a;
    stUsuario res;
    res.idUsuario = -1;

    FILE* pArch = fopen(arUsuarios,"rb");
    if(pArch){
        while((flag == 0) && (fread(&a,sizeof(stUsuario),1,pArch)>0)){
            if(a.idUsuario == idUser){
                if(a.eliminado != 1){
                    res = a;
                    flag = 1;
                }
                else{
                    flag = 1;
                }
            }
        }

        fclose(pArch);
    }

    return res;
}

int existeRegistroUsuario(char arUsuarios[],int idUser){
    int res = 0;

    stUsuario a;

    FILE* pArch = fopen(arUsuarios,"rb");
    if(pArch){
        while((res == 0) && (fread(&a,sizeof(stUsuario),1,pArch)>0)){
            if(a.idUsuario == idUser){
                if(a.eliminado != 1){
                    res = 1;
                }
                else{
                    res = -1;
                }
            }
        }

        fclose(pArch);
    }

    if(res == -1){
        res++;
    }

    return res;
}

int pasarDeArchivoPlaylistToADLUser(stCelda ADLUser[],char arPlaylist[],char arUsuarios[],nodoArbol* arbolC,int valid,int dimension){
    FILE* pArch = fopen(arPlaylist,"rb");
    if(pArch){
        stPlaylist aux;

        while(fread(&aux,sizeof(stPlaylist),1,pArch) > 0){
                valid = copiarDataPlaylistToADLUser(ADLUser,aux,arUsuarios,arbolC,valid,dimension);

        }

        fclose(pArch);
    }

    return valid;
}

nodoListaCancion* crearNodoListaCancion(stCancion a){
    nodoListaCancion* nuevo = malloc(sizeof(nodoListaCancion));

    nuevo->c = a;
    nuevo->sig = NULL;

    return nuevo;
}

int copiarDataPlaylistToADLUser(stCelda ADLUser[],stPlaylist data,char arUsuarios[],nodoArbol* arbolC,int valid,int dimension){
    nodoArbol* auxCancionArb = buscarNodoArbolById(arbolC,data.idCancion);
    stUsuario auxUsuario = buscarUsuarioById(arUsuarios,data.idUsuario);


    if((auxCancionArb != NULL) && (auxUsuario.idUsuario != -1)){

        int pos = buscarPosUsuarioEnADL(ADLUser,data.idUsuario,valid);

        if(pos == -1 && valid < dimension){
            valid = agregarUsuarioToADLUser(ADLUser,auxUsuario,valid);
            pos = valid - 1;
            ADLUser[pos].listaCanciones = inicLista();
        }

        if(pos != -1){
            nodoListaCancion* auxCancionNodo = crearNodoListaCancion(auxCancionArb->dato);
            ADLUser[pos].listaCanciones = agregarFinLista(ADLUser[pos].listaCanciones,auxCancionNodo);
        }

    }

    return valid;
}

nodoListaCancion* inicLista(){
    return NULL;
}

nodoListaCancion* buscarUltimoNodo(nodoListaCancion* lista){
    if(lista != NULL){
        while(lista->sig != NULL){
            lista = lista->sig;
        }
    }

    return lista;
}

nodoListaCancion* agregarFinLista(nodoListaCancion* lista,nodoListaCancion* nuevo){
    if(lista != NULL){
        nodoListaCancion* ult = buscarUltimoNodo(lista);
        ult->sig = nuevo;
    }
    else{
        lista = nuevo;
    }

    return lista;
}

int buscarPosUsuarioEnADL(stCelda ADLUser[],int idUser,int valid){
    int pos = -1;
    int i=0;

    while(pos == -1 && i<valid){
        if(ADLUser[i].usr.idUsuario == idUser){
            pos = i;
        }

        i++;
    }

    return pos;
}

int agregarUsuarioToADLUser(stCelda ADLUser[],stUsuario user, int valid){
    ADLUser[valid].usr = user;

    valid++;

    return valid;
}
