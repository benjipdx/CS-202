//#includes

#include "player.h"
//#include "board.h"//for assn 2
//#include "player.h"
//#include "utilities.h"
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

//		This file is main.cpp and it is the client program and deals with how to intereact 		//
//		with the user and organize the game's behavior 											//

//prototypes
void welcome();
void prog_manager();


int main(){
	
	welcome();
	prog_manager();

	return 0;
}


void welcome(){

  cout << "\n\n\n\n\n\n\n\n\n\n########    ########        ###        ######      ####     ######  "<<endl
	   << "   ##       ##     ##      ## ##      ##    ##      ##     ##    ## "<<endl
	   << "   ##       ##     ##     ##   ##     ##            ##     ##       "<<endl
	   << "   ##       ########     ##     ##    ##   ####     ##     ##       "<<endl
	   << "   ##       ##   ##      #########    ##    ##      ##     ##       "<<endl
	   << "   ##       ##    ##     ##     ##    ##    ##      ##     ##    ## "<<endl
	   << "   ##       ##     ##    ##     ##     ######      ####     ######  "<<endl
	   <<endl;

	cout << "T R A G I C, a tradgic representation of Magic	the Gathering, in a weeks work." <<endl <<endl;
	cout << "Version 0.01, BETA, please submit bug reports to tragic+bug+reports@ifixurcode.com." <<endl <<endl;

}

//this function manages the program through function calls - the backbone of the program
void prog_manager(){

//the player object definition;
player * player1;

char userinput; //make temp variable for user single char input

while(userinput != 'X'){
		cout << "\n\nThis is the T R A G I C Menu Selection System.\n" 
		 << "Please enter one of the following choices: \n"
		 << "A - Add instant card to deck, interactively\n"
		 << "L - Add land card to deck, interactively\n"
		 << "C - Add creature card to deck, interactively\n"
		 << "E - Add enchantment card to deck, interactively\n"
		 << "B - Build the deck from a file, ie cards.txt\n"
		 << "H - Add card to hand\n"
		 << "R - Remove card from hand\n"
		 << "P - Change your information\n"
		 << "Z - Peek at top card in deck\n"
		 << "X - Exit the program\n"
		 << "Enter here: "; //tell the options they have
	cin >> userinput; //get their selection
	cin.ignore(100, '\n'); //ignore input buffer
	userinput = toupper(userinput); //capitalize character for matching
	
	if (userinput == 'A' ){ //if matches call appropriate function
		card * new_card = new instant;
		char temp[500]; //for static alloc
		int temp_int;
		char * temp_char; //when dynamically allocated and size use this
		cout << "Please enter the following information about the card." <<endl;
		
		cout << "Name: ";
		cin.get(temp, 500, '\n');
		cin.ignore(500, '\n');
		temp_char = new char[strlen(temp)+1];
		strcpy(temp_char, temp);
		new_card -> add_name(temp_char);

		delete [] temp_char;
		cout << "Description: ";
		cin.get(temp, 500, '\n');
		cin.ignore(500, '\n');
		temp_char = new char[strlen(temp)+1];
		strcpy(temp_char, temp);
		new_card -> add_desc(temp_char);

		delete [] temp_char;
		
		cout << "Mana Cost: "; 
		cin >> temp_int;
		cin.ignore(500, '\n');
		
		cout << "Effect (number): ";
		cin >> temp_int;
		cin.ignore(500, '\n');

		deck * player1_deck;
		player1_deck = player1 -> get_deck(); //get the deck
		player1_deck -> add_card(new_card); //add the new data and card to the deck
		player1_deck = NULL;

		cout << "Card Added!";	

	}
	else if (userinput == 'L'){
		card * new_card = new land;
		char temp[500]; //for static alloc
		int temp_int;
		char * temp_char; //when dynamically allocated and size use this
		cout << "Please enter the following information about the card." <<endl;
		
		cout << "Name: ";
		cin.get(temp, 500, '\n');
		cin.ignore(500, '\n');
		temp_char = new char[strlen(temp)+1];
		strcpy(temp_char, temp);
		new_card -> add_name(temp_char);

		delete [] temp_char;
		cout << "Description: ";
		cin.get(temp, 500, '\n');
		cin.ignore(500, '\n');
		temp_char = new char[strlen(temp)+1];
		strcpy(temp_char, temp);
		new_card -> add_desc(temp_char);

		delete [] temp_char;
		
		cout << "Mana Cost: "; 
		cin >> temp_int;
		cin.ignore(500, '\n');
		new_card -> add_mana_cost(temp_int);

		cout << "Color (number): ";
		cin >> temp_int;
		cin.ignore(500, '\n');
		new_card -> add_color(temp_int);

		cout << "Mana Gain: ";
		cin >> temp_int;
		cin.ignore(500, '\n');
		new_card -> add_mana_gain(temp_int);

		deck * player1_deck;
		player1_deck = player1 -> get_deck(); //get the deck
		player1_deck -> add_card(new_card); //add the new data and card to the deck

		player1_deck = NULL;
		cout << "Card Added!";	


	}
	else if (userinput == 'C'){
		card * new_card = new creature;
		char temp[500]; //for static alloc
		int temp_int;
		char * temp_char; //when dynamically allocated and size use this
		cout << "Please enter the following information about the card." <<endl;
		
		cout << "Name: ";
		cin.get(temp, 500, '\n');
		cin.ignore(500, '\n');
		temp_char = new char[strlen(temp)+1];
		strcpy(temp_char, temp);
		new_card -> add_name(temp_char);

		delete [] temp_char;
		cout << "Description: ";
		cin.get(temp, 500, '\n');
		cin.ignore(500, '\n');
		temp_char = new char[strlen(temp)+1];
		strcpy(temp_char, temp);
		new_card -> add_desc(temp_char);

		delete [] temp_char;
		
		cout << "Damage: "; 
		cin >> temp_int;
		cin.ignore(500, '\n');
		new_card -> add_damage(temp_int);

		cout << "Defense: ";
		cin >> temp_int;
		cin.ignore(500, '\n');
		new_card -> add_defense(temp_int);

		cout << "Ability: ";
		cin >> temp_int;
		cin.ignore(500, '\n');
		new_card -> add_ability(temp_int);

		deck * player1_deck;
		player1_deck = player1 -> get_deck(); //get the deck
		player1_deck -> add_card(new_card); //add the new data and card to the deck
		player1_deck = NULL;

		cout << "Card Added!";	


	}
	else if (userinput == 'E'){
		card * new_card = new enchantment;
		char temp[500]; //for static alloc
		int temp_int;
		char * temp_char; //when dynamically allocated and size use this
		cout << "Please enter the following information about the card." <<endl;
		
		cout << "Name: ";
		cin.get(temp, 500, '\n');
		cin.ignore(500, '\n');
		temp_char = new char[strlen(temp)+1];
		strcpy(temp_char, temp);
		new_card -> add_name(temp_char);

		delete [] temp_char;
		cout << "Description: ";
		cin.get(temp, 500, '\n');
		cin.ignore(500, '\n');
		temp_char = new char[strlen(temp)+1];
		strcpy(temp_char, temp);
		new_card -> add_desc(temp_char);

		delete [] temp_char;
		
		cout << "Mana Cost: "; 
		cin >> temp_int;
		cin.ignore(500, '\n');
		
		cout << "Effect (number): ";
		cin >> temp_int;
		cin.ignore(500, '\n');

		deck * player1_deck;
		player1_deck = player1 -> get_deck(); //get the deck
		player1_deck -> add_card(new_card); //add the new data and card to the deck
		player1_deck = NULL;

		cout << "Card Added!";	


	}
	else if (userinput == 'Z'){
		deck * player1_deck = NULL;
		player1_deck = player1 -> get_deck();
		player1_deck -> peek();
	}
	else if (userinput == 'B'){
		deck * player1_deck = player1 -> get_deck();
	//	player1_deck -> build_deck


		char temp_filename[100];
		cout << "Please specify card data filename: "; 
		cin.get(temp_filename, 100, '\n');
		cin.ignore(100, '\n');
		char * filename = new char[strlen(temp_filename)+1];

		player1_deck -> build_deck(filename);

		player1_deck = NULL;


	}
	else if (userinput == 'H'){

	}
	else if (userinput == 'R'){

	}
	else if (userinput == 'P'){

	}
	else if (userinput == 'X') //if want to quit, return false and while looop in main will die and program will exit
		userinput = 'X'; //let them go, when the loop goes around again

/*}}}}}`
	player player1;
	cout << "made a player" <<endl;

	char temp_filename[100];
	cout << "Please specify card data filename: "; 
	cin.get(temp_filename, 100, '\n');
	cin.ignore(100, '\n');
	char * filename = new char[strlen(temp_filename)+1];

	deck * test_deck = player1.get_deck();
	test_deck -> build_deck(filename);
	//player1.player_deck -> build_deck("cards.txt");
	cout << "made a deck!!!!!" <<endl;

	char * temp_name;
	char temp[100];
	cout <<"Enter name: ";
	cin.get(temp, 100, '\n');
	cin.ignore(100, '\n');

	temp_name = new char[strlen(temp)+1];
	strcpy(temp_name, temp);
	cout << "Name coming is is: " <<temp_name <<endl;

	card * my_card = new instant;
	my_card -> add_name(temp_name);
	my_card -> add_desc(temp_name);
	my_card -> display();

	cout << "Adding to hand" <<endl;

	hand my_hand;
	my_hand.add_card(my_card);
	my_hand.display(1);
*/

}

}
