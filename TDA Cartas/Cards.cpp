#include "Cards.h"
#include "Player.h"
#include <iostream>

using namespace std;

Cards::Cards(){

	this->typeCard = ' ';
	this->numberCard = NULL;
	this->description = "";
}

Cards::Cards(char type, unsigned int number, string description){

	this->typeCard = type;
	this->numberCard = number;
	this->description = description;
}

Cards::Cards(const Cards & carta){

	this->typeCard = carta.typeCard;
	this->numberCard = carta.numberCard;
	this->description = carta.description;
}

char Cards::getTypeCard(){

	return this->typeCard;
}

void Cards::setTypeCard(char card){

	this->typeCard = card;
}

string Cards::getDescription(){

	return this->description;
}

void Cards::setDescription(string description){

	this->description = description;
}

unsigned int Cards::getNumberCard(){

	return this->numberCard;
}

void Cards::setNumberCard(unsigned int number){

	this->numberCard = number;
}

void Cards::newCard(int aleatory){

	switch(aleatory){
		case 1:
			typeCard = AIRPLANE;
			description = "Airplane";
			break;

		case 2:
			typeCard = BOAT;
			description = "Boat";
			break;

		case 3:
			typeCard = MISSILE;
			description = "Missile";
			break;

	}
}

Cards::~Cards(){
}

void Cards::removeCard(){

	this->typeCard = ' ';
	this->numberCard = NULL;
	this->description = "";
}


