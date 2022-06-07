#include "Tablero.h"

#include <iostream>
#include <stdlib.h>
using namespace std;


Tablero::Tablero(int maxFila, int maxColumna, int maxAltura){
	if(maxFila < 1 ){
		throw "la fila debe ser mayor a 1";
	}
	if(maxColumna < 1 ){
		throw "la columna debe ser mayor a 1";
	}
	if(maxAltura < 1 ){
		throw "la altura debe ser mayor a 1";
	}
	
	else{
		this->maxFila = maxFila;
		this->maxColumna = maxColumna;
		this->maxAltura = maxAltura;
		
		this->casilleros = new Lista<Lista<Lista<Casilla *> *> *>();
		
		for (int x = 1; x <= maxFila; x++){
			this->casilleros->add(new Lista<Lista<Casilla *> *>());
			for (int y = 1; y <= maxColumna; y++){
				this->casilleros->get(x)->add(new Lista<Casilla *>());
				for (int z = 1; z <= maxAltura; z++){
					this->casilleros->get(x)->get(y)->add(new Casilla(x,y,z,GENERAL));
				}
			}
		}
	}
}
Tablero::~Tablero(){
	for(int x = 1; x <= this->maxFila; x++ ){
		for(int y = 1; y <= this->maxColumna; y++ ){
			for(int z = 1; z<= this->maxAltura; z++){
				delete this->casilleros->get(x)->get(y)->get(z);
			}
			delete this->casilleros->get(x)->get(y);
		}
		delete this->casilleros->get(x);
	}
	delete []this->casilleros;
}
	
void Tablero::mostrarTablero(){
	for (int x = 1; x <= this->maxFila; x++){
        for (int y = 1; y <= this->maxColumna; y++){
            for (int z = 1; z <= this->maxAltura; z++){
                std::cout << this->casilleros->get(x)->get(y)->get(z)->getEstado();
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void Tablero::validarRango(int x, int y, int z){
	if(x < 1 ){
		throw " el x debe ser mayor a 1";
	}
	if(y < 1 ){
		throw " el y debe ser mayor a 1";
	}
	if(z < 1 ){
		throw " el z debe ser mayor a 1";
	}
	
	if(x > this->maxFila ){
		throw " el x es invalido " ;
	}
	if(y > this->maxColumna ){
		throw " el y es invalido " ;
	}
	if(z > this->maxAltura ){
		throw " el z es invalido " ;
	}
	
}

Casilla* Tablero::getCasilla(int fila, int columna, int altura){
	validarRango(fila,columna,altura);
	return this->casilleros->get(fila)->get(columna)->get(altura);
}

//Acá debería entrar a la casilla o al tablero, a este punto ya ni idea
//Y fijarse si el contenido es INACTIVO
bool Tablero::esPosicionValida(){
	bool posicionValida = true;
	//chequeo, si no es true, lo cambio a false.
	return posicionValida;
}
