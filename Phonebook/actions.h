//actions.h: Actions

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

struct entry {
	string firstName;
	//string middleInt; 
	string lastName;
	string phoneNumber;
	//string DOB; day of birth
	//string MOB; month of birth
	//string YOB; year of birth
	//string hAddress; Home
	//string eAddress; Email
	//string occupation;
};

struct node{
	entry input;
	node* left;
	node* right
};
node* current;
node* bcurrent;
node* bhome = new node;
node* home = new node;
node* newNode = new node;

void Entry(); //input to node;
bool alphabet(); //Determine left or right.
void search(); //Search for name
void printone(node*); //Prints one node.
void printone(node*); //Prints entire tree.
void deleteOne(string); //Deletes a node from the tree.
void edit(string); //Edits one node. 