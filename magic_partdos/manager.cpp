#include "manager.h"

manager::manager(){
	playercount = 0;
	gameplayer = NULL;
	turn = 0;
	gamebattlefield = new battlefield;
}

manager::~manager(){
	playercount = 0;
	delete [] gameplayer;
	gameplayer = NULL;
}

void manager::start(){
	welcome();

	int numplayers;
	cout << "How many players are playing today? (max supported currently is 2): ";
	cin >> numplayers;
	cin.ignore(100, '\n');

	gameplayer = new player * [numplayers];

	for(int i = 0; i < numplayers; ++i){
		char tempname[100];
		cout << "Player " <<i+1 <<", please enter your name: ";
		cin.get(tempname, 100, '\n');
		cin.ignore(100, '\n');
		char * playername = new char[strlen(tempname)+1];
		strcpy(playername, tempname); //now have the players name
		gameplayer[i] = new player;
		gameplayer[i]->add_name(playername); //added their name
		
		
		char tempdeck[100];
		cout << "Player " <<i+1 << ", " << gameplayer[i]->get_name() <<", please enter the your deck file name: " ;
		cin.get(tempdeck, 100, '\n');
		cin.ignore(100, '\n');
		char * deckfile = new char[strlen(tempdeck)+1];
		strcpy(deckfile, tempdeck);
		gameplayer[i]->get_deck()->build_deck(deckfile);
	}
	//now we have a dynamically allocated array of players and their names set
	playercount = numplayers; //set the number of players in the manager class object data
	turn = 1; //1st players turn now
	//call the turn function
	
	while(do_turn() == 0){
		do_turn(); //while you can play, give the other player a turn
	}

}

int manager::do_turn(){
	//check to see if we're still able to play the game
	//check if both players still have health, if not, end the game.
	
	//player ** gameplayer
	for (int i = 0; i < playercount; ++i){
		if(gameplayer[i]->get_hp() == 0){ //if any of the players in the game dont have health, end the game
			cout << "Player " <<i+1 <<", " <<gameplayer[i]->get_name() <<" ran out of health. The rest of the players win." <<endl;
			return 99; //the end of the game dun dun dun, this gets returned to the while loop in start()
		}
	}
	//else, the players all still have some health, so lets play!

	cout << "\n\nPlayer " <<turn <<", " <<gameplayer[turn-1]->get_name() <<", it is your turn." <<endl;
	cout << "You have " <<gameplayer[turn-1]->get_hp() <<" health left. Good luck. " <<endl;
	menu_select();	
	
	//figure out who's turn it is
	//playercount is number of players
	//turn is player currently
	
	//if last player, return turn to first player ie from player 2 back to player 1
	if(turn == playercount){ //if this is the last player
		turn = 1; //now its the first players turn
		return 0;
	}
	else{
		++turn;
		return 0; 
	}

}

void manager::welcome(){
	

  cout << "\n\n\n\n\n\n\n\n\n\n########    ########        ###        ######      ####     ######  "<<endl
	   << "   ##       ##     ##      ## ##      ##    ##      ##     ##    ## "<<endl
	   << "   ##       ##     ##     ##   ##     ##            ##     ##       "<<endl
	   << "   ##       ########     ##     ##    ##   ####     ##     ##       "<<endl
	   << "   ##       ##   ##      #########    ##    ##      ##     ##       "<<endl
	   << "   ##       ##    ##     ##     ##    ##    ##      ##     ##    ## "<<endl
	   << "   ##       ##     ##    ##     ##     ######      ####     ######  "<<endl
	   <<endl;

	cout << "T R A G I C, a tradgic representation of Magic	the Gathering, in a few weeks work." <<endl <<endl;
	cout << "Version 0.01, BETA, please submit bug reports to tragic+bug+reports@ifixurcode.com." <<endl <<endl;

}

bool manager::menu_select(){
//turn is the index of the current player

char userinput; //make temp variable for user single char input

	while(userinput != 'X'){
		cout << "\n\nThis is the T R A G I C Menu Selection System.\n" 
		 << "Please enter one of the following choices: \n"
		 << "A - Place card from your hand onto the battlefield\n"
		 << "D - Draw a card from the deck\n"
		 << "T - Tap a card on the battlefield\n"
		 << "Y - Attack the other player\n"
		 << "H - Display cards in hand\n"
		 << "B - Display battlefield\n"
		 << "X - End your turn\n"
		 << "Enter here: "; //tell the options they have
		cin >> userinput; //get their selection
		cin.ignore(100, '\n'); //ignore input buffer
		userinput = toupper(userinput); //capitalize character for matching
	
		if (userinput == 'A' ){ //if matches call appropriate function
			hand2battlefield();
		}

		else if (userinput == 'D'){
			draw();
		}
		
		else if (userinput == 'D'){
			draw();
		}

		else if (userinput == 'T'){
			tap();
		}

		else if (userinput == 'Y'){
			attack();
		}
		
		else if (userinput == 'H'){
			display_hand();
		}

		else if (userinput == 'B'){
			display_battlefield();
		}
	

		else if (userinput == 'X') //if want to quit, return false and while looop in main will die and program will exit
			userinput = 'X'; //let them go, when the loop goes around again
	}
}


//menu select functions

int manager::hand2battlefield(){
	int position = 0; //place the card is in the users hand
	int bfposition = 0; //position on the battlefield the user wants to put the card

	cout << "Enter the position of the card in your hand that you want to play on the battlefield [1-7]: ";
	cin >> position;
	cin.ignore(100, '\n');
	
	cout << "If you are player 1, you have positions 1-5, if player 2, 6-10 are your battlefield positions." <<endl;
	cout << "What position on the battlefield would you like to place your card? " ;
	cin >>bfposition;
	cin.ignore(100, '\n');

	card * fromhand = gameplayer[turn-1]->get_hand()->get_card(position); //get the card from the hand
	gameplayer[turn-1]->get_hand()->rm_card(position); //remove card from hadn, but we already have a pointer to the card;
	gamebattlefield->add_card(fromhand, bfposition);	
}

int manager::draw(){
	cout << "\nDrawing a card...\n";
	card * drawncard = gameplayer[turn-1]->get_deck()->draw(); //get the next card in the deck
	gameplayer[turn-1]->get_hand()->add_card(drawncard);
	cout << "Drew a card from your deck and placed it in your hand.\n\n";
}

int manager::tap(){
	int pos; //card position
	cout << "\n What card would you like to tap (position on the battlefield)?\n";
	cin >> pos;
	cin.ignore(100, '\n');
	gamebattlefield->get_card(pos)->rotate(); //tap der card
	//done
}

int manager::attack(){
	cout << "\n As this program is a work in progress, the attack option has not been implemented. \n";
}

int manager::display_hand(){
	gameplayer[turn-1]->get_hand()->display_all();
}

int manager::display_battlefield(){
	gamebattlefield->display(); //display
}





