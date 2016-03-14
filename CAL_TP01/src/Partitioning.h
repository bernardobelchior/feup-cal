/*
 * Partioning.h
 */

#ifndef PARTITIONING_H_
#define PARTITIONING_H_

#include "Defs.h"

/*Implementa a fun��o s(n,k) usando recursividade*/
int s_recursive(int n,int k){
	return (k == 1 || k == n) ? 1 : s_recursive(n-1, k-1) + k*s_recursive(n-1, k);
}

/*Implementa a fun��o b(n) usando recursividade*/
int b_recursive(int n){
	int result = 0;
	for(unsigned int k = 1; k <= n; k++){
		result += s_recursive(n, k);
	}

	return result;
}

/*Implementa a fun��o s(n,k) usando programa��o din�mica*/
int s_dynamic(int n,int k);

/*Implementa a fun��o b(n) usando programa��o din�mica*/
int b_dynamic(int n);

#endif /* SUM_H_ */
