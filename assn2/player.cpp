#include "player.h"
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
int check_num(int num){
	if(num < 0 || num > 1000){
		return 1; //for failure
	}
	else if(num > 0 && num < 1000){ //highest value 
		return 0; //for success and a valid number
	}

}

/////////////////////////////////////////////////////////////////////////
/////////////CARD CLASS/////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


int card::add_ability(int){};
int card::add_color(int){};
int card::add_damage(int){};
int card::add_defense(int){};
int card::add_effect(int){};
int card::ch_ability(int){};
int card::ch_color(int){};
int card::ch_damage(int){};
int card::ch_defense(int){};
int card::ch_effect(int){};
int card::get_damage(){};
int card::get_defense(){};
int card::get_effect(){};
int card::get_ability(){};
int card::get_color(){};
int card::ch_mana_gain(int){};
int card::add_mana_gain(int){};
int card::get_mana_gain(){};
void card::display(){};

card::card(){
//default constructor

//set variables appropriately
desc = NULL;
name = NULL;
mana_cost = 0;
rotated = 0;

}

card::~card(){
	delete [] desc;
	desc = NULL;
	delete [] name;
	name = NULL;
}

char * card::get_desc(){
	if (desc != NULL){
		return desc;
	}
	else{
		//if there is no descriptino and they call the function, return N/A
		//new char[strlen(temp_chars)+1];
		//strcpy(newchar, tempchar);
		char * no_desc = new char[4];
		strcpy(no_desc, "N/A");

		return no_desc; 
	}
}

char * card::get_name(){
	if (name != NULL){
		return name;
	}
	else{
		//if there is no descriptino and they call the function, return N/A
		//new char[strlen(temp_chars)+1];
		//strcpy(newchar, tempchar);

		char * no_name = new char[4];
		strcpy(no_name, "N/A");

		return no_name; 
	}
}

int card::get_mana(){
	int returned = mana_cost;
	return returned;
}

int card::rotate(){
	//0 is not rotated or tapped
	//1 is rotated and tapped
	if(rotated == 0){
		rotated = 1;
		return 1;
	}
	else if(rotated == 1){
		rotated == 0;
		return 0;
	}

}

int card::add_desc(char * new_desc){
	if (desc == NULL){
		//add desd
		desc = new char[strlen(new_desc)+1];
		strcpy(desc, new_desc);
		return 0;
	}
	else {
		return 1; //already had description, return failure
	}

}

//don;t forget about copy constructors///////

int card::ch_desc(char * new_desc){
	if(desc == NULL){
		return 1; //for failure, since there hasnt been a desc added yet, use add_desc
	}
	else{
		delete [] desc; //get rid of the old desc
		desc = new char[strlen(new_desc)+1]; //copy in new description
		strcpy(desc, new_desc);
		return 0;
	}
}

int card::ch_name(char * new_name){
	if(name == NULL){
		return 1; //for failure, since there hasnt been a desc added yet, use add_desc
	}
	else{
		delete [] name; //get rid of the old desc
		name = new char[strlen(new_name)+1]; //copy in new description
		strcpy(name, new_name);
		return 0;
	}
}

int card::add_name(char * new_name){
	if (name == NULL){
		//add desd
		name = new char[strlen(new_name)+1];
		strcpy(name, new_name);
		return 0;
	}
	else {
		return 1; //already had description, return failure
	}

}

int card::add_mana_cost(int new_cost){
	if(mana_cost == 0 && check_num(new_cost) == 0){
		mana_cost = new_cost;
		return 0;
	}
	else{
		return 1; //there already was a mana cost, use ch_mana_cost
	}
}

int card::ch_mana_cost(int new_cost){
	if(mana_cost == 0){
		return 1; //for failure, need to add cost first
	}
	else{
		if(check_num(new_cost) == 0){
			mana_cost = new_cost;
			return 0; //for success
		}
	}

}
//declare virtual functions for the card class?

//DYNAMICALLY BOUND FUNCTIONS BELOW//////////////////////////////////////////

///////////////////////////////////////////////////////////////////
//instants
///////////////////////////////////////////////////////////////////

int instant::add_ability(int ability_num){};
int instant::add_color(int new_color){};
int instant::add_damage(int new_dmg){};
int instant::add_defense(int new_def){};
int instant::ch_ability(int ability_num){};
int instant::ch_color(int new_color){};
int instant::ch_damage(int new_dmg){};
int instant::ch_defense(int new_def){};
int instant::get_damage(){};
int instant::get_defense(){};
int instant::get_ability(){};
int instant::ch_mana_gain(int new_gain){};
int instant::add_mana_gain(int new_gain){};
int instant::get_mana_gain(){};
int instant::get_color(){};

//default constructor
instant::instant(){
	effect = 0;
}

//default deconstructor
instant::~instant(){
}


void instant::display(){
	char * temp_name = card::get_name();
	char * temp_desc = card::get_desc();
	int temp_mana_cost = card::get_mana();
	int temp_effect = get_effect();

	cout << "Name: " << temp_name <<endl;
	cout << "Description: " <<temp_desc <<endl;
	cout << "Mana Cost: " <<temp_mana_cost <<endl;
	cout << "Effect: " << temp_effect <<endl;


};


int instant::add_effect(int effect_num){
	//probably should do some error checking here
	if (effect == 0 && check_num(effect_num) == 0){
		effect = effect_num;
		return 0;
	}
	else {
		return 1; //for failure
	}

}

int instant::ch_effect(int effect_num){
	//probably should do some error checking here
	if (effect != 0 && check_num(effect_num) == 0){
		effect = effect_num;
		return 0;
	}
	else {
		return 1; //for failure
	}

}

int instant::get_effect(){
	int returned;
	returned = effect;
	return returned;
}

///////////////////////////////////////////////////////////////////////////////
//enchantments
/////////////////////////////////////////////////////////////////////////////
int enchantment::add_ability(int ability_num){};
int enchantment::add_color(int new_color){};
int enchantment::add_damage(int new_dmg){};
int enchantment::add_defense(int new_def){};
int enchantment::ch_ability(int ability_num){};
int enchantment::ch_color(int new_color){};
int enchantment::ch_damage(int new_dmg){};
int enchantment::ch_defense(int new_def){};
int enchantment::get_damage(){};
int enchantment::get_defense(){};
int enchantment::get_ability(){};
int enchantment::ch_mana_gain(int new_gain){};
int enchantment::add_mana_gain(int new_gain){};
int enchantment::get_mana_gain(){};
int enchantment::get_color(){};

enchantment::enchantment(){
	effect = 0;	
}

enchantment::~enchantment(){
}


void enchantment::display(){
	char * temp_name = card::get_name();
	char * temp_desc = card::get_desc();
	int temp_mana_cost = card::get_mana();
	int temp_effect = get_effect();

	cout << "Name: " << temp_name <<endl;
	cout << "Description: " <<temp_desc <<endl;
	cout << "Mana Cost: " <<temp_mana_cost <<endl;
	cout << "Effect: " << temp_effect <<endl;

};


int enchantment::ch_effect(int effect_num){
	//probably should do some error checking here
	if (effect == 0){
		return 1;
	}
	else if (effect != 0 && check_num(effect_num) == 0){
		effect = effect_num;
		return 0; //for failure
	}

}

int enchantment::add_effect(int effect_num){
	//probably should do some error checking here
	if (effect == 0 && check_num(effect_num) == 0){
		effect = effect_num;
		return 1;
	}
	else {
		return 1; //for failure
	}

}

int enchantment::get_effect(){
	int returned; 
	returned = effect;
	return returned;

}
////////////////////////////////////////////////////////////////////
//implementations for der creature clazz////////////////////////////////
//////////////////////////////////////////////////////////////////////


int creature::add_color(int new_color){};
int creature::ch_color(int new_color){};
int creature::add_effect(int effect_num){};
int creature::ch_effect(int effect_num){};
int creature::get_effect(){};
int creature::ch_mana_gain(int new_gain){};
int creature::add_mana_gain(int new_gain){};
int creature::get_mana_gain(){};
int creature::get_color(){};

creature::creature(){
	defense = 0;
	damage = 0;
	ability = 0;

}

creature::~creature(){

}


void creature::display(){
	char * temp_name = card::get_name();
	char * temp_desc = card::get_desc();
	int temp_mana_cost = card::get_mana();
	int temp_damage = get_damage();
	int temp_defense = get_defense();
	int temp_ability = get_ability();

	cout << "Name: " << temp_name <<endl;
	cout << "Description: " <<temp_desc <<endl;
	cout << "Mana Cost: " <<temp_mana_cost <<endl;
	cout << "Damage: " << temp_damage <<endl;
	cout << "Defense: " << temp_defense <<endl;
	cout << "Ability: " << temp_ability <<endl;

};



int creature::get_ability(){
	int returned = ability;
	return returned;
}

int creature::ch_damage(int new_dmg){
	if(damage == 0){
		return 1; //need to add a damage first before changing one
	}
	else if(check_num(new_dmg) == 0){
		damage = new_dmg;
		return 0;
	}

}

int creature::ch_defense(int new_def){
	if(defense == 0){
		return 1; //need to add defense before can change it
	}
	else if(defense != 0 && check_num(new_def) == 0){
		defense = new_def;
		return 0;
	}

}

int creature::get_damage(){
	int returned = damage;
	return returned;
}

int creature::get_defense(){
	int returned = defense;
	return returned;

}

int creature::add_ability(int ability_num){
	if(ability == 0 && check_num(ability_num) == 0){
		ability = ability_num;
		return 0;
	}
	else {
		return 1; //failed
	}
}

int creature::ch_ability(int ability_num){
	if(ability == 0){
		return 1; //ability already exists
	}
	else if(ability != 0 && check_num(ability_num) == 0){
		ability = ability_num;
		return 0;
	}
}

int creature::add_damage(int new_dmg){
	//probably should do some error checking here
	if (damage == 0 && check_num(new_dmg) == 0){
		damage = new_dmg;
		return 0;
	}
	else {
		return 1; //for failure
	}
}

int creature::add_defense(int new_def){
	if(defense == 0 && check_num(new_def) == 0){
		defense == new_def;
		return 0;
	}
	else{
		return 1;
	}
}


/////////////////////////////////////////////////////////////////
//////////////LAND CLASS///////////////////////////////////////////
//////////////////////////////////////////////////////////////////


int land::add_ability(int ability_num){};
int land::add_damage(int new_dmg){};
int land::add_defense(int new_def){};
int land::add_effect(int effect_num){};
int land::ch_ability(int ability_num){}; 
int land::ch_damage(int new_dmg){};
int land::ch_defense(int new_def){};
int land::ch_effect(int effect_num){};
int land::get_damage(){};
int land::get_defense(){};
int land::get_effect(){};
int land::get_ability(){};

land::land(){
	color = 0;
	mana_gain = 0;
}

land::~land(){
}



void land::display(){
	char * temp_name = card::get_name();
	char * temp_desc = card::get_desc();
	int temp_mana_cost = card::get_mana();
	int temp_mana_gain = get_mana_gain();

	cout << "Name: " << temp_name <<endl;
	cout << "Description: " <<temp_desc <<endl;
	cout << "Mana Cost: " <<temp_mana_cost <<endl;
	cout << "Mana Cost: " << temp_mana_cost <<endl;

};


int land::ch_mana_gain(int new_gain){
	if(mana_gain == 0){
		return 1; //need to add before can change value
	}
	else if(mana_gain != 0 && check_num(new_gain) == 0){
		mana_gain = new_gain;
		return 0; //success
	}

}

int land::add_mana_gain(int new_gain){
	if (mana_gain == 0 && check_num(new_gain) == 0){
		mana_gain = new_gain;
		return 0;
	}
	else{
		return 1;
	}
}

int land::get_mana_gain(){
	int returned = mana_gain;
	return returned;
}

int land::ch_color(int new_color){
	if(color == 0){
		return 1; //dont have color, need to add one first
	}
	else if(color != 0 && check_num(new_color) == 0){
		color = new_color;
		return 0;
	}
}

int land::add_color(int new_color){
	if(color == 0 && check_num(new_color) == 0){
		color = new_color;
		return 0;
	}
	else{
		return 1; //need to change color, not add a new one
	}
}

int land::get_color(){
	int returned = color;
	return returned;
}
//using namespace std;

///////////////////////////////////////////////////////////////////////
///////////data structures/////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

node::node(){
	next = NULL;
	card_data = NULL;
}

node::~node(){

	delete card_data;
	card_data = NULL;
	delete next;
	next = NULL;

}

node * node::get_next(){
	return next;
}

void node::set_data(card * new_card){
	card_data = new_card;
}

card * node::get_data(){
	return card_data;
}

void node::set_next(node * next){
	this -> next = next;
}

hand::hand(){
	head = NULL;
}

hand::~hand(){
	delete head;
}


int hand::add_card(card * added_card){
	
	if(!head){
		head = new node;
		head -> set_data(added_card);
	}

	else{
	node * current = head;
	node * new_card = new node;
	new_card -> set_data(added_card);

	while(current -> node::get_next()){
		current = current -> node::get_next();
	}

	//current -> get_next(); = new_card; //NEED OT FIX HOW TO SET NEXT NODE
	//new_card -> set_next(NULL);
	}
}

int hand::rm_card(int index){
	int on_index = 1;
	node * last = head;
	node * current = head;
	
	while (on_index =! index){
		last = current;
		current = current -> get_next();
		on_index++;
	}
	
	if(current == head){
		head = current -> get_next();
		delete current;
	}

	else{
		last -> set_next(current -> get_next());
		delete current;
	}

}

card * hand::get_card(int index){
	//loop to correct card, return current -> card_data;
	node * current = head;
	
	for (int i = 1; i < index; i++){
		current = current -> get_next();
	}
	return current -> get_data();
}

void hand::display(int index){
	//loop to correct card, display the card's data
	node * current = head;
	
	for (int i = 1; i < index; i++){
		current = current -> get_next();
	}
	//current should point to the card we want to display, so output
	card * temp_card = current -> get_data();
	temp_card -> display();
}


int hand::check_index(int num){
	if( num > 0 && num <= 7 ){
		return 0; //for valid number, success
	}

	else
		return 1;
}

//need a check index functino to make sure its not more than 7 and more or equal to 1;


//////////////deck//////////////////////



deck::deck(){
	top = NULL;

}

deck::~deck(){
	delete top;
}

int deck::add_card(card * added_card){
	if(top == NULL){
		top = new node;
		top -> set_data(added_card);
		top -> set_next(NULL);
	}
	else{ //if there is a top, append the card to the top of the deck
		node * temp = new node;
		temp -> set_data(added_card);
		temp -> set_next(top); //set the current card on the to to be the next up in the stack, below the added card
		top = temp; //set top to be pointing to the new top card

	}
}

int deck::build_deck(char * filename){
	//if already have deck, dont ask to build a deck, delete the deck first

	ifstream inFile;
    inFile.open(filename);

	while (inFile.good()){ //while there is things to read from the file
		char * line;
		char temp[500];
		inFile.get(temp, 500, '\n');
		inFile.ignore(500, '\n');
		line = new char[strlen(temp)+1];
		strcpy(line, temp);

		if(strcmp(line, "\n") == 0){ //the line was a newline
			delete [] line;
			//do nothing and read in the next line
		}
		else if(strcmp(line, "land") == 0){ //the line was land
			//now read in all the data 
			card * new_card = new instant;
			//create a new card object of type instant
			
			//this sectino is for reading in the name
			delete [] line;
			inFile.get(temp, 500, '\n');
			inFile.ignore(500, '\n');
			line = new char[strlen(temp)+1];
			strcpy(line, temp);
			new_card -> add_name(line);

			//this sectino is for reading in the description
			delete [] line;
			inFile.get(temp, 500, '\n');
			inFile.ignore(500, '\n');
			line = new char[strlen(temp)+1];
			strcpy(line, temp);
			new_card -> add_desc(line);

			//this sectino is for reading in the mana cost
			int temp_int;
			inFile >> temp_int;
			inFile.ignore(100, '\n');
			new_card -> add_mana_cost(temp_int);

			//this sectino is for reading in the color
			inFile >> temp_int;
			inFile.ignore(100, '\n');
			new_card -> add_color(temp_int);

			//this section for mana fain
			inFile >> temp_int;
			inFile.ignore(100, '\n');

			//add the card to the stack
			add_card(new_card);

		}
		
		else if(strcmp(line, "enchantment") == 0){ //the line was enchantment
			//now read in all the data 
			card * new_card = new enchantment;
			//create a new card object of type instant
			
			//this sectino is for reading in the name
			delete [] line;
			inFile.get(temp, 500, '\n');
			inFile.ignore(500, '\n');
			line = new char[strlen(temp)+1];
			strcpy(line, temp);
			new_card -> add_name(line);

			//this sectino is for reading in the description
			delete [] line;
			inFile.get(temp, 500, '\n');
			inFile.ignore(500, '\n');
			line = new char[strlen(temp)+1];
			strcpy(line, temp);
			new_card -> add_desc(line);

			//this sectino is for reading in the mana cost
			int temp_int;
			inFile >> temp_int;
			inFile.ignore(100, '\n');
			new_card -> add_mana_cost(temp_int);

			//this sectino is for reading in the effect
			inFile >> temp_int;
			inFile.ignore(100, '\n');
			new_card -> add_effect(temp_int);

			add_card(new_card);
		}
			
		else if(strcmp(line, "instant") == 0){ //the line was land
			//now read in all the data 
			card * new_card = new instant;
			//create a new card object of type instant
			
			//this sectino is for reading in the name
			delete [] line;
			inFile.get(temp, 500, '\n');
			inFile.ignore(500, '\n');
			line = new char[strlen(temp)+1];
			strcpy(line, temp);
			new_card -> add_name(line);

			//this sectino is for reading in the description
			delete [] line;
			inFile.get(temp, 500, '\n');
			inFile.ignore(500, '\n');
			line = new char[strlen(temp)+1];
			strcpy(line, temp);
			new_card -> add_desc(line);

			//this sectino is for reading in the mana cost
			int temp_int;
			inFile >> temp_int;
			inFile.ignore(100, '\n');
			new_card -> add_mana_cost(temp_int);

			//this sectino is for reading in the effect
			inFile >> temp_int;
			inFile.ignore(100, '\n');
			new_card -> add_effect(temp_int);

			add_card(new_card);

		}
	
		else if(strcmp(line, "creature") == 0){ //the line was land
			//now read in all the data 
			card * new_card = new instant;
			//create a new card object of type instant
			
			//this sectino is for reading in the name
			delete [] line;
			inFile.get(temp, 500, '\n');
			inFile.ignore(500, '\n');
			line = new char[strlen(temp)+1];
			strcpy(line, temp);
			new_card -> add_name(line);

			//this sectino is for reading in the description
			delete [] line;
			inFile.get(temp, 500, '\n');
			inFile.ignore(500, '\n');
			line = new char[strlen(temp)+1];
			strcpy(line, temp);
			new_card -> add_desc(line);

			//this sectino is for reading in the mana cost
			int temp_int;
			inFile >> temp_int;
			inFile.ignore(100, '\n');
			new_card -> add_mana_cost(temp_int);

			//this sectino is for reading in the defense
			inFile >> temp_int;
			inFile.ignore(100, '\n');
			new_card -> add_defense(temp_int);

			//this sectino is for reading in the damage
			inFile >> temp_int;
			inFile.ignore(100, '\n');
			new_card -> add_damage(temp_int);

			//this sectino is for reading in the ability
			inFile >> temp_int;
			inFile.ignore(100, '\n');
			new_card -> add_ability(temp_int);
			
			add_card(new_card);

		}
	
		else	
			return 1;

	}

	inFile.close();

}

void deck::peek(){
	card * temp = top -> get_data(); 
	temp -> display();
}


card * deck::draw(){
	

	if(top){
		card * returned = top -> get_data();
		top = top -> get_next(); //set the top to the next card;
		return returned;
	}
		
	else
		return NULL;

}


//////////////////////////////////////////////////////////////////////
///////player class.......///////////////////////////////////////////
////////////////////////////////////////////////////////////////////

player::player(){
	player_deck = new deck;
	player_hand = NULL;
	name = NULL;
	id = 0;
	health = 20; //health to start out with
}


player::~player(){
	delete player_deck;
	delete player_hand;
	delete [] name;
}

int player::add_name(char * new_name){
	if (name == NULL){
		name = new char[strlen(new_name)+1];
		strcpy(name, new_name);
		return 0;
	}
	else {
		return 1; //already had description, return failure
	}
}

int player::ch_name(char * new_name){
	if(name){
		delete [] name;
		name = new char[strlen(new_name)+1];
		strcpy(name, new_name);
		return 0;
	}
	else 
		return 1;
}

void player::set_id(int new_id){
	if(new_id > 0 && new_id < 100)
		id = new_id;
}

char * player::get_name(){
	return name;
}

int player::get_id(){
	return id;
}

int player::get_hp(){
	return health;
}

deck * player::get_deck(){
	return player_deck;
}


hand * player::get_hand(){
	return player_hand;
}
