﻿// Phonebook.cpp: Main
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
		cout << "(1)Enter a User."<< endl;
		cout << "(2)Search for a user *Not Finished, Working*" << endl;
		cout << "(3)Edit a User *Not Done*" << endl;
		cout << "(4)Delete a User *Not Working*" << endl;
		cout << "(5)Print All Users."<< endl;
		cout << "(6)Delete all users."<< endl;
		cout << "(7)Quit Program" << endl;
		cin >> act;

		if (act == "1") {
			Entry();
			cout << endl;
		}
		if (act == "2") {
			string name = "";
			int i = 0;
			cout << "Enter the first name of the person you would like to find: ";
			cin >> name;
			search(head, name, i);
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
			cout << deleteOne(head, name) << endl;
			cout << head << endl;
			delFile();
			outfile.open("book.txt", ios::app);
			copyTree(head, outfile);
			reHash(head);
		}
		if (act == "5") { printAll(head,0);}

		if (act == "6") { 
			delTree(head);
			delFile();
			head = new node;
			rootConstructor(); 
		}

		if (act == "7") {
			ofstream outfile;
			delFile();
			copyTree(head, outfile);
			outfile.close();
			delTree(head);
			head = NULL;
			return 0;
		}
		if (act == "8") {
			reHash(head);
		}
	}
}
//"You're going to fast"