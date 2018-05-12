#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "string.h"
#define LIMITE 20

int main()
{
    char seguir='s';
    int opcion=0;
    EPersona personas[LIMITE];
    init_personas(personas, LIMITE);
    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n\n");
        fflush(stdin);
        scanf("%d",&opcion);
        while(opcion>5 || opcion<1)
        {
            printf("\nOPCION INVALIDA <1-5>, REINGRESE OPCION DESEADA: ");
            fflush(stdin);
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1:
                system("cls");
                cargaPersona(personas, LIMITE);
                break;
            case 2:
                system("cls");
                bajaPersona(personas, LIMITE);
                break;
            case 3:
                system("cls");
                ordenarPersonas(personas, LIMITE, 0);
                break;
            case 4:
                system("cls");
                imprimir_GraficoEdad(personas,LIMITE);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
