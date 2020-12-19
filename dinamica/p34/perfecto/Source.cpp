// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
	PRACTICA 34: Las Vacas pensantes

	El problema es resuelto a través de una matriz en la que almacenamos los valores. Además,
	la diagonal d = 1 es dónde se encuentra el caso básico y después sólo se recorren las diagonales
	impares (porque en cada 'ronda' se gastan dos cubos).
	
	Coste en tiempo: O(n^2) debido a los dos cubles for
	Coste en espacio: O(n^2) por el uso de matrices
	
	Llamada recursiva:
	
	vacas(i, j) = max {
						pi + {vacas(i + 1, j - 1) si pj > pi+1  ||  vacas(i + 2, j) si pi+1 > pj
						pj + {vacas(i + 1, j - 1) si pi > pj-1  ||  vacas(i, j - 2) si pj-1 > pi
					}
	
	Caso básico:
	
	vacas(i, i + 1) = max{pi, pi + 1}
*/
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm> // min
#include "Matriz.h"
#include <vector>
#include <string>

using namespace std;



int vacas(vector<int> const& C) {

	int n = C.size() - 1;
	Matriz<int > vacas(n + 1, n + 1);

	int inicio ;

	if (n % 2 == 0){
		//inicializacion
		for (int i = 1; i <= n - 1; i++)
		{
			vacas[i][i + 1] = max(C[i], C[i + 1]);

		}
		inicio = 3;
	}

	else {
		//inicializacion
		for (int i = 1; i <= n ; i++)
		{
			vacas[i][i] =  C[i];

		}
		inicio = 2;
	}


	//recorre diagonales
	for (int d = inicio; d <= n - 1; d ++)
	{
		//recorre elementos dentro de la diagonal
		for (int i = 1; i <= n - d; i++)
		{
			int j = i + d;
			int como_i;
			int como_j;

			if (C[j] > C[i + 1]) {
				como_i = vacas[i + 1][j - 1];
			}
			else {
				como_i = vacas[i + 2][j];
			}

			if (C[i] > C[j - 1])
			{
				como_j = vacas[i + 1][j - 1];
			}
			else {
				como_j = vacas[i][j - 2];
			}
			vacas[i][j] = max(C[i] + como_i, C[j] + como_j);
			
		}

	}

	// fin recorrido diagonales
	 

	return vacas[1][n];
}
bool resuelveCaso() {


	int N; // numero de cubos

	cin >> N;

	if (N == 0) {
		return false;
	}
	vector<int>cantidad_comida(N + 1);

	for (size_t i = 1; i <= N; i++)
	{
		cin >> cantidad_comida[i];
	}
	int solucion = vacas(cantidad_comida);

	// mostrar solucion
	cout << solucion << endl;
	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}