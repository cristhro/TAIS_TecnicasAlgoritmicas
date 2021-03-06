// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

// El problema se ha resuelto usando  la clase Arbol_Libre,  
// un nuevo m�todo que devuelve si un arbol es libre (previamente calculado en el constructor de la clase).
// claves dadas.

#include <iostream>
#include <string>
#include "GrafoValorado.h"
#include "Pavimentar_City.h"
using namespace std;



// lectura estandar de un grafo por consola
GrafoValorado<double> leer_Grafo(size_t V){
	size_t E;
	cin >> E;
	 
	GrafoValorado<double> g(V);
	
	size_t v, w, valor;

	for (size_t i = 0; i < E; i++)
	{
	
		cin >> v;
		cin >> w;
		cin >> valor;

		Arista<double> arista(v,w,valor);    
		g.ponArista(arista);
	}
	return g;
}


// resuelve un caso de prueva
bool resuelveCaso(){

	// leer grafo
	size_t V;
	cin >> V;

	if (!cin){
		return false;
	}

	GrafoValorado<double> G = leer_Grafo(V);			// O( e + v ) donde n es el numero de vertices del grafo.

	//G.print();
	// Pavimentar city

	Pavimentar_City pavimentar(G);

	cout << pavimentar.coste_minimo() << endl;
	// Mostrar solucion

	return true;

}

int main(){

	// casos de prueba ilimitados
	while (resuelveCaso());
	system("PAUSE");
	return 0;
}