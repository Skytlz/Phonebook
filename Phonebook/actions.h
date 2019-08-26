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

node* current;
node* bcurrent;
node* bhead = new node;
node* head = new node;

void rootConstructor(); //Constructs the head
void fromFile(); //Read from file
void delFile(); //Deletes book.txt
bool alphabet(string); //Determine left or right.
void Entry(); //input to node (Only First Name);
void Entry(int, string); //From file into memory.
bool search(struct node*, string); //Search for name
void printAll(struct node*, int); //Prints entire tree.
struct node* edit(struct node*, string); //Edits one node. 
struct node* deleteOne(struct node*, string); //Deletes one user from the tree.
void copyTree(struct node*, ofstream&); //Copies the Entire tree to file.
void delTree(struct node*); //Deletes entire tree
struct node* leastVal(struct node*);
void checker(int, string);

void rootConstructor() {
	bhead->right = head;
	bhead->left = head;

	head->input.hash = "";
	head->input.firstName = "Max"; //The untouchable.
	//head->input.middleInt = "C";
	//head->input.lastName = "Breamer";
	//head->input.phoneNumber = "1234567890";
	//head->input.DOB = "1";
	//head->input.MOB = "January";
	//head->input.YOB = "1980";
	//head->input.hAddress = "123 Fake St";
	//head->input.eAddress = "johnEDoe@skytlz.com";
	//head->input.occupation = "Man";
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
	switch (num) {
	case 0:
		hashBuffer = data;
		data.clear();
	case 1:
		if (data == "") { break; }
		bcurrent = head;
		current = head;

		bool moving = false;
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
		current->input.firstName = data;
		cout << current->input.hash << endl;
		cout << "\"" << data << "\" Done.\n" << endl;
	}
}

void delFile() {
	remove("book.txt");
}

bool alphabet(string alpha) {
	int alphaLength = alpha.length();
	int nameLength = current->input.firstName.length();

	if (alphaLength < nameLength) {
		for (int i = 0; i < alphaLength; i++) {
			if (alpha.at(i) > current->input.firstName.at(i)) {
				return false;
				break;
			}
			else if (alpha.at(i) < current->input.firstName.at(i)) {
				return true;
				break;
			}
		}
	}
	else if (alphaLength >= nameLength) {
		for (int i = 0; i < nameLength; i++) {
			if (alpha.at(i) < current->input.firstName.at(i)) {
				return true;
				break;
			}
			else if (alpha.at(i) > current->input.firstName.at(i)) {
				return false;
				break;
			}
		}
	}
	return true;
}

void Entry() {
	ofstream outfile;
	string buffer;
	string no;
	outfile.open("book.txt", ios::out | ios::app);

	cout << "First Name: ";
	cin >> buffer;
	
	int rightPointers = 0;
	int leftPointers = 0;

	bcurrent = bhead;
	current = head;

	bool currentMove = false;
	while (current != nullptr) {
		if (alphabet(buffer)) {
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
	current->input.firstName = buffer;
	outfile << current->input.hash << ",";
	outfile << current->input.firstName << "\n"; //<- Change to ',' later
/*
	//cout << "Middle Initial: ";s
	//cin >> current->input.middleInt;
	//outfile << current->input.middleInt << ",";

	//cout << "Last Name: ";
	//cin >> current->input.lastName;
	//outfile << current->input.lastName << ",";

	//cout << "Phone Number: ";
	//cin >> current->input.phoneNumber;
	//outfile << current->input.phoneNumber << ",";

	//cout << "Day of Birth: ";
	//cin >> current->input.DOB;
	//outfile << current->input.DOB << ",";

	//cout << "Month of Birth: ";
	//cin >> current->input.MOB;
	//outfile << current->input.MOB << ",";

	//cout << "Year of Birth: ";
	//cin >> current->input.YOB;
	//outfile << current->input.YOB << ",";

	//cout << "Home Address: ";
	//cin >> current->input.hAddress;
	//outfile << current->input.hAddress << ",";

	//cout << "Email Adress: ";
	//cin >> current->input.eAddress;
	//outfile << current->input.eAddress << ",";

	//cout << "Occupation: ";
	//cin >> current->input.occupation;
	//outfile << current->input.occupation << ",";*/
	outfile.close();
}

bool search(struct node* start, string target) { //Needs case if there is more than 1 of the same.
	current = start;
	while (current != nullptr) {
		if (current->input.firstName == target) { return true; }
		else {
			if (alphabet(target)) {
				current = current->right;
			}
			else {
				current = current->left;
			}
		}
	}
	return false;
}

struct node* edit(struct node* start, string name) {
	if (start == nullptr) return start;
}

struct node* deleteOne(struct node* start, string name) {
	if (start == nullptr) return start;
	
	if (alphabet(name)) {
		start->right = deleteOne(start->right, name);
	}
	else {
		start->left = deleteOne(start->left, name);
	}
	if (start->input.firstName == name) {
		if (start->right == nullptr) {
			struct node *temp = start->left;
			free(start);
			return temp;
		}
		else if (start->left == nullptr) {
			struct node* temp = start->right;
			free(start);
			return temp;
		}
		struct node* temp = leastVal(start->left);

		start->input.firstName = temp->input.firstName;
	}
	return start;
}

struct node* leastVal(struct node* start) {
	struct node* temp = start;

	while (temp && temp->left != nullptr)
		temp = temp->left;

	return temp;
}

void printAll(struct node* start, int space) {
	if (start == nullptr) return;

	space += 5;

	printAll(start->left, space);

	cout << endl;
	for (int i = 5; i < space; i++)
		cout << " ";
	cout << start->input.hash << ", " << start->input.firstName << "\n";
	
	printAll(start->right, space);
	/*printAll(start->left);
	if (start->input.hash == "") { cout << "NULL, " << start->input.firstName << endl; }
	else { cout << start->input.hash << ", " << start->input.firstName << endl; }
	printAll(start->right);*/
}

void copyTree(struct node* start, ofstream& outfile) {
	if (start == nullptr) return;

	copyTree(start->left, outfile);
	if (start->input.hash != "") {
		outfile << start->input.hash << "," << start->input.firstName << endl;
	}
	copyTree(start->right, outfile);
}

void delTree(struct node* start) {
	if (start == nullptr) return;

	delTree(start->left);
	delTree(start->right);
	if (start->input.hash == "") { cout << "Deleting: " << "NULL, " << start->input.firstName << endl; }
	else { cout << "Deleting: " << start->input.hash << ", " << start->input.firstName << endl; }
	
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