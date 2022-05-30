#include "Casilla.h"

Casilla::Casilla(unsigned int largo, unsigned int ancho, unsigned int alto, char tipo){
  //Esto no va acà creo pero lo dejo aca por si se necesita
    if(proporcionesValidasTablero(largo,ancho,alto)){
        this->contenido = VACIO;
        this->tipoDeCasilla = tipo;
        this->coordenadaX = largo;
        this->coordenadaY = ancho;
        this->coordenadaZ = alto;
    }
    if(!proporcionesValidasTablero(largo,ancho,alto)){
        throw "Proporciones invalidas del tablero";
    }
    
}

bool Casilla::proporcionesValidasTablero(unsigned int largo, unsigned int ancho, unsigned int alto){
    return (largo >= 0 && largo < MAX_LARGO && ancho >= 0 && ancho < MAX_ANCHO && alto >= 0 && alto < MAX_ALTO);
}


Casilla::~Casilla(){
  
}

void Casilla::setContenido(char contenido){
    if(contenido == VACIO || contenido == LLENO || contenido == INACTIVO){
        this->contenido = contenido;
    }
    else{
        throw "El contenido es inválido, debe ser: VACIO, FULL, INACTIVO";
    }
}

char Casilla::getContenido(){
    return this->contenido;
}

void Casilla::setTipoDeCasilla(char tipoDeCasilla){
    if(tipoDeCasilla == TIERRA || tipoDeCasilla == AIRE || tipoDeCasilla == AGUA){
        this->tipoDeCasilla = tipoDeCasilla;
    }
    else{
        throw "Invalid type.";
    }
}

char Casilla::getTipoDeCasilla(){
    return this->tipoDeCasilla;
}

void Casilla::setCoordenadaX(unsigned int coordenadaX){
    if(coordenadaX > 0 && coordenadaX < MAX_LARGO){
        this->coordenadaX = coordenadaX;
    }
    else{
        throw "La coordenada X para la casilla no está dentro de un rango de valores válidos.";
    }
}

unsigned int Casilla::getCoordenadaX(){
    return this->coordenadaX;
}

void Casilla::setCoordenadaY(unsigned int coordenadaY){
    if(coordenadaY > 0 && coordenadaY < MAX_ANCHO){
        this->coordenadaY = coordenadaY;
    }
    else{
        throw "La coordenada Y para la casilla no está dentro de un rango de valores válidos.";
    }
}

unsigned int Casilla::getCoordenadaY(){
    return this->coordenadaY;
}

void Casilla::setCoordenadaZ(unsigned int coordenadaZ){
    if(coordenadaZ > 0 && coordenadaZ < MAX_ALTO){
        this->coordenadaZ = coordenadaZ;
    }
    else{
        throw "La coordenada Z para la casilla no está dentro de un rango de valores válidos.";
    }
}

unsigned int Casilla::getCoordenadaZ(){
    return this->coordenadaZ;
}
