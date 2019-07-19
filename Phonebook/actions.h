//actions.h: Actions

#pragma once
#include <iostream>
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

void fromFile(); //Read from file
void delFile(); //Deletes book.txt
bool alphabet(string); //Determine left or right.
void Entry(); //input to node (Only First Name);
void Entry(int, string); //From file into memory.
bool search(struct node*, string); //Search for name
void printAll(struct node*); //Prints entire tree.
void deleteOne(struct node*, string); //Deletes a node from the tree.
void edit(struct node*, string); //Edits one node. 
void copyTree(struct node*, ofstream&); //Copies the Entire tree to file.
void delTree(struct node*); //Deletes entire tree

void fromFile() {
	ifstream infile;
	string buffer;
	int i = 0;
	char letter;
	infile.open("book.txt", ios::in);
	
	while (infile.get(letter)) {
		if (letter == ',') {
			Entry(i, buffer);
			buffer.clear();
		}

		if (letter == '\n') {
			i++;
			buffer = buffer.substr(1);
			Entry(i, buffer);
			buffer.clear();
			i = 0;
		}
		
		else { buffer += letter; }
	}
	infile.close();
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
			current = current->left;
			no += '0';
			currentMove = true;
			leftPointers++;
			cout << "testL" << leftPointers << endl;
		}
		else {
			bcurrent = current;
			current = current->right;
			no += '1';
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

void Entry(int num, string data) {
	int i = 0;
	string hashNo;
	switch (num) {
	case 0:
		hashNo = data;

	case 1:
		bcurrent = head;
		current = head;
		
		bool moving = false;
		while (current != nullptr) {
			if (alphabet(data)) {
				bcurrent = current;
				current = current->left;
				moving = true;
			}
			else {
				bcurrent = current;
				current = current->right;
				moving = false;
			}
		}
		if (moving) {
			bcurrent->left = new node;
			current = bcurrent->left;
		}
		else {
			bcurrent->right = new node;
			current = bcurrent->right;
		}
		current->input.hash = hashNo;
		current->input.firstName = data;
		cout << current->input.hash << endl;
		cout << "\"" << data << "\" Done.\n" << endl;
	}
}
	

bool search(struct node* start, string target) { //Needs case if there is more than 1 of the same.
	current = start;
	while (current != nullptr) {
		if (current->input.firstName == target) { return true; }
		else {
			if (alphabet(target)) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}
	}
	return false;
}

void deleteOne(struct node* start, string del) {
	
}

/*void edit(struct node* start, string name) {
	ofstream outfile;
	ifstream infile;
	string change;
	search(start, name);
	if (current != nullptr) {

		cout << current->input.firstName << endl;
		cout << "Enter the new name" << endl;
		cin >> change;
		current->input.firstName = change;
	}
	else { cout << "Person not found" << endl; }
	current = head;
	delFile();
	outfile.open("book.txt", ios::out | ios::app);
	copyTree(head, outfile);
	delTree(head);
	fromFile();

	/*ifstream infile;
	string change;
	string buffer;
	char letter;
	infile.open("book.txt", ios::in);

	while (infile.get(letter)) {
		if (letter == '\n') {
			if (buffer == change) {}
		}
		else { buffer += letter; }
	}
	infile.close();
}*/ //Quarantining code until safe us.

void printAll(struct node* start) {
	if (start == nullptr) return;

	printAll(start->left);
	cout << start->input.hash << start->input.firstName << endl;
	printAll(start->right);
}

void copyTree(struct node* start, ofstream& outfile) {
	if (start == nullptr) return;

	copyTree(start->left, outfile);
	outfile << start->input.hash << "," << start->input.firstName << endl;
	copyTree(start->right, outfile);
}

void delTree(struct node* start) {
	if (start == nullptr)return;
	delTree(start->left);
	delTree(start->right);
	free(start);
}