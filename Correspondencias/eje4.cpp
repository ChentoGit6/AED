/*mergeMap. Dadas dos correspondencias A y B, que asocian enteros con listas ordenadas de enteros,
escribir una funci´on void merge_map(map<int, list<int>> &A, map<int, list<int>> &B,
map<int, list<int>> &C) que devuelve en C una correspondencia que asigna al elemento x la
fusi´on ordenada de las dos listas A[x] y B[x]. Si x no es clave de A, entonces C[x] debe ser B[x] y
viceversa. Sugerencia: utilice la funci´on merge implementada en uno de los ejercicios anteriores.*/

#include <iostream>
#include <map>
#include <list>
using namespace std;

void merge_map(map<int, list<int>> &a, map<int, list<int>> &b, map<int, list<int>> &c){
	// 1. Cargamos todas las claves y listas de 'a' en 'c'
	c = a;
	// 2. Procesamos 'b'
	for (auto &par : b) {
		int clave = par.first;
		list<int> lista_b = par.second; // Copia local para no vaciar 'b' con merge()
		
		if (c.count(clave) == 0) {
			// Caso: clave solo en b
			c[clave] = lista_b;
		} else {
			// Caso: clave en ambos -> fusionamos las dos listas ordenadas
			c[clave].merge(lista_b);
		}
	}
}
	
	int main() {
		map<int, list<int>> A = {
			{1, {10, 30, 50}},
		{2, {1, 5}},
			{4, {100}}
		};
		
		map<int, list<int>> B = {
			{1, {20, 40}},
		{3, {7, 8, 9}},
			{4, {50, 150}}
		};
		
		map<int, list<int>> C;
		merge_map(A, B, C);
		
		for (const auto &par : C) {
			cout << "Clave " << par.first << ": ";
			for (int val : par.second) {
				cout << val << " ";
			}
			cout << "\n";
		}
	return 0;
}

