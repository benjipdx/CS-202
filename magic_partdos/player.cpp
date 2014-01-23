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

void node::new_next(){
	next = new node;
	next -> next = NULL;

}

//end node class

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
//		delete current;
		current = NULL;
	}

	else{
		last -> set_next(current -> get_next());
		//delete current;
		current = NULL;
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

void hand::display_all(){
	node * current = head;
	if(!current){
		cout << "\nThere are no cards in your hand. Considering drawing some cards." <<endl <<endl;
		return;
	}
	//else
	int index = 1;
	while(current){
		cout << "\nThis is the card at position " <<index <<" in your hand." <<endl <<endl;
		current -> get_data() -> display();//display the card wher current is
		current = current -> get_next(); //traverse
		++index; //incremetn the card index counter
	}
	return;
	//hopefully ouput all the itesm in the list
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
	cout << "Building your deck..." <<endl;
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
	
	} //end of while block

	inFile.close();
	cout << "Deck built." <<endl <<endl;
	return 0;

} //end function build deck

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
	player_hand = new hand;
	name = NULL;
	id = 0;
	health = 20; //health to start out with, in this case 20 hp
}


player::~player(){
	delete player_deck;
	delete player_hand;
	delete [] name;
}

int player::damage(int damage){
	if(damage >= health){ //if attack damage was more than the health the player had, player no longer has health, game is over
		health = 0; //no health left
		return 1;
	}
	else { //if the health is large enough to take the damage, then just subtract it
		health = health - damage; //health minus the damage taken
		return 0;
	}

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

graveyard * player::get_graveyard(){
	return player_graveyard;
}

hand * player::get_hand(){
	return player_hand;
}

////////////////////////////////////////////////////
///////////GRAVEYARD///////////////////////////////
///////////////////////////////////////////////////

graveyard::graveyard(){
head = NULL;
tail = NULL;
}

graveyard::~graveyard(){
	//remove all data from the circular linked list
	if(!head)
		return;
	//there is a list if we got to this point
	if(head->get_next()){
		node * current = head->get_next();
		while(current != head){
			//delete the data
			node * temp = current;
			current = current -> get_next();
			delete temp;
		}
		//should be siting on head at this point
		delete current;
		head = NULL;
		tail = NULL; //we already delete the last node which was the tail
		//so we can just set it to null. 
	}
}

int graveyard::add(card * added_card){
	//works like a stack, with the bottom card being the tail pointer, though
	//this is a stack ADT built on a CLL data structure
	if(!added_card)
		return 1; //wtf, you pass me a null pointer, well then return
	//else, there is a pointer to a card
	if(!head){
		head = new node;
		head -> set_next(NULL);
		tail = head;
		tail -> set_next(head);
		return 0;
	}

	tail -> new_next();//made new node, now set der data
	tail = tail -> get_next(); //set tail to be the end of the lll now.
	tail -> set_next(head);
	tail -> set_data(added_card); //add the card to the data
	return 0;

}
card * graveyard::draw(){
	if(!head){ //empty graveyard, return null
		return NULL;
	}
	node * returned = head;
	head = head -> get_next();
	return returned->get_data();
}









