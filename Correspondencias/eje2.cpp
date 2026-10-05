/*list2map. Escribir una funci´on que dadas las listas de claves (k1,k2,k3, ...) y valores
(v1,v2,v3, ...) retorna el map M con las asignaciones correspondientes
{ k1->v1, k2->v2, k3->v3, ...}. Utilice la signatura void list2map(map<int,int> &M,
list<int> &Keys, list<int> &Vals). Nota: si hay claves repetidas, s´olo debe quedar la
asignaci´on correspondiente a la ´ultima clave en la lista. Si hay menos valores que claves utilizar
cero como valor. Si hay m´as valores que claves, ignorarlos.*/

#include <iostream>
#include <map>
#include <list>
using namespace std;

void list2map(map<int,int> &m ,list<int> keys, list<int> &vals){
	auto it_k = keys.begin();
	auto it_v = vals.begin();
	
	while (it_k != keys.end()) {
		int clave = *it_k;
		int valor = 0; // si hay menos valores que calves, le ponemos cero
		
		if (it_v != vals.end()) {
			valor = *it_v;
			++it_v;
		}
		
		m[clave] = valor;
		++it_k;
	}
}

int main() {
	map<int, int> m;
	list<int> keys = {1, 2, 1, 4, 5};
	list<int> vals = {10, 20, 30, 40, 50, 60, 70, 80};
	
	list2map(m, keys, vals);
	
	for (auto &par : m) {
		cout << par.first << "," << par.second << " - ";
	}
	cout << endl;
	
	return 0;
	return 0;
}
