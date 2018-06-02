#include <iostream>
#include <fstream>
using namespace std;
#include "studybuddy.h"

Schedule::Schedule() {
    name = "";
    block = "";
}

Schedule::Schedule(string userName, string userBlock) {
    name = userName;
    block = userBlock;
}

void Schedule::read() {
	cout << "\nEnter your first name and last name initial: ";
    cin >> ws;
    getline(cin, name);
	
    isValid(name);
	cout << "\nList what sessions blocks you are available for: ";
    cin >> ws;
    getline(cin, block);
	isValid(block);
}

void Schedule::read(ifstream& fin) {
    fin >> ws;
    getline(fin, name);
    fin >> ws;
    getline(fin, block);
}

void Schedule::print() const{
        cout << name << " " << block << endl;
}

string Schedule::getName() const {
    return name;
}

string Schedule::getBlock() const {
    return block;
}

void Schedule::isValid(string& b) {
    char response = 'y';
    cout << "Is this correct? " << b;
    cout << "\n(y/n): ";
    cin >> response;
    while (response != 'y') {
        cout << "Please enter it correctly: ";
        cin >> ws;
		getline(cin, b);
        cout << "Is this correct now? " << b;
        cout << "\n(y/n): ";
        cin >> response;
    }
}