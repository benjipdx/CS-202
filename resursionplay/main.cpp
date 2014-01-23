#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node{
	node * next;
	int data;
};

struct DLL{
	node * previous;
	node * next;
	int data;
};

struct CLL{
	node * next;
	int data;
};

//prototypes
int add(node * head, int data);
int remove();
void display(node * head);

//DLL
int add_DLL(node * head, int data);
int display_DLL(node * head);

//CLL
int add_CLL(node * head, int data);
int display_CLL(node * head, int data);

//cs/cs163/lab/recursion/


int main(){

	node * head = new node;
	head -> next = NULL;
		add(head, 3);
		add(head, 5);
		add(head, 6);
	for(int i = 0; i<100; i++){
		add(head, i);
	}

	cout << "Display: " <<endl;
	display(head);

	node * DLLhead = new node;
	head -> next = NULL;
	head -> data = 199; 
	cout << "Display ddll: " <<endl;
	for(int i = 0; i<10; ++i){
		add_DLL(DLLhead, i);
	}
	display(DLLhead);

	return 0; 
}

void display(node * head){
	if(!head)
	return;
	else{
		cout << "Data is: " <<head->data <<endl;
		display(head->next);
	}

}

int add(node * head, int data){
	if(head -> next == NULL){
		node * temp = new node;
		temp -> data = data;
		temp -> next = NULL;
		head -> next = temp;
		return 0;
	}
	else{	
		add(head->next, data);
		}

}


//DLL
int add_DLL(node * head, int data){
/*	if(head -> next == NULL){
		node * temp = new node;
		temp -> data = data;
*/
	node * previous = head;
	node * current = head;
	if(!head){
		head = new node;
		head -> data = data;
		head -> next = NULL;
	}
	while(current){
		previous = current;
		current = current -> next;
	}

	current = new node;
	current -> data = data;
	previous -> next = current;
	current -> next = NULL;
	
}

int display_DLL(node * head){

}

//CLL
int add_CLL(node * head, int data);
int display_CLL(node * head, int data);


