#include "battlefield.h"
using namespace std;

//default constructor
flexarray::flexarray(){
	next = NULL;
	card_array = new card * [array_size];
	for (int i =0; i <array_size; ++i){
		card_array[i] = NULL;
	}
}

flexarray::~flexarray(){
	next = NULL;
	delete [] card_array;
	card_array = NULL;

}

int flexarray::add(card * new_card, int index){
	/*if(!card_array){ //one doesnt exist yet :(
		card_array = new card * [array_size]; //int this case array size is 5, so we have 0,1,2,3,4 as array indices
		for(int i; i<array_size; ++i){
		//initialize the array to nUll
			card_array[i] = NULL;
		}
		card_array[index] = new_card; //make sure this is 0,1,2,3,4 NOT 1,2,3,4,5
		
		return 0;
	}
	*/
	if(card_array[index] == NULL){ //there isnt a card there
		card_array[index] = new_card;
		return 0;
	}

	else
		return 1; //there was a card dere, try removing it first
}

int flexarray::discard(int index){
	if(!card_array)
		return 1; //there isnt a card array to remove from
	if(card_array[index] != NULL){
		card_array[index] = NULL; //set the pointer to null, dont want to DELETE the card
		return 0;
	}
	else
		return 1; //there was no card to delete

}


card * flexarray::get_card(int index){
	return card_array[index]; //return the wanted card in the array
}

void flexarray::display(int index){
	card_array[index] -> display();

}

flexarray * flexarray::get_next(){
	return next;
}

/////////////////////////////////////////////////////////////////////
//////////the battlefield class :) ///////////////////////////////////
/////////////////////////////////////////////////////////////////////////

battlefield::battlefield(){
	flexarray * head = new flexarray;
}

battlefield::~battlefield(){
	//loop to go through and delte each node
	flexarray * previous = head;
	flexarray * current = head;
	while(current -> get_next()){
		current = current -> get_next();
		delete previous;
		previous = current;
	}
	//on last node, now delete it
	delete current;
	head = NULL; //should be gud naow
}

void battlefield::display(){
//card.display() for the cards
	if(!head){
		cout << "There are no cards on the current battlefield." <<endl;
		return;
	}
	//players name?
	
	flexarray * current = head;
	cout <<"\n\n\n\n\nPlayer 1's battlefield: " <<endl;
	for (int i = 0; i<array_size; ++i){
		cout << "Slot " <<i+1 <<" : " <<endl;
		if (!current -> get_card(i)){ //if there isnt a card on that spot
			cout << "No card in this slot." <<endl;
		}
		else{
			current -> display(i); //display the card using the card class methods
		}
	}

	current = current -> get_next(); //traverse to the other players battlefield, which is just another array in the flexible array

	cout <<"\n\nPlayer 2's battlefield: " <<endl;
	for (int i = 0; i<array_size; ++i){
		cout << "Slot " <<i <<" : " <<endl;
		if (!current -> get_card(i)){ //if there isnt a card on that spot
			cout << "No card in this slot." <<endl;
		}
		else{
			current -> display(i); //display the card using the card class methods
		}
	}

}

int battlefield::add_card(card * new_card, int index){
	int divided = index / array_size; //determine how many nodes to go over to get to the array data
	int modded = index % array_size; //determine which array index the card is on, 0,1,2,3,4 
	
	flexarray * current = head;


	for(int i = 0; i < divided; ++i){
		current = current -> get_next(); //traverse to the right node
	}
	//now on the right node
	//just need to add the right array index
		
	current -> add(new_card, modded); //add der kard
	return 0;

}

card * battlefield::get_card(int index){
	int divided = index / array_size; //determine how many nodes to go over to get to the array data
	int modded = index % array_size; //determine which array index the card is on, 0,1,2,3,4 
	
	flexarray * current = head;


	for(int i = 0; i < divided; ++i){
		current = current -> get_next(); //traverse to the right node
	}
	//now on the right node
	//return the right card pointer
	//just need to return the right array index
	return current -> get_card(modded);
	//BOOM
}

int battlefield::discard(int index){
	int divided = index / array_size; //determine how many nodes to go over to get to the array data
	int modded = index % array_size; //determine which array index the card is on, 0,1,2,3,4 
	
	flexarray * current = head;

	for(int i = 0; i < divided; ++i){
		current = current -> get_next(); //traverse to the right node
	}
	//now on the right node
	//return the right card pointer
	//just need to return the right array inde
	
	current -> discard(modded); //done, got rid of that card, good riddens}

}
