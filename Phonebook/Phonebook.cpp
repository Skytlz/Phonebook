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
#include <algorithm>

using namespace std;

int main() {
	ofstream outfile;
	ifstream infile;
	ofstream godfile;

	bhead->right = head;
	bhead->left = head;

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

	entry data;
	string Buffer;
	char letter;
	int i = 0;
	string act;

	infile.open("book.txt", ios::in);
	godfile.open("test.txt", ios::out);

	while (infile.get(letter)) {
		if (letter == '\n') {
			i++;
			switch (i) {
				case 1:
					//Buffer.pop_back();
					Entry(i, Buffer);
					godfile << Buffer << "L" << Buffer.length() << "E" << Buffer.empty();
					break;
				/*case 2:
					Entry(1, Buffer);
					break;
				case 2:
					buffer.lastName = Buffer;
					break;
				case 3:
					buffer.phoneNumber = Buffer;
					break;
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
					break;*/
						
			}
			
			//Buffer = "\0";
			//Buffer = "";
			//Buffer.erase(remove(Buffer.begin(), Buffer.end(), '\n'), Buffer.end());
			Buffer.clear();
			i = 0;
		}
		else { Buffer += letter; }
	}
	infile.close();
	godfile.close();
	

	outfile.open("book.txt", ios::out | ios::app);

	while (true) {
		cout << "\nRunning Phonebook V\n" << endl;
		cout << "(1)Enter a User *Working*" << endl;
		cout << "(2)Search for a user *Working*" << endl;
		cout << "(3)Edit a User *Not Done*" << endl;
		cout << "(4)Delete a User *Not Done*" << endl;
		cout << "(5)Print All Users *Debug*" << endl;
		cout << "(6)Delete all users *Not Working*" << endl;
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
			search(head, name);
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
		if (act == "5") { printAll(head); }
		if (act == "6") { remove("book.txt"); }

		if (act == "7") {
			delete head;
			delete bhead;
			current = nullptr;
			delete current;
			bcurrent = nullptr;
			delete bcurrent;
			outfile.close();
			return 0;
		}
	}
}
//"You're going to fast"