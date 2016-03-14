/*
 * Factorial.h
 */

#ifndef FACTORIAL_H_
#define FACTORIAL_H_

#include "Defs.h"

/*Calcula o factorial de um valor de entrada n usando recursividade*/
int factorialRecurs(int n){
	return (n==1) ? 1 : (n*factorialRecurs(n-1));
}

/*Calcula o factorial de um valor de entrada n usando programa��o din�mica*/
int factorialDinam(int n);

/*Calcula o factorial de todos os valores at� n (n >=0), colocando os resultados numa array*/
int* factorialDinamArray(int n);

#endif /* FACTORIAL_H_ */
