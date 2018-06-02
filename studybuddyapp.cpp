#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

#include "studybuddy.h"

const int DAYS_SIZE = 5;
const int BLOCKS_SIZE = 6;
const int CS_CLASS = 95076;
const int ENGL_CLASS = 95012;
vector<Schedule> classList;

void isValid(int &a);
void readList(vector<Schedule>& classList, string fileName);
void readList(string sched, vector<Schedule>& classList);
int menu(int c);
void menuChoice();

int main() {
	vector<string>days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
	vector<string>blocks = {"8am-10am", "10am-12pm", "12pm-2pm", "2pm-4pm", "4pm-6pm", "6pm-8pm"};
    int classCode = 0, choice = 0; 
    string userName = "", freeSched = "";
    cout << "Enter provided class code: ";
    cin >> classCode;
 
    isValid(classCode);
   
    for (int i = 0; i < DAYS_SIZE; i ++) {
        cout << setw(10) << left << days[i] << " "; 
        for (int j = 0; j < BLOCKS_SIZE; j++) {
            cout << setw(2) << right << "[" << i << j << "]" << blocks[j] << "  ";
        }
        cout << endl;
    }
    Schedule temp;
    cout << "\nEnter your first name and last name initial: ";
    cin >> ws;
    getline(cin, userName);
    temp.isValid(userName);
	
    cout << "\nList what session block you are available for: ";
    cin >> freeSched;
	temp.isValid(freeSched);

    readList(freeSched, classList);
    
	menu(choice);
    return 0;
}

void isValid(int &a) {
    while (cin.fail()) {
        cout << "You must only enter digits, not words.";
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nEnter a valid code: ";
        cin >> a;
    } 
    while (a != CS_CLASS && a!= ENGL_CLASS) {
        cout << "Please enter a valid code: ";
        cin >> a;
        while (cin.fail()) {
            cout << "You must only enter digits, not words.";
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nEnter a valid code: ";
            cin >> a;
        } 
    }
    if (a == CS_CLASS) {
        readList(classList, "csclass.txt");
    } else if (a == ENGL_CLASS) {
        readList(classList, "csclass.txt");
    }
}

void readList(vector<Schedule>& classList, string fileName) {
    ifstream fin(fileName);
    if (fin.fail()) {
        cout << "File failed to open.\n";
        exit(-1);
    }
    while (fin.good()) {
        Schedule temp;
        temp.read(fin);
        if (fin.good()) {
            classList.push_back(temp);
        }
    }
}

void readList(string sched, vector<Schedule>& classList) {
    for (unsigned i = 0; i < classList.size(); i++) {
        string temp = classList[i].getBlock();
        cout << endl;
        if (sched == temp) {
            cout << "You can meet with " << classList[i].getName() << " at session " << sched;
        } else {
            cout << "Sorry, " << classList[i].getName() << " is not available to meet with you.";
        }
    }
}

int menu(int c){
	while (c == 0) {
		cout << endl << "\n1. Exit program"
			 << "\n2. Extra code" << endl
             << "Choose:  ";
		cin >> c;
    }
    if (c == 1) {
        cout << "\nThank you for using StudyBuddy. Good luck studying!!!";
        exit (-1);
    } else if (c == 2){
        menuChoice();
    }
    return c;
}

void menuChoice() {
    cout << "- setprecision(): "
         << "\nAnswer of 3.14*3.14 should be 9.86 --> " << "3.14*3.14 = "
         << fixed << setprecision(2) << 3.14*3.14; 
    cout << "\n\nThank you for using StudyBuddy. Good luck studying!!!";
    exit (-1);
}