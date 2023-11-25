#include"doble.h"

int main()
{
    Lista milista;
    crearlista(&milista);

    Data dato1 = {1};
    enlistariniciodoble(&milista, dato1);

    printf("Lista despues de agregar al principio en la doble enlazada:\n");
    recorrefiladoble(milista);
    Data dato3 = {3};
    enlistarfinaldoble(&milista, dato3);
    Data dato4 = {4};
    enlistarfinaldoble(&milista, dato4);

    
    printf("\nLista despues de agregar al final en la doble enlazada:\n");
    recorrefiladoble(milista);

    Data dato5 = {5};
    enlistarindicedoble(0, &milista, dato5); 
    Data dato7 = {23};
    enlistarindicedoble(1, &milista, dato7); 
    Data dato8 = {12};
    enlistarindicedoble(3, &milista, dato8);  
    printf("\nLista despues de agregar en una posicion :\n");
    recorrefiladoble(milista);

Data abuscar;
abuscar.valor=3;
int lugar;
    puts("empezando busqueda");
    lugar=buscarsecuencialdoble(milista,abuscar);
    if ( lugar != -1) {
        printf("Se encontro el valor %d en el lugar %d.\n", abuscar.valor, lugar);
    } else {
        printf("No se encontro el valor %d en la lista.\n", abuscar.valor);
    }  
    ordenardoble(&milista);
    recorrefiladoble(milista);
Data extraido;
    puts("empezando a extraer datos");
    puts("se extrae el de la posicion 2");
    extraido=desenlistarindicedoble(2,&milista);
    printf("el dato extraido fue %d\n",extraido.valor);
    puts("se extrae el del inicio");
    extraido=desenlistariniciodoble(&milista);
    printf("el dato extraido fue %d\n",extraido.valor);
    puts("se extrae el del final");
    extraido=desenlistarfinaldoble(&milista);
    printf("el dato extraido fue %d\n",extraido.valor);
    puts("se extrae el de la posicion 0");
    extraido=desenlistarindicedoble(0,&milista);
    printf("el dato extraido fue %d\n",extraido.valor);

    puts("lista vigente");
    recorrefiladoble(milista);


    Data dato10 = {7};
    enlistariniciodoble(&milista, dato10);
    
    Data dato11 = {8};
    enlistarfinaldoble(&milista, dato11);
    puts("lsita normal");
    recorrefiladoble(milista);

    imprimiralrevesdoble(milista);
    puts("lista vigente");
    recorrefiladoble(milista);
    //liberartodoscircu(&milista);
    matarlistadoble(&milista); 
    recorrefiladoble(milista);

    return 0;
}