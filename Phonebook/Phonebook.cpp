// Phonebook.cpp: Main
//

#include "stdafx.h"
#include "actions.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main()
{
	ofstream outfile;
	ifstream infile;

	bhome->right = home;
	bhome->left = home;
	
	home->input.firstName = "John";
	//home->input.middleInt = "E";
	home->input.lastName = "Doe";
	home->input.phoneNumber = "1234567890";
	//home->input.DOB = "1";
	//home->input.MOB = "January";
	//home->input.YOB = "1980";
	//home->input.hAddress = "123 Fake St";
	//home->input.eAddress = "johnEDoe@skytlz.com";
	//home->input.occupation = "Man";

	entry buffer;
	string Buffer;
	char letter;
	int i = 0;
	string act;

	infile.open("book.txt", ios::in);
	
	while (infile.get(letter) && i < 10) {
		cout << letter;
		if (letter == '*') {
			i++;
			switch (i) {
			case 1:
				buffer.firstName = Buffer;
				break;
			/*case 2:
				buffer.middleInt = Buffer;
				*/
			case 2:
				buffer.lastName = Buffer;
				break;
			case 3:
				buffer.phoneNumber = Buffer;
				break;
				/*
			case 4:
				buffer.DOB = Buffer;
				break;
			case 5:
				buffer.MOB = Buffer;
				break;
			case 6:
				buffer.YOB = Buffer;
				break;
			case 7:
				buffer.hAddress = Buffer;
				break;
			case 8:
				buffer.eAddress = Buffer;
				break;
			case 9:
				buffer.occupation = Buffer;
				break;
				*/
			}
			Buffer="";
		}
		else { Buffer += letter; }
	}
	infile.close;

	outfile.open("book.txt", ios::out);

	while (true) {
		cout << "\nRunning Phonebook V\n" << endl;
		cout << "(1)Enter a User *Working*" << endl;
		cout << "(2)Search for a user *Not Done*" << endl;
		cout << "(3)Edit a User *Not Done*" << endl;
		cout << "(4)Delete a User *Not Done*" << endl;
		cout << "(5)Print All Users *Debug*" << endl;
		cout << "(6)Quit Program" << endl;
		cin >> act;

		if (act == "1") {
			Entry();
			outfile << current->input.firstName << "*";
			//outfile << current->input.middleInt << "*";
			outfile << current->input.lastName << "*";
			outfile << current->input.phoneNumber << "*";
			//outfile << current -> input.DOB << "*";
			//outifle << current -> input.MOB << "*";
			//outfile << current -> input.YOB << "*";
			//outfile << current -> input.hAddress << "*";
			//outfile << current -> input.eAddress << "*";
			//outfile << current -> input.occupation << "*";
			cout << endl;
			//outfile.close();
		}if (act == "2") {
			cout << "Enter the first name of the person you would like to find: ";
			string name = "";
			cin >> name;
			search(name);
		}
		if (act == "3") {
			cout << "Enter the first name of the person you would like to edit: ";
			string name = "";
			cin >> name;
			edit(name);
		}
		if (act == "4") {
			cout << "Enter the first name of the person you would like to delete: ";
			string name = "";
			cin >> name;
			deleteOne(name);
		}
		if (act == "5") {
			printAll(home);
		}
		if (act == "6") {
			return 0;
		}
	}
}

