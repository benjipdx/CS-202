#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////
//		Benjamin Reichert CS202 11/15/13 Program #3											    //
//		This program is a representation of object oriented programming and operator 			//
//		overloading	through an recently played list of songs on a persons personal music		//	
//		playing device, such as an ipod. The program uses a song class for the representation	//
//		of a song object and a linear linked list of binary search trees for the list of songs	//
//		that have been played. There is a manager class that prompts the user, and calls the 	//
//		apprpriate methods based on user input.													//
//////////////////////////////////////////////////////////////////////////////////////////////////

class song{

	public:
		song(); //default constructor
		song(song * & incoming); //copy constructor
		~song(); //default destructor
		//copy constructor
		
		song & operator = (const song & added); //overload assigment operators so we can assign a song to another song object
		song & operator = (const char * added);
		
		friend ostream & operator << (ostream & output, song & displayed); //output the song name!

		friend bool operator == ( song & op1,  song & op2); //compare two songs, this is very important for the bst
		friend bool operator == ( char * op1,  song & op2);
		friend bool operator == ( song & op1,  char * op2);
		
		friend bool operator != ( song * & op1,  song & op2); //as well as all the relational operators for the song class
		friend bool operator != ( char * op1,  song & op2);
		friend bool operator != ( song & op1,  char * op2);

		friend bool operator < ( song * & op1,  song & op2); //<, > crucial to adding songs to the bst class
		friend bool operator < ( char * op1,  song & op2);
		friend bool operator < ( song & op1,  char * op2);
	
		friend bool operator > ( song * & op1,  song & op2);
		friend bool operator > ( char * op1,  song & op2);
		friend bool operator > ( song & op1,  char * op2);
	
		///increment the number of plays
		song & operator++(int); //postfix, dont use the int argument

		//some helper functions 
		void copy(const char * from); //copy a char * from to the name data
		void display(); //display the song
		char *  getName(); //for testing purposes
		int getPlays(); //not oop


	private:
		char * name;
		int plays; //number of times the song has been played
		int index; //number index of where it is in the top played list, ie #1-10


};

