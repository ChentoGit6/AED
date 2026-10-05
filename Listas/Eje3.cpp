/*Concatena. Escriba procedimientos para concatenar: a) dos listas L1 y L2 usando insert; b) una
lista LL de n sublistas usando insert; c) una lista LL de n sublistas usando splice. Cada
procedimiento debe retornar el resultado en una lista nueva*/

#include <iostream>
#include <list>
using namespace std;

template <typename T>

list<T> concatena1 (list<T>&l1, list<T>&l2){
	l1.insert(l1.end(),l2.begin(),l2.end());
	return l1;
}

template <typename T>
list<T> concatena2 (list<list<T>>&ll){
	list<T>l;
	for(auto sublista : ll){
		l.insert(l.end(),sublista.begin(),sublista.end());
	}
	return l;
}

template <typename T>
list<T> concatena3 (list<list<T>>&ll){
	list<T>l;
	for(auto sublista : ll){
		l.splice(l.end(),sublista);
	}
	return l;
}

int main() {
	//a)
	list<int> l1 = {1, 2, 3};
	list<int> l2 = {4, 5, 6};
	
	list<int> l3 = concatena1(l1, l2);
	
	for (int x : l3) {
		cout << x << " ";
	}
	cout << endl;
	
	//b)
	list<list<int>> LL = { {1, 2}, {3, 4, 5}, {6} };
	
	list<int> aplanada = concatena2(LL);
	
	for (int x : aplanada) {
		cout << x << " ";
	}
	cout << endl;
	
	//c)
	list<int> aplanada2 = concatena3(LL);
	
	for (int x : aplanada2) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}







