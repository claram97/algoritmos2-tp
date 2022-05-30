#ifndef TABLERO_H
#define TABLERO_H

class Tablero{
	private:
		int fila; // X
		int columna; // Y
		int profundidad; // Z
		char ***matriz;
		
	public:
		Tablero(int, int, int);	// tablero(int, int);
		void mostrarTablero();
		int getLargo();
		int getAncho();
		void cargarFilas(int fila);
		void cargarColumnas(int columna);
		void cargarProfundidad(int profundidad);
		//int generarMatriz();
		void rellenarMatriz();
		void modificarPosicion(int valor, int fila, int columna, int profundidad);
};
#endif
