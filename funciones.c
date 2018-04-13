#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funciones.h"

///--------------------------- OPERANDO UNO (A) -------///

/** \brief FUNCION PARA EL INGRESO Y VALIDACION DEL PRIMER OPERANDO ACORDE AL TIPO DE DATO
 *
 * \param numUno float* Cargo el primer operando (A).
 * \param mensaje char* Mensaje de instrucción al usuario.
 * \param mensajeError char* Mensaje de error para el usuario, en caso de sobrepasar el tamaño de almacenamiento segun tipo de dato.
 * \return int Retorno [0] si el numero se guardo sin errores, [-1] si sobrepaso los limites del long.
 *
 */

int getNumUno(float *numUno, char* mensaje, char* mensajeError)
{
    int retorno = -1;
    float aux = 0;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%f", &aux);
    while (!(aux < LONG_LONG_MAX && aux > LONG_LONG_MIN))
    {
        printf("%s", mensajeError);
        scanf("%f", &aux);
    }
    *numUno = aux;
    retorno = 0;

    return retorno;
}

///-------------------------SEGUNDO OPERANDO (B)-----///

/** \brief  FUNCION PARA EL INGRESO Y VALIDACION DEL SEGUNDO OPERANDO ACORDE AL TIPO DE DATO.
 *
 * \param numDos float* Cargo el segundo operando (B).
 * \param mensaje char* Mensaje de instruccion al usuario.
 * \param mensajeError char* Mensaje de error para el usuario,
                    en caso de sobrepasar el tamaño de almacenamiento segun tipo de dato.
 * \return int Retorno [0] si el numero se guardo sin errores, [-1] si sobrepaso los limites del long.
 *
 */
int getNumDos(float *numDos, char* mensaje, char* mensajeError)
{
    int retorno = -1;
    float aux = 0;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%f", &aux);
    while (!(aux < LONG_LONG_MAX && aux > LONG_LONG_MIN))
    {
        printf("%s", mensajeError);
        scanf("%f", &aux);
    }
    *numDos = aux;
    retorno = 0;
    return retorno;
}

///------------------------FUNCION SUMAR------///

/** \brief FUNCION UTILIZADA PARA CALCULAR SUMA ENTRE OPERANDO (A) y (B).
 *
 * \param suma float* Cargo en el main el resultado de la suma, por puntero.
 * \param auxUno float  valor Primer (A) operando cargado previamente.
 * \param auxDos float  valor Segundo (B) operando cargado previamente.
 * \param condicionOperandoUno int Valido si el Primer operando fue ingresado.
 * \param condicionOperandoDos int Valido si el Segundo operando fue ingresado.
 * \param mensajeErrorA char* Cargo mensaje por parametro (Si operando (A) no fue cargado).
 * \param mensajeErrorB char* Cargo mensaje por parametro (Si operando (B) no fue cargado).
 * \param mensajeErrorAB char* Cargo mensaje por parametro (Si ningun operando fue cargado (A) y (B)).
 * \return int Retorno [0] si se realizo la suma satisfactoriamente y [1] si no se pudo realizar operacion.
 *
 */
int getSuma(float *suma, float auxUno, float auxDos, int condicionOperandoUno, int condicionOperandoDos, char* mensajeErrorA, char* mensajeErrorB, char* mensajeErrorAB)
{
    int retorno = 1;
    if(condicionOperandoUno == 0 && condicionOperandoDos == 0)
    {
        *suma = auxUno + auxDos;
        retorno = 0;
    }
    else if(condicionOperandoUno == 1 && condicionOperandoDos == 0)
    {
       printf("%s", mensajeErrorA);
    }
    else if(condicionOperandoUno == 0 && condicionOperandoDos == 1)
    {
        printf("%s", mensajeErrorB);
    }

    else if(condicionOperandoUno == 1 && condicionOperandoDos == 1)
    {
        printf("%s", mensajeErrorAB);
    }

return retorno;
}

///-------------------------FUNCION RESTAR-----///

/** \brief  FUNCION UTILIZADA PARA CALCULAR RESTA ENTRE OPERANDO (A) y (B)
 *
 * \param resta float* Devuelvo el resultado de la operación resta al mail, mediante puntero.
 * \param auxUno float Cargo operando (A), primer valor.
 * \param auxDos float Cargo operando (B), segundo valor.
 * \param condicionOperandoUno int Verifico que el operando (A), sea valido y haya sido cargado.
 * \param condicionOperandoDos int Verifico que el operando (B), sea valido y haya sido cargado.
 * \param mensajeErrorA char* Si condicionOperandoUno = [1] muestro mensaje que indica que Operando (A) no fue cargado.
 * \param mensajeErrorB char* Si condicionOperandoDos = [1] muestro mensaje que indica que Operando (B) no fue cargado.
 * \param mensajeErrorAB char* Si condicionOperandoUno y condicionOperandoDos = [1], muestro que ningun operando fue cargado.
 * \return int Retorno [0] si se realizo la resta satisfactoriamente y [1] si no se pudo realizar operacion.
 *
 */
 int getResta(float *resta, float auxUno, float auxDos, int condicionOperandoUno, int condicionOperandoDos, char* mensajeErrorA, char* mensajeErrorB, char* mensajeErrorAB)
{
    int retorno= 1;
    if(condicionOperandoUno == 0 && condicionOperandoDos == 0)
    {
        *resta = auxUno - auxDos;
        retorno = 0;
    }
    else if(condicionOperandoUno == 1 && condicionOperandoDos == 0)
    {
        printf("%s", mensajeErrorA);
    }
    else if(condicionOperandoUno == 0 && condicionOperandoDos == 1)
    {
        printf("%s", mensajeErrorB);
    }
    else if(condicionOperandoUno == 1 && condicionOperandoDos == 1)
    {
        printf("%s", mensajeErrorAB);
    }
    return retorno;
}

///-------------------------------FUNCION DIVIDIR-----///

/** \brief FUNCION UTILIZADA PARA CALCULAR DIVISONES ENTRE OPERANDO (A) y (B)
 *
 * \param division float* Devuelvo el resultado de la operación DIVISION al MAIN, mediante puntero.
 * \param auxUno float Cargo operando (A), primer valor.
 * \param auxDos float Cargo operando (B), segundo valor.
 * \param condicionOperandoUno int Verifico que el operando (A), sea valido y haya sido cargado.
 * \param condicionOperandoDos int Verifico que el operando (B), sea valido y haya sido cargado.
 * \param mensajeErrorA char* Si condicionOperandoUno = [1] muestro mensaje que indica que Operando (A) no fue cargado.
 * \param mensajeErrorB char* Si condicionOperandoDos = [1] muestro mensaje que indica que Operando (B) no fue cargado.
 * \param mensajeErrorAB char* Si condicionOperandoUno y condicionOperandoDos = [1], muestro que ningun operando fue cargado.
 * \param mensajeErrorCero char* Si auxDos = 0, muestra error ya que no se puede dividir por 0.
 * \return int Retorno [0] si se realizo la DIVISION satisfactoriamente y [1] si no se pudo realizar operacion.
 *
 */
int getDivision(float *division, float auxUno, float auxDos, int condicionOperandoUno, int condicionOperandoDos, char* mensajeErrorA, char* mensajeErrorB, char* mensajeErrorAB, char* mensajeErrorCero)
{
    int retorno= 1;
    if(condicionOperandoUno == 0 && condicionOperandoDos == 0)
    {
        if(auxDos != 0)
        {
            *division = auxUno / auxDos;
            retorno = 0;
        }
        else
        {
            printf("%s", mensajeErrorCero);
        }

    }
    else if(condicionOperandoUno == 1 && condicionOperandoDos == 0)
    {
            printf("%s", mensajeErrorA);
    }
    else if(condicionOperandoUno == 0 && condicionOperandoDos == 1)
    {
        printf("%s", mensajeErrorB);
    }
    else if(condicionOperandoUno == 1 && condicionOperandoDos == 1)
    {

            printf("%s", mensajeErrorAB);
    }
    return retorno;
}

///----------------------------FUNCION PARA MULTIPLICAR-----///

/** \brief FUNCION UTILIZADA PARA CALCULAR MULTIPLICACION ENTRE OPERANDO (A) y (B)
 *
 * \param multiplicacion float* Devuelvo el resultado de la operación MULTIPLICACION al MAIN, mediante puntero.
 * \param auxUno float Cargo operando (A), primer valor.
 * \param auxDos float Cargo operando (B), segundo valor.
 * \param condicionOperandoUno int Verifico que el operando (A), sea valido y haya sido cargado.
 * \param condicionOperandoDos int Verifico que el operando (B), sea valido y haya sido cargado.
 * \param mensajeErrorA char* Si condicionOperandoUno = [1] muestro mensaje que indica que Operando (A) no fue cargado.
 * \param mensajeErrorB char* Si condicionOperandoDos = [1] muestro mensaje que indica que Operando (B) no fue cargado.
 * \param mensajeErrorAB char* Si condicionOperandoUno y condicionOperandoDos = [1], muestro que ningun operando fue cargado.
 * \return int Retorno [0] si se realizo la MULTIPLICACION satisfactoriamente y [1] si no se pudo realizar operacion.
 *
 */
int getMultiplicacion(float *multiplicacion, float auxUno, float auxDos, int condicionOperandoUno, int condicionOperandoDos, char* mensajeErrorA, char* mensajeErrorB, char* mensajeErrorAB)
{
    int retorno= 1;
    if(condicionOperandoUno == 0 && condicionOperandoDos == 0)
    {
        *multiplicacion = auxUno * auxDos;
        retorno = 0;
    }
    else if(condicionOperandoUno == 1 && condicionOperandoDos == 0)
    {
            printf("%s", mensajeErrorA);
    }
    else if(condicionOperandoUno == 0 && condicionOperandoDos == 1)
    {
        printf("%s", mensajeErrorB);
    }
    else if(condicionOperandoUno == 1 && condicionOperandoDos == 1)
    {
        printf("%s", mensajeErrorAB);
    }
    return retorno;
}

///-------------------------   FACTORIAL   ----------------///

/** \brief FUNCION UTILIZADA PARA CALCULAR FACTORIAL DE (A)
 *
 * \param resultadoFactorial long* Devuelvo el resultado de la operación FACTORIAL al MAIN, mediante puntero.
 * \param auxUno long Cargo operando (A), primer valor.
 * \param validacionOperandoUno int Verifico que el operando (A), sea valido y haya sido cargado (validacionOperandoUno = 0).
 * \param mensajeErrorOp char* Muestro mensaje indicando que no se cargo Operando (A) si (validacionOperando = 1).
 * \param mensajeErrorCero char* Si auxUno = [0], muestro error, no se puede calcular factorial <= 0.
 * \return int
 *
 */
int getFactorial(long *resultadoFactorial, long auxUno, int validacionOperandoUno, char* mensajeErrorOp, char* mensajeErrorCero)
{
    int retorno = 1;
    long i = 1;
    long auxFactorial = 1;


    if(validacionOperandoUno == 0)
    {
        if((long)auxUno > 0)
        {
            for (i = 1 ; i <= auxUno; i++)
            {
                auxFactorial = auxFactorial * (i);
            }
            if(auxFactorial > LONG_LONG_MAX)
            {
                printf("\nEL VALOR DEL FACTORIAL SOBREPASA TIPO DE DATO LONG\n");
            }
            else
            {
                *resultadoFactorial = auxFactorial;
                retorno = 0;
            }




        }
        else
        {
            printf("%s", mensajeErrorCero);
        }
    }
    else
    {
        printf("%s", mensajeErrorOp);
    }
    return retorno;
}

///----------------   TOTAL FUNCIONES    --------------///

/** \brief FUNCION CREADA PARA VERIFICAR ERRORES MATEMATICOS, DE SER VALIDO TODOS LOS VALORES, SE REALIZARAN TODAS LAS FUNCIONES.
 *
 * \param auxUno float Cargo operando (A), primer valor.
 * \param auxDos float Cargo operando (B), segundo valor.
 * \param condicionOperandoUno int Verifico que el operando (A), sea valido y haya sido cargado.
 * \param condicionOperandoDos int Verifico que el operando (B), sea valido y haya sido cargado.
 * \return int retorno el valor de "retorno", si es = [0], realizo todas las funciones, = y vuelvo funcion a valores por defecto si = [1]
 */
int getImprimirFunciones(float auxUno, float auxDos, int validacionNumUno, int validacionNumDos)
{
    int retorno = 1;

    if (validacionNumUno == 0 && validacionNumDos ==0)
    {
        if(auxUno <= 0 &&auxDos == 0)
        {
            printf("\nERROR, (A) <= 0, NO SE PUEDE CALCULAR FACTORIAL\n");
            printf("\nERROR, (B) = 0, NO SE PUEDE DIVIDIR POR 0\n\n");
        }
        else if(auxUno != 0 &&auxDos == 0)
        {
            printf("\nERROR, (B) = 0, NO SE PUEDE DIVIDIR POR 0\n\n");
        }
        else if(auxUno <= 0 && auxDos !=0)
        {
            printf("\nERROR, (A) <= 0, NO SE PUEDE CALCULAR FACTORIAL\n\n");
        }
        else
        {
            retorno = 0;
        }
    }


    else if(validacionNumUno == 0 && validacionNumDos == 1)
    {
        if(auxUno <= 0)
        {
            printf("\nERROR, (A) <= 0, NO SE PUEDE CALCULAR FACTORIAL\n");
            printf("\nERROR, DEBE INGRESAR SEGUNDO OPERANDO (B) (OP 2)\n\n");
        }
        else
        {
            printf("\nERROR, DEBE INGRESAR SEGUNDO OPERANDO (B) (OP 2)\n\n");
        }
    }
    else if(validacionNumUno == 1 && validacionNumDos == 0)
    {
        if(auxDos == 0)
        {
            printf("\nERROR, DEBE INGRESAR PRIMER OPERANDO (A) (OP 1)\n");
            printf("\nERROR, (B) = 0, NO SE PUEDE DIVIDIR POR 0\n\n");
        }
        else
        {
            printf("\nERROR, DEBE INGRESAR PRIMER OPERANDO (A) (OP 1)\n\n");
        }

    }
    else
    {
         printf("\nNO HA INGRESADO NINGUN OPERANDO (A y B) \n");
    }


    return retorno;
}

/// ----------------  FUNCION REINICIO VALORES VARIABLES ----------------///

/** \brief FUNCION PARA VOLVER LAS VARIABLES DEL MAIN A SUS VALORES INICIALES PARA EVITAR IMPRESION DE RESULTADOS;
 *
 * \param rsuma Retorno valor por defecto a declarada en el main como "resultadoSuma"
 * \param rresta int* Retorno valor por defecto a declarada en el main como "resultadoResta"
 * \param rdivision int* Retorno valor por defecto a declarada en el main como "resultadoDivision"
 * \param rmultiplicacion int* Retorno valor por defecto a declarada en el main como "resultadoMultiplicacion"
 * \param rfactorial int* Retorno valor por defecto a declarada en el main como "resultadoFactorial"
 * \param rtotalfunciones int* Retorno valor por defecto a declarada en el main como "totalFunciones"
 * \return int Retorno [0].
 *
 */
int volverDefault(int *rsuma, int *rresta, int *rdivision, int *rmultiplicacion, int *rfactorial, int *rtotalfunciones)
{
    system("cls");
    *rsuma = 1;
    *rresta = 1;
    *rdivision = 1;
    *rmultiplicacion=1;
    *rfactorial=1;
    *rtotalfunciones = 1;
    return 0;
}


