#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{
    char titulo[50];
    char genero[20];
    float duracion;
    char descripcion[300];
    float puntaje;
    char linkImagen[300];
    int isEmpty;
    int id;
}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
EMovie* agregarPelicula(EMovie* this, int* cantidadActual);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
  void crearPagina(EMovie* this);
 void crearPagina(EMovie* this);
int isValidAll(char* title, char* genre, float* duration, char* description, float* score, char* linkImagen);
EMovie* movie_new(void);
int movie_setId(EMovie* this);
int movie_getId(EMovie* this, int* id);
void movie_delete(EMovie* this);
int movie_getIsEmpty(EMovie* this, int* isEmpty);
int movie_setIsEmpty(EMovie* this);
int movie_setTitle(EMovie* this, char* titulo);
int movie_getTitle(EMovie* this, char* titulo);
int movie_setGenre(EMovie* this, char* genre);
int movie_getGenre(EMovie* this, char* genre);
int movie_setDuration(EMovie* this, float duration);
int movie_getDuration(EMovie* this, float* duration);
int movie_setDescription(EMovie* this, char* description);
int movie_getDescription(EMovie* this, char* description);
int movie_setScore(EMovie* this, float score);
int movie_getScore(EMovie* this, float* score);
int movie_setLink(EMovie* this, char* link);
int movie_getLink(EMovie* this, char* link);
EMovie* agregarPelicula(EMovie* this, int* cantidadActual);
void movie_generarBinario(EMovie* array, int i);
void movie_imprimir(EMovie* array);

#endif // FUNCIONES_H_INCLUDED
