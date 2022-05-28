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
			Post: Se coloca la ficha
		*/
		Ficha(int posicionX,int posicionY,int posicionZ, char tipo); 
		
		
		/*
			Pre: que se haya creado una ficha
			Post: destruye la ficha
		*/
		virtual ~Ficha();
		
		int getPosicionY();
		int getPosicionX();
		int getPosicionZ();
		
		/*
			
		*/
		char verQueFichaEs();
		char getTipo();
};

#endif
