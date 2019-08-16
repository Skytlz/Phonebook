// Phonebook.cpp: Main
//

#pragma once
#include "stdafx.h"
#include "actions.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
	rootConstructor();

	string act;

	fromFile();
	
	while (true) {
		cout << "\nRunning Phonebook V\n" << endl;
		cout << "(1)Enter a User *Working*" << endl;
		cout << "(2)Search for a user *Working*" << endl;
		cout << "(3)Edit a User *Not Done*" << endl;
		cout << "(4)Delete a User *Not Done*" << endl;
		cout << "(5)Print All Users *Debug*" << endl;
		cout << "(6)Delete all users *Working*" << endl;
		cout << "(7)Quit Program" << endl;
		cin >> act;

		if (act == "1") {
			Entry();
			cout << endl;
		}
		if (act == "2") {
			string name = "";
			cout << "Enter the first name of the person you would like to find: ";
			cin >> name;
			cout << search(head, name) << endl;
		}
		if (act == "3") {
			cout << "Enter the first name of the person you would like to edit: ";
			string name = "";
			cin >> name;
			edit(head, name);
		}
		if (act == "4") {
			ofstream outfile;
			cout << "Enter the first name of the person you would like to delete: ";
			string name = "";
			cin >> name;
			deleteOne(head, name);
			delFile();
			outfile.open("book.txt", ios::app);
			copyTree(head, outfile);
			reHash(head);
		}
		if (act == "5") { printAll(head,0);}

		if (act == "6") { 
			delTree(head);
			head = new node;
			rootConstructor(); 
		}

		if (act == "7") {
			delTree(head);
			head = NULL;
			return 0;
		}
		if (act == "8") {
			reHash(head);
		}
		if (act == "9") {
			delFile();
		}
	}
}
//"You're going to fast"