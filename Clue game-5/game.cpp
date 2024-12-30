// events.ncpp
#include "game.h"

//this is the first function where it would read the first players response: 
void read_first(node *& head){
	
	node *newnode = new node;

	char to_add_text[121];
	char to_add_answer[121];

	cout <<"please enter your text: ";
	cin.get(to_add_text, 100, '\n');
	cin.ignore(100, '\n');
	newnode -> data.text = new char[strlen(to_add_text) + 1];
	strcpy(newnode-> data.text, to_add_text);


	cout <<"please enter your answer: ";
	cin.get(to_add_answer, 100, '\n');
        cin.ignore(100, '\n');
	newnode ->data.answer = new char[strlen(to_add_answer)+ 1];
	strcpy(newnode ->data.answer, to_add_answer);

	
	cout <<"please enter your level ";
	cin >> newnode-> data.level;
       	cin.ignore(100, '\n');
	
	newnode -> next = head;
	head = newnode;
}
// I used another function here where it would treverse and add it to the end of the array in the struct:
void add_clue(node * & head) 
{
	node * newnode = new node;

	char to_add_text[121];
        char to_add_answer[121];

	cout <<"please enter your text: ";
	cin.get(to_add_text, 100, '\n');
        cin.ignore(100, '\n');
        newnode ->data.text = new char[strlen(to_add_text) + 1];
        strcpy(newnode->data.text, to_add_text);


        cout <<"please enter your answer: ";
	cin.get(to_add_answer, 100, '\n');
        cin.ignore(100, '\n');
        newnode ->data.answer = new char[strlen(to_add_answer)+ 1];
        strcpy(newnode -> data.answer, to_add_answer);


        cout <<"please enter your level: ";
	cin >> newnode -> data.level;
        cin.ignore(100, '\n');


	if(head == nullptr) {
		head = newnode;
	} else {
		node *current = head;
		while(current -> next != nullptr){
			current = current -> next;
		}
		current -> next = newnode;
	}
}
//This function will display everything the user will enter for the text, answer and level:
void display(node * head) {
	if( head == nullptr) {
		cout << "you have entered nothing" <<endl;
	}
	else{
		node * current = head;
		while(current != nullptr) {
			cout << "Text: " << current ->data.text << endl;
		       	cout << "Answer: " << current -> data.answer <<endl;
			cout << "Level: " << current -> data.level << endl;
			
			current = current -> next;
		}
	}	
}
//This function will let the user to treverse through the list and answer the text: 
void play_game(node * head) {
	if(head == nullptr) {
		cout << "No clues available to play the game."<< endl;
		return;
	}

	node * current = head;
	int index = 1;
	int choice;
	char user_answer[121];
	
	
	while (current != nullptr) {
		cout << "clue: " << current->data.text << endl;
		current = current -> next;
		++index;
	}
	cout << "Enter the number of the clue you to answer (enter 0 to go back): ";
	cin >> choice;
	cin.ignore(100, '\n');
	current = head;
	do{
		cout << "your answer: ";
		cin.get(user_answer, 121);
		cin.ignore(100,'\n');

		if (choice > 0 && choice < index) {
				current = head;
				for(int i = 1; i < choice; ++i) {
					current = current -> next;
				}
				cout << "clue: "<< current->data.text << endl;
				cout << "your answer: ";
				cin.get(user_answer, 121);
				
				if(strcmp(user_answer, current -> data.answer)== 0) {
					cout << "correct!" << endl;
				} else{
					cout << "Incorrect. the correct answer is: " << current -> data.answer << endl;
			
				}		
		}else if( choice != 0) {
			cout << "invalid choice. try again.";
		}
		cout << "Enter the number of clue you want to answer (enter 0 if you want to go back): ";
		cin >> choice;
		cin.ignore(100, '\n');
	}while (choice != 0);
}
void release(node * & head) {
	while (head) {
		node * current  = head;
		delete[] current -> data.text;
		delete[] current -> data.answer;
		head = head -> next;
		delete current;
	}
}
