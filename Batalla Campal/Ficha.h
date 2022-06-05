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
	
	//Jugador* jugador;
	char tipo;
		
		
public:
		
	/*
	 *  Pre:
	 *  Post: crea una ficha con el tipo sin definir y posiciones seteadas en -1 (deben cambiarse luego).
	 */
	Ficha();

	/*
		Pre: recibe un tipo de ficha, con valores válidos: SOLDADO, AVIÓN, BARCO, MINAS.
		Post: Se crea una ficha del tipo dado si el valor es válido, sino deja el tipo sin definir.
		Las posiciones iniciales estarán seteadas en -1, deben actualizarse.
	*/
	Ficha(char tipo, int x, int y, int z);
		
	/*
		Pre: - 
		Post: devuelve la posicion Y
	*/
	int getPosicionY();
	
	/*
		pre: - 
		pos: devuelve la posicion X
	*/
	int getPosicionX();
	
	/*
		pre: - 
		pos: devuelve la posicion Z
	*/
	int getPosicionZ();
		

	/*
		pre: - 
		pos: devuelve el tipo de ficha
	*/
	char getTipo();
	
	/*
		pre: el tipo tiene que ser soldado, avion, barco o mina.
		post: setea el tipo de la ficha actual según el tipo recibido.
	*/
	void setTipo(char tipo);
	
	/*
	 *  pre:
	 *  pos:
	 */
	void setCoordenadas(int x, int y);
		

	void setCoordenadasSoldado(int posicionX, int posicionY);

	bool esPosicionValida(int x, int y, int z);

	bool esTipoValido(char tipo);

	bool tipoConcuerdaConPosicion(int x, int y, int z, char tipo);

	void definirTipo(char tipo);
	
	/*
		pre: - 
		pos: devuelve de qué tipo tendría que ser una ficha dadas sus coordenadas actuales.
	*/
	char validarFicha();
};


#endif
