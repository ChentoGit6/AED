/* cutoffmap. Implemente una funci´on void cutoffmap(map<int, list<int>> &M, int p, int q)
que elimina todas las claves que NO est´an en el rango [p,q). En las asignaciones que quedan
tambi´en debe eliminar los elementos de la lista que no est´an en el rango. Si la lista queda vac´ia
entonces la asignaci´on debe ser eliminada. Por ejemplo: si M = {1->(2,3,4), 5->(6,7,8),
8->(4,5), 3->(1,3,7)}, entonces cutoffmap(M,1,6) debe dejar M={1->(2,3,4), 3->(1,3)}.
Notar que la clave 5 ha sido eliminada si bien est´a dentro del rango porque su lista quedar´ia vac´ia.
Restricciones: el programa no debe usar contenedores auxiliares*/

#include <iostream>
#include <map>
#include <list>
using namespace std;

void cutoffmap(map<int, list<int>> &m, int p, int q) {
	auto it = m.begin();
	
	while (it != m.end()) {
		// Caso 1: la clave está fuera del rango [p, q)
		if (it->first < p or it->first >= q) {
			it = m.erase(it); // Borra y avanza al siguiente elemento
		} 
		else {
			// Caso 2: la clave está dentro, limpiamos la lista
			auto b = it->second.begin();
			while (b != it->second.end()) {
				if (*b < p or *b >= q) {
					b = it->second.erase(b);
				} else {
					++b;
				}
			}
			
			// Si la lista quedó vacía, borramos la entrada del mapa
			if (it->second.empty()) {
				it = m.erase(it); // Borra y avanza
			} else {
				++it; // Avanzamos manualmente solo si no borramos
			}
		}
	}
}

int main() {
	map<int, list<int>> M = {{1, {2, 3, 4}}, {5, {6, 7, 8}}, {8, {4, 5}}, {3, {1, 3, 7}}};
	
	cutoffmap(M, 1, 6);
	
	// Salida esperada:
	// 1 -> 2 3 4 
	// 3 -> 1 3 
	for (const auto &par : M) {
		cout << par.first << " -> ";
		for (int x : par.second) {
			cout << x << " ";
		}
		cout << "\n";
	}
	return 0;
}
