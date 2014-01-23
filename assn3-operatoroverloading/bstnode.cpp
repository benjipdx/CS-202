#include "bstnode.h"
//////////////////////////////////////////////////////////////////////////////////////////////////
//		Benjamin Reichert CS202 11/15/13 Program #3											    //
//		This program is a representation of object oriented programming and operator 			//
//		overloading	through an recently played list of songs on a persons personal music		//	
//		playing device, such as an ipod. The program uses a song class for the representation	//
//		of a song object and a linear linked list of binary search trees for the list of songs	//
//		that have been played. There is a manager class that prompts the user, and calls the 	//
//		apprpriate methods based on user input.													//
//////////////////////////////////////////////////////////////////////////////////////////////////

bstnode::bstnode(){
	left = NULL;
	right = NULL;
	songData = NULL;
}

bstnode::~bstnode(){
	left = NULL;
	right = NULL;
	delete songData;
}

int bstnode::getIndex(){
	return index;
}

void bstnode::minus(){
	--index;
}

void bstnode::plus(){
	++index;
}

bstnode * bstnode::getLeft(){
	return left;
}

bstnode * bstnode::getRight(){
	return right;
}

song * bstnode::getSongData(){
	return songData;
}

int bstnode::setLeft(bstnode * newLeft){
	left = newLeft;
	return 0;
}

int bstnode::setRight(bstnode * newRight){
	right = newRight;
	return 0;
}

int bstnode::setSongData(song * & newSong){
	if(!songData){
	songData = new song(newSong); //create a new song, and use the copy constructor
	return 0;
	}

	else{ //there is already data
		delete songData;
		songData = new song(newSong);
		return 0;
	}
}


void bstnode::display(){
	cout << songData;
}


//implement
/*


	
		bstnode * & operator = (const song * & added);
		bstnode * & operator = (const char * added);
		
		friend ostream & operator << (ostream & output, bstnode * & displayed);

		friend bool operator == ( bstnode  *& op1,  bstnode * & op2);
		friend bool operator == ( char * op1,  bstnode  *& op2);
		friend bool operator == ( bstnode  *& op1,  char * op2);
		
		friend bool operator != ( bstnode  * & op1,  bstnode *& op2);
		friend bool operator != ( char * op1,  bstnode  *& op2);
		friend bool operator != ( bstnode  *& op1,  char * op2);

		friend bool operator < ( bstnode  * & op1,  bstnode *& op2);
		friend bool operator < ( char * op1,  bstnode  *& op2);
		friend bool operator < ( bstnode  *& op1,  char * op2);
	
		friend bool operator > ( bstnode  * & op1,  bstnode *& op2);
		friend bool operator > ( char * op1,  bstnode  *& op2);
		friend bool operator > ( bstnode  *&



*/



