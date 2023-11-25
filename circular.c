#include"funcircu.h"

int main()
{
    Lista milista;
    crearlista(&milista);

    Data dato1 = {1};
    enlistariniciocircu(&milista, dato1);

    printf("Lista despues de agregar al principio en la circular:\n");
    recorrefilacircu(milista);
    Data dato3 = {3};
    enlistarfinalcircu(&milista, dato3);
    Data dato4 = {4};
    enlistarfinalcircu(&milista, dato4);

    
    printf("\nLista despues de agregar al final en la circular:\n");
    recorrefilacircu(milista);

    Data dato5 = {5};
    enlistarindicecircu(0, &milista, dato5); 
    Data dato7 = {23};
    enlistarindicecircu(1, &milista, dato7); 
    Data dato8 = {12};
    enlistarindicecircu(3, &milista, dato8);  
    printf("\nLista despues de agregar en una posicion :\n");
    recorrefilacircu(milista);

Data abuscar;
abuscar.valor=3;
int lugar;
    puts("empezando busqueda");
    lugar=buscarsecuencialcircu(milista,abuscar);
    if ( lugar != -1) {
        printf("Se encontro el valor %d en el lugar %d.\n", abuscar.valor, lugar);
    } else {
        printf("No se encontro el valor %d en la lista.\n", abuscar.valor);
    }  

    puts("empezando a ordenar la lista circular");
    ordenarcircu(&milista);
    recorrefilacircu(milista);
Data extraido;
    puts("empezando a extraer datos");
    puts("se extrae el de la posicion 2");
    extraido=desenlistarindicecircu(2,&milista);
    printf("el dato extraido fue %d\n",extraido.valor);
    puts("se extrae el del inicio");
    extraido=desenlistariniciocircu(&milista);
    printf("el dato extraido fue %d\n",extraido.valor);
    puts("se extrae el del final");
    extraido=desenlistarfinalcircu(&milista);
    printf("el dato extraido fue %d\n",extraido.valor);
    recorrefilacircu(milista);
    puts("se extrae el de la posicion 0");
    extraido=desenlistarindicecircu(0,&milista);
    printf("el dato extraido fue %d\n",extraido.valor);

    puts("lista vigente");
    recorrefilacircu(milista);


    Data dato10 = {7};
    enlistariniciocircu(&milista, dato10);
    
    Data dato11 = {8};
    enlistarfinalcircu(&milista, dato11);
puts("otra vez la lista despues de agregar alguno snulmeritos");
recorrefilacircu(milista);
liberartodoscircu(&milista);
enlistarfinalcircu(&milista,dato3);
enlistariniciocircu(&milista,dato7);
enlistariniciocircu(&milista,dato8);
recorrefilacircu(milista);
liberartodoscircu(&milista);
recorrefilacircu(milista);  
return 0;
}