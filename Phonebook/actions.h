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
	node* right;
};
node* current;
node* bcurrent;
node* bhome = new node;
node* home = new node;
node* newNode = new node;

bool alphabet(string); //Determine left or right.
void Entry(); //input to node;
void search(string); //Search for name
void printone(node*); //Prints one node.
void printone(node*); //Prints entire tree.
void deleteOne(string); //Deletes a node from the tree.
void edit(string); //Edits one node. 

bool alphabet(string alpha) {
	int alphaLength = alpha.length();
	int nameLength = current->input.firstName.length(); //So I don't have to type "current->input.firstName.length();" again and again.

	if (alphaLength < nameLength) {
		for (int i = 0; i < alphaLength; i++) {
			if (alpha.at(i) > current->input.firstName.at(i)) {
				return true;
				break;
			}
			else if (alpha.at(i) < current->input.firstName.at(i)) {
				return false;
				break;
			}
		}
	}
	else if (alphaLength >= nameLength) {
		for (int i = 0; i < nameLength; i++) {
			if (alpha.at(i) < current->input.firstName.at(i)) {
				return false;
				break;
			}
			else if (alpha.at(i) > current->input.firstName.at(i)) {
				return true;
				break;
			}
		}
	}
	return false;
}

void Entry() {
	string buffer;
	cout << "First Name: ";

	cin >> buffer;
	

	newNode = NULL;
	bcurrent = bhome;
	current = home;

	bool currentMove = false;
	cout << "enter the while" << endl;
	while (current != NULL) {
		if (alphabet(buffer)) {
			bcurrent = current;
			current = current->left;
			currentMove = true;
			cout << "testL" << endl;
			break;
		}else{
			bcurrent = current;
			current = current->right;
			currentMove = false;
			cout << "testR" << endl;
			break;
		}
	}
	cout << "Exit the while" << endl;
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

void search(string name) {

}

void printOne(node* output) {
	cout << output->input.firstName << endl;
	//cout << output->input.middleINT << endl;
	cout << output->input.lastName << endl;
	cout << output->input.phoneNumber << endl;
	//cout << output->input.DOB << endl;
	//cout << output->input.MOB << endl;
	//cout << output->input.YOB << endl;
	//cout << output->input.hAddress << endl;
	//cout << output->input.eAddress << endl;
	//cout << output->input.occupation << endl;
}

void printAll(node* start) {
	if (start->right != NULL) {
		printOne(start->right);
	}
	printOne(start);
	if (start->left != NULL) {
		printOne(start -> left);
	}
}

void deleteOne(string del) {

}
 
void edit(string change) {

}