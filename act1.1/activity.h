// =================================================================
//
// File: activity.h
// Author: Benjamin Arauz - A00836936
// Date: 18/08/2023
//
// =================================================================
#ifndef ACTIVITY_H
#define ACTIVITY_H

// =================================================================
// sumaIterativa. Calculate the sum from 1 to n with an iterative
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	??
// =================================================================
unsigned int sumaIterativa(unsigned int n) {
	int res = 0;
	for (int i = 1; i <= n; i++){
		res += i;
	}
	return res;
	//La complejidad es O(n), puesto que es un ciclo y se repite n veces.
}

// =================================================================
// sumaRecursiva. Calculate the sum from 1 to n with an recursive
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	??
// =================================================================
unsigned int sumaRecursiva(unsigned int n) {
	if (n == 0){
		return 0;
	} else {
		return n + sumaRecursiva(n-1);
		// Su compleejidad es O(n), debido a que se tiene una sola llamada en ejecucion y su 
		// parametro esta disminuyendo constantemente.
	}
}

// =================================================================s
// sumaDirecta. Calculate the sum from 1 to n with a mathematical
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	??
// =================================================================
unsigned int sumaDirecta(unsigned int n) {
	int res = (n * (n+1))/2;
	// Es O(1), debido a que no es un ciclo, solo es un calculo que se hace
	return res;
}

#endif /* ACTIVITY_H */
