#ifndef TABLERO_H
#define TABLERO_H
#include "Casilla.h"
#include "Vector.h"

class Tablero{
	private:
		int maxFila; // X
		int maxColumna; // Y
		int maxAltura; // Z
			
		//Lista<Lista<Lista<Casila*>*>*>* casilleros;
	
		Vector<Vector<Vector<Casilla *> *> *> * casilleros;
		void validarRango(unsigned int x, unsigned int y, unsigned int z);
	
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
		 /*
		 * Pre:
		 * Pos:
		 */
		bool esPosicionValida();
		/*
		*/
		virtual ~Tablero();
};
#endif
