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

class bstnode{

	public:
		bstnode(); //default constructor
		~bstnode(); //default descturcotr
		bstnode * getLeft(); //return the left pointer
		bstnode * getRight(); //return the right pointer
		song * getSongData(); //return the pointer to the song object that the bst node has
		int setLeft(bstnode * newLeft); //set teh left pointer to the passed in bstnode poitner
		int setRight(bstnode * newRight); //set the right poitner
		int setSongData(song * & newSong); //set the songData to the passed in song object pointer
		void display(); //display the bst node
		int getIndex(); //get the index of the bst node, this refers to the 
		void minus(); //-- the index
		void plus(); //++ the index
		//operator overloading
		
		bstnode * & operator = (const song * & added);
		bstnode * & operator = (const char * added);
		
		friend ostream & operator << (ostream & output, bstnode  & displayed);

		friend bool operator == ( bstnode  & op1,  bstnode  & op2);
		friend bool operator == (  char * op1,  bstnode  & op2);
		friend bool operator == ( bstnode  & op1,   char * op2);
		
		friend bool operator != ( bstnode   & op1,  bstnode & op2);
		friend bool operator != (  char * op1,  bstnode  & op2);
		friend bool operator != ( bstnode  & op1,   char * op2);

		friend bool operator < ( bstnode   & op1,  bstnode & op2);
		friend bool operator < (  char * op1,  bstnode  & op2);
		friend bool operator < ( bstnode  & op1,   char * op2);
	
		friend bool operator > ( bstnode   & op1,  bstnode & op2);
		friend bool operator > (  char * op1,  bstnode  & op2);
		friend bool operator > ( bstnode  & op1,   char * op2);
	
		///increment the index
		bstnode * & operator++(int); //postfix, dont use the int argument

	private:
		int index;
		bstnode * left;
		bstnode * right;
		song * songData;

};

