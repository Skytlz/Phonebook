//actions.h: Actions

#pragma once
#include <iostream>
#include <queue>
#include <memory>
#include <fstream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include "stdafx.h"

using namespace std;

struct entry {
	string hash;
	string firstName;
	string middleInt; 
	string lastName;
	string phoneNumber;
	string MOB;// month of birth
	string DOB; //day of birth
	string YOB; //year of birth
	string hAddress; //Home
	string eAddress; //Email
	string occupation;
};

struct node {
	entry input;
	node* left;
	node* right;
	node() : left(nullptr), right(nullptr) {}
};

node* current;
node* bcurrent;
node* bhead = new node;
node* head = new node;

void rootConstructor(); //Constructs the head
bool isValidDate(string, string, string); //Checks to see if day given is valid.
void fromFile(); //Read from file
void delFile(); //Deletes book.txt
bool alphabet(string); //Determine left or right.
void Entry(); //input to node (Only First Name);
void Entry(int, string); //From file into memory.
struct node* search(struct node*, string); //hash to name
void search(struct node*, string, int); //Search for name
string toLower(string); //Get string and make it all lowercase.
void printAll(struct node*, int); //Prints entire tree.
void edit(struct node*, string, string, int); //Edits one node. 
struct node* deleteOne(struct node*, string); //Deletes one user from the tree.
void copyTree(struct node*, ofstream&, int); //Copies the Entire tree to file.
int depth(struct node*); //Find max depth of tree.
void delTree(struct node*); //Deletes entire tree
struct node* leastVal(struct node*); //Gets least value node on tree.
void checker(int, string); //Checks

void rootConstructor() {

	bhead->right = head;
	bhead->left = head;

	head->input.hash = "";
	head->input.firstName = "John"; //The untouchable.
	head->input.middleInt = "C";
	head->input.lastName = "Maxton";
	head->input.phoneNumber = "1234567890";
	head->input.DOB = "1";
	head->input.MOB = "January";
	head->input.YOB = "1970";
	head->input.hAddress = "123 Fake St";
	head->input.eAddress = "johnEDoe@skytlz.com";
	head->input.occupation = "Man";
}
bool isValidDate(string month, string day, string year) {
	const int maxYr = 9999;
	const int minYr = 1800;
	int imonth;
	bool leap = false;
	int iyear = stoi(year);
	int iday = stoi(day);
	if (toLower(month) == "january") imonth = 1;
	else if (toLower(month) == "februar") imonth = 2;
	else if (toLower(month) == "march") imonth = 3;
	else if (toLower(month) == "april") imonth = 4;
	else if (toLower(month) == "may") imonth = 5;
	else if (toLower(month) == "june") imonth = 6;
	else if (toLower(month) == "july") imonth = 7;
	else if (toLower(month) == "august") imonth = 8;
	else if (toLower(month) == "september") imonth = 9;
	else if (toLower(month) == "october") imonth = 10;
	else if (toLower(month) == "november") imonth = 11;
	else if (toLower(month) == "december") imonth = 12;

	if (((iyear % 4 == 0) && (iyear % 100 != 0)) || (iyear % 400 == 0)) leap = true;

	if (imonth = 2) {
		if (leap) return (iday <= 29);
		else return (iday <= 28);
	}
	if (imonth == 4 || imonth == 6 || imonth == 9 || imonth == 1) return (iday <= 30);

	return true;
}

void fromFile() {
	ifstream infile;
	string buffer;
	int i = 0;
	char letter;
	infile.open("book.txt", ios::in);
	
	while (infile.get(letter)) {
		if (letter == ',') {
			Entry(i, buffer);
			i++;
			buffer.clear();
		}

		if (letter == '\n') {
			buffer = buffer.substr(1);
			Entry(i, buffer);
			buffer.clear();
			i = 0;
		}
		
		else { buffer += letter; }
	}
	infile.close();
}

void Entry(int num, string data) {
	int i = 0;
	string hashBuffer;
	string no;
	bool moving = false;
	switch (num) {
	case 0:
		hashBuffer = data;
		data.clear();
	case 1:
		if (data == "") { break; }
		if (data[0] == ',') data.erase(0,1);
		bcurrent = bhead;
		current = head;

		while (current != nullptr) {
			if (alphabet(data)) {
				bcurrent = current;
				current = current->right;
				no += '1';
				moving = true;
			}
			else {
				bcurrent = current;
				current = current->left;
				no += '0';
				moving = false;
			}
		}
		if (moving) {
			bcurrent->right = new node;
			current = bcurrent->right;
		}
		else {
			bcurrent->left = new node;
			current = bcurrent->left;
		}
		current->input.hash = no;
		current->input.lastName = data;
		cout << current->input.hash << endl;
	case 2:
		current->input.middleInt = data;
	case 3:
		current->input.firstName = data;
	case 4:
		current->input.phoneNumber = data;
	case 5:
		current->input.MOB = data;
	case 6:
		current->input.DOB = data;
	case 7:
		current->input.YOB = data;
	case 8:
		current->input.hAddress = data;
	case 9:
		current->input.eAddress = data;
	case 10:
		current->input.occupation = data;
	}


}

void delFile() {
	remove("book.txt");
}

bool alphabet(string alpha) {
	int alphaLength = alpha.length();
	int nameLength = current->input.lastName.length();

	if (alphaLength < nameLength) {
		for (int i = 0; i < alphaLength; i++) {
			if (alpha.at(i) > current->input.lastName.at(i)) {
				return true;
				break;
			}
			else if (alpha.at(i) < current->input.lastName.at(i)) {
				return false;
				break;
			}
		}
	}
	else if (alphaLength >= nameLength) {
		for (int i = 0; i < nameLength; i++) {
			if (alpha.at(i) < current->input.lastName.at(i)) {
				return false;
				break;
			}
			else if (alpha.at(i) > current->input.lastName.at(i)) {
				return true;
				break;
			}
		}
	}
	return true;
}

void Entry() {
	ofstream outfile;
	string abuffer, bbuffer, pbuffer, dbuffer, mbuffer, ybuffer;
	string no;
	outfile.open("book.txt", ios::out | ios::app);

	cout << "First Name: ";
	cin >> abuffer;

	cout << endl;

	cout << "Last Name: ";
	cin >> bbuffer;

	int rightPointers = 0;
	int leftPointers = 0;

	bcurrent = bhead;
	current = head;

	bool currentMove = false;
	while (current != nullptr) {
		if (alphabet(bbuffer)) {
			bcurrent = current;
			current = current->right;
			no += '1';
			currentMove = true;
			rightPointers++;
			cout << "testR" << rightPointers << endl;
		}
		else {
			bcurrent = current;
			current = current->left;
			no += '0';
			currentMove = false;
			leftPointers++;
			cout << "testL" << leftPointers << endl;
		}
	}
	if (currentMove) {
		bcurrent->right = new node;
		current = bcurrent->right;
	}
	else {
		bcurrent->left = new node;
		current = bcurrent->left;
	}

	current->input.hash = no;
	current->input.firstName = abuffer;
	current->input.lastName = bbuffer;
	cout << "Middle Initial: ";
	cin >> current->input.middleInt;
	outfile << current->input.hash << ",";
	outfile << current->input.lastName << ",";
	outfile << current->input.middleInt << ",";
	outfile << current->input.firstName << ",";

	cout << endl;
	
	cout << "Phone Number (add area code): ";
	cin >> pbuffer;
	if (pbuffer.length != 10) {
		cout << "Must be 10 digits." << endl;
		cout << "Enter again: ";
		cin >> pbuffer;
	}
	current->input.phoneNumber = pbuffer;
	outfile << current->input.phoneNumber << ",";

	cout << endl;

	bool date = false;

	while (date = false) {
		cout << "Please enter full month (May, June, July, etc)";
		cout << "Month of Birth: ";
		cin >> mbuffer;

		cout << "Day of Birth: ";
		cin >> dbuffer;

		cout << "Year of Birth (yyyy format): ";
		cin >> ybuffer;
		if (ybuffer.length != 4) {
			cout << "Please enter a valid year (4 digits)";
			cout << "Year of Birth: ";
			cin >> ybuffer;
		}
		if (isValidDate(mbuffer, dbuffer, ybuffer)) {
			date = true;
		}
		else {
			cout << "Please enter a valid date" << endl;
		}
	}
	current->input.DOB = dbuffer;
	current->input.MOB = mbuffer;
	current->input.YOB = ybuffer;
	outfile << current->input.DOB << ",";
	outfile << current->input.MOB << ",";
	outfile << current->input.YOB << ",";

	cout << "Home Address (Include spaces): ";
	cin >> current->input.hAddress;
	outfile << current->input.hAddress << ",";

	cout << "Email Adress: ";
	cin >> current->input.eAddress;
	outfile << current->input.eAddress << ",";

	cout << "Occupation: ";
	cin >> current->input.occupation;
	outfile << current->input.occupation << "\n";
	outfile.close();
}
struct node* search(struct node* start, string hash) {
	if (start == NULL) return NULL;

	if (start->input.hash == hash) { return start; }
	node* temp = search(start->right, hash);
	if (temp != NULL) return temp;
	return search(start->left, hash);
}

void search(struct node* start, string target, int i) {
	if (start == nullptr) return;
	search(start->left, target, i);
	
	if (toLower(target) == toLower(start->input.firstName) || toLower(target) == toLower(start->input.lastName) || toLower(target) == start->input.phoneNumber || toLower(target) == toLower(start->input.MOB) || toLower(target) == start->input.DOB || toLower(target) == start->input.YOB || toLower(target) == toLower(start->input.hAddress) || toLower(target) == toLower(start->input.eAddress) || toLower(target) == toLower(start->input.occupation)) {
		if (start->input.hash == "") return;
		i++;
		cout << i << "." << endl;
		cout << "Hash: " << start->input.hash << endl;
		cout << "First Name: " << start->input.firstName << endl;
		cout << "Middle Initial: " << start->input.middleInt << endl;
		cout << "Last Name: " << start->input.lastName << endl;
		cout << "Phone Number: " << start->input.phoneNumber << endl;
		cout << "Birthday: " << start->input.MOB << start->input.DOB << ", " << start->input.YOB << endl;
		cout << "Home Address: " << start->input.hAddress << endl;
		cout << "Email Address: " << start->input.eAddress << endl;
		cout << "Occupation: " << start->input.occupation << endl;
		cout << endl;
	}
	else if (toLower(target) != toLower(start->input.firstName) || toLower(target) != toLower(start->input.lastName) || toLower(target) != start->input.phoneNumber || toLower(target) != toLower(start->input.MOB) || toLower(target) != start->input.DOB || toLower(target) != start->input.YOB || toLower(target) != toLower(start->input.hAddress) || toLower(target) != toLower(start->input.eAddress) || toLower(target) != toLower(start->input.occupation)) {
		if (start->input.hash == "") return;
		size_t found;
		found = toLower(start->input.firstName).find(toLower(target));
		if (found != string::npos) {
			i++;
			cout << i << "." << endl;
			cout << "Hash: " << start->input.hash << endl;
			cout << "First Name: " << start->input.firstName << endl;
			cout << "Middle Initial: " << start->input.middleInt << endl;
			cout << "Last Name: " << start->input.lastName << endl;
			cout << "Phone Number: " << start->input.phoneNumber << endl;
			cout << "Birthday: " << start->input.MOB << start->input.DOB << ", " << start->input.YOB << endl;
			cout << "Home Address: " << start->input.hAddress << endl;
			cout << "Email Address: " << start->input.eAddress << endl;
			cout << "Occupation: " << start->input.occupation << endl;
			cout << endl;
		}
		else if (found == string::npos) {
			found = toLower(start->input.lastName).find(toLower(target));
			if (found != string::npos) {
				if (start->input.hash == "") return;
				i++;
				cout << i << "." << endl;
				cout << "Hash: " << start->input.hash << endl;
				cout << "First Name: " << start->input.firstName << endl;
				cout << "Middle Initial: " << start->input.middleInt << endl;
				cout << "Last Name: " << start->input.lastName << endl;
				cout << "Phone Number: " << start->input.phoneNumber << endl;
				cout << "Birthday: " << start->input.MOB << start->input.DOB << ", " << start->input.YOB << endl;
				cout << "Home Address: " << start->input.hAddress << endl;
				cout << "Email Address: " << start->input.eAddress << endl;
				cout << "Occupation: " << start->input.occupation << endl;
				cout << endl;
			}
			else if (found == string::npos) {
				found = toLower(start->input.phoneNumber).find(toLower(target));
				if (found != string::npos) {
					if (start->input.hash == "") return;
					i++;
					cout << i << "." << endl;
					cout << "Hash: " << start->input.hash << endl;
					cout << "First Name: " << start->input.firstName << endl;
					cout << "Middle Initial: " << start->input.middleInt << endl;
					cout << "Last Name: " << start->input.lastName << endl;
					cout << "Phone Number: " << start->input.phoneNumber << endl;
					cout << "Birthday: " << start->input.MOB << start->input.DOB << ", " << start->input.YOB << endl;
					cout << "Home Address: " << start->input.hAddress << endl;
					cout << "Email Address: " << start->input.eAddress << endl;
					cout << "Occupation: " << start->input.occupation << endl;
					cout << endl;
				}
				else if (found == string::npos) {
					found = toLower(start->input.MOB).find(toLower(target));
					if (found != string::npos) {
						if (start->input.hash == "") return;
						i++;
						cout << i << "." << endl;
						cout << "Hash: " << start->input.hash << endl;
						cout << "First Name: " << start->input.firstName << endl;
						cout << "Middle Initial: " << start->input.middleInt << endl;
						cout << "Last Name: " << start->input.lastName << endl;
						cout << "Phone Number: " << start->input.phoneNumber << endl;
						cout << "Birthday: " << start->input.MOB << start->input.DOB << ", " << start->input.YOB << endl;
						cout << "Home Address: " << start->input.hAddress << endl;
						cout << "Email Address: " << start->input.eAddress << endl;
						cout << "Occupation: " << start->input.occupation << endl;
						cout << endl;
					}
					else if (found == string::npos) {
						found = toLower(start->input.YOB).find(toLower(target));
						if (found != string::npos) {
							if (start->input.hash == "") return;
							i++;
							cout << i << "." << endl;
							cout << "Hash: " << start->input.hash << endl;
							cout << "First Name: " << start->input.firstName << endl;
							cout << "Middle Initial: " << start->input.middleInt << endl;
							cout << "Last Name: " << start->input.lastName << endl;
							cout << "Phone Number: " << start->input.phoneNumber << endl;
							cout << "Birthday: " << start->input.MOB << start->input.DOB << ", " << start->input.YOB << endl;
							cout << "Home Address: " << start->input.hAddress << endl;
							cout << "Email Address: " << start->input.eAddress << endl;
							cout << "Occupation: " << start->input.occupation << endl;
							cout << endl;
						}
						else if (found == string::npos) {
							found = toLower(start->input.hAddress).find(toLower(target));
							if (found != string::npos) {
								if (start->input.hash == "") return;
								i++;
								cout << i << "." << endl;
								cout << "Hash: " << start->input.hash << endl;
								cout << "First Name: " << start->input.firstName << endl;
								cout << "Middle Initial: " << start->input.middleInt << endl;
								cout << "Last Name: " << start->input.lastName << endl;
								cout << "Phone Number: " << start->input.phoneNumber << endl;
								cout << "Birthday: " << start->input.MOB << start->input.DOB << ", " << start->input.YOB << endl;
								cout << "Home Address: " << start->input.hAddress << endl;
								cout << "Email Address: " << start->input.eAddress << endl;
								cout << "Occupation: " << start->input.occupation << endl;
								cout << endl;
							}
							else if (found == string::npos) {
								found = toLower(start->input.eAddress).find(toLower(target));
								if (found != string::npos) {
									if (start->input.hash == "") return;
									i++;
									cout << i << "." << endl;
									cout << "Hash: " << start->input.hash << endl;
									cout << "First Name: " << start->input.firstName << endl;
									cout << "Middle Initial: " << start->input.middleInt << endl;
									cout << "Last Name: " << start->input.lastName << endl;
									cout << "Phone Number: " << start->input.phoneNumber << endl;
									cout << "Birthday: " << start->input.MOB << start->input.DOB << ", " << start->input.YOB << endl;
									cout << "Home Address: " << start->input.hAddress << endl;
									cout << "Email Address: " << start->input.eAddress << endl;
									cout << "Occupation: " << start->input.occupation << endl;
									cout << endl;
								}
								else if (found == string::npos) {
									found = toLower(start->input.occupation).find(toLower(target));
									if (found != string::npos) {
										if (start->input.hash == "") return;
										i++;
										cout << i << "." << endl;
										cout << "Hash: " << start->input.hash << endl;
										cout << "First Name: " << start->input.firstName << endl;
										cout << "Middle Initial: " << start->input.middleInt << endl;
										cout << "Last Name: " << start->input.lastName << endl;
										cout << "Phone Number: " << start->input.phoneNumber << endl;
										cout << "Birthday: " << start->input.MOB << start->input.DOB << ", " << start->input.YOB << endl;
										cout << "Home Address: " << start->input.hAddress << endl;
										cout << "Email Address: " << start->input.eAddress << endl;
										cout << "Occupation: " << start->input.occupation << endl;
										cout << endl;
									}

								}
							}
						}
					}
				}
			}
		}
		if (start->input.hash == "") return;
	}
	search(start->right, target, i);
}

string toLower(string data) {
	string lower;
	for (size_t i = 0; i < data.length(); i++) {
		if (data.at(i) >= 'A' && data.at(i) <= 'Z') { lower += data.at(i) + 32; }
		else {	lower += data.at(i); }
	}
	return lower;
}

void edit(struct node* start, string editName, string newName, int num) {
	if (start == nullptr || num > 10) return;

		edit(start->right, editName, newName, num);

		edit(start->left, editName, newName, num);

	if (toLower(start->input.firstName) == toLower(editName) || toLower(start->input.lastName) == toLower(editName) || toLower(start->input.phoneNumber) == editName || toLower(start->input.middleInt) == toLower(editName) || toLower(start->input.MOB) == toLower(editName) || toLower(start->input.DOB) == toLower(editName) || toLower(start->input.YOB) == toLower(editName) || toLower(start->input.eAddress) == toLower(editName) || toLower(start->input.hAddress) == toLower(editName) || toLower(start->input.occupation) == toLower(editName)) {
		if (num == 3) {
			string no;
			bcurrent = bhead;
			current = head;
			bool moving = false;
			while (current != nullptr) {
				if (alphabet(newName)) {
					bcurrent = current;
					current = current->right;
					no += '1';
					moving = true;
				}
				else {
					bcurrent = current;
					current = current->left;
					no += '0';
					moving = false;
				}
			}
			if (moving) {
				bcurrent->right = new node;
				current = bcurrent->right;
			}
			else {
				bcurrent->left = new node;
				current = bcurrent->left;
			}
			current->input.firstName = start->input.firstName;
			current->input.lastName = newName;
			current->input.hash = no;
		}
		else {
			if (num == 1) { start->input.firstName = newName;}
			if (num == 2) { start->input.middleInt = newName; }
			if (num == 4) { start->input.phoneNumber = newName; }
			if (num == 5) { start->input.MOB = newName; }
			if (num == 6) { start->input.DOB = newName; }
			if (num == 7) { start->input.YOB = newName; }
			if (num == 8) { start->input.hAddress = newName; }
			if (num == 9) { start->input.eAddress = newName; }
			if (num == 10) { start->input.occupation = newName; }
		}
	}
	
}

struct node* deleteOne(struct node* start, string name) {
	if (start == NULL)
		return start;

	current = start;
	if (alphabet(name)) {
		start->right = deleteOne(start->right, name);
	}
	else{
		start->left = deleteOne(start->left, name);
	}

	if (toLower(start->input.lastName) == toLower(name)) {
		if (start->left == NULL) {
			struct node* temp = start->right;
			free(start);
			return temp;
		}
		else if (start->right == NULL) {
			struct node* temp = start->left;
			free(start);
			return temp;
		}
		struct node* temp = leastVal(start->right);
		start->input.firstName = temp->input.firstName;
		start->input.middleInt = temp->input.middleInt;
		start->input.lastName = temp->input.lastName;
		start->input.phoneNumber = temp->input.phoneNumber;
		start->input.MOB = temp->input.MOB;
		start->input.DOB = temp->input.DOB;
		start->input.YOB = temp->input.YOB;
		start->input.hAddress = temp->input.hAddress;
		start->input.eAddress = temp->input.eAddress;
		start->input.occupation = temp->input.occupation;

		start->right = deleteOne(start->right, temp->input.lastName);
	}
	return start;

}

struct node* leastVal(struct node* start) {
	struct node* temp = start;

	while (temp && temp->left != NULL)
		temp = temp->left;

	return temp;
}

void printAll(struct node* start, int space) {
	if (start == nullptr) return;

	space += 5;

	printAll(start->right, space);

	cout << endl;
	for (int i = 5; i < space; i++)
		cout << " ";
	if (start->input.hash == "") { cout << "NULL, " << start->input.lastName << ", " << start->input.middleInt << ", " << start->input.firstName << ", " << start->input.phoneNumber << ", " << start->input.MOB << ", " << start->input.DOB << ", " << start->input.YOB << ", " << start->input.hAddress << ", " << start->input.eAddress << ", " << start->input.occupation << endl; }
	else { cout << start->input.hash << ", " << start->input.lastName << ", " << start->input.middleInt << ", " << start->input.firstName << ", " << start->input.phoneNumber << ", " << start->input.MOB << ", " << start->input.DOB << ", " << start->input.YOB << ", " << start->input.hAddress << ", " << start->input.eAddress << ", " << start->input.occupation << endl;
	}

	printAll(start->left, space);
}

void copyTree(struct node* start, ofstream& outfile, int n) {
	if (start == nullptr) return;
	
	if (start->input.hash != "" && n == 0) {
		cout << "Copying:" << start->input.lastName << "," << start->input.middleInt << "," << start->input.firstName << "," << start->input.phoneNumber << "," << start->input.MOB << "," << start->input.DOB << "," << start->input.YOB << "," << start->input.hAddress << "," << start->input.eAddress << "," << start->input.occupation << endl;
		outfile << start->input.hash << "," << start->input.lastName << "," << start->input.middleInt << "," << start->input.firstName << "," << start->input.phoneNumber << "," << start->input.MOB << "," << start->input.DOB << "," << start->input.YOB << "," << start->input.hAddress << "," << start->input.eAddress << "," << start->input.occupation << endl;
	}
	else {
		copyTree(start->left, outfile, n - 1);
		copyTree(start->right, outfile, n - 1);
	}
	
}
int depth(struct node* start) {
	if (start == NULL) return 0;
	else {
		int leftD = depth(start->left);
		int rightD = depth(start->right);

		if (leftD > rightD) return (leftD + 1);
		else return (rightD + 1);
	}
}

void delTree(struct node* start) {
	if (start == nullptr) return;

	delTree(start->left);
	delTree(start->right);
	if (start->input.hash == "") { cout << "Deleting: " << "NULL, " << start->input.lastName << ", " << start->input.middleInt << ", " << start->input.firstName << ", " << start->input.phoneNumber << ", " << start->input.MOB << ", " << start->input.DOB << ", " << start->input.YOB << ", " << start->input.hAddress << ", " << start->input.eAddress << ", " << start->input.occupation << endl; }
	else { cout << "Deleting: " << start->input.hash << ", " << start->input.lastName << ", " << start->input.middleInt << ", " << start->input.firstName << ", " << start->input.phoneNumber << ", " << start->input.MOB << ", " << start->input.DOB << ", " << start->input.YOB << ", " << start->input.hAddress << ", " << start->input.eAddress << ", " << start->input.occupation << endl;
	}
	
	free(start);
}

void reHash(struct node* start) {
	ifstream infile;
	string buffer;
	int i = 0;
	char letter;
	infile.open("book.txt", ios::in);

	while (infile.get(letter)) {
		if (letter == ',') {
			checker(i, buffer);
			i++;
			buffer.clear();

			if (letter == '\n') {
				buffer = buffer.substr(1);
				checker(i, buffer);
				buffer.clear();
				i = 0;
			}

			else { buffer += letter; }
		}
		infile.close();
	}
}

void checker(int num, string data) {
	int i = 0;
	string hashbuf;
	string no;
	switch (num) {
	case 0:
		hashbuf = data;
		data.clear();
	case 1:
		if (data == "") { break; }
		current = head;
		bcurrent = head;

		while (current != nullptr) {
			if (alphabet(data)) {
				bcurrent = current;
				current = current->right;
				no += '0';
			}
			else {
				bcurrent = current;
				current = current->left;
				no += '1';
			}
			current->input.hash = no;
		}
	}
}