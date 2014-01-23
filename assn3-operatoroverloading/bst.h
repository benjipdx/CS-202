#include "bstnode.h"
//////////////////////////////////////////////////////////////////////////////////////////////////
//		Benjamin Reichert CS202 11/15/13 Program #3											    //
//		This program is a representation of object oriented programming and operator 			//
//		overloading	through an recently played list of songs on a persons personal music		//	
//		playing device, such as an ipod. The program uses a song class for the representation	//
//		of a song object and a linear linked list of binary search trees for the list of songs	//
//		that have been played. There is a manager class that prompts the user, and calls the 	//
//		apprpriate methods based on user input.													//
//////////////////////////////////////////////////////////////////////////////////////////////////A
const int DEFAULT_SIZE = 100; //default number of nodes a bst will allow

class bst{


	public: 
		bst(); //default constructor
		bst(int size); //constructor that has a size int so we can create the amounf of items the bst can hold on creation 
		~bst(); //default destructor
		int display(bstnode * root); // display the bst nodes
		int add(song * newSong); //wrapper for adding
		int remove(bstnode * root, song * removedSong, bstnode *& returnedNode); //where index is displayed by display();
		bool search(bstnode * root, char * matchSong); //returns true if finds song in bst, false if it doesnt
		bool full(); //check if the bst has room for a new item, with respect to size
		bstnode * getLeastPlayed(bstnode * root); //get the least played item, like #10	

	private:
		void increasePlays(bstnode * root);  //recursively increase the plays of all the items in teh bst, used when adding and deleting items to 
			//determing how old the items is in the bst, since it is organized by song name, not recently played status 
		void decreasePlays(bstnode * root); //same, but decreasing the play count
		void nuke(bstnode * root); //delete the bst
		int add(bstnode * root, song * newSong, bstnode *& returnedSong); //add a song recursively to the bst
		bstnode * root; //root pointer for the bst
		int size; ///how many items the bst should have MAX , for top ten list, itll be 10
		int nodeCount; //how many songs / nodes are in the bst

};
