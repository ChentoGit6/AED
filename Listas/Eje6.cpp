/* ReemplazaSecuencia. Dada una lista de enteros L y dos listas SEQ y REEMP, posiblemente de
distintas longitudes, escribir una funci´on void reemplaza(list<int> &L, list<int>& SEQ,
list<int> &REEMP), que busca todas las secuencias de SEQ en L y las reemplaza por REEMP. Por
ejemplo, si L=(1,2,3,4,5,1,2,3,4,5,1,2,3,4,5), SEQ=(4,5,1) y REEMP=(9,7,3), entonces
despu´es de llamar a reemplaza(L,SEQ,REEMP), debe quedar
L=(1,2,3,9,7,3,2,3,9,7,3,2,3,4,5). Para implementar este algoritmo primero buscar desde el
principio la secuencia SEQ, al encontrarla, reemplazar por REEMP, luego seguir buscando a partir
del siguiente elemento al ´ultimo de REEMP.*/

#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

void reemplaza(list<int> &l, list<int> &s, list<int> &r){
	if (s.empty()) return;
	auto it1 = l.begin();
	auto it = search(it1,l.end(),s.begin(),s.end());
	
	while(it != l.end()){
		
		l.insert(it,r.begin(),r.end());
		
		auto fin_s = next(it,s.size());
		
		it1 = l.erase(it,fin_s);
		
		it = search(it1,l.end(),s.begin(),s.end());
	}
}

int main() {
	list<int> l = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
	list<int> s = {4,5,1};
	list<int> r = {9,7,3};
	for(auto x : l){
		cout << x << " ";
	}
	cout << endl;
	reemplaza(l,s,r);
	for(auto x : l){
		cout << x << " ";
	}
	return 0;
}
