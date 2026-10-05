/*SortStack. Escribir una funci´on void sort(list<int> &L), que ordena los elementos de L de
mayor a menor. Para ello emplear el siguiente algoritmo simple, utilizando una pila auxiliar P: ir
tomando el menor elemento de L, eliminarlo de L e insertarlo en P hasta que L este vac´ia. Luego
insertar los elementos de P en L.*/

#include <iostream>
#include <list>
#include <stack>
using namespace std;

void sort_stack(list<int> &l){
	stack<int>s;
	while(!l.empty()){
		auto b = l.begin();
		for( list<int>::iterator it=l.begin(); it!=l.end(); ++it ) { 
			if (*it < *b){
				b = it;
			}
		}
		s.push(*b);
		l.erase(b);
	}
	while(!s.empty()){
		l.push_back(s.top());
		s.pop();
	}
	
}

int main() {
	
	return 0;
}







