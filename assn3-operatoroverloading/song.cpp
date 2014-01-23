#include "song.h"
//////////////////////////////////////////////////////////////////////////////////////////////////
//		Benjamin Reichert CS202 11/15/13 Program #3											    //
//		This program is a representation of object oriented programming and operator 			//
//		overloading	through an recently played list of songs on a persons personal music		//	
//		playing device, such as an ipod. The program uses a song class for the representation	//
//		of a song object and a linear linked list of binary search trees for the list of songs	//
//		that have been played. There is a manager class that prompts the user, and calls the 	//
//		apprpriate methods based on user input.													//
//////////////////////////////////////////////////////////////////////////////////////////////////

song::song(){
	name = NULL;
	plays = 0;
	index = 0;
}

song::~song(){
	if(!name){
		name = NULL;
		return;
	}
	delete [] name;
	name = NULL;
}

//copy constructor
song::song(song * & incoming){
	name = new char[strlen(incoming->getName())+1];
	strcpy(name, incoming->getName());
	//copy in dataz
	plays = incoming->getPlays();

}

/*song::song(const song & incoming){
	if(!incoming.name)
		return;
	//else
	name = new char[strlen(incoming.name)+1];
	strcpy(name, incoming.name);
	plays = incoming.plays;
}*/

void song::copy(const char * from){
	if(!name){
		name = new char[strlen(from)+1];
		strcpy(name, from);
	}
	//else
	delete [] name;
	name = new char[strlen(from)+1];
	strcpy(name, from);
}


song & song::operator = (const song & added){
	copy(added.name);
	plays = added.plays;
}

song & song::operator = (const char * added){
	copy(added);
	plays = 0;
}

ostream & operator << (ostream & output, song & displayed){
	displayed.display();
	return output;
}

void song::display(){
	if(!name) {
		cout << "Song does not have a name, yet." <<endl;
	}
	cout << "Song: " << name << "." <<endl;
	cout << "Number of plays: " <<plays << "." <<endl;
}

bool operator == ( song & op1,  song & op2){
	if(strcmp(op1.getName(), op2.getName())){
		return true;
	}
	else 
		return false;
}

bool operator == ( char * op1,  song & op2){
	if(strcmp(op1, op2.getName()) == 0){
		return true;
	}
	else
		return false;
}

bool operator == (song & op1, char * op2){
	if(strcmp(op1.getName(), op2) == 0){
		return true;
	}
	else
		return false;

}


bool operator != ( song & op1,  song & op2){
	if(strcmp(op1.getName(), op2.getName()) != 0){
		return true; //theyre not equal
	}
	else
		return false;
}

bool operator != ( char * op1,  song & op2){
	if(strcmp(op1, op2.getName()) != 0){
		return true; //theyre not equal
	}
	else
		return false;
}

bool operator != ( song & op1,  char * op2){
	if(strcmp(op1.getName(), op2) != 0){
		return true; //theyre not equal
	}
	else
		return false;
}


bool operator < ( song & op1,  song & op2){
	if(strcmp(op1.getName(), op2.getName()) < 0){
		//op1 is bigger
		return true;
	}
	else
		return false;
}

bool operator < ( char * op1,  song & op2){
	if(strcmp(op1, op2.getName()) < 0){
		//op1 is bigger
		return true;
	}
	else
		return false;

}

bool operator < ( song & op1,  char * op2){
	if(strcmp(op1.getName(), op2) < 0){
		//op1 is bigger
		return true;
	}
	else
		return false;
}


bool operator > ( song & op1,  song & op2){
	if(strcmp(op1.getName(), op2.getName()) > 0){
		//op1 is bigger
		return true;
	}
	else
		return false;
}

bool operator > ( char * op1,  song & op2){
	if(strcmp(op1, op2.getName()) > 0){
		//op1 is bigger
		return true;
	}
	else
		return false;

}

bool operator > ( song & op1,  char * op2){
	if(strcmp(op1.getName(), op2) > 0){
		//op1 is bigger
		return true;
	}
	else
		return false;
}

song & song::operator++(int){
	++plays;
	return *this;
}

char * song::getName(){
	return name;
}

int song::getPlays(){
	return plays;
}







