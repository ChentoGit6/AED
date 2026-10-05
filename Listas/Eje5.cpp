/*Junta. Escribir una funci´on void junta(list<int> &L, int c) que, dada una lista L, agrupa de
a c elementos, dejando su suma in place. Por ejemplo, si se le pasa como argumento la lista
L=(1,3,2,4,5,2,2,3,5,7,4,3,2,2), despu´es de aplicar el algoritmo junta(L,3) debe quedar
L=(6,11,10,14,4) (notar que se agrupan los ´ultimos elementos, pese a no completar los tres
requeridos). El algoritmo debe tener un tiempo de ejecuci´on O(n).*/

#include <iostream>
#include <list>
using namespace std;

void junta (list<int> &l, int c){
	if (l.empty() || c <= 1) return;
	auto b = l.begin();
	
	while (b != l.end()){
		
		auto it = next(b);
		int cont = 1;
		
		while (it != l.end() && cont < c) {
			*b += *it;
			it = l.erase(it); 
			cont++;
		}
		
		b = it;
		
	}
}

int main() {
	list<int> l = {1,3,2,4,5,2,2,3,5,7,4,3,2,2};
	junta(l,3);
	for(auto x : l){
		cout << x << " ";
	}
	return 0;
}

