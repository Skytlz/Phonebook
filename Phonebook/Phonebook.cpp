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
			cout << "Search: ";
			cin >> name;
			search(head, name, i);
		}
		if (act == "3") {
			int i = 0;
			int num;
			ofstream outfile;
			cout << "Search (Edit): ";
			string name = "";
			cin >> name;
			search(head, name, i);
			cout << "Please enter the hash you would like to edit: ";
			string no;
			cin >> no;
			if (no != "NULL" || "null") {
				cout << "1. First Name" << endl;
				//cout << "2. Middle Initial" << endl;
				cout << "3. Last Name" << endl;
				//cout << "4. Phonenumber" << endl;
				//cout << "5. Day of Birth" << endl;
				//cout << "6. Month of Birth" << endl;
				//cout << "7. Year of Birth" << endl;
				//cout << "8. Home address" << endl;
				//cout << "9. Email adress" << endl;
				//cout << "10. Occupation" << endl;
				cout << "What would you like to edit (number): ";
				cin >> num;
				if (num == 1) {
					cout << "Enter new name: " << endl;
					string newName;
					cin >> newName;
					string editNode = search(head, no)->input.firstName;
					edit(head, editNode, newName, num);
					
				//if (num == 2) {}
				if (num == 3) {
					cout << "Enter new name: " << endl;
					string newName;
					cin >> newName;
					string editNode = search(head, no)->input.lastName;
					edit(head, editNode, newName, num);
					deleteOne(head, editNode);
					delFile();
					outfile.open("book.txt", ios::app);
					int n = depth(head) - 1;
					for (int i = 0; i <= n; i++) {
						copyTree(head, outfile, i);
					}
					reHash(head);
				}
				}
				//if (num == 4) {}
				//if (num == 5) {}
				//if (num == 6) {}
				//if (num == 7) {}
				//if (num == 8) {}
				//if (num == 9) {}
				//if (num == 10) {}	
			}
		}
		if (act == "4") {
			int i = 0;
			ofstream outfile;
			cout << "Search (del): ";
			string name = "";
			cin >> name;
			search(head, name, i);
			cout << "Please enter the Hash you would like to delete: ";
			string no;
			cin >> no;
			if (no != "NULL" || "null") {
				string delName = search(head, no)->input.lastName;
				deleteOne(head, delName);
				delFile();
				outfile.open("book.txt", ios::app);
				int n = depth(head) - 1;
				for (int i = 0; i <= n; i++) {
					copyTree(head, outfile, i);
				}

				reHash(head);
			}
			
		}
		if (act == "5") { printAll(head,0);}

		if (act == "6") { 
			delTree(head);
			delFile();
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
			int n = depth(head)-1;
			ofstream outfile;
			for (int i = 0; i <= n; i++) {
				copyTree(head, outfile, i);
			}
			
		}
	}
}
//"You're going to fast"