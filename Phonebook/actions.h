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

void Entry() {
	string buffer;
	cout << "First Name: ";

	cin >> buffer;

	newNode = NULL;
	bcurrent = bhome;
	current = home;

	bool currentMove = false;

	while (current != NULL) {
		if (alphabet(buffer)) {
			bcurrent = current;
			current = current->left;
			currentMove = true;
		}
		else {
			bcurrent = current;
			current = current->left;
			currentMove = false;
		}
	}
	if (currentMove) {
		bcurrent->left = new node;
		current = bcurrent->left;
	}
	else {
		bcurrent->right = new node;
		current = bcurrent->right;
	}
	current->input.firstName = buffer;

	//cout << "Middle Initial: ";
	//cin >> current->input.middleInt;

	cout << "Last Name: ";
	cin >> current->input.lastName;

	cout << "Phone Number: ";
	cin >> current->input.phoneNumber;

	//cout << "Day of Birth: ";
	//cin >> current->input.DOB;

	//cout << "Month of Birth: ";
	//cin >> current->input.MOB;

	//cout << "Year of Birth: ";
	//cin >> current->input.YOB;

	//cout << "Home Address: ";
	//cin >> current->input.hAddress;

	//cout << "Email Adress: ";
	//cin >> current->input.eAddress;

	//cout << "Occupation: ";
	//cin >> current->input.occupation;
}