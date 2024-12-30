// events. h

#include <iostream>
#include <cstring>

using namespace std;



struct clue {
	char * text;
	char * answer;
	int level;
};
struct node {
	clue  data;
	node * next;   // pointing to the next data
};

void read_first(node *& head);
void display(node * head);
void add_clue(node *& head);
void play_game(node * head); 
void release(node * & head);


