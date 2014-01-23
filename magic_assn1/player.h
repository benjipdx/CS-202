#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////
//		Benjamin Reichert CS202 10/18/13 Program #1											    //
//		This program is a representation of object oriented programming and dynamic binding		//
//		through a game similar to Magic the Gathering. Classes are used to represent objects	//
//		within the program. There are also implemented data structures that are used by the 	//
//		classes to organize data and store data. The program also has the ability to read		//
//		in information about cards from text files and store that appropriately as cards		//
//		in the game. 																			//
//////////////////////////////////////////////////////////////////////////////////////////////////

//this is card.h, the header file for the card class and its derivative classes


//0 indicates success as return type, 1 indicates failure
//this class is the base class called card and has children of type enchantment, instant, creature, or land
//manages all the data belonging to a card
class card 
{

	public:
		card(); //default constructor
		virtual ~card(); //virtual destructor
		char * get_desc(); //returns the description of the card as a char *
		char * get_name(); // returns the name of the card as a char *
		int add_desc(char * new_desc); //adds a descriotion to the card through a char * argument
		int add_name(char * new_name); //adds a name to the card through a char * arg
		int ch_desc(char * new_desc); //changes an already existing desc to something else
		int ch_name(char * new_name); //changes an already existing name to somethign else
		int rotate(); //rotates the card, ie tapping in the game of magic the gathering
		int add_mana_cost(int new_cost); //adds a mana cost to the card
		int ch_mana_cost(int new_cost); //changes the mana cost to the card
		int get_mana(); //return an int of that value of the mana cost
		
		//dynamically bound functions, all implemented for each card type
		virtual int add_ability(int ability_num); //only allow one ability per card, adds ability to card
		virtual int add_color(int new_color); //colors and abiliteis and effects are represented as numbers
		//and then the client program can translate 1 ie black, or 2 == red. this makes data storage
		//much simpler and more efficnet
		virtual int add_damage(int new_dmg); //add an integer new_dmg as the damage
		virtual int add_defense(int new_def); //add an int new_def as the defense
		virtual int add_effect(int effect_num); //where effect num is the effect represented by an integer
		virtual int ch_ability(int ability_num); //where ability_num is an ability based on the integer
		virtual int ch_color(int new_color); // change the color int
		virtual int ch_damage(int new_dmg); //change the damage int
		virtual int ch_defense(int new_def); //change the def int
		virtual int ch_effect(int effect_num); //change the effect itn
		virtual int get_damage(); //returns and int of current damage value
		virtual int get_defense(); //returns an int of the current defense value
		virtual int get_effect(); //return int with the value of effect
		virtual int get_ability(); //return in with the value of ability
		virtual int get_color(); //return int with the value of color
		virtual int ch_mana_gain(int new_gain); //change mana gain as int new_gain
		virtual int add_mana_gain(int new_gain); //add mana gain as int_new_gain
		virtual int get_mana_gain(); //returns int with the value of mana-gain
		virtual void display(); //display the card and its data

	protected:
		//to be data or not to be data? that is the question/	
		char * desc;
		char * name;
		int mana_cost;
		int rotated; //basicallly a bool, 0 == not rotated, 1 == rotated
};

//this is a derivative class of the card class
//see notations in the card class for what each functions do
class land : public card
{

	public:
//		~card();//not sure about virtual destructor
		land();
		~land();
	//	land(card * & old_card); //copy constructor


		//dynamically bound functions
		int add_ability(int ability_num); //only allow one ability per card
		int add_color(int new_color);
		int add_damage(int new_dmg);
		int add_defense(int new_def);
		int add_effect(int effect_num); //where effect num is the effect represented by an integer
		int ch_ability(int ability_num); //where ability_num is an ability based on the integer
		int ch_color(int new_color);
		int ch_damage(int new_dmg);
		int ch_defense(int new_def);
		int ch_effect(int effect_num);
		int get_damage(); //returns and int of current damage value
		int get_defense(); //returns an int of the current defense value
		int get_effect();
		int get_ability();
		int ch_mana_gain(int new_gain);
		int add_mana_gain(int new_gain);
		int get_mana_gain();
		int get_color();
		void display();

	protected:
		//color integers are: 1 - white, 2 - black, 3 - green, 4 - blue, 5 - red
		int color;	
		int mana_gain;

};

//this is a derivative class of the card class
//see notations in the card class for what each functions do
class instant : public card
{

	public:
//		~card();//not sure about virtual destructor
		instant();
		~instant();
//		instant(card * & old_card);

		int add_ability(int ability_num); //only allow one ability per card
		int add_color(int new_color);
		int add_damage(int new_dmg);
		int add_defense(int new_def);
		int add_effect(int effect_num); //where effect num is the effect represented by an integer
		int ch_ability(int ability_num); //where ability_num is an ability based on the integer
		int ch_color(int new_color);
		int ch_damage(int new_dmg);
		int ch_defense(int new_def);
		int ch_effect(int effect_num);
		int get_damage(); //returns and int of current damage value
		int get_defense(); //returns an int of the current defense value
		int get_effect();
		int get_ability();
		int ch_mana_gain(int new_gain);
		int add_mana_gain(int new_gain);
		int get_mana_gain();
		int get_color();
		void display();

	protected:
		int effect;

};


class enchantment : public card
{
	public:
//		~card();//not sure about virtual destructor
		enchantment();
		~enchantment();
		
		int add_ability(int ability_num); //only allow one ability per card
		int add_color(int new_color);
		int add_damage(int new_dmg);
		int add_defense(int new_def);
		int add_effect(int effect_num); //where effect num is the effect represented by an integer
		int ch_ability(int ability_num); //where ability_num is an ability based on the integer
		int ch_color(int new_color);
		int ch_damage(int new_dmg);
		int ch_defense(int new_def);
		int ch_effect(int effect_num);
		int get_damage(); //returns and int of current damage value
		int get_defense(); //returns an int of the current defense value
		int get_effect();
		int get_ability();
		int ch_mana_gain(int new_gain);
		int add_mana_gain(int new_gain);
		int get_mana_gain();
		int get_color();	
		void display();
		

	protected:
		int effect;
};

//this is a derivative class of the card class
//see notations in the card class for what each functions do
class creature : public card
{

	public:
//		~card();//not sure about virtual destructor
		creature();
		~creature();
		int add_ability(int ability_num); //only allow one ability per card
		int add_color(int new_color);
		int add_damage(int new_dmg);
		int add_defense(int new_def);
		int add_effect(int effect_num); //where effect num is the effect represented by an integer
		int ch_ability(int ability_num); //where ability_num is an ability based on the integer
		int ch_color(int new_color);
		int ch_damage(int new_dmg);
		int ch_defense(int new_def);
		int ch_effect(int effect_num);
		int get_damage(); //returns and int of current damage value
		int get_defense(); //returns an int of the current defense value
		int get_effect();
		int get_ability();
		int ch_mana_gain(int new_gain);
		int add_mana_gain(int new_gain);
		int get_mana_gain();
		int get_color();	
		void display();

	protected:
		int defense;
		int damage;
		int ability;

};

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
		deck * get_deck(); //get the deck pointer, cheap workaround to wrappers, not so OOP
		hand * get_hand(); //same , but for hand pointer
 
	protected:
		deck * player_deck; //poinrter to deck
		hand * player_hand; //pointer to hand
		char * name; //name of player
		int id;  //id of player
		int health; //health of player

};


