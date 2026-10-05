/*Inverso. Escribir un procedimiento bool inverso(list<char>&z) para determinar si una cadena
de caracteres de entrada es de la forma z=xy donde y es la cadena inversa (o espejo) de la cadena
x, ignorando los espacios en blanco. Emplear una cola y una pila auxiliares.*/

#include <iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;

bool inverso(list<char>&z){
	
	stack<char>p;
	queue<char>c;
	
	for(auto x : z) { 
		if (x != ' ') {
			p.push(x);
			c.push(x);
		}
	}
	
	if (p.size() % 2 != 0) {
		return false;
	}
	
	while (!p.empty()) {
		if (p.top() != c.front()) {
			return false;
		}
		p.pop();
		c.pop();
	}
	
	return true;
}

int main() {
	
	return 0;
}
