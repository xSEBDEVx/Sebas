#include<iostream>
#include "binario.h"
using namespace std;
using std::cout;
using std::endl;
using std::cin;

using arbol::binario;
int main (int argc, char *argv[]) {
	//Crear la instancia
	binario<int> a;
	// Insertamos los valores en el arbol binario
	a.insertar(5);
	a.insertar(3);
	a.insertar(4);
	a.insertar(2);
	a.insertar(1);
	a.insertar(9);
	a.insertar(7);
	a.insertar(6);
	a.insertar(8);
	//Llamamos las funciones de ordenamiento e imprimimos 
	cout << endl;
	cout << "PREORDEN" << endl;
	a.preorden();
	cout << endl;
	cout << "INORDEN" << endl;
	a.inorden();
	cout << endl;
	cout << "POSORDEN" << endl;
	a.posorden();
	cout << endl;
	cout << endl;
	cout << "Dato a eliminar = 5";
	int dato = 5;
	a.eliminar(dato);
	cout << endl;
	cout << "PREORDEN" << endl;
	a.preorden();
	cout << endl;
	cout << "INORDEN" << endl;
	a.inorden();
	cout << endl;
	cout << "POSORDEN" << endl;
	a.posorden();
	cout << endl;
	
	
	return 0;
}
