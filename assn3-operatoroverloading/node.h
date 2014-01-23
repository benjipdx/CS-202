#include "bst.h"
//////////////////////////////////////////////////////////////////////////////////////////////////
//		Benjamin Reichert CS202 11/15/13 Program #3											    //
//		This program is a representation of object oriented programming and operator 			//
//		overloading	through an recently played list of songs on a persons personal music		//	
//		playing device, such as an ipod. The program uses a song class for the representation	//
//		of a song object and a linear linked list of binary search trees for the list of songs	//
//		that have been played. There is a manager class that prompts the user, and calls the 	//
//		apprpriate methods based on user input.													//
//////////////////////////////////////////////////////////////////////////////////////////////////

class node{

	public: 
		node(); 
		~node();
		int add(song * & newSong); //check if bst is null, if it is, then create a bst and call add function
		int rm(char * match); //if find match song, delete that song
		//might be another better way to do that
		node * getNext();
		int setNext(node * nextNode);

	private:
		node * next;
		bst * binaryTree; ///the binary tree of each node

};
