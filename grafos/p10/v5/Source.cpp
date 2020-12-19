// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
				PRACTICA 10: Arboles libres
				-----------------------------
		
*/
#include <iostream>
#include <string>
#include "Grafo.h"
#include<fstream>

using namespace std;


/*
	Funcion que recorre un grafo contabilizando las aristas ( a ),
	tendremos en  cuenta que no contaremos dos veces las aristas,
	es decir que el origen solo contaremos cuando el origen <= al destino.	

	Complejidad O(v + e)
*/
void dfs_Aristas(Grafo const& G, size_t v, size_t &k, size_t &a, size_t *recorrido) {

	 vector<size_t> lista;
	 size_t w ;
	 ++k;

	recorrido[v] = k;
	lista = G.adj(v);

	while (!lista.empty()){

		w = lista.back();
		lista.pop_back();

		if (v <= w){

			a = a + 1;
		}
		if (recorrido[w] == 0){

			dfs_Aristas(G, w, k, a, recorrido);
		}
	}
	
}

bool es_Arbol_libre(Grafo G){

	size_t k = 0; size_t a = 0;
	size_t *recorrido = new size_t[G.V()];
	
	// INICIALIZAMOS A  0 el vector
	for (size_t i = 0; i < G.V(); i++)
	{
		recorrido[i] = 0;
	}

	dfs_Aristas(G, 1, k, a, recorrido);

	return ( (k == G.V()) && a == G.V() - 1);
}


void Grafo::ponArista(size_t v, size_t w) {
	if (v >= _V || w >= _V) throw std::invalid_argument("V�rtice inexistente");
	++_E;
	_adj[v].push_back(w);
	_adj[w].push_back(v);
}

const Adys& Grafo::adj(size_t v) const {
	if (v >= _V) throw std::invalid_argument("V�rtice inexistente");
	return _adj[v];
}



void resuelveCaso(Grafo G){

	
	// Arbol Libre
	bool ok =  es_Arbol_libre(G);

	// Mostrar solucion
	if (ok) cout << "SI" << endl;
	else cout << "NO" << endl;
	;
}

// Leer de fichero
void leer_Grafo_Archivo(string file) {

	ifstream entrada(file);
	size_t e, _V;
	size_t v, w;

	if (entrada.fail())
		throw std::runtime_error("Error en fichero.");
	
	// PRIMER GRAFO
	entrada >> _V;
	entrada >> e;

	while (_V != -1){
		
			// grafo auxiliar
				Grafo aux(_V);

				for (size_t i = 0; i < e; ++i) {
					entrada >> v;
					entrada >> w;
					aux.ponArista(v, w);
				}
				entrada.clear();
				resuelveCaso(aux);

		// SIGUIENTE GRAFO 
				entrada >> _V;
				entrada >> e;
				
	}
	
	entrada.close();
}

int main(){

	const string fich = "prueba.txt";
	
	leer_Grafo_Archivo(fich);

	system("PAUSE");
	return 0;
}