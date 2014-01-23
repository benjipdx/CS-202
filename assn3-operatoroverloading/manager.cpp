#include "manager.h"

manager::manager(){
}

manager::~manager(){
}

void manager::start(){
	welcome();

	menu_select();
/*
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
*/

//initialize, start the processes along
}
void manager::welcome(){

cout <<	"\n\n\n\n\n\n  #### ########   #######  ########      ######  ########    ###    ########   ######  ##     ##" <<endl
	 <<"   ##  ##     ## ##     ## ##     ##    ##    ## ##         ## ##   ##     ## ##    ## ##     ##" <<endl 
	 <<"   ##  ##     ## ##     ## ##     ##    ##       ##        ##   ##  ##     ## ##       ##     ##" <<endl
	 <<"   ##  ########  ##     ## ##     ##     ######  ######   ##     ## ########  ##       #########" <<endl
	 <<"   ##  ##        ##     ## ##     ##          ## ##       ######### ##   ##   ##       ##     ##" <<endl
	 <<"   ##  ##        ##     ## ##     ##    ##    ## ##       ##     ## ##    ##  ##    ## ##     ##" <<endl
	<<"  #### ##         #######  ########      ######  ######## ##     ## ##     ##  ######  ##     ##" <<endl
	<<endl;
	cout <<"╔═══╗ ♪ ♫"	<<endl
		 <<"║███║ ♫♪ ♫" <<endl
		 <<"║(●)║" <<endl
		 <<"╚═══╝" <<endl
		 << endl;

	cout << "iPod Search, a way to see what music you listen to frequently." <<endl <<endl;
	cout << "Version 0.01, BETA, please submit bug reports to ipod+search+bug+reports@ifixurcode.com." <<endl <<endl;

}
	
bool manager::menu_select(){
//turn is the index of the current player

char userinput; //make temp variable for user single char input

	while(userinput != 'X'){
		cout << "\n\nThis is the iPod Search Menu Selection System.\n" 
		 << "Please enter one of the following choices: \n"
		 << "D - Display the top ten songs in your iPod\n"
		 << "A - Add a song to your library\n"
		 << "P - Play a song\n"
		 << "R - remove a song from the library\n"
		 << "S - search for a song in the library\n"
		 << "X - Exit iPod Search\n"
		 << "Enter here: "; //tell the options they have
		cin >> userinput; //get their selection
		cin.ignore(100, '\n'); //ignore input buffer
		userinput = toupper(userinput); //capitalize character for matching
	
		if (userinput == 'A' ){ //if matches call appropriate function
		}

		else if (userinput == 'D'){
		}
		
		else if (userinput == 'D'){
		}

		else if (userinput == 'T'){
		}

		else if (userinput == 'Y'){
		}
		
		else if (userinput == 'H'){
		}

		else if (userinput == 'B'){
		}
	
		else if (userinput == 'X') //if want to quit, return false and while looop in main will die and program will exit
			userinput = 'X'; //let them go, when the loop goes around again
	}
}


//menu select functions




