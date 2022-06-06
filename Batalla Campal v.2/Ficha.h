#ifndef FICHA_H
#define FICHA_H

enum tipoDeFicha{
	AVION,
	BARCO,
	MINA,
	SOLDADO,
	SIN_DEFINIR
};

 enum tipoCarta{
	MISIL,
	RADAR,
	SUPER,
	BARCOS,
	AVIONES,
	MINAS
};


class Ficha{
	
private:

	int posicionX;
	int posicionY;
	int posicionZ;
	char tipo;
		
		
public:
		
	/*
	 *  Post: Crea una ficha con el tipo sin definir y posiciones seteadas en -1 (deben cambiarse luego).
	 */
	Ficha();
	/*
	 * Pre: Recibe un tipo de ficha, con valores válidos: SOLDADO, AVIÓN, BARCO, MINAS.
	 * Post: Se crea una ficha del tipo dado si el valor es válido, sino deja el tipo sin definir.
	 * Las posiciones iniciales estarán seteadas en -1, deben actualizarse.
	 */
	Ficha(char tipo, int x, int y, int z);
	/*
	 *  Post: Devuelve la posicion X/fila
	 */
	int getPosicionY();
	/*
	 *  Post: Devuelve la posicion Y/columna
	 */
	int getPosicionX();
	/*
	 *  Post: Devuelve la posicion Z/altura
	 */
	int getPosicionZ();
	/*
	 *	Post: Devuelve el tipo de ficha
	 */
	char getTipo();
	/*
	 * Pre: El tipo tiene que ser soldado, avion, barco o mina.
	 * Post: Setea el tipo de la ficha actual según el tipo recibido.
	 */
	void setTipo(char tipo);
	/*
	 *  Pre: Necesita las coordenadas de la fila y la columna
	 *  Post: Si es soldado, cambia su posicion
	 */
	void setCoordenadasSoldado(int posicionX, int posicionY);
	/*
	 *  Pre: Necesita las coordenadas de la casilla
	 *  Post: Devuelve true si la casilla es valida
	 */
	bool esPosicionValida(int x, int y, int z);
	/*
	 *  Pre: Necesita un tipo de ficha
	 *  Post: Devuelve true si el tipo de ficha es valido
	 */
	bool esTipoValido(char tipo);
	/*
	*  Pre: Necesita las coordenadas y un tipo de ficha
	*  Post: Devuelve true si el tipo de ficha es valido para el tipo de casilla
	*/
	bool tipoConcuerdaConPosicion(int x, int y, int z, char tipo);
	/*
	 *  Pre: Necesita un tipo de ficha
	 *  Post: Setea la ficha al tipo dado
	 */
	void definirTipo(char tipo);
};


#endif
