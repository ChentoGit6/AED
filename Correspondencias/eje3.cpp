/*InverseMaps. Dos correspondencias M1 y M2 son inversas una de la otra si tienen el mismo n´umero
de asignaciones y para cada par de asignaci´on x->y en M1 existe el par y->x en M2. Escribir un
predicado bool areinverse(map<int,int> &M1, map<int,int> &M2); que determina si las
correspondencias M1 y M2 son inversas.*/

#include <iostream>
#include <map>
using namespace std;

bool areinverse(map<int,int> &m1, map<int,int> &m2){
	if (m1.size() != m2.size()) {
		return false;
	}
	
	map<int,int>maux;
	for(auto &par : m1){
		maux[par.second] = par.first;
	}
	
	if (maux.size() != m1.size()) {
		return false;
	}
	
	return m1==m2;
}

int main() {
	map<int, int> m1 = {{1, 10}, {2, 20}};
	map<int, int> m2 = {{10, 1}, {20, 2}};
	map<int, int> m3 = {{1, 10}, {2, 99}}; 
	
	bool b = areinverse(m1,m3);
	cout << b;
	
	return 0;
}

