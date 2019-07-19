// Phonebook.cpp: Main
//

#pragma once
#include "stdafx.h"
#include "actions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
	bhead->right = head;
	bhead->left = head;

	head->input.hash = "";
	head->input.firstName = "John";
	//home->input.middleInt = "E";
	//home->input.lastName = "Doe";
	//home->input.phoneNumber = "1234567890";
	//home->input.DOB = "1";
	//home->input.MOB = "January";
	//home->input.YOB = "1980";
	//home->input.hAddress = "123 Fake St";
	//home->input.eAddress = "johnEDoe@skytlz.com";
	//home->input.occupation = "Man";

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
			cout << "Enter the first name of the person you would like to delete: ";
			string name = "";
			cin >> name;
			deleteOne(head, name);
		}
		if (act == "5") { printAll(head);}
		if (act == "6") { delFile(); delTree(head); }

		if (act == "7") {
			delete head;
			delete bhead;
			return 0;
		}
	}
}
//"You're going to fast"