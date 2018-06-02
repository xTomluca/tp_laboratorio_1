#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

static int isValidTitle(char* titulo);
static int isValidDescription(char* description);
static int isValidGenre(char* genre);
static int isValidLink(char* link);
static int isValidDuration(float duration);
static int isValidScore(float score);

/** \brief Verifica que el array de char contenga solo NUMEROS.
 *
 * \param auxCarga char* Array de char a validar.
 * \param mensajeError char* Mensaje de error a mostrar si se ingresa alguna LETRA.
 * \param tamanioVector int tamaño del array/vector.
 * \return int retorno [0] si no contiene LETRAS. [1] = ERROR.
 *
 */
int verificacionDigito(char *auxCarga, char *mensajeError, int tamanioVector)
{
    int i=0;
    int j=strlen(auxCarga);
    int retorno =1;
    while(i<j-1)
    {
        if(isdigit(auxCarga[i])!=0)
        {
            i++;
            retorno =0;
        }
        else
        {
            printf("ERROR VERIFICACION DIGITO");
            fflush(stdin);
            fgets(auxCarga, tamanioVector, stdin);
            j=strlen(auxCarga);
            i=0;
            retorno =1;

        }
    }
    return retorno;
}

/** \brief Verifica que el array de char contenga solo LETRAS.
 *
 * \param auxCarga char* Array de char a validar.
 * \param mensajeError char* Mensaje de error a mostrar si se ingresa algun NUMERO.
 * \param tamanioVector int tamaño del array/vector.
 * \return int retorno [0] si no contiene NUMEROS. [1] = ERROR.
 *
 */

int verificacionChar(char *auxCarga, char *mensajeError, int tamanioVector)
{
    int i=0;
    int j=strlen(auxCarga);
    int retorno =1;
    while(i<j-1)
    {
        retorno =1;
        if(!isdigit(auxCarga[i]))
        {
            i++;
            retorno =0;
        }
        else
        {
            printf("%s", mensajeError);
            fflush(stdin);
            fgets(auxCarga, tamanioVector, stdin);
            j=strlen(auxCarga);
            i=0;
        }
    }
    return retorno;
}

/** \brief Valida NOMBRE.
 *
 * \param nombre char* Mediante puntero paso array de char.
 * \return int retorno [0] si se cargo el NOMBRE con exito. [1] = ERROR.
 *
 */

int getArrayTexto(char* texto,char* textoInstruccion,char* textoError, int limite)
{
    int retorno=1;
    char auxTexto[limite];
    printf("%s",textoInstruccion);
    fflush(stdin);
    fgets(auxTexto, limite, stdin);
    if(!verificacionChar(auxTexto,textoError,limite))
    {
            strcpy(texto, auxTexto);
            retorno=0;
    }
    return retorno;
}

/** \brief Valida NUMERO.
 *
 * \param numMax int Defino NUMERO maximo.
 * \param numMin int Defino NUMERO minima.
 * \param numero int* Mediante puntero paso NUMERO.
 * \return int retorno [0] si se cargo la NUMERO con exito. [1] = ERROR.
 *
 */
int getNumeroFloat(float numMax, float numMin, float *numero,int limite,int intentos,char *mensaje, char *mensajeError){
    int retorno=1;
    float auxNum;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%f",&auxNum);
    while((auxNum > (float)numMax || auxNum < (float)numMin))
    {
        if(intentos==0)
            return 1;
        printf("%s",mensajeError);
        fflush(stdin);
        scanf("%f",&auxNum);
        intentos-=1;
    }
        *numero = auxNum;
        retorno=0;
    return retorno;
}

/** \brief Obtiene Cadena Alfanumerica
 *
 * \param array char* Mediante puntero pasa texto
 * \param mensaje char* Instruccion usuario
 * \param mensajeError char* Muestra error
 * \return int retorna [0] si se obtuvo cadena, [1] ERROR
 *
 */
int getCadena(char* array, char *mensaje, char *mensajeError, int limite)
{
    int retorno=1;
    char auxArray[limite];
    printf("%s",mensaje);
    fflush(stdin);
    fgets(auxArray, limite, stdin);

    if(strlen(auxArray)>0 && auxArray!=NULL)
    {
            strcpy(array, auxArray);
            retorno=0;
    }
    else
    {
        printf("%s",mensajeError);
    }

    return retorno;
}
/** \brief VALIDA TODO LOS DATOS INGRESADOS POR EL USUARIO
 *
 * \param title char* VALIDA TITULO
 * \param genre char* VALIDA GENERO
 * \param duration float* VALIDA DURACION
 * \param description char* VALIDA DESCRIPCION
 * \param score float* VALIDA PUNTAJE
 * \param linkImagen char* VALIDA IMAGEN
 * \return int RETORNA 0 SI SE INGRESARON LOS DATOS CORRECTAMENTE 1 ERROR
 *
 */
int isValidAll(char* title, char* genre, float* duration, char* description, float* score, char* linkImagen)
{
    int retorno=1;
    if(!getCadena(title,"\nIngrese titulo pelicula (MAX 50 CARACTERES): ", "\nSE PRODUJO ERROR AL INGRESAR TITULO!", 50)
    && !getCadena(genre,"\nIngrese genero pelicula(MAX 20 CARACTERES): ", "\nSE PRODUJO ERROR AL INGRESAR GENERO!", 20)
    && !getCadena(description,"\nIngrese descripcion pelicula(MAX 400 CARACTERES): ", "\nSE PRODUJO ERROR AL INGRESAR DESCRIPCION!", 400)
    && !getNumeroFloat(5,0.01,duration,5,2,"\nIngrese duracion de la pelicula(0.01 a 5.00HS): ","\nERROR, REINGRESE DURACION: ")
    && !getNumeroFloat(5,1,score,5,2,"\nIngrese puntaje pelicula(1 a 5): ","\nERROR, REINGRESE PUNTAJE: ")
    && !getCadena(linkImagen,"\nIngrese link imagen pelicula(MAX 400 CARACTERES): ", "\nSE PRODUJO ERROR AL INGRESAR LINK!", 400))
    {
        retorno = 0;
    }
    return retorno;
}
///*******************************************************************************************************************************************

/** \brief NUEVO ESPACIO MEMORIA TIPO MOVIE
 *
 * \param void NO RECIBE PARAMETROS
 * \return EMovie* RETORNA ESPACIO
 *
 */
EMovie* movie_new(void)
{

    EMovie* returnAux = (EMovie*) malloc(sizeof(EMovie));
    return returnAux;

}

int movie_setId(EMovie* this)
{
    static int ultimoId = -1;
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        ultimoId++;
        this->id = ultimoId;
    }
    return retorno;
}

int movie_getId(EMovie* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}

void movie_delete(EMovie* this)
{
    if(this != NULL)
        free(this);
}

int movie_getIsEmpty(EMovie* this, int* isEmpty)
{
    int retorno = -1;
    if(this != NULL && isEmpty != NULL)
    {
        retorno = 0;
        *isEmpty = this->isEmpty;
    }
    return retorno;
}

int movie_setIsEmpty(EMovie* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        this->isEmpty = 0 ;
    }
    return retorno;
}


int movie_setTitle(EMovie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL && !isValidTitle(titulo))
    {
        retorno = 0;
        strcpy(this->titulo,titulo);
    }
    return retorno;
}

int movie_getTitle(EMovie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        retorno = 0;
        strcpy(titulo,this->titulo);
    }
    return retorno;
}

static int isValidTitle(char* title)
{
    int largo = strlen(title);
    int retorno=1;
    if(title != NULL && largo < 20)
        retorno = 0;

    return retorno;
}

int movie_setGenre(EMovie* this, char* genre)
{
    int retorno = -1;
    if(this != NULL && genre != NULL && !isValidGenre(genre))
    {
        retorno = 0;
        strcpy(this->genero,genre);
    }
    return retorno;
}

int movie_getGenre(EMovie* this, char* genre)
{
    int retorno = -1;
    if(this != NULL && genre != NULL)
    {
        retorno = 0;
        strcpy(genre,this->genero);
    }
    return retorno;
}

static int isValidGenre(char* genre)
{
    int retorno = 1;
    if(genre != NULL && strlen(genre) < 20)
    {
        retorno = 0;
    }
    return retorno;
}


int movie_setDuration(EMovie* this, float duration)
{
    int retorno = -1;
    if(this != NULL && !isValidDuration(duration))
    {
        retorno = 0;
        this->duracion = duration;
    }
    return retorno;
}

int movie_getDuration(EMovie* this, float* duration)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        *duration = this->duracion;
    }
    return retorno;
}

static int isValidDuration(float duration)
{
    int retorno = 1;
    if(duration > 0 || duration <= 5)
    {
        retorno = 0;
    }
    return retorno;
}

int movie_setDescription(EMovie* this, char* description)
{
    int retorno = -1;
    if(this != NULL && description != NULL && !isValidDescription(description))
    {
        retorno = 0;
        strcpy(this->descripcion,description);
    }
    return retorno;
}

int movie_getDescription(EMovie* this, char* description)
{
    int retorno = -1;
    if(this != NULL && description != NULL)
    {
        retorno = 0;
        strcpy(description,this->descripcion);
    }
    return retorno;
}

static int isValidDescription(char* description)
{
    int retorno=1;
    int largo = strlen(description);
    if(description != NULL && largo < 400 )
    {
               retorno = 0;
    }

    return retorno;
}

int movie_setScore(EMovie* this, float score)
{
    int retorno = -1;
    if(this != NULL && !isValidScore(score))
    {
        retorno = 0;
        this->puntaje = score;
    }
    return retorno;
}

int movie_getScore(EMovie* this, float* score)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        *score = this->puntaje;
    }
    return retorno;
}

static int isValidScore(float score)
{
    int retorno = 1;
    if(score > 0 || score <= 5)
    {
        retorno = 0;
    }
    return retorno;
}


int movie_setLink(EMovie* this, char* link)
{
    int retorno = -1;
    if(this != NULL && link != NULL && !isValidLink(link))
    {
        retorno = 0;
        strcpy(this->linkImagen,link);
    }
    return retorno;
}

int movie_getLink(EMovie* this, char* link)
{
    int retorno = -1;
    if(this != NULL && link != NULL)
    {
        retorno = 0;
        strcpy(link,this->linkImagen);
    }
    return retorno;
}

static int isValidLink(char* link)
{
    int retorno = 1;
    if(link != NULL && strlen(link) < 400)
    {
        retorno = 0;
    }
    return retorno;
}

EMovie* agregarPelicula(EMovie* movie)
{
    int id;
    char title[50];
    char genre[20];
    char description[400];
    char linkImagen[400];
    float duration;
    float score;
    int isEmpty;
    EMovie* this;

    this = movie_new();

    if(this != NULL && !isValidAll(title,genre,&duration,description,&score,linkImagen))
    {
        if(    !movie_setTitle(this,title)
            && !movie_setDescription(this,description)
            && !movie_setGenre(this,genre)
            && !movie_setDuration(this,duration)
            && !movie_setScore(this,score)
            && !movie_setLink(this,linkImagen)
            && !movie_setIsEmpty(this)
            && !movie_setId(this))
        {
            movie_getId(this,&id);
            movie_getTitle(this,title);
            movie_getGenre(this,genre);
            movie_getDescription(this,description);
            movie_getLink(this,linkImagen);
            movie_getDuration(this,&duration);
            movie_getScore(this,&score);
            movie_getIsEmpty(this,&isEmpty);
            printf("\nCARGA EXITOSA! ID PELICULA: %d\n",id);
            movie_generarBinario(this);
            return this;
        }
        else
        {
            printf("\nERROR AL MOMENTO DE CARGAR PERSONA!");
        }
    }
    movie_delete(this);
    return NULL;
}
void movie_generarBinario(EMovie* array)
{
    FILE* pFile;
    pFile = fopen("peliculas.bin","w");
    EMovie *puntero = array;


    if(pFile==NULL)
    {
        printf("\n ERROR APERTURA ARCHIVO");
        exit(1);
    }
    fwrite(puntero, sizeof(EMovie),1,pFile);


    fclose(pFile);
}


