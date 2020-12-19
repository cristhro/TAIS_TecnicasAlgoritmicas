// Cristhian Rodriguez Gomez
// E51


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
// función que resuelve el problema
/*int resolver(int datos) {
cout << " Resolver datos" << endl;
return 1;
}*/

void contarMax(const int v[], int elem, int &numRepMax, int &valorMax){

	 valorMax = v[0], numRepMax = 0;

	for (int i = 0; i < elem; i++)
	{
		if (valorMax < v[i])
		{
			valorMax = v[i];
			numRepMax = 0;
		}
		if (valorMax == v[i])
		{
			numRepMax++;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int elem;
	cin >> elem;
	if (elem > 0 && elem <= 20000)
	{
		int *v = new int[elem];
		for (int i = 0; i < elem; i++)
		{
			cin >> v[i];
		}
		int numRepMax , valorMax;
		contarMax(v,elem, numRepMax, valorMax);
		delete[] v;

		// escribir sol
		std::cout << valorMax << " " << numRepMax<< std::endl;
	}
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	#ifndef DOMJUDGE
		std::ifstream in("datos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	#endif


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i){
		resuelveCaso();
	}


		// Para restablecer entrada. Comentar para acepta el reto
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		//system("PAUSE");
	#endif

	return 0;
}
