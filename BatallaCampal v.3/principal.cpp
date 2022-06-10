#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "BatallaCampal.h"
#include "Pantalla.h"
#include <string>
#include "EasyBMP.h"
#include "EasyBMP_Geometry.h"

using namespace std;

void creacionImagen(BMP &Image, int tamanio){
	RGBApixel LightGray;
	LightGray.Red = 255;
	LightGray.Green = 255;
	LightGray.Blue = 255;
	for( int j=0 ; j < Image.TellHeight() ; j++ )
	{
		for( int i=0 ; i < Image.TellWidth() ; i++ )
		{
			*Image(i,j) = LightGray;
		}
	}

	Image.WriteToFile( "tablero.bmp" );
}

void pintarCirculo(BMP &Image, int centerX, int centerY){
	RGBApixel FontColor;
	FontColor.Red = 255;
	FontColor.Green = 255;
	FontColor.Blue = 255;
	DrawArc(Image, centerX+20, centerY+20, 5, 0, 360, FontColor);

	Image.WriteToFile( "tablero.bmp" );
}

void pintarLineas(BMP &Image, int tamanio){
	RGBApixel FontColor;
	FontColor.Red = 0;
	FontColor.Green = 0;
	FontColor.Blue = 0;
	for (int i = 20; i <= tamanio*tamanio; i = i+20){
		for (int j = 20; j <= tamanio*tamanio; j = j+20){
			DrawLine(Image, i, j, i, tamanio*tamanio, FontColor);
			DrawLine(Image, j, i, tamanio*tamanio, i, FontColor);
		}
	}
	Image.WriteToFile( "tablero.bmp" );
}
void pintarCuadrado(BMP &Image, int xi,int yi, int xf, int yf, TipoDeCasillero tipo){
	RGBApixel FontColor;
	if(tipo == TIERRA){
		FontColor.Red = 0;
		FontColor.Green = 255;
		FontColor.Blue = 0;
	}else if(tipo == AGUA){
		FontColor.Red = 0;
		FontColor.Green = 0;
		FontColor.Blue = 255;
	}
	for (yi; yi <= yf ; yi++){
		DrawLine(Image, xi, yi, xf, yi, FontColor);
	}
	Image.WriteToFile( "tablero.bmp" );
}

int main(){

	try{
		cout << "--BATALLA CAMPAL--"<<endl;

		srand(time(NULL));

		char opcionUsuarioC;
		char filaOColumna;
		unsigned int coordX;
		unsigned int coordY;
		unsigned int coordZ;
		char movimiento;
		int numeroCarta;
		bool encontrado;
		int i;

		RGBApixel LightGray;
		LightGray.Red = 192;
		LightGray.Green = 192;
		LightGray.Blue = 192;
		BMP Window;
		int xi,xf,yi,yf;

		Pantalla* pantalla = new Pantalla();
		pantalla->nuevaPartida();

		BatallaCampal* batalla = new BatallaCampal(pantalla->getCantidadJugadores(), pantalla->getCantidadSoldados(), pantalla->getDimensionDelTablero());


		batalla->cargarMapa(pantalla->mapaElegido());

		Window.SetSize(pantalla->getDimensionDelTablero()*20, pantalla->getDimensionDelTablero()*20);
		for( int j=0 ; j < Window.TellHeight() ; j++ )
		{
		for( int i=0 ; i < Window.TellWidth() ; i++ )
		{
		*Window(i,j) = LightGray;
		}
		}
		creacionImagen(Window, batalla->getDimensionDelTablero());

		for (int x = 1; x <= batalla->getDimensionDelTablero(); x++){
		        for (int y = 1; y <= batalla->getDimensionDelTablero(); y++){
		            	for (int z = 1; z <= batalla->getDimensionDelTablero(); z++){
		                		if(batalla->getTablero()->getCasilla(x,y,z)->getTipoDeCasilla() == TIERRA){
		                			xi = x*20;
		                			xf = (x*20)+20;
		                			yi = y*20;
		                			yf = (y*20)+20;
		                			pintarCuadrado(Window, xi, yi, xf, yf, TIERRA);
		                		}else if(batalla->getTablero()->getCasilla(x,y,z)->getTipoDeCasilla() == AGUA){
		                			xi = x*20;
		                			xf = (x*20)+20;
		                			yi = y*20;
		                			yf = (y*20)+20;
		                			pintarCuadrado(Window, xi, yi, xf, yf, AGUA);
		                		}
		            	}
		    	}
		}

		pintarLineas(Window, batalla->getDimensionDelTablero());

		batalla->getJugador()->reiniciarCursor();
		while(batalla->getJugador()->avanzarCursor()){

			for( int j = 1; j <= batalla->getCantidadDeSoldados(); j++){
				cout << "Jugador " << batalla->getJugador()->getCursor()->getId() << " elija posiciones para el soldado [" << j << "]: " << endl;
				cout << "fila: ";
				cin >> coordX;
				cout << "columna: ";
				cin >> coordY;
				if( coordX < batalla->getDimensionDelTablero() && coordY <= batalla->getDimensionDelTablero()){
					batalla->getJugador()->getCursor()->nuevoSoldado(coordX, coordY);
				}
				else{
					throw "Coordenada invalida";
				}
				batalla->getTablero()->getCasilla(coordX, coordY, 1)->setEstado(LLENO);
				coordX = (coordX*20)-10;
				coordY = (coordY*20)-10;
				pintarCirculo(Window, coordX, coordY);

			}
		}
		
		cout << "Se establecida la siguiente configuracion: (" << batalla->getCantidadDeJugadores() <<")jugadores | ("<< batalla->getCantidadDeSoldados()<<")soldados por jugador | (" << batalla->getDimensionDelTablero() << ")dimension del tablero" << endl;
		cout << "--COMIENZA EL JUEGO--" << endl;

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
						i = 1;
						batalla->getJugador()->getCursor()->getCartas()->reiniciarCursor();
						while(batalla->getJugador()->getCursor()->getCartas()->avanzarCursor()){
							cout << i <<"."<< batalla->getJugador()->getCursor()->getCartas()->getCursor()->getDescripcion() << endl;
							i++;
						}
						cout << "Elegir carta: " <<endl;
						cin >> numeroCarta;
						batalla->getJugador()->getCursor()->getCartas()->reiniciarCursor();
						for (int i = 0; i <= numeroCarta; i++){
							batalla->getJugador()->getCursor()->getCartas()->avanzarCursor();
						}
						cout << "Ingrese coordenadas: "<<endl;
						cout << "Fila: ";
						cin >> coordX;
						cout << "Columna: ";
						cin >> coordY;
						cout << "Altura: ";
						cin >> coordZ;
						if (batalla->getJugador()->getCursor()->getCartas()->getCursor()->getTipoDeCarta() == SUPER){
							cout << "Elegir Columna (C) o Fila (F): "<<endl;
							cin >> filaOColumna;
						}
						cout << "Ejecutando carta..." <<endl;
						if (batalla->getJugador()->getCursor()->getCartas()->getCursor()->getTipoDeCarta() == RADAR){
							if (batalla->esCoordenadaValida(coordX, coordY, coordZ) && batalla->esCoordenadaValida(coordX+2, coordY+2, coordZ+2) && batalla->esCoordenadaValida(coordX-2, coordY-2, coordZ-2)){
							cout << "En los alrededores se encuentran "<< batalla->usarRadar(coordX, coordY, coordZ) << "cantidad de fichas"<<endl;
							}
						}else{
							batalla->usarCarta(numeroCarta, coordX, coordY, coordZ,  filaOColumna);
						}
						batalla->getJugador()->getCursor()->eliminarCarta(numeroCarta);
					}
					batalla->getJugador()->getCursor()->getHerramienta()->reiniciarCursor();
					for (int i = 0; i < batalla->getJugador()->getCursor()->getCantidadDeHerramientas() ;i++){
						if (batalla->getJugador()->getCursor()->getHerramienta()->getCursor()->getTipo() == BARCO){
							cout << "Usando barco "<<endl;
							cout << "Ingrese coordenadas : "<<endl;
							cout << "Fila: ";
							cin >> coordX;
							cout << "Columna: ";
							cin >> coordY;
							cout << "Altura: ";
							cin >> coordZ;
							batalla->dispararMisil(coordX, coordY, coordZ);
						}
						if (batalla->getJugador()->getCursor()->getHerramienta()->getCursor()->getTipo() == AVION){
							cout << "Usando avion"<<endl;
							cout << "Ingrese coordenadas de disparo adicional: "<<endl;
							cout << "fila: ";
							cin >> coordX;
							cout << "columna: ";
							cin >> coordY;
							cout << "Altura: ";
							cin >> coordZ;
							cout << "Disparando..." <<endl;
							if (batalla -> soldadosCoinciden(coordX, coordY)){
								cout << "Fuego amigo!" << endl;
							}else if(batalla -> eliminarEnemigo(coordX, coordY)){
									batalla -> realizarDisparo(coordX, coordY, coordZ);
									cout << "Mataste a un soldado enemigo" << endl;
								}
							cout << "Ingrese coordenadas del 2do disparo adicional: "<<endl;
							cout << "fila: ";
							cin >> coordX;
							cout << "columna: ";
							cin >> coordY;
							cout << "Altura: ";
							cin >> coordZ;
							cout << "Disparando..." <<endl;
							if (batalla -> soldadosCoinciden(coordX, coordY)){
								cout << "Fuego amigo!" << endl;
							}else if(batalla -> eliminarEnemigo(coordX, coordY)){
									batalla -> realizarDisparo(coordX, coordY, coordZ);
									cout << "Mataste a un soldado enemigo" << endl;
								}
						}
						batalla->getJugador()->getCursor()->getHerramienta()->avanzarCursor();
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
						if (batalla -> eliminarEnemigo(coordX, coordY)){
							batalla -> realizarDisparo(coordX, coordY, coordZ);
							cout << "Mataste a un soldado enemigo" << endl;
						}

					}

					cout << "La casilla ahora esta: "<< batalla->getTablero()->getCasilla(coordX, coordY, coordZ)->getEstado() <<endl;

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
