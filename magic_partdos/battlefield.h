//welcome to battlefield.h
#include "player.h"


const int array_size = 5; //this is a constant for the flexarray and battlefield classes
//it is the size of the array for the flexible array, ie the amount of cards on each side of the 
//battlefield allowed at one time


class flexarray{

	public:
		flexarray();
		~flexarray();
		int add(card * new_card, int index);
		int discard(int index); //"removes" the card from the battlefield, (just sets array data to null)
		card * get_card(int index); //use this to discard cards, get pointer, then run discard
		void display(int index);
		flexarray * get_next();

	private:
		flexarray * next;
		card ** card_array; //make sure to card_array = new card[10]; or something like that to make it an array, not just a pointer

};


class battlefield
{

	public:
		battlefield();
		~battlefield();
		void display();
		int add_card(card * new_card, int index); //where the index is the place on the battlefield the user wants to place the card
		//make sure to return values if there is already a card to make sure the user doesnt just override the card that is in the spot
		//this will have to make sure to add the card to the correct array
		card * get_card(int index); //user to get the card pointer before discarding
		int discard(int index); //make sure to get the card pointer BEFORE discarding!

	private:
		//flexible array
		flexarray * head; //head of the lll that the flexible array is built on top of

};
