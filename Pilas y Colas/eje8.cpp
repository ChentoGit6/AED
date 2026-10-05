/*Rotaci´on. Escribir una funci´on void rotacion(queue <int> &C), la cual saca una cierta cantidad
de enteros del frente de la cola C y los vuelve a insertar en fin de la misma, de tal manera que
quede en el frente de cola un n´umero par. Por ejemplo, si C = [1, 3, 5, 2, 4] entonces, despu´es
de rotacion(C), debe quedar C = [2, 4, 1, 3, 5].
*/

#include <iostream>
#include <queue>
using namespace std;

void rotacion(queue<int> &c) {
	if (c.empty()) return;
	
	int n = c.size();
	int rotaciones = 0;
	
	// Rota mientras el frente sea impar y no hayamos dado una vuelta entera(por si los elementos son todos impar)
	while (c.front() % 2 != 0 && rotaciones < n) {
		c.push(c.front());
		c.pop();
		rotaciones++;
	}
}
template <typename T>
void imprimir_cola(queue<T> q) { // Recibe por COPIA (no modifica la original)
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
}
int main() {
	queue<int>c({1, 3, 5, 2, 4});
	rotacion(c);
	imprimir_cola(c);
	
	return 0;
}







