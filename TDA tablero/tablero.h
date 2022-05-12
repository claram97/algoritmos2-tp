#ifndef TABLERO_H
#define TABLERO_H

class tablero{
	private:
		int fila; // X
		int columna; // Y
		int profundidad; // Z
		int ***matriz;
		
	public:
		tablero(int, int, int);	// tablero(int, int);
		void mostrarTablero();
		int getLargo();
		int getAncho();
		int cargarFilas(int fila);
		int cargarColumnas(int columna);
		int cargarProfundidad(int profundidad);
		//int generarMatriz();
		int rellenarMatriz();
		void modificarPosicion(int valor, int fila, int columna, int profundidad);
};
#endif
