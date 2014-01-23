#include "battlefield.h"

//This is the manager of the program, it deals with rules, gameplay, data organization and everything else
//MANAGER.h

//Classes

class manager{

	public:
		manager(); //default constructor
		~manager(); //default destructor
		int add_player(); //add a player to the game
		int rm_player(); //remove a player from the game
		void start(); //the function that reads in the players name, and decks and gives control to the game mechanics
		int do_turn(); //managers the turn and then changes the turn to give the other player a chance to play
		
		//menu select functions
		int hand2battlefield(); //place a card on the battlefield
		int draw(); //draw a card from the deck
		int tap(); //tap a card on the battlefield
		int attack(); //attack the other player, this is the most complicated function
		int display_hand(); //display the players hand
		int display_battlefield(); //display the players hand
		//end menu select functions

		bool menu_select(); //workhorse, call functions and things
		void welcome();

	protected:
		player ** gameplayer;
		int playercount;
		int turn; //index of player whose turn it is
		battlefield * gamebattlefield; //the battlefield
};

/*

		 << "A - Place card from your hand onto the battlefield\n"
		 << "D - Draw a card from the deck\n"
		 << "T - Tap a card on the battlefield\n"
		 << "Y - Attack the other player\n"
		 << "H - Display cards in hand\n"
		 << "B - Display battlefield\n"
		 << "X - End your turn\n"
		 << "Enter here: "; //tell the options they have

*/
