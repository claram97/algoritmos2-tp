#include <iostream>
#include "Fichas.h"

using namespace std;

int main() {                   //comentario importante, si el barco o el soldado son puestos en el piso, pero en posiciones X invalidas, no deberia mostrar la letra.
	
	try{
		
	Fichas *ficha1 = new Fichas(0,0,4,'B');

	cout<<ficha1->getPosicionX()<<endl;
	cout<<ficha1->getPosicionY()<<endl;
	cout<<ficha1->getPosicionZ()<<endl;
	cout<<ficha1->verQueFichaEs()<<endl;

	
	delete ficha1;
	
	}catch(const char*x){
		cout<<"ERROR: "<<x<<endl;
	}

	return 0;
}
