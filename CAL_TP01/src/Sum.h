/*
 * Sum.h
 */

#ifndef SUM_H_
#define SUM_H_

#include "Defs.h"
#include <climits>
#include <sstream>

/* Calcula, numa sequ�ncia de n n�meros (n > 0), para cada subsequ�ncia de m n�meros (m <= n, m > 0),
 * o �ndice i a partir do qual a soma s dos valores dessa subsequ�ncia � m�nimo.
 *
 * Argumentos:
 * 	sequence - Array com a sequ�ncia
 * 	size - Tamanho da sequ�ncia
 *
 * Devolve:
 * Uma string que cont�m com a indica��o do �ndice i e somat�rio s, para cada m
 * i[0],s[0];i[1],s[1],i[2],s[2]...
 * Exemplo: 1,4;9,1;11,2;18,1;22,0;
 */
string calcSum(int* sequence, int size){
	stringstream str;
	for(unsigned int m = 1; m <= size; m++){
		int minSeq = INT_MAX;
		unsigned int minSeqIndex;
		for(unsigned int i = 0; i <= size - m; i++){
			int seq = 0;
			for(unsigned int j = 0; j < m; j++){
				seq += sequence[i+j];
			}
			if(seq < minSeq){
				minSeq = seq;
				minSeqIndex = i;
			}

		}
		str << minSeq << "," << minSeqIndex << ";";
		//cout << "m: " << m << " s: " << minSeq << " i: " << minSeqIndex << endl;
	}
	return str.str();
}

#endif /* SUM_H_ */
