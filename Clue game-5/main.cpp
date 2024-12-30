// Aqdas Juya , 06/11/2024 , ajuya@pdx.edu ,  Program # 5 , cs 162
#include "game.h"
#include <iostream>

int main() { 
	node* head = nullptr; 
	int pick;
	cout <<"\nwelcome to this game!!" << endl; 
	cout <<"\nThis is a clue game. In this game you will get a chance to enter (text, answer, and level) " << endl;
	cout <<"You can decide to display all the sentence you enter or treverse to answer the text.\n"<< endl;  
	read_first(head);
	
	do
	{
		cout << "1. Would like to add a game and the answer?" << endl;
		cout << "2. would you like to display all?"<< endl;
		cout << "3. would you like to play?"<< endl;
		cout << "4. would you like to quit?" <<endl;


		cout<< "\nplease enter your choice: ";
		cin >> pick;
		cin.ignore(100,'\n');

		if (pick == 2) {
			display(head);
		}
		else if (pick == 1) {
			add_clue(head);	
		}
		else if (pick == 3) {	
			play_game(head);
		}
		else {
			cout <<"Enter correct code"<< endl;
		}
	}while(pick != 4); 
	
	release(head);
	return 0;

}

