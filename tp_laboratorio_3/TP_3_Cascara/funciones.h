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
EMovie* agregarPelicula(EMovie* movie);

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
void generarPagina(EMovie lista[], char nombre[]);
int init_personas(EMovie* PMovie,int limite);
EMovie* movie_new(void);
void movie_delete(EMovie* this);
int isValidAll(char* title, char* genre, float* duration, char* description, float* score, char* linkImagen);
void movie_generarBinario(EMovie *this);

#endif // FUNCIONES_H_INCLUDED
