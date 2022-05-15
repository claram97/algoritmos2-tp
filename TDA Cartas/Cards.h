#ifndef SRC_CARDS_H_
#define SRC_CARDS_H_
#include <string>

const char AIRPLANE = 'A';
const char BOAT = 'B';
const char MISSILE = 'M';
#define MAX_CARTAS 5

class Cards{


	private:

		char typeCard;
		std::string description;
		unsigned int numberCard;


	public:

		Cards();
		Cards(char, unsigned int, std::string);
		Cards(const Cards &);

		~Cards();

		char getTypeCard();
		void setTypeCard(char);

		std::string getDescription();
		void setDescription(std::string);

		unsigned int getNumberCard();
		void setNumberCard(unsigned int);

		void newCard(int);
		void removeCard();

};



#endif
