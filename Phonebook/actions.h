//actions.h: Actions

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct entry {
	string firstName;
	//string middleInt; 
	//string lastName;
	//string phoneNumber;
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
	node() : left(nullptr), right(nullptr) {}
};
/*unique_ptr<node> home(new node());
unique_ptr<node> bhome(new node());
shared_ptr<node> current(nullptr);
shared_ptr<node> bcurrent(nullptr);*/
node* current;
node* bcurrent;
node* bhome = new node;
node* home = new node;

int counter = 0;

bool alphabet(string); //Determine left or right.
void Entry(); //input to node;
bool search(struct node*, string); //Search for name
void printAll (struct node*); //Prints entire tree.
//void printAll(struct node*, int);
//void printAll();
void deleteOne(struct node*, string); //Deletes a node from the tree.
void edit(struct node*, string); //Edits one node. 


bool alphabet(string alpha) {
	int alphaLength = alpha.length();
	int nameLength = current->input.firstName.length(); 

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
	ofstream outfile;
	outfile.open("book.txt", ios::out | ios::app);

	cout << "First Name: ";
	cin >> buffer; 

	int rightPointers = 0;
	int leftPointers = 0;


	bcurrent = bhome;
	current = home; 

	bool currentMove = false;
	while (current != nullptr) { 
		if (alphabet(buffer)) {
			bcurrent = current;
			current = current->left;
			currentMove = true;
			leftPointers++;
			cout << "testL" << leftPointers << endl; 
		}else{
			bcurrent = current;
			current = current->right;
			currentMove = false;
			rightPointers++;
			cout << "testR" << rightPointers << endl;
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
	outfile << current->input.firstName << "*" << endl;

	//cout << "Middle Initial: ";
	//cin >> current->input.middleInt;
	//outfile << current->input.middleInt << "*";

	//cout << "Last Name: ";
	//cin >> current->input.lastName;
	//outfile << current->input.lastName << "*";

	//cout << "Phone Number: ";
	//cin >> current->input.phoneNumber;
	//outfile << current->input.phoneNumber << "*\n";


	//cout << "Day of Birth: ";
	//cin >> current->input.DOB;
	//outfile << current->input.DOB << "*";

	//cout << "Month of Birth: ";
	//cin >> current->input.MOB;
	//outfile << current->input.MOB << "*";

	//cout << "Year of Birth: ";
	//cin >> current->input.YOB;
	//outfile << current->input.YOB << "*";

	//cout << "Home Address: ";
	//cin >> current->input.hAddress;
	//outfile << current->input.hAddress << "*";

	//cout << "Email Adress: ";
	//cin >> current->input.eAddress;
	//outfile << current->input.eAddress << "*";

	//cout << "Occupation: ";
	//cin >> current->input.occupation;
	//outfile << current->input.occupation << "*\n";

	outfile.close();
}

bool search(struct node* start, string target) {
	if (start == nullptr) { return false; }
	current = home;
	bcurrent = bhome;
	
	if (target == start->input.firstName) { return true; }
	else {
		if (alphabet(target)) { current = current->left; return search(start->left, target); }
		else { current = current->right; return search(start->right, target); }
	}
	return false;
}

void deleteOne(struct node* start, string del) {
	cout << search(start, del) << endl;
}
 
void edit(struct node* start, string change) {

}


/*void printAll(node* start, int indent = 0) { //print entire tree
	if (start != NULL) {
		if (start->left) printAll(start->left, indent + 4);
		if (start->right) printAll(start->right, indent + 4);
		if (indent) {
			cout << setw(indent) << ' ';
		}
		cout << start->input.firstName << "\n";
	}
}*/

void printAll(struct node* node) {
	if (node == nullptr) return;

	//counter++;
	printAll(node->left);
	cout << node->input.firstName << endl;
	printAll(node->right);

	delete node;
}


/*void printAll(node* start) {
	if (start->right != NULL) {
		printAll(start->right);
	}
	cout << start->input.firstName << endl;
	if (start->left != NULL) {
		printAll(start->left);
	}
}*/
