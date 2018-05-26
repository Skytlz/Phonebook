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

struct node {
	entry input;
	node* left;
	node* right
};
node* current;
node* bcurrent;
node* bhome = new node;
node* home = new node;
node* newNode = new node;

bool alphabet(string); //Determine left or right.
void Entry(); //input to node;
void search(); //Search for name
void printone(node*); //Prints one node.
void printone(node*); //Prints entire tree.
void deleteOne(string); //Deletes a node from the tree.
void edit(string); //Edits one node. 

bool alphabet(string alpha) {
	unsigned long alphaLength = alpha.length();
	unsigned long firstNameLength = current->input.firstName.length();

	bool side = false;

	if (alphaLength >= firstNameLength) {
		for (int i = 0; i < current->input.firstName.length(); i++) {
			if (alpha.at(i) < current->input.firstName.at(i)) {
				side = false;
				break;
			}
			else if (alpha.at(i) > current->input.firstName.at(i)) {
				side = true;
				break;
			}
		}
	}
	else if (alphaLength < firstNameLength) {
		for (int i = 0; i < alphaLength - 1; i++) {
			if (alpha.at(i) > current->input.firstName.at(i)) {
				side = true;
				break;
			}
			else if (alpha.at(i) < current->input.firstName.at(i)) {
				side = false;
				break;
			}
		}
	}
	return side;
}