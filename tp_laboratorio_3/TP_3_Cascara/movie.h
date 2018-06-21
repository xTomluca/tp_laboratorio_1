#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED
typedef struct
{
    char titulo[50];
    char genero[20];
    float duracion;
    char descripcion[400];
    float puntaje;
    char linkImagen[400];
}EMovie;

EMovie* movie_new();
void movie_delete();
EMovie* movie_newConParametros(char* titulo,char* genero,float duracion,char* descripcion,float puntaje,char* linkImagen);

int movie_setTitulo(EMovie* this,char* titulo);
int movie_getTitulo(EMovie* this,char* titulo);

int movie_setGenero(EMovie* this,char* genero);
int movie_getGenero(EMovie* this,char* genero);

int movie_setDuracion(EMovie* this,float duracion);
int movie_getDuracion(EMovie* this,float* duracion);

int movie_setDescripcion(EMovie* this,char* descripcion);
int movie_getDescripcion(EMovie* this,char* descripcion);

int movie_setPuntaje(EMovie* this,float puntaje);
int movie_getPuntaje(EMovie* this,float* puntaje);

int movie_setLinkImagen(EMovie* this,char* linkImagen);
int movie_getLinkImagen(EMovie* this,char* linkImagen);

#endif // MOVIE_H_INCLUDED
