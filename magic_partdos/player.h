#include "card.h"

//////////////////////////////////////////////////////////////////////////////////////////////////
//		Benjamin Reichert CS202 10/18/13 Program #1											    //
//		This program is a representation of object oriented programming and dynamic binding		//
//		through a game similar to Magic the Gathering. Classes are used to represent objects	//
//		within the program. There are also implemented data structures that are used by the 	//
//		classes to organize data and store data. The program also has the ability to read		//
//		in information about cards from text files and store that appropriately as cards		//
//		in the game. 																			//
//////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
///////////////////NOW ONTO DATA CLASSES AND DECK AND HANDS////////
//////////////////////////////////////////////////////////////////

//this class is the base set of data holding for the hand and deck
//classes, which use a lll and stack accordintly
class node 
{

	public:	
		node();
		~node();
		//get, set
		node * get_next(); //return pointer to next
		void set_data(card * new_card); //set the data of the card
		card * get_data(); //get the pointer of the card_data
		void set_next(node * next); //set the next pointer
		void new_next();

	private:
		node * next;
		card * card_data; //card dataz

};

//this class is the class that manages what cards are in the players hand,
//7 max at a time
class hand
{
	public:
		hand();
		~hand();
		int add_card(card * added_card); //add card to hand
		int rm_card(int index); //where index is location in LLL, remove card from hadn
		card * get_card(int index); //get card pointer as returned value
		int check_index(int num); //check if the inex is valid num
		void display(int index); //display card at index in hand
		void display_all(); //display all the cards in teh hand
	private:
		node * head;

};

//this is a stack implementation for the deck, using a node structure to hold data for each card
class deck
{

	public:
		deck();
		~deck();
		int add_card(card * added_card);
		int build_deck(char * filename); //this is where io happens and it reads from a file
		void peek(); //displays the next card in the stack, but doesnt remove it
		card * draw();

	protected:
		node * top;

};

class graveyard
{

	public:
		graveyard();
		~graveyard();
		int add(card * added_card);
		card * draw(); //grabs the top card from the graveyard
	private:
		node * head;
		node * tail;

};

//top class has all data members directly or indirectly
class player
{

	public:
		player();
		~player();
		int add_name(char * new_name); //add name for the user
		int ch_name(char * new_name); //change name for the user
		void set_id(int new_id); //set id for the user
		char * get_name(); //get name of the user
		int get_hp(); //get health
		int get_id(); //get id;
		int damage(int damage); //take health away from player
		deck * get_deck(); //get the deck pointer, cheap workaround to wrappers, not so OOP
		hand * get_hand(); //same , but for hand pointer
		graveyard * get_graveyard(); //get the graveyard pointer
		//ADD FUUNCTIONS FOR GRAVEYARD	

	protected:
		deck * player_deck; //poinrter to deck
		hand * player_hand; //pointer to hand
		graveyard * player_graveyard;
		char * name; //name of player
		int id;  //id of player
		int health; //health of player
};
