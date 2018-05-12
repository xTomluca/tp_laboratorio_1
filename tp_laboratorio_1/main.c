#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funciones.h"

int main()
{
    char seguirOperando='s';
    int opcionUsuario=0;
    float numUno = 0;
    float numDos = 0;
    float suma = 0;
    float resta = 0;
    float division = 1;
    float multiplicacion = 1;
    long factorial = 1;
    int resultadoSuma = 1;
    int resultadoResta = 1;
    int resultadoOperandoUno = 1;
    int resultadoOperandoDos = 1;
    int resultadoDivision = 1;
    int resultadoMultiplicacion = 1;
    int resultadoFactorial = 1;
    int totalFunciones = 1;


    while(seguirOperando=='s')
    {
        if(resultadoOperandoUno == 0)
        {
            printf("\n1- Ingresar 1er operando (A=%.2f)\n", numUno);
        }
        else
        {
            printf("\n1- Ingresar 1er operando (A=x)\n");
        }
        if(resultadoOperandoDos == 0)
        {
            printf("2- Ingresar 2do operando (B=%.2f)\n", numDos);
        }
        else
        {
            printf("2- Ingresar 2do operando (B=x)\n");
        }
        if(resultadoSuma == 0 ||  totalFunciones== 0)
        {
            printf("3- Calcular la suma (A+B)| EL RESULTADO ES : %.2f\n", suma);
        }
        else
        {
            printf("3- Calcular la suma (A+B)\n");
        }
        if(resultadoResta == 0 ||  totalFunciones== 0)
        {
            printf("4- Calcular la resta (A-B)| EL RESULTADO ES : %.2f\n", resta);
        }
        else
        {
            printf("4- Calcular la resta (A-B)\n");
        }
        if(resultadoDivision == 0 ||  totalFunciones== 0)
        {
            printf("5- Calcular la division (A/B) | EL RESULTADO ES : %.2f\n", division);
        }
        else
        {
            printf("5- Calcular la division (A/B)\n");
        }
        if(resultadoMultiplicacion == 0 || totalFunciones== 0)
        {
            printf("6- Calcular la multiplicacion (A*B) | EL RESULTADO ES : %.2f\n", multiplicacion);
        }
        else
        {
            printf("6- Calcular la multiplicacion (A*B)\n");
        }
        if(resultadoFactorial == 0 || totalFunciones == 0)
        {
           printf("7- Calcular el factorial (A!) | FACTORIAL DE (A) %ld = %ld\n", (long)numUno, (long)factorial);
        }
        else
        {
            printf("7. Calcular el factorial (A!)\n");
        }
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n\n");
        fflush(stdin);
        scanf("%d",&opcionUsuario);
        while(!(opcionUsuario < 10 && opcionUsuario > 0))
        {
            printf("\nValor ingresado invalidado, intentelo nuevamente \n");
            fflush(stdin);
            scanf("%d",&opcionUsuario);
        }
            switch(opcionUsuario)
            {
                case 1:
                        volverDefault(&resultadoSuma, &resultadoResta, &resultadoDivision, &resultadoMultiplicacion, &resultadoFactorial, &totalFunciones);
                        resultadoOperandoUno = getNumUno(&numUno, &resultadoOperandoUno, &resultadoOperandoDos, "1- Ingresar 1er operando (A=x)\n", "\nVALOR INVALIDO! Reingresar 1er operando (A=x) ");
                        break;
                case 2:
                        volverDefault(&resultadoSuma, &resultadoResta, &resultadoDivision, &resultadoMultiplicacion, &resultadoFactorial, &totalFunciones);
                        resultadoOperandoDos = getNumDos(&numDos, &resultadoOperandoUno, &resultadoOperandoDos, "2- Ingresar 2do operando (B=x)\n", "\nVALOR INVALIDO! Reingresar 2do operando (A=x) ");
                        break;
                case 3:
                        volverDefault(&resultadoSuma, &resultadoResta, &resultadoDivision, &resultadoMultiplicacion, &resultadoFactorial, &totalFunciones);
                        resultadoSuma= getSuma(&suma, numUno, numDos, resultadoOperandoUno, resultadoOperandoDos,"\nERROR, DEBE INGRESAR PRIMER OPERANDO (A) (Op 1) \n\n", "\nERROR, DEBE INGRESAR SEGUNDO OPERANDO (B) (OP 2) \n\n", "\nNO HA INGRESADO NINGUN OPERANDO (A y B) \n\n");
                        break;
                case 4:
                        volverDefault(&resultadoSuma, &resultadoResta, &resultadoDivision, &resultadoMultiplicacion, &resultadoFactorial, &totalFunciones);
                        resultadoResta= getResta(&resta, numUno, numDos, resultadoOperandoUno, resultadoOperandoDos, "\nERROR, DEBE INGRESAR PRIMER OPERANDO (A) (Op 1) \n\n", "\nERROR, DEBE INGRESAR SEGUNDO OPERANDO (B) (OP 2) \n\n", "\nNO HA INGRESADO NINGUN OPERANDO (A y B) \n\n");
                        break;
                case 5:
                        volverDefault(&resultadoSuma, &resultadoResta, &resultadoDivision, &resultadoMultiplicacion, &resultadoFactorial, &totalFunciones);
                        resultadoDivision = getDivision(&division, numUno, numDos, resultadoOperandoUno, resultadoOperandoDos, "\nERROR, DEBE INGRESAR PRIMER OPERANDO (A) (Op 1) \n\n", "\nERROR, DEBE INGRESAR SEGUNDO OPERANDO (B) (OP 2) \n\n", "\nNO HA INGRESADO NINGUN OPERANDO (A y B) \n\n", "\nDIVIDIR POR 0 NO ES VALIDO\n\n");
                        break;
                case 6:
                        volverDefault(&resultadoSuma, &resultadoResta, &resultadoDivision, &resultadoMultiplicacion, &resultadoFactorial, &totalFunciones);
                        resultadoMultiplicacion = getMultiplicacion(&multiplicacion, numUno, numDos, resultadoOperandoUno, resultadoOperandoDos, "\nERROR, DEBE INGRESAR PRIMER OPERANDO (A) (Op 1) \n\n", "\nERROR, DEBE INGRESAR SEGUNDO OPERANDO (B) (OP 2) \n\n", "\nNO HA INGRESADO NINGUN OPERANDO (A y B) \n\n");
                        break;
                case 7:
                        volverDefault(&resultadoSuma, &resultadoResta, &resultadoDivision, &resultadoMultiplicacion, &resultadoFactorial, &totalFunciones);
                        resultadoFactorial = getFactorial(&factorial, (long)numUno, resultadoOperandoUno, "\nERROR, DEBE INGRESAR PRIMER OPERANDO (A) (Op 1) \n\n", "\nERROR, OPERANDO (A) <= 0\n\n");
                        break;
                case 8:
                        volverDefault(&resultadoSuma, &resultadoResta, &resultadoDivision, &resultadoMultiplicacion, &resultadoFactorial, &totalFunciones);
                        totalFunciones = getImprimirFunciones(numUno, numDos, resultadoOperandoUno, resultadoOperandoDos);
                        if(totalFunciones == 0)
                        {
                            resultadoSuma= getSuma(&suma, numUno, numDos, resultadoOperandoUno, resultadoOperandoDos, "", "", "");
                            resultadoResta= getResta(&resta, numUno, numDos, resultadoOperandoUno, resultadoOperandoDos, "", "", "");
                            resultadoDivision = getDivision(&division, numUno, numDos, resultadoOperandoUno, resultadoOperandoDos, "", "", "", "");
                            resultadoMultiplicacion = getMultiplicacion(&multiplicacion, numUno, numDos, resultadoOperandoUno, resultadoOperandoDos, "", "", "");
                            resultadoFactorial = getFactorial(&factorial, (long)numUno, resultadoOperandoUno, "", "");
                        }
                        break;
                case 9:
                        seguirOperando = 'n';
                        break;

             }
    }
return 0;
}
