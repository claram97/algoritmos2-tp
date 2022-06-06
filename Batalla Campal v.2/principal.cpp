#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "BatallaCampal.h"
#include "Pantalla.h"

using namespace std;

int main(){

	try{
		cout << "--BATALLA CAMPAL--"<<endl;

		srand(time(NULL));

		char opcionUsuarioC;
		char filaOColumna;
		int coordX;
		int coordY;
		int coordZ;
		char movimiento;
		int numeroCarta;
		bool encontrado;

		Pantalla* pantalla = new Pantalla();
		pantalla->nuevaPartida();

		BatallaCampal* batalla = new BatallaCampal(pantalla->getCantidadJugadores(), pantalla->getCantidadSoldados(), pantalla->getDimensionDelTablero());

		batalla->getJugador()->reiniciarCursor();
		while(batalla->getJugador()->avanzarCursor()){

			for( int j = 1; j <= batalla->getCantidadDeSoldados(); j++){
				cout << "Jugador " << batalla->getJugador()->getCursor()->getId() << " elija posiciones para el soldado [" << j << "]: " << endl;
				cout << "fila: ";
				cin >> coordX;
				cout << "columna: ";
				cin >> coordY;
				if( coordX < batalla->getDimensionDelTablero() && coordY < batalla->getDimensionDelTablero()){
					batalla->getJugador()->getCursor()->nuevoSoldado(coordX, coordY);
				}else{
					throw "Coordenada inválida";
				}
				batalla->getTablero()->getCasilla(coordX, coordY, 1)->setEstado(LLENO);

			}
		}
		
		cout << "Se estableció la siguiente configuracion: (" << batalla->getCantidadDeJugadores() <<")jugadores | ("<< batalla->getCantidadDeSoldados()<<")soldados por jugador | (" << batalla->getDimensionDelTablero() << ")dimension del tablero" << endl;
		cout << "--COMIENZA EL JUEGO--" << endl;

		batalla->getTablero()->mostrarTablero();

		while( batalla->getEstadoDelJuego() == JUGANDO){

			cout << "---SIGUIENTE TURNO---" << endl;
			encontrado = false;
			batalla->siguienteTurno();
			batalla->getJugador()->reiniciarCursor();
			while(batalla->getJugador()->avanzarCursor() && (!encontrado)){
				if(batalla->getJugador()->getCursor()->getId() == batalla->getTurno()){
					encontrado = true;

					cout << "Turno del jugador: " << batalla->getJugador()->getCursor()->getId() << endl;
					cout << "Generando nueva carta..." << endl;
					if(batalla->getJugador()->getCursor()->getCantidadDeCartas() == 5){
						cout << "No puedes obtener mas cartas" << endl;
					}
					int aleatorio = rand() %6 +1;
					batalla->getJugador()->getCursor()->nuevaCarta(aleatorio);
					cout << "Cartas del jugador: " << batalla->getJugador()->getCursor()->getCantidadDeCartas() <<endl;
					cout << "Desea usar una carta? (SI: S, NO: N): ";
					cin >> opcionUsuarioC;
					if(opcionUsuarioC == 'S'){
						cout << "Cartas disponibles: "<<endl;

						batalla->getJugador()->getCursor()->getCarta()->reiniciarCursor();
						while(batalla->getJugador()->getCursor()->getCarta()->avanzarCursor()){
							cout << "1" <<"."<< batalla->getJugador()->getCursor()->getCarta()->getCursor()->getDescripcion() << endl;
						}
						cout << "Elegir carta: " <<endl;
						cin >> numeroCarta;
						cout << "Ingrese coordenadas: "<<endl;
						cout << "Fila: ";
						cin >> coordX;
						cout << "Columna: ";
						cin >> coordY;
						cout << "Altura: ";
						cin >> coordZ;
						cout << "Ejecutando carta..." <<endl;
						if (numeroCarta == 4){
							if (batalla->verificarCoordenadas(coordX, coordY, coordZ) && batalla->verificarCoordenadas(coordX+2, coordY+2, coordZ+2) && batalla->verificarCoordenadas(coordX-2, coordY-2, coordZ-2)){
							cout << "En los alrededores se encuentran "<< batalla->usarRadar(coordX, coordY, coordZ) << "cantidad de fichas"<<endl;
							}
						}else if(numeroCarta == 5){
							cout << "Elegir Columna (C) o Fila (F): "<<endl;
							cin >> filaOColumna;
							if (filaOColumna == 'C'){
								cout << "Ingresar columna: "<<endl;
								cin >> coordY;
								batalla->dispararSuperMisil(coordY, true);
							}else if (filaOColumna == 'F'){
								cout << "Ingresar fila: "<<endl;
								cin >> coordX;
								batalla->dispararSuperMisil(coordX,false);
							}
						}else{
							batalla->ejecutarCarta(numeroCarta, coordX, coordY, coordZ);
						}
						batalla->getJugador()->getCursor()->eliminarCarta(numeroCarta);
					}
					cout << "Cantidad de Armamento: "<< batalla->getJugador()->getCursor()->getCantidadDeHerramientas() << endl;
					cout << "Cantidad de soldados: "<< batalla->getJugador()->getCursor()->getCantidadDeSoldados() << endl;

					cout <<" Desea mover un soldado? (SI: S, NO: N): ";
					cin >> opcionUsuarioC;
					if(opcionUsuarioC == 'S'){
						cout << "elija el soldado a mover: " <<endl;

						batalla->getJugador()->getCursor()->getSoldado()->reiniciarCursor();
						while(batalla->getJugador()->getCursor()->getSoldado()->avanzarCursor()){
							cout << "Soldado: ["<< batalla->getJugador()->getCursor()->getSoldado()->getCursor()->getPosicionX() <<","<<batalla->getJugador()->getCursor()->getSoldado()->getCursor()->getPosicionY() <<"]"<<endl;
						}
						cout << "fila: ";
						cin >> coordX;
						cout << "columna: ";
						cin >> coordY;

						cout << "Elija movimiento (WASD): ";
						cin >> movimiento;
						cout << "Moviendo soldado..." << endl;
						batalla->moverSoldado(movimiento, coordX, coordY);
					}

					cout << "Ingrese coordenadas de disparo: "<<endl;

					cout << "fila: ";
					cin >> coordX;
					cout << "columna: ";
					cin >> coordY;
					cout << "Altura: ";
					cin >> coordZ;
					cout << "Disparando..." <<endl;
					if (batalla -> soldadosCoinciden(coordX, coordY)){
						cout << "Fuego amigo!" << endl;
						cout << "Perdiste el turno..." << endl;
					}
					else{
						if (batalla -> enemyKill(coordX, coordY)){
							batalla -> realizarDisparo(coordX, coordY, coordZ);
							cout << "Mataste a un soldado enemigo" << endl;
						}

					}

					cout << "La casilla ahora está: "<< batalla->getTablero()->getCasilla(coordX, coordY, coordZ)->getEstado() <<endl;

				}
			}

			cout << "-----FIN DE TURNO----" << endl;
			batalla->estadoActualDelJuego();
		}
		cout << "-----FIN DEL JUEGO----" << endl;
		cout << "Gana el jugador: " << batalla->getTurno() << endl;

		return 0;

	}catch(const char* X){
		cout << "ERROR: " << X <<endl;
	}
}


