/*BasicSort. Escribir una funci´on void basic_sort(list<int> &L), que ordena los elementos de L
de menor a mayor. Para ello emplear el siguiente algoritmo simple: utilizando una lista auxiliar L2,
tomar el menor elemento de L, eliminarlo de L e insertarlo al final de L2 hasta que L este vac´ia.
Luego insertar los elementos de L2 en L.
*/

#include <iostream>
#include <list>
using namespace std;

void basic_sort(list<int>&L) {
	list<int>L2;
	while(!L.empty()) {
		auto b = L.begin();
		for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) { 
			if (*it < *b){
				b = it;
			}
		}	
		L2.push_back(*b);
		L.erase(b);
	}
	L = L2;
}

int main() {
	list<int>L = {3,2,5,1,4};
	for(auto it : L){
		cout << it << " ";
	}
	cout << endl;
	basic_sort(L);
	for(auto it : L){
		cout << it << " ";
	}
	auto it = L.begin();
	cout << ++*it;
	return 0;
}







