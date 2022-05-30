#ifndef TABLERO_H
#define TABLERO_H
#include "Casilla.h"

class Tablero{
	private:
		int fila; // X
		int columna; // Y
		int profundidad; // Z
		Casilla**** matrizCasillas;
		
	public:
		/*
		 * Pre:
		 * Pos:
		 */
		Tablero(int, int, int);
		/*
		 * Pre:
		 * Pos:
		 */
		void mostrarTablero();
		/*
		 * Pre:
		 * Pos:
		 */
		int getLargo();
		/*
		 * Pre:
		 * Pos:
		 */
		int getAncho();
		/*
		 * Pre:
		 * Pos:
		 */
		void setFilas(int fila);
		/*
		 * Pre:
		 * Pos:
		 */
		void setColumnas(int columna);
		/*
		 * Pre:
		 * Pos:
		 */
		void setProfundidad(int profundidad);
		/*
		 * Pre:
		 * Pos:
		 */
		void rellenarMatriz();
		/*
		 * Pre:
		 * Pos:
		 */
		void modificarPosicion(char tipo, int fila, int columna, int profundidad);
		/*
		 * Pre:
		 * Pos:
		 */
		Casilla* getCasilla(int fila, int columna, int profundidad);
};
#endif
