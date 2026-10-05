/*Varios. Utilizando las operaciones del contenedor stack<> de STL, construir una serie de
procedimientos que realicen cada una de las actividades siguientes en una pila:
a Asignar i al segundo elemento desde la parte superior de la pila, dejando la pila sin sus dos
elementos de la parte superior.
b Asignar i al segundo elemento desde la parte superior de la pila, sin modificarla
c Dado un entero n, asignar i al elemento n-´esimo desde la parte superior de la pila, dejando la
pila sin sus n elementos superiores.
d Asignar i al elemento del fondo de la pila, dejando la pila vac´ia.
e Asignar i al elemento del fondo de la pila, dejando la pila sin modificar.*/

#include <iostream>
#include <stack>
using namespace std;

template <typename T>
void get_segundo_y_descartar(stack<T> &s, T &i) {
	s.pop();        // Quita el primer elemento
	i = s.top();    // Toma el segundo
	s.pop();        // Quita el segundo elemento
}
template <typename T>
void get_segundo(stack<T> &s, T &i) {
	T primero = s.top(); // Guarda el primer elemento
	s.pop();        // Quita el primer elemento
	i = s.top();    // Toma el segundo
	s.push(primero); // Añade el primero
}
template <typename T>
void asignar_elemento_y_descartar(stack<T> &s, T &i, int n) {
	for(int j=1;j<n;j++) { 
		s.pop();
	}
	i = s.top();
	s.pop();
}
template <typename T>
void asignar_ultimo_y_vaciar(stack<T> &s, T &i) {
	while (!s.empty()) {
		i = s.top();
		s.pop();
	}
}
template <typename T>
void asignar_ultimo(stack<T> &s, T &i) {
	stack<T> aux;
	
	// 1. Pasar todo a aux (el fondo de s quedará arriba de aux)
	while (!s.empty()) {
		aux.push(s.top());
		s.pop();
	}
	
	// 2. Tomar el elemento del fondo
	i = aux.top();
	
	// 3. Regresar todo a s para restaurar el orden exacto original
	while (!aux.empty()) {
		s.push(aux.top());
		aux.pop(); // ¡Imprescindible para no quedar en bucle infinito!
	}
}

int main() {
	
	return 0;
}
