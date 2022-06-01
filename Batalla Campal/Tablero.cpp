#include "Tablero.h"

#include <iostream>
#include <stdlib.h>
using namespace std;


Tablero::Tablero(int fila, int columna, int profundidad){

	this->fila = fila;
	this->columna = columna;
	this->profundidad = profundidad;

	this->matrizCasillas = new Casilla***[fila];
	for (int i = 0; i < fila; i++)
    {
        this->matrizCasillas[i] = new Casilla**[columna];	// a cada dirección de "x" le asigna otra dirección con "y" posiciones
        for (int j = 0; j < columna; j++) {
            this->matrizCasillas[i][j] = new Casilla*[profundidad];	// a cada dirección de "y" le asigna otras "z" posiciones
        }
    }

	for (int i = 0; i < fila; i++){
        for (int j = 0; j < columna; j++){
        	for (int k = 0; k < profundidad; k++){
        		this->matrizCasillas[i][j][k] = new Casilla(i, j, k, AIRE);
        	}

        }
    }

}

void Tablero::setFilas(int fila){
	this -> fila = fila;

}

void Tablero::setColumnas(int columna){
	this -> columna = columna;
}

void Tablero::setProfundidad(int profundidad){
	this -> profundidad = profundidad;
}


void Tablero::rellenarMatriz(){
	for (int i = 0; i < this->fila; i++)
    {
        for (int j = 0; j < this->columna; j++)
        {
            for (int k = 0; k < this->profundidad; k++) {
                matrizCasillas[i][j][k]->setTipoDeCasilla(TIERRA);
            }
        }
    }
}

void Tablero::mostrarTablero(){
	for (int i = 0; i < this->fila; i++)
    {
        for (int j = 0; j < this->columna; j++)
        {
            for (int k = 0; k < this->profundidad; k++) {
                std::cout << matrizCasillas[i][j][k]->getContenido() << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void Tablero::modificarPosicion(char tipo, int fila, int columna, int profundidad){
	
	matrizCasillas[fila][columna][profundidad]->setContenido(tipo);
	
}

Casilla* Tablero::getCasilla(int fila, int columna, int altura){

	return this->matrizCasillas[fila][columna][altura];
}

//Acá debería entrar a la casilla o al tablero, a este punto ya ni idea
//Y fijarse si el contenido es INACTIVO
bool Tablero::esPosicionValida(){
	bool posicionValida = true;
	//chequeo, si no es true, lo cambio a false.
	return posicionValida;
}
