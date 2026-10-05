/*SelectionSort. Escribir una funci´on void selection_sort(list<int> &L), que ordena los
elementos de L de menor a mayor. Para ello debe tomarse el menor elemento de L e intercambiarlo
(swap) con el primer elemento de la lista. Luego intercambiar el menor elemento de la lista
restante, con el segundo elemento, y as´i sucesivamente. Esta funci´on debe ser IN PLACE.*/

#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

void selection_sort(list<int>&L) {
	auto i = L.begin();
	size_t cont = 0;
	while(cont < L.size()) {
		auto b = i;
		for( list<int>::iterator it=i; it!=L.end(); ++it ) { 
			if (*it < *b){
				b = it;        
			}
		}
		swap(*i,*b);
		i++;
		
		cont++;
	}
}

int main() {
	list<int>L = {3,2,5,1,4};
	for(auto it : L){
		cout << it << " ";
	}
	cout << endl;
	selection_sort(L);
	for(auto it : L){
		cout << it << " ";
	}
	return 0;
}







