#ifndef JUGADOR_H
#define JUGADOR_H
#include <vector>
#define MAX_CARTAS 5

class Jugador {

private:
	unsigned int id;
	std::vector<int*>* soldados;
	unsigned int cantidadDeSoldados;
	std::vector<int*>* cartas; //TODO: Reemplazar int por TDA cartas
	//estadoJugador estadoDelJugador; //deberia empezar en jugando

public:
	//Pre: -
	//Post: crea un jugador con su respectivo id, la cantidad de soldados que posee y las cartas en su mazo.
	Jugador(int id, int cantidadDeSoldados);


	//Pre: -
	//Post: destruye la instancia de jugador.
	virtual ~Jugador();

	//Pre: -
	//Post: devuelve la cantidad de soldados.
	unsigned int getCantidadDeSoldados();


	//Pre: recibe una cantidad de soldados mayor a 0.
	//Post: inicializa la cantidad de soldados.
	void setCantidadDeSoldados(unsigned int cantidadDeSoldados);

	//Pre: -
	//Post: devuelve la cantidad de cartas.
	unsigned int getCantidadDeCartas();

	//Pre: -
	//Post: de ser posible, agrega la carta al mazo.
	void crearCarta();

	//Pre: (habria que poner alguna condicion, tipo el tipo de carta o algo)
	//Post: devuelve una carta.
	int* getCarta(); //cambiar por Cartas*

	//Pre: -
	//Post: disminuye en 1 la cantidad de soldados.
	void decrementarCantidadDeSoldados();

};

#endif
