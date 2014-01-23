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

node::node(){
	next = NULL;
}

node::~node(){
	delete binaryTree;
	next = NULL;
}

int node::add(song * & newSong){
	
}

int node::rm(char * match){

}

node * node::getNext(){
	return next;
}

int node::setNext(node * nextNode){
	if(next){
		return 1; //there already is a next node
	}
	if(!next){
		next = nextNode;
	}
}
