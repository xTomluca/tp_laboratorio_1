#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
static int buscarLugarLibre(EPersona* aCargar,int limite);
static int buscarPorDNI(EPersona* aCargar,int limite, int id);

/** \brief Busca lugar libre en el array
 *
 * \param aCargar[] EPersona Pasamos el array de personas
 * \param limite int Limite del array (Limite de personas)
 * \return int retorna [i] si encuentra lugar libre, de lo contrario [-1].
 *
 */
static int buscarLugarLibre(EPersona* aCargar,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && aCargar != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(aCargar[i].estado==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Compara DNI ingresado con DNI guardado en array.
 *
 * \param aCargar EPersona* Array de personas.
 * \param limite int Limite del array (Limite de personas).
 * \param dni int
 * \return int retorna [i](ID PERSONA) si ARRAY DNI = DNI INGRESADO POR USUARIO // [-1] Si no hay coincidencia.
 *
 */
static int buscarPorDNI(EPersona* aCargar,int limite, int dni)
{
    int retorno = -1;
    int i;
    if(limite > 0 && aCargar != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!aCargar[i].estado && aCargar[i].dni==dni)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

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
        retorno =1;
        if(isdigit(auxCarga[i])!=0)
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

int getNombre(char* nombre)
{
    int retorno=1;
    char auxNombre[50];
    printf("\nIngrese Nombre: ");
    fflush(stdin);
    fgets(auxNombre, 50, stdin);
    if(!verificacionChar(auxNombre,"\nEL NOMBRE NO PUEDE CONTENER NUMEROS, REINGRESE NOMBRE: ",50))
    {
            strcpy(nombre, auxNombre);
            retorno=0;
    }
    return retorno;
}

/** \brief Valida EDAD.
 *
 * \param edadMax int Defino edad maxima.
 * \param edadMin int Defino edad minima.
 * \param edad int* Mediante puntero paso edad.
 * \return int retorno [0] si se cargo la EDAD con exito. [1] = ERROR.
 *
 */
int getEdad(int edadMax, int edadMin, int *edad){
    char auxCharEdad[10];
    int retorno=1;
    int auxEdad;
    int verificacion=0;
    printf("\nIngrese Edad: ");
    fflush(stdin);
    fgets(auxCharEdad, 10, stdin);
    if(!verificacionDigito(auxCharEdad,"\nLA EDAD NO PUEDE TENER LETRAS, REINGRESE EDAD: ", 10))
    {
        auxEdad = atoi(auxCharEdad);

        while(auxEdad > edadMax || auxEdad < edadMin || verificacion==1)
        {
            printf("\nLa edad ingresada no es valida. REINGRESE EDAD: ");
            fflush(stdin);
            fgets(auxCharEdad, 10, stdin);
            verificacion = verificacionDigito(auxCharEdad,"\nLA EDAD NO PUEDE TENER LETRAS, REINGRESE EDAD: ", 10);
            if(!verificacion)
            {
                auxEdad = atoi(auxCharEdad);
            }
        }
        *edad = auxEdad;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida DNI.
 *
 * \param dni int* Mediante puntero devuelve DNI ingresado y validado.
 * \return int retorno [0] si se cargo el DNI con exito. [1] = ERROR.
 *
 */
int getDni(int *dni){

    char auxDni[10];
    int retorno=1;
    int longitudDni=0;
    int verificacion=0;
    printf("\nIngrese DNI: ");
    fflush(stdin);
    fgets(auxDni, 20, stdin);
    if(!verificacionDigito(auxDni,"EL DNI NO CONTIENE LETRAS, REINGRESE DNI VALIDO: ", 20))
    {
        longitudDni = strlen(auxDni);
        while(!(longitudDni == 8 || longitudDni == 9) || verificacion==1)
        {
            printf("\nEl DNI ingresado no es valido. REINGRESE DNI: ");
            fflush(stdin);
            fgets(auxDni, 20, stdin);
            verificacion = verificacionDigito(auxDni,"\nEL DNI NO CONTIENE LETRAS, REINGRESE DNI VALIDO:  ", 20);
            if(!verificacion)
            {
                longitudDni = strlen(auxDni);
            }
        }
        *dni = atoi(auxDni);
        retorno=0;
    }
    return retorno;
}

/** \brief Inicializo array en estado = 1 (NO CARGADO).
 *
 * \param aCargar EPersona* Trabajo sobre array personas.
 * \param limite int Limite del array (Limite de personas).
 * \return int retorno [0] si se realizo la inicializacion con exito. [1] = ERROR.
 *
 */
int init_personas(EPersona* aCargar,int limite)
{
    int retorno = 1;
    int i;
    if(limite > 0 && aCargar != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            aCargar[i].estado=1;
        }
    }
    return retorno;
}

/** \brief Alta/carga de personas. Si NOMBRE/EDAD/DNI son validos, doy alta.
 *
 * \param aCargar EPersona* Trabajo sobre array personas.
 * \param limite int int Limite del array (Limite de personas).
 * \return int retorno [0] si se realizo el ALTA con exito. [1] = ERROR.
 *
 */
int cargaPersona(EPersona* aCargar,int limite)
{
    int edad;
    int dni;
    int retorno=1;
    char nombre[50];
    int i;
    i = buscarLugarLibre(aCargar,limite);
    if(i>=0)
    {
        if(!getNombre(nombre))
        {
            if(!getEdad(150, 1,&edad))
            {
                if(!getDni(&dni) && buscarPorDNI(aCargar,limite,dni))
                {
                    retorno = 0;
                    strcpy(aCargar[i].nombre, nombre);
                    aCargar[i].edad = edad;
                    aCargar[i].dni = dni;
                    aCargar[i].estado = 0;
                    aCargar[i].id = i;
                    printf("\nPersona cargada con exito!!\n\n");
                }
                else
                {
                    printf("\nERRORR!!! DNI YA REGISTRADO!!!\n\n");
                }
            }
        }
    }
     return retorno;
}

/** \brief Baja de personas mediante DNI // SI DNI = DNI Persona se produce la baja.
 *
 * \param aCargar EPersona* Trabajo sobre array personas.
 * \param limite int Limite del array (Limite de personas).
 * \return int retorno [0] si se realizo la BAJA con exito. [1] = ERROR.
 *
 */
int bajaPersona(EPersona* aCargar,int limite)
{
    int indiceABorrar, retorno;
    int dni=0;
    getDni(&dni);
    indiceABorrar = buscarPorDNI(aCargar, 20, dni);
    if(indiceABorrar < limite && indiceABorrar != -1)
    {
        aCargar[indiceABorrar].estado = 1;
        printf("\nBaja exitosa!!\n\n");
    }
    retorno = 0;
    return retorno;
}

/** \brief
 *
 * \param aCargar EPersona* Trabajo sobre array personas.
 * \param limite int Limite del array (Limite de personas).
 * \param flagOrden int ORDENO DE MENOR A MAYOR = [0] // ORDENO DE MAYOR A MENOR = [1].
 * \return int retorno [0] si se realizo el ordenamiento con exito. [1] = ERROR.
 *
 */
int ordenarPersonas(EPersona* aCargar, int limite, int flagOrden)
{
	int i=0, ordenar=0;
	EPersona aux;
    int retorno = 1;

    if(limite > 0 && aCargar != NULL)
    {
            do
            {
                ordenar = 0;
                for(i=0;i<limite-1;i++)
                {
                    if(!aCargar[i].estado && !aCargar[i+1].estado)
                    {
                        retorno=0;
                        /// DE MENOR A MAYOR                                                        DE MAYOR A MENOR
                        if((strcmp(aCargar[i].nombre,aCargar[i+1].nombre) > 0 && flagOrden ==0) || (strcmp(aCargar[i].nombre,aCargar[i+1].nombre) < 0 && flagOrden ==1))
                        {
                            aux = aCargar[i];
                            aCargar[i] = aCargar[i+1];
                            aCargar[i+1] = aux;
                            ordenar =1;
                        }
                    }
                }
            }while(ordenar==1);
	}

    if(ordenar ==0)
    {
        if(limite > 0 && aCargar != NULL)
        {
            for(i=0;i<limite;i++)
            {
                if(!aCargar[i].estado)
                {
                    printf("NOMBRE: %s  EDAD: %d - DNI: %d - ID: %d  - ESTADO: %d\n", aCargar[i].nombre, aCargar[i].edad, aCargar[i].dni, aCargar[i].id, aCargar[i].estado);
                    retorno=0;
                }

            }
        }
    }

	return retorno;
}

/** \brief Imprimo grafico de edades --> Genero contadores de las tres frajas de edad, si encuentro EDAD en el mismo rango cantidad[?] + 1.
 *
 * \param array EPersona* Trabajo sobre array personas.
 * \param limite int Limite del array (Limite de personas).
 * \return int retorno [0] si se pudo realizar impresion o [1] = ERROR.
 *
 */
int imprimir_GraficoEdad(EPersona* array,int limite)
{
    int i,j;
    int retorno=1;
    int auxEdadCantidad = 0;
    int cantidad[3];

    if(limite > 0 && array != NULL)
    {
        cantidad[0]=0;
        cantidad[1]=0;
        cantidad[2]=0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].estado && array[i].edad <= 18 && array[i].edad >0)
            {
                cantidad[0]+= 1;
            }
            else if(!array[i].estado && array[i].edad > 18 && array[i].edad <=35)
            {
                cantidad[1]+= 1;
            }
            else if(!array[i].estado && array[i].edad > 35)
            {
                cantidad[2]+= 1;
            }
        }
        if(cantidad[0]>cantidad[1] && cantidad[0]>cantidad[2])
        {
                auxEdadCantidad = cantidad[0];
        }
        else if(cantidad[1]>cantidad[0] && cantidad[1]>cantidad[2])
        {
            auxEdadCantidad = cantidad[1];
        }
        else
        {
            auxEdadCantidad = cantidad[2];
        }
        if(cantidad[0]!=0 || cantidad[1] !=0 || cantidad[2] !=0)
        {
            retorno=0;
            printf("\n--GRAFICO DE EDADES--\n");
            for(i=auxEdadCantidad; i>=0; i--)
            {
                for(j=0;j<3;j++)
                {
                    if(i<cantidad[j])
                    {
                        printf("  *\t");
                    }
                    else
                    {
                        printf("\t");
                    }
                }
                printf("\n");
            }
            printf("<18 \t18-35 \t>35 \n");
            printf("  %d \t  %d \t  %d ",cantidad[0],cantidad[1],cantidad[2]);
            printf("\nCANTIDAD DE PERSONAS\n\n");
        }
    }
    return retorno;
}
