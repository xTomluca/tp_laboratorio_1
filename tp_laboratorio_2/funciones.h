#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string.h>
#include <ctype.h>

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;
    int id;

}EPersona;

int getNombre(char* nombre);
int getEdad(int edadMax, int edadMin, int *numero);
int getDni(int *dni);
int verificacionDigito(char *auxCarga, char *mensajeError, int tamanioVector);
int verificacionChar(char *auxCarga, char *mensajeError, int tamanioVector);
int init_personas(EPersona* aCargar,int limite);
int cargaPersona(EPersona* aCargar,int limite);
int bajaPersona(EPersona* aCargar,int limite);
int mostrarDebug(EPersona* aCargar,int limite);int ordenarPersonas(EPersona* aCargar, int limite, int flagOrden);
int imprimir_GraficoEdad(EPersona* array,int limite);

#endif // FUNCIONES_H_INCLUDED
