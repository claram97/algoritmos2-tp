#include <iostream>
#include <stdlib.h>
#include "tablero.h"
using namespace std;


Tablero :: 	Tablero(int fila, int columna, int profundidad){
	matriz = new int**[fila];	// le asigna "x" direcciones al puntero
	for (int i = 0; i < fila; i++)
    {
        matriz[i] = new int*[columna];	// a cada dirección de "x" le asigna otra dirección con "y" posiciones
        for (int j = 0; j < columna; j++) {
            matriz[i][j] = new int[profundidad];	// a cada dirección de "y" le asigna otras "z" posiciones
        }
    }
}

int Tablero :: cargarFilas(int fila){
	this -> fila = fila;
}

int Tablero :: cargarColumnas(int columna){
	this -> columna = columna;
}

int Tablero :: cargarProfundidad(int profundidad){
	this -> profundidad = profundidad;
}


int Tablero :: rellenarMatriz(){	// rellena la matriz x, y, z
	for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            for (int k = 0; k < profundidad; k++) {
                matriz[i][j][k] = 0;
            }
        }
    }
}

void Tablero :: mostrarTablero(){	// mostrar xd
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

void Tablero :: modificarPosicion(int valor, int fila, int columna, int profundidad){	//modificar la posición ingresada con el valor ingresado
	
	matriz[fila][columna][profundidad] = valor;
	
}
