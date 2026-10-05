/*map2list. Escribir una funci´on que dado un map M retorna las listas de claves y valores, utilice la
signatura void map2list(map<int,int> &M, list<int> &Keys, list<int> &Vals). Ejemplo:
si M={1->2, 3->5, 8->20}, entonces debe retornar Keys = (1,3,8) y Vals = (2,5,20).*/

#include <iostream>
#include <map>
#include <list>
using namespace std;

void map2list(map<int,int> &m, list<int> &keys, list<int> &vals){
	for(auto &par : m){
		keys.push_back(par.first);
		vals.push_back(par.second);
	}
}

int main() {
	map<int,int>m = {{1, 2}, {3,5}, {8, 20}};
	list<int>keys;
	list<int>vals;
	for(auto &par : m){
		cout << par.first << "," << par.second << " ";
	}
	cout << endl;
	map2list(m,keys,vals);
	for(auto &x:keys){
		cout << x << " ";
	}
	cout << endl;
	for(auto &x:vals){
		cout << x << " ";
	}
	return 0;
}
