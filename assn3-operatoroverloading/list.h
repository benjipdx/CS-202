#include "node.h"
//////////////////////////////////////////////////////////////////////////////////////////////////
//		Benjamin Reichert CS202 11/15/13 Program #3											    //
//		This program is a representation of object oriented programming and operator 			//
//		overloading	through an recently played list of songs on a persons personal music		//	
//		playing device, such as an ipod. The program uses a song class for the representation	//
//		of a song object and a linear linked list of binary search trees for the list of songs	//
//		that have been played. There is a manager class that prompts the user, and calls the 	//
//		apprpriate methods based on user input.													//
//////////////////////////////////////////////////////////////////////////////////////////////////

class list{

	//tons of operators
	public:
		list(); //default constructor
		list(int librarySize); // where libary size is the size of the main storage that isnt the top list 
		~list(); //default destructor
		int build(); //create a bst, another node to hold the library of songs
		


	private:
		int move2library(); //move something in the top 10 plays to the library node, which acts as a storage device
		node * head;

};
