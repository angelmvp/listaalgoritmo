
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
    struct Nodo* sig;
    struct Nodo* ant;
};

typedef struct
{
    struct Nodo* Lista;
} Lista;

bool estavacia(Lista l)
{
    return l.Lista==NULL;
}

void enlistariniciodoble(Lista *l, Data dato)
{
    struct Nodo *nuevonodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevonodo == NULL){
        puts("no puedes enlistar mas datos");
        return; 
    }
    nuevonodo->info=dato;
    if(estavacia(*l)){
        l->Lista=nuevonodo;
        nuevonodo->sig=NULL;
        nuevonodo->ant=NULL;
    }else{
        l->Lista->ant=nuevonodo;
        nuevonodo->sig=l->Lista;
        nuevonodo->ant=NULL;
        l->Lista=nuevonodo;
    }
}
void enlistarfinaldoble(Lista* l, Data dato){
    struct Nodo* nuevonodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevonodo == NULL){
        puts("no puedes enlistar mas datos");
        return; 
    }
    nuevonodo->info=dato;
    nuevonodo->sig=NULL;
    if(estavacia(*l)){
        enlistariniciodoble(l,dato);
        }
    else{
        struct Nodo* aux;
        aux=l->Lista;
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig=nuevonodo;
        nuevonodo->ant=aux;
    }
}
void enlistarindicedoble(int posicion, Lista *l, Data dato)
{
    struct Nodo *nuevonodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevonodo == NULL){
        puts("No puedes enlistar mas datos");
        return;
    }
    nuevonodo->info = dato;
    nuevonodo->sig = NULL;
    if (estavacia(*l)||posicion==0){
        enlistariniciodoble(l,dato);
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
        nuevonodo->ant=aux;
        aux->sig->ant=nuevonodo;
        aux->sig = nuevonodo;    
}
void recorrefiladoble(Lista l){
    if(estavacia(l)){
        puts("no hay elemento s en la lista");
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
Data desenlistariniciodoble(Lista* l) {
    Data dato;
    if (estavacia(*l)){
        puts("no hay elementos en la lista");
        dato.valor=-1;
        return dato;
    }
    else{
        if(l->Lista->sig==NULL){
            dato=l->Lista->info;
            l->Lista=NULL;
            return dato;
        }else{
        l->Lista=l->Lista->sig;
        l->Lista->ant->sig=NULL;
        dato = l->Lista->ant->info;
        free(l->Lista->ant);
        l->Lista->ant=NULL;
        return dato;
        }
    } 
}
Data desenlistarfinaldoble(Lista* l){
    Data dato;
    if (estavacia(*l)){
        puts("no hay elementos en la lista");
        dato.valor=-1;
        return dato;
    }
    else{
        if(l->Lista->sig==NULL){
            desenlistariniciodoble(l);
        }else{
            struct Nodo* aux;
            aux=l->Lista;
            while(aux->sig!=NULL ){
                aux=aux->sig;
            }
            dato=aux->info;
            aux->ant->sig=NULL;
            aux->ant=NULL;
            free(aux);
            return(dato);
        }
    }
}
Data desenlistarindicedoble(int posicion, Lista *l){
    Data dato;
    if (estavacia(*l)){
        puts("no hay elementos en la lista");
        dato.valor=-1;
        return dato;
    }else{
        if(posicion==0||l->Lista->sig==NULL){
            dato=desenlistariniciodoble(l);
        }else{
    int i = 0;
    struct Nodo *aux = l->Lista;
    while (aux->sig != NULL && i < posicion ){
        aux = aux->sig;
        i++;
    }
        dato=aux->info;
        aux->ant->sig=aux->sig;
        aux->sig->ant=aux->ant;
        aux->ant=NULL;
        aux->sig=NULL;        
        free(aux);
        }
        return dato;
    }
}
int buscarsecuencialdoble(Lista l,Data dato){
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
} 
}
void ordenardoble(Lista* l){
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

void imprimiralrevesdoble(Lista l){
    struct Nodo* aux;
    aux=l.Lista;
    while(aux->sig!=NULL){
        aux=aux->sig;
    }
    printf("la lista impresa al reves es \n");
    while(aux!=NULL){
        printf("el dato es %d\n",aux->info);
        aux=aux->ant;
    }
}
void matarlistadoble(Lista* l){
    if(estavacia(*l)){
        puts("la lista ya esta vacia");
    }else{
        puts("empezando a matar lista");
    struct Nodo* actual = l->Lista;
    while (actual != NULL){
            l->Lista=actual->sig;
            if(actual->sig!=NULL){
                actual->sig->ant=NULL;
                actual->sig=NULL;
            }
            free(actual);
            actual=l->Lista;
        }
    l->Lista=NULL;
    puts("se mato la lista");
}
}
void liberartodoscircu(Lista* l) {
    Data datoextraido;
    puts("Liberando todos los elementos de la lista:");
    while (!estavacia(*l)) {
        datoextraido = desenlistariniciodoble(l);
        printf("Dato extraido: %d\n", datoextraido.valor);
    }
    l->Lista = NULL;
}

    

