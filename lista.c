#include"listasfunciones.h"

int main()
{
    Lista milista;
    crearlista(&milista);

    Data dato1 = {1};
    enlistarinicio(&milista, dato1);

    printf("Lista despues de agregar al principio:\n");
    recorrefila(milista);
    Data dato3 = {3};
    enlistarfinal(&milista, dato3);

    Data dato4 = {4};
    enlistarfinal(&milista, dato4);

    
    printf("\nLista despues de agregar al final:\n");
    recorrefila(milista);

    Data dato5 = {5};
    enlistarindice(0, &milista, dato5); 
    Data dato7 = {23};
    enlistarindice(1, &milista, dato7); 
    Data dato8 = {12};
    enlistarindice(3, &milista, dato8);  
    printf("\nLista despues de agregar en una posicion :\n");
    recorrefila(milista);

Data abuscar;
abuscar.valor=3;
int lugar;
    puts("empezando busqueda");
    lugar=buscarsecuencial(milista,abuscar);
    if ( lugar != -1) {
        printf("Se encontro el valor %d en el lugar %d.\n", abuscar.valor, lugar);
    } else {
        printf("No se encontro el valor %d en la lista.\n", abuscar.valor);
    }  
    ordenar(&milista);
    recorrefila(milista);
Data extraido;
    puts("empezando a extraer datos");
    puts("desenlsitando posicion numero 2");
    extraido=desenlistarindice(2,&milista);
    printf("el dato extraido fue %d\n",extraido.valor);
    extraido=desenlistarinicio(&milista);
    puts("desenlsitando inicio");
    printf("el dato extraido fue %d\n",extraido.valor);
    extraido=desenlistarfinal(&milista);
    puts("desenlsitando final");
    printf("el dato extraido fue %d\n",extraido.valor);

    puts("lista vigente");
    recorrefila(milista);
    liberartodos(&milista);
matarlista(&milista);

recorrefila(milista);
    return 0;
}