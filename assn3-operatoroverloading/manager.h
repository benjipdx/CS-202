//MANAGER.h
#include "list.h"
//Classes

class manager{

	public:
		manager(); //default constructor
		~manager(); //default destructor
		void start(); //the function that reads in the players name, and decks and gives control to the game mechanics
		
		//menu select functions

		//end menu select functions

		bool menu_select(); //workhorse, call functions and things
		void welcome();

	protected:

};

