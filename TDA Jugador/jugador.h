#ifndef JUGADOR_H
#define JUGADOR_H
#include <deque>
#define MAX_CARTAS 5

class Jugador {

private:
	unsigned int id;
	Ficha** fichas;
	unsigned int cantidadDeFichas;
	std::deque<int**> cartas; //TODO: Reemplazar int por TDA cartas

public:
	//Pre: -
	//Post: crea un jugador con su respectivo id, la cantidad de fichas que posee y las cartas en su mazo.
	Jugador(int id, int cantidadDeFichas, std::deque<int*>* cartas);
	
	//Pre: -
	//Post: devuelve la cantidad de fichas.
	unsigned int getCantidadDeFichas();
	
    	//Pre: recibe una cantidad de fichas mayor a 0.
    	//Post: inicializa la cantidad de fichas.
    	void setCantidadDeFichas(unsigned int cantidadDeFichas);
	
	//Pre: -
	//Post: devuelve la cantidad de cartas.
	unsigned int getCantidadDeCartas();
	
	//Pre: recibe una carta.
	//Post: de ser posible, agrega la carta al mazo.
	void agregarCarta(int*carta); //cambiar por Cartas*
	
	//Pre: (habria que poner alguna condicion, tipo el tipo de carta o algo)
	//Post: devuelve una carta.
	int* getCarta(); //cambiar por Cartas*
	
	//Pre: -
	//Post: disminuye en 1 la cantidad de fichas.
	void decrementarCantidadDeFichas();

};

#endif
