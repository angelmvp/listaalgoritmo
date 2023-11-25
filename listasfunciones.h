
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

void enlistarinicio(Lista *l, Data dato)
{
    struct Nodo *nuevonodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevonodo == NULL){
        puts("no puedes enlistar mas datos");
        return; 
    }
    nuevonodo->info=dato;
        nuevonodo->sig=l->Lista;
        l->Lista=nuevonodo;
}
void enlistarfinal(Lista *l, Data dato){
    struct Nodo *nuevonodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevonodo == NULL){
        puts("no puedes enlistar mas datos");
        return; 
    }
    nuevonodo->info=dato;
    nuevonodo->sig=NULL;
    if(estavacia(*l)){
        l->Lista=nuevonodo;
        }
    else{
        struct Nodo* aux;
        aux=l->Lista;
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig=nuevonodo;
    }
}

void enlistarindice(int posicion, Lista *l, Data dato)
{
    struct Nodo *nuevonodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevonodo == NULL){
        puts("No puedes enlistar mas datos");
        return;
    }
    nuevonodo->info = dato;
    nuevonodo->sig = NULL;
    if (estavacia(*l)||posicion==0){
        enlistarinicio(l,dato);
        return;
    }
    int i;
    i = 0;
    struct Nodo *aux;
    aux= l->Lista;
    while (aux->sig != NULL && i < posicion-1 ){
        aux = aux->sig;
        i++;
    }
        nuevonodo->sig = aux->sig;
        aux->sig = nuevonodo;
    
}
void recorrefila(Lista l){
    if(estavacia(l)){
        puts("la lista esta vacia");
    }else{
    struct Nodo *aux;
    aux = l.Lista;
    while (aux != NULL)
    {
        printf("El dato es %d\n", aux->info.valor);
        aux = aux->sig;
    }
    }
}
void crearlista(Lista* l){
    l->Lista=NULL;
}
Data desenlistarinicio(Lista* l) {
    Data dato;
    if (estavacia(*l)){
        puts("no hay elementos en la lista");
        dato.valor=-1;
        return dato;
    }
    else{
        struct Nodo* aux = l->Lista;
        dato = aux->info;
        l->Lista = aux->sig;
        aux->sig = NULL;
        free(aux);
        return dato;
    } 
}
Data desenlistarfinal(Lista *l){
    Data dato;
    if (estavacia(*l)){
        puts("no hay elementos en la lista");
        dato.valor=-1;
        return dato;
    }
    else{
        struct Nodo* aux;
        struct Nodo* antes=NULL;
        aux=l->Lista;
        while(aux->sig!=NULL ){
            antes=aux;
            aux=aux->sig;
        }
        if(antes==NULL){
            dato=aux->info;
            l->Lista=NULL;
        }else{
        dato=aux->info;
        antes->sig = NULL;
        }
        free(aux);
        return dato;
    }
}

Data desenlistarindice(int posicion, Lista *l){
    Data dato;
    if (estavacia(*l)){
        puts("no hay elementos en la lista");
        dato.valor=-1;
        return dato;
    }
    int i = 0;
    struct Nodo *aux = l->Lista;
    struct Nodo *antes = NULL;
    while (aux->sig != NULL && i < posicion ){
        antes=aux;
        aux = aux->sig;
        i++;
    }
        if(antes==NULL){
            dato=aux->info;
            l->Lista=aux->sig;
        }else{
        dato=aux->info;
        antes->sig = aux->sig;
        }
        free(aux);
        return dato;
}
int buscarsecuencial(Lista l,Data dato){
struct Nodo* aux;
aux=l.Lista;
int i=0;
while(aux!=NULL && aux->info.valor!=dato.valor){
    aux=aux->sig;
    i++;
}
if(aux==NULL){
    return -1;
}else{
    return i;
} }
void ordenar(Lista* l){
    struct Nodo *i, *j;
    Data aux;
    for(i=l->Lista; i!=NULL && i->sig!=NULL; i=i->sig){
        for(j=i->sig;j!=NULL; j=j->sig){
            if(j->info.valor<i->info.valor){
                aux=i->info;
                i->info=j->info;
                j->info=aux;
            }
        }
    }
}
void matarlista(Lista *l){
    if(estavacia(*l)){
        puts("no hay nada que matar");
    }else{
    struct Nodo *actual = l->Lista;
    while (actual != NULL)
    {
        l->Lista = actual->sig;
        actual->sig=NULL;
        free(actual);
        actual = l->Lista;
    }
    l->Lista=NULL;
}
}
void liberartodos(Lista* l) {
    Data datoextraido;
    puts("Liberando todos los elementos de la lista:");
    while (!estavacia(*l)) {
        datoextraido = desenlistarinicio(l);
        printf("Dato extraido: %d\n", datoextraido.valor);
    }
    l->Lista = NULL;
}

