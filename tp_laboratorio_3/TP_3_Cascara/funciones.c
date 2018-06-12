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

EMovie* agregarPelicula(EMovie* this, int* cantidadActual)
{
    int id;
    int empty;
    char title[50];
    char genre[20];
    char description[400];
    char linkImagen[400];
    float duration;
    float score;
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
            movie_getIsEmpty(this,&empty);
            movie_getId(this,&id);
            printf("\nCARGA EXITOSA! ID PELICULA: %d\n",id);
            printf("\nCARGA EMPTYYY! ID PELICULA: %d\n",empty);
            *cantidadActual+=1;
            printf("%d CANTIDAD ACUTAL", *cantidadActual);
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
void movie_generarBinario(EMovie** this, int* len)
{
    FILE* pFile;
    pFile = fopen("peliculas.html","wb");
    int i,isEmpty=1;
    float duration,score;
    char title[50], genre[20], description[400], linkImagen[400];
    if(pFile==NULL)
    {
        printf("\n ERROR APERTURA ARCHIVO");
        exit(1);
    }
    else if(*len >= 0)
    {
        printf("\nLEN : %d",*len);
        fprintf(pFile,"<!DOCTYPE html>\n");
        fprintf(pFile,"<!-- Template by Quackit.com -->\n");
        fprintf(pFile,"<html lang='en'>\n");
        fprintf(pFile,"<head>\n");
        fprintf(pFile,"<meta charset='utf-8'>\n");
        fprintf(pFile,"<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
        fprintf(pFile,"<meta name='viewport' content='width=device-width, initial-scale=1'>\n");
        fprintf(pFile,"<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n");
        fprintf(pFile,"<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
        fprintf(pFile,"<meta name='viewport' content='width=device-width, initial-scale=1'>\n");
        fprintf(pFile,"<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n");
        fprintf(pFile,"<title>Lista peliculas</title>\n");
        fprintf(pFile,"<!-- Bootstrap Core CSS -->\n");
        fprintf(pFile,"<link href='css/bootstrap.min.css' rel='stylesheet'>\n");
        fprintf(pFile,"<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n");
        fprintf(pFile,"<link href='css/custom.css' rel='stylesheet'>\n");
        fprintf(pFile,"<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n");
        fprintf(pFile,"<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n");
        fprintf(pFile,"<!--[if lt IE 9]>\n");
        fprintf(pFile,"<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n");
        fprintf(pFile,"<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n");
        fprintf(pFile,"<![endif]-->\n");
        fprintf(pFile,"</head>\n");
        fprintf(pFile,"<body>\n");
        fprintf(pFile,"<div class='container'>\n");
        fprintf(pFile,"<div class='row'>\n");
        fprintf(pFile,"<!-- Repetir esto para cada pelicula -->\n");

        for(i=0;i<=*len;i++)
        {
            movie_getIsEmpty(this[i],&isEmpty);
            printf("\n\n EL ISEMPLI%d",isEmpty);
            if(!isEmpty)
            {
                movie_getTitle(this[i],title);
                movie_getGenre(this[i],genre);
                movie_getDuration(this[i],&duration);
                movie_getDescription(this[i],description);
                movie_getScore(this[i],&score);
                movie_getLink(this[i],linkImagen);
                printf("---------------------%s GENRE",genre);

                /*fprintf(pFile,"<article class='col-md-4 article-intro'>\n");
                fprintf(pFile,"<a href='#'>\n");
                fprintf(pFile,"<img class='img-responsive img-rounded' src='%s' alt=''>\n",linkImagen);
                fprintf(pFile,"<h3>\n");
                fprintf(pFile,"<a href='#'>%s</a>\n",title);
                fprintf(pFile,"</h3>\n");
                fprintf(pFile,"<ul>\n");
                fprintf(pFile,"<li>%s</li>\n",genre);
                fprintf(pFile,"<li>%f</li>\n",score);
                fprintf(pFile,"<li>%f</li>\n",duration);
                fprintf(pFile,"</ul>\n");
                fprintf(pFile,"<p>%s</p>\n",description);
                fprintf(pFile,"</article>\n");*/
            }
        }
        fprintf(pFile,"<!-- Repetir esto para cada pelicula -->\n");
        fprintf(pFile,"</div>\n");
        fprintf(pFile,"<!-- /.row -->\n");
        fprintf(pFile,"</div>\n");
        fprintf(pFile,"<!-- /.container -->\n");
        fprintf(pFile,"<!-- jQuery -->\n");
        fprintf(pFile,"<script src='js/jquery-1.11.3.min.js'></script>\n");
        fprintf(pFile,"<!-- Bootstrap Core JavaScript -->\n");
        fprintf(pFile,"<script src='js/bootstrap.min.js'></script>\n");
        fprintf(pFile,"<!-- IE10 viewport bug workaround -->\n");
        fprintf(pFile,"<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
        fprintf(pFile,"<!-- Placeholder Images -->\n");
        fprintf(pFile,"<script src='js/holder.min.js'></script>\n");
        fprintf(pFile,"</body>\n");
        fprintf(pFile,"</html>\n");
    }
    else{printf("ERROR AL ENTRAR AL ELSE");}
    fclose(pFile);
}
void movie_imprimir(EMovie* array)
{
    FILE* pLecturaTexto;
    pLecturaTexto = fopen("peliculas.bin","rb");
    if(pLecturaTexto==NULL)
    {

    }
    else
    {
            fread(array,sizeof(EMovie),1,pLecturaTexto);
            printf("\nDescrp: _ %s",array->descripcion);
            printf("\nTitulo_ %s",array->titulo);
            printf("\nPuntaje_ %2.f",array->puntaje);
            printf("\nDuracion _  %2.f",array->duracion);
    }
}

 void crearPagina(EMovie* this)
{
    //pPelicula
    //fprintf(,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Género:%s</li><li>Puntaje:%d</li><li>Duración:%d</li></ul><p>%s</p></article>
}



