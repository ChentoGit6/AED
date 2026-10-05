/*Invierte. Escribir una funci´on void invert(list<int> &L), que invierte el orden de la lista L.
Este algoritmo debe implementarse in place y debe ser O(n). Restricci´on: no utilizar el m´etodo
size().*/

#include <iostream>
#include <list>
using namespace std;

void invert(list<int> &l){
	if (l.empty()) return;
	auto i = l.begin();
	auto f = prev(l.end());
	int tam = distance(l.begin(), l.end());
	int cont = 0;
	while(cont < tam/2){
		swap(*i,*f);
		i++;
		f--;
		cont++;
	}
}

int main() {
	list<int>L = {3,2,5,1,4};
	for(auto it : L){
		cout << it << " ";
	}
	cout << endl;
	invert(L);
	for(auto it : L){
		cout << it << " ";
	}
	return 0;
}







