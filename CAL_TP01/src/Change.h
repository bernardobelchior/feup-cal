/*
 * Change.h
 */

#ifndef CHANGE_H_
#define CHANGE_H_

#include "Defs.h"
#include <sstream>

/* Calcula o troco para n c�ntimos, utilizando o n�mero m�nimo de moedas, tendo apenas dispon�veis
 * moedas de 1, 2 e 5 c�ntimos.
 *
 * Devolve:
 * Uma string que cont�m com a indica��o, para cada n, a combina��o de moedas a utilizar.
 * Por exemplo: troco de 1 c�ntimo: 1 moeda de 1
 * 				troco de 2 c�ntimos: 1 moeda de 2
 * 				troco de 3 c�ntimos: 1 moeda de 1, 1 moeda de 2
 * 				(...)
 * A string devolvida representar os valores das moedas (separadas por virgula) para cada n (separado por ponto e v�rgula)
 * Exemplo: 1;2;1,2;2,2;5;1,5;...
 * */
//string calcChange(int n){
//	string change;
//
//	for(unsigned int i = 1; i <= n; i++){
//		unsigned int k = i;
//		unsigned int n1, n2, n5;
//
//		n5 = k/5;
//		k %= 5;
//		n2 = k/2;
//		n1 = k%2;
//
//		for(unsigned int j = 0; j < n1; j++)
//			change += "1,";
//
//		for(unsigned int j = 0; j < n2; j++)
//			change += "2,";
//
//		for(unsigned int j = 0; j < n5; j++)
//			change += "5,";
//
//		change[change.length()-1] = ';';
//	}
//
//	return change;
//}

string calcChange(int n){
	unsigned int best[n+1] = {0};
	unsigned int cost[n+1] = {0};
	int coins[] = {5, 2, 1};

	for(unsigned int i = 0; i < 3; i++){
		for(unsigned int j = coins[i]; j <=n; j++){
			unsigned int toPay = j - cost[j];
			if(coins[i] <= toPay){
				best[j] = coins[i];
				cost[j] = coins[i] + cost[j-coins[i]];
			}
		}
	}

	//Create the solution
	stringstream ss;
	for(unsigned int i = 0; i <= n; i++){
		unsigned int rest = i;
		while(rest > 0){
			ss << best[rest] << ",";
			rest -= best[rest];
		}
		ss << ";";
	}


	return ss.str();
}

#endif /* CHANGE_H_ */
