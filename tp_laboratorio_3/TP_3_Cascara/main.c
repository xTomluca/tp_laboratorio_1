#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "movie.h"
#include "valid.h"
#include "arraylist\examples\example_4\inc\ArrayList.h"

int main()
{
    ArrayList* pArray = al_newArrayList();
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        opcion=0;
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");
        if(!getNumeroInt(4,1,&opcion,0,20,"",""))
        {
            switch(opcion)
            {
                case 1:
                    system("cls");
                    agregarPelicula(pArray);
                    break;
                case 2:
                    system("cls");
                    borrarPelicula(pArray);
                    break;
                case 3:
                    system("cls");
                    movie_generarBinario(pArray);
                    break;
                case 4:
                    seguir = 'n';
                    break;
            }
        }
        else
        {
            system("cls");
            printf("\nOPCION INVALIDA!! <1-4>\n\n");
        }

    }

    return 0;
}
