/*Camino. Implemente la funci´on bool es_camino(map<int,list<int>> G, list<int> &L) que
recibe una lista L y determina si es o no camino en el grafo G. El grafo se representa como un
mapa que relaciona cada v´ertice (clave) con la lista de sus v´ertices adyacentes (valor).*/

#include <iostream>
#include <map>
#include <list>
using namespace std;

bool es_camino(map<int,list<int>> &g, list<int> &l){
	if (l.size() <= 1) {
		return true;
	}
	
	auto it = l.begin();
	auto it2 = next(it);
	
	while(it2 != l.end()){
		auto it3 = g[*it].begin();
		
		bool encontrado = false;
		while(it3 != g[*it].end()){
			if (*it2 == *it3){
				encontrado = true;
				break;
			} else {
				++it3;
			}
		}
		
		if (!encontrado){
			return false;
		}
		++it;
		++it2;
	}
	return true;
}

int main() {
	// Grafo: 
	// 1 -> {2, 3}
	// 2 -> {3, 4}
	// 3 -> {4}
	// 4 -> {}
	map<int, list<int>> grafo = {
		{1, {2, 3}},
		{2, {3, 4}},
		{3, {4}},
		{4, {}}
	};
	
	list<int> c1 = {1, 2, 4}; // Camino válido (1->2 y 2->4)
	list<int> c2 = {1, 4};    // No es camino (no hay arista directa 1->4)
	list<int> c3 = {2, 4};
	list<int> c4 = {4};
	
	cout << boolalpha;
	cout << "c1 es camino: " << es_camino(grafo, c1) << "\n"; // true
	cout << "c2 es camino: " << es_camino(grafo, c2) << "\n"; // false
	cout << "c3 es camino: " << es_camino(grafo, c3) << "\n"; // true
	cout << "c4 es camino: " << es_camino(grafo, c4) << "\n"; // true
	
	return 0;
}
