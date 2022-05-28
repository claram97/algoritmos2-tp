#include <iostream>
#include "tablero.h"

using namespace std;


int main() {
	
	Tablero *miTablero = new Tablero(5, 3, 3);
	
	miTablero->cargarFilas(5);
	miTablero->cargarColumnas(3);
	miTablero->cargarProfundidad(3);
	//miTablero->generarMatriz();
	miTablero->rellenarMatriz();
	miTablero->mostrarTablero();
	cout<<"\nmodificar posición \n";
	miTablero->modificarPosicion(1, 4, 2, 2); // el primer valor sería el jugador después x, y, z
	miTablero->mostrarTablero();
	
	return 0;
}
