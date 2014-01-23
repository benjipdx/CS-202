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

bst::bst(){
	root = NULL;
	size = DEFAULT_SIZE;
}

bst::bst(int size){
	root = NULL;
	size = size;
}

bst::~bst(){
	nuke(root);
}

void bst::nuke(bstnode * root){
	if(!root)
		return;
	if(root){ //if can go left
		nuke(root -> getLeft()); //then go left
		nuke(root -> getRight()); //then go left
		//on return, delete the node
		delete root;
		root -> setRight(NULL);
		root -> setLeft(NULL);
		root = NULL;
		return;
	}
}

int bst::display(bstnode * root){
	if(!root){
		return 1; //hit the bottom of the bst
	}
	if(root){
		display(root -> getLeft());
		display(root -> getRight());
		//on return display the nodes
		cout << "Index: " <<root -> getIndex() <<endl;
		root -> display();
	}

}


int bst::add(song * newSong){
		bstnode * returned;
		add(root, newSong, returned); 
}

int bst::add(bstnode * root, song * newSong, bstnode *& returnedSong){
	
	if(!root){
		root = new bstnode;
		root -> setSongData(newSong);
		returnedSong = root;
		root -> setRight(NULL);
		root -> setLeft(NULL);
		++nodeCount;
		return 10; //added new node

	}
	else if(newSong < root -> getSongData()){
	//go to the left
		int returned = add(root -> getLeft(), newSong, returnedSong);
		if(returned == 10){
			root -> setLeft(returnedSong);		
		}
		return 0;
	}

	else if(newSong > root -> getSongData()){
		//go to the right
		int returned = add(root -> getRight(), newSong, returnedSong);
		if(returned == 10){
		//link up
			root -> setLeft(returnedSong);
		}
		return 0;
	}

}

int bst::remove(bstnode * root, song * removedSong, bstnode * & returnedNode){
	if(!root)
		return 1;
	//else

	else if(removedSong < root -> getSongData()){
		int returned = remove(root -> getLeft(), removedSong, returnedNode);
		if(returned == 10){
			//link up
			
		}
	}

	else if(removedSong > root -> getSongData()){
		int returned = remove(root -> getRight(), removedSong, returnedNode);
		//if(returned == 
	}

	else if(removedSong == root -> getSongData()){
		//on the node we want to remove
		bstnode * temp = new bstnode;
		temp -> setLeft(root -> getLeft());
		temp -> setRight(root -> getRight());
		delete root; //delete the root
		returnedNode = temp;
		//now return;
		if(temp -> getRight() && temp -> getLeft()){
			//has two childeren

			//has two children, but the right child has no children), and the left child has no chilren
			if(temp -> getRight() -> getRight() == NULL
			&& temp -> getRight() -> getLeft() == NULL 
			&& temp -> getLeft() -> getLeft() == NULL
			&& temp -> getLeft() -> getRight() == NULL){
			return 11; //return for has two children, but both dont have their own children
	
			}
			
			//has two children, but the right has a right child, and no left
			//NEED TO FINISH

		}
		


		else if(temp -> getRight() == NULL && temp -> getLeft() !=  NULL){
			//has a left child, but no right
			return 20;
		}
		else if(temp -> getLeft() == NULL && temp -> getRight() != NULL){
			//has right child, but no left child
			return 30;
		}

	}
	


}

bstnode * bst::getLeastPlayed(bstnode * root){
	if(!root)
		return NULL;
	//root -> getIndex();
	//if plays is 10, it is the lest played
	//index 
		if(root -> getIndex() == nodeCount){
			return root;
		}

		bstnode * temp1 = getLeastPlayed(root -> getLeft());
		bstnode * temp2 = getLeastPlayed(root -> getRight());
		
		if(temp1 == NULL && temp2 != NULL){
			return temp2;
		}
		if(temp1 != NULL && temp2 == NULL){
			return temp1;
		}

}

void bst::increasePlays(bstnode * root){
	if(!root)
		return;
	
	root -> plus(); //++ the root
	increasePlays(root -> getLeft());
	increasePlays(root -> getRight());
	
}

void bst::decreasePlays(bstnode * root){
	if(!root)
		return;
	root -> minus();
	decreasePlays(root -> getLeft());
	decreasePlays(root -> getRight());
}

bool bst::search(bstnode * root, char * matchSong){
//probably need to rewrite
	
	if(!root){
		return false;	
	}
	if(root){
		bool rt1;
		bool rt2;
		rt1 = search(root -> getLeft(), matchSong);
		rt2 = search(root -> getRight(), matchSong);
		//if either of them were returned true
		if(rt1 == true || rt2 == true){
			return true; //this muigh be relly buggy and need to be fixed
		}
		else 
			return false;
	}
}

bool bst::full(){
	if(nodeCount == size)
		return true; //return full
	else
		return false;
}

