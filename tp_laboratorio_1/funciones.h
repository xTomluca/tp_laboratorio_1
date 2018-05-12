#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <limits.h>

int getNumUno(float *numUno, int *validacionOperandoUno, int *validacionOperandoDos, char* mensaje, char* mensajeError);
int getNumDos(float *numDos,  int *validacionOperandoUno, int *validacionOperandoDos, char* mensaje, char* mensajeError);
int getSuma(float *suma, float auxUno, float auxDos, int condicionOperandoUno, int condicionOperandoDos, char* mensajeErrorA, char* mensajeErrorB, char* mensajeErrorAB);
int getResta(float *resta, float auxUno, float auxDos, int condicionOperandoUno, int condicionOperandoDos, char* mensajeErrorA, char* mensajeErrorB, char* mensajeErrorAB);
int getDivision(float *division, float auxUno, float auxDos, int condicionOperandoUno, int condicionOperandoDos, char* mensajeErrorA, char* mensajeErrorB, char* mensajeErrorAB, char* mensajeErrorCero);
int getMultiplicacion(float *multiplicacion, float auxUno, float auxDos, int condicionOperandoUno, int condicionOperandoDos,char* mensajeErrorA, char* mensajeErrorB, char* mensajeErrorAB);
int getFactorial(long *resultadoFactorial, long auxUno, int validacionOperandoUno, char* mensajeErrorOp, char* mensajeErrorCero);
int getImprimirFunciones(float auxUno, float auxDos, int validacionNumUno, int validacionNumDos);
int volverDefault(int *rsuma, int *rresta, int *rdivision, int *rmultiplicacion, int *rfactorial, int *rtotalfunciones);

#endif // FUNCIONES_H_INCLUDED
