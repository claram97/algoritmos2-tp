#ifndef FICHA_H
#define FICHA_H
#include <string>


#define SOLDADO 'S'
#define AVION 'A'
#define BARCO 'B'
#define MINA 'M'

class Ficha
{
	private:

		int posicionX;
		int posicionY;
		int posicionZ;
		
		char tipo;
		char fichaFinal;
		//std::string jugador;
		
	public:
		
		/*
			Pre: Ingresa las posiciones donde quiere colocar la ficha, mientras esta sea una ficha valida (S,B,A,M)
			Pos: Se coloca la ficha
		*/
		Ficha(int posicionX,int posicionY,int posicionZ, char tipo); 
		
		
		/*
			Pre: -
			Pos: destruye la ficha
		*/
		virtual ~Ficha();
		
		/*
			pre: - 
			pos: devuelve la posicion Y
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
			pos: evalua si las posiciones y el tipo de ficha son validas entre si
		*/
		char verQueFichaEs();
	
		/*
			pre: - 
			pos: devuelve el tipo de ficha
		*/
		char getTipo();
		
};

#endif
