#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define limitePeliculas 100

int main()
{
    EMovie* movie;
//  init_personas(movie,limitePeliculas);
    char seguir='s';
    int opcion=0;
    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(movie);
                break;
            case 2:

                break;
            case 3:
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
