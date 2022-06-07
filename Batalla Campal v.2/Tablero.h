#ifndef TABLERO_H
#define TABLERO_H
#include "Casilla.h"
#include "Lista.h"

class Tablero{
	private:
		int maxFila;
		int maxColumna;
		int maxAltura;
			
		Lista<Lista<Lista<Casilla*>*>*>* casilleros;
	
	
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
		Casilla* getCasilla(int fila, int columna, int profundidad);
		 /*
		 * Pre:
		 * Pos:
		 */
		bool esRangoValido(int x,int y,int z);
		/*
		*/
		virtual ~Tablero();

};
#endif
