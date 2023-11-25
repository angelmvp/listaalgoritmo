
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{

    int valor;
} Data;

struct Nodo
{
    Data info;
    struct Nodo *sig;
};

typedef struct
{
    struct Nodo* Lista;
} Lista;

bool estavacia(Lista l)
{
    return l.Lista==NULL;
}

void enlistariniciocircu(Lista *l, Data dato)
{
    struct Nodo* nuevonodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevonodo == NULL){
        puts("no puedes enlistar mas datos");
        return; 
    }else{
        nuevonodo->info=dato;
        if(estavacia(*l)){
            l->Lista=nuevonodo;
            nuevonodo->sig=l->Lista;
        }else{
            struct Nodo* aux;
            aux=l->Lista;
            while(aux->sig!=l->Lista){
                aux=aux->sig;
            }
            aux->sig=nuevonodo;
            nuevonodo->sig=l->Lista;
            l->Lista=nuevonodo;
        }
    }
}
void enlistarfinalcircu(Lista *l, Data dato){
    struct Nodo *nuevonodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevonodo == NULL){
        puts("no puedes enlistar mas datos");
        return; 
    }
    nuevonodo->info=dato;
    if(estavacia(*l)){
            l->Lista=nuevonodo;
            nuevonodo->sig=l->Lista;
        }
    else{
        struct Nodo* aux;
        aux=l->Lista;
        while(aux->sig!=l->Lista){
            aux=aux->sig;
        }
        aux->sig=nuevonodo;
        nuevonodo->sig=l->Lista;
    }
}

void enlistarindicecircu(int posicion, Lista *l, Data dato)
{
    struct Nodo *nuevonodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevonodo == NULL){
        puts("No puedes enlistar mas datos");
        return;
    }
    nuevonodo->info = dato;
    nuevonodo->sig = NULL;
    if (estavacia(*l)||posicion==0){
        enlistariniciocircu(l,dato);
        return;
    }
    int i;
    i = 0;
    struct Nodo *aux;
    aux= l->Lista;
    while (aux->sig != l->Lista && i < posicion-1 ){
        aux = aux->sig;
        i++;
    }
        nuevonodo->sig = aux->sig;
        aux->sig = nuevonodo;
    
}
void recorrefilacircu(Lista l){
    if(estavacia(l)){
        puts("lalista esta vacia");
    }else{
    struct Nodo *aux;
    aux = l.Lista;
    do
    {
        printf("El dato es %d\n", aux->info.valor);
        aux = aux->sig;
    }while (aux != l.Lista);
    }
}
void crearlista(Lista* l){
    l->Lista=NULL;
}
Data desenlistariniciocircu(Lista* l) {
    Data dato;
    if (estavacia(*l)){
        puts("no hay elementos en la lista");
        dato.valor=-1;
        return dato;
    }
    else{
        dato = l->Lista->info;
        if(l->Lista==l->Lista->sig){
            struct Nodo* eliminar=l->Lista;
            l->Lista=NULL;
            eliminar->sig=NULL;
            free(eliminar);
        }else{
        struct Nodo* aux = l->Lista;
        while(aux->sig!=l->Lista){
            aux=aux->sig;
        }
        struct Nodo* eliminar = l->Lista;
        l->Lista=l->Lista->sig;
        aux->sig = l->Lista;
        eliminar->sig=NULL;
        free(eliminar);
        }
        return dato;
    } 
}
Data desenlistarfinalcircu(Lista *l){
    Data dato;
    if (estavacia(*l)){
        puts("no hay elementos en la lista");
        dato.valor=-1;
        return dato;
    }
    else{
        if(l->Lista->sig==l->Lista){
           dato=desenlistariniciocircu(l); 
        }else{
        struct Nodo* aux;
        aux=l->Lista;
        while(aux->sig->sig!=l->Lista ){
            aux=aux->sig;
        }
        struct Nodo* eliminar;
        eliminar=aux->sig;
        dato=eliminar->info;
        aux->sig=eliminar->sig;
        eliminar->sig=NULL;
        free(eliminar);
        }
        return dato;
    }
}

Data desenlistarindicecircu(int posicion, Lista *l){
    Data dato;
    if (estavacia(*l)){
        puts("no hay elementos en la lista");
        dato.valor=-1;
        return dato;
    }else{
        if(l->Lista->sig==l->Lista||posicion==0){
           dato=desenlistariniciocircu(l); 
        }else{
        int i = 0;
        struct Nodo *aux = l->Lista;
        while (aux->sig != l->Lista && i < posicion-1 ){
            aux = aux->sig;
            i++;
        }
        struct Nodo* eliminar;
        eliminar=aux->sig;
        dato=eliminar->info;
        aux->sig=eliminar->sig;
        eliminar->sig=NULL;
        free(eliminar);
        }
        return dato;
    }
}
int buscarsecuencialcircu(Lista l,Data dato){
struct Nodo* aux;
aux=l.Lista;
int i=0;
do{
    aux=aux->sig;
    i++;
}while(aux!=l.Lista && aux->info.valor!=dato.valor);
if(aux==l.Lista){
    return -1;
}else{
    return i;
} }
void ordenarcircu(Lista* l){
    struct Nodo *i, *j;
    Data aux;
    for(i=l->Lista; i->sig!=l->Lista && i->sig!=NULL; i=i->sig){
        for(j=i->sig;j!=l->Lista; j=j->sig){
            if(j->info.valor<i->info.valor){
                aux=i->info;
                i->info=j->info;
                j->info=aux;
            }
        }
    }
}
void liberartodoscircu(Lista* l) {
    Data datoextraido;
    puts("Liberando todos los elementos de la lista:");
    while (!estavacia(*l)) {
        datoextraido = desenlistariniciocircu(l);
        printf("Dato extraido: %d\n", datoextraido.valor);
    }
    l->Lista = NULL;
}
void matarlistacircu(Lista* l){
    if(estavacia(*l)){
        puts("la lista ya esta vacia");
    }else{
    struct Nodo *actual = l->Lista;
    struct Nodo *siguiente;
    do { 
        siguiente = actual->sig; 
        free(actual); 
        actual = siguiente; 
        } while (actual != l->Lista);
        }
    l->Lista=NULL;
}

