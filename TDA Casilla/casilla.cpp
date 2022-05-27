
#include "casilla.h"

bool Casilla::isValidProportionsForBoard(unsigned int lenght, unsigned int wide, unsigned int height){
    return (lenght > 0 && lenght < MAX_LENGHT && wide > 0 && wide < MAX_WIDE && height > 0 && height < MAX_HEIGHT);
}

Casilla::Casilla(unsigned int amountOfTokens,unsigned int lenght; unsigned int wide, unsigned int height){
  //Esto no va acà creo pero lo dejo aca por si se necesita
    if(isValidProportionsForBoard(lenght,wide,height) && amountOfTokens > 0){
        this->content = VACIO;
        this->type;
        this->lenght = lenght;
        this->wide = wide;
        this->height = height;
    }
    if(!isValidProportionsForBoard(lenght,wide,height)){
        throw "Invalid proportions for board.";
    }
    
}
Casilla::~Casilla(){
  
}

void Casilla::setContenido(char contenido){
    if(contenido == VACIO || contenido == FULL || contenido == INACTIVO){
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
    if(tipoDeCasilla == TIERRA || tipoDeCasilla == AGUA || tipoDeCasilla == MAR){
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
    if(lenght > MIN_DIMENSION && lenght < MAX_DIMENSION){
        this->coordenadaX = coordenadaX;
    }
    else{
        throw "La coordenada X para la casilla no está dentro de un rango de valores válidos."
    }
}

unsigned int Casilla::getCoordenadaX(){
    return this->coordenadaX;
}

void Casilla::setCoordenadaY(unsigned int coordenadaY){
    if(lenght > MIN_DIMENSION && lenght < MAX_DIMENSION){
        this->coordenadaY = coordenadaY;
    }
    else{
        throw "La coordenada Y para la casilla no está dentro de un rango de valores válidos."
    }
}

unsigned int Casilla::getCoordenadaY(){
    return this->coordenadaY;
}

void Casilla::setCoordenadaZ(unsigned int coordenadaZ){
    if(lenght > MIN_DIMENSION && lenght < MAX_DIMENSION){
        this->coordenadaZ = coordenadaZ;
    }
    else{
        throw "La coordenada Z para la casilla no está dentro de un rango de valores válidos."
    }
}

unsigned int Casilla::getCoordenadaZ(){
    return this->coordenadaZ;
}
