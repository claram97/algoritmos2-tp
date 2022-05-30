#include "Tablero.h"

#include <iostream>
#include <stdlib.h>
using namespace std;


Tablero::Tablero(int fila, int columna, int profundidad){

	this->fila = fila;
	this->columna = columna;
	this->profundidad = profundidad;

	matriz = new char**[fila];	// le asigna "x" direcciones al puntero
	for (int i = 0; i < fila; i++)
    {
        matriz[i] = new char*[columna];	// a cada dirección de "x" le asigna otra dirección con "y" posiciones
        for (int j = 0; j < columna; j++) {
            matriz[i][j] = new char[profundidad];	// a cada dirección de "y" le asigna otras "z" posiciones
        }
    }
}

void Tablero::cargarFilas(int fila){
	this -> fila = fila;

}

void Tablero::cargarColumnas(int columna){
	this -> columna = columna;
}

void Tablero::cargarProfundidad(int profundidad){
	this -> profundidad = profundidad;
}


void Tablero::rellenarMatriz(){	// rellena la matriz x, y, z
	for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            for (int k = 0; k < profundidad; k++) {
                matriz[i][j][k] = 'O';
            }
        }
    }
}

void Tablero::mostrarTablero(){	// mostrar xd
	for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            for (int k = 0; k < profundidad; k++) {
                std::cout << matriz[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void Tablero::modificarPosicion(int valor, int fila, int columna, int profundidad){	//modificar la posición ingresada con el valor ingresado
	
	matriz[fila][columna][profundidad] = valor;
	
}
