#ifndef STUDYBUDDY_H
#define STUDYBUDDY_H

#include <string>
using namespace std;

class Schedule {
    public:
        Schedule();
        Schedule(string userName, string userBlock);
        void read();
        void read(ifstream& fin);
        void print() const;
		string getName() const;
        string getBlock() const;
        void isValid(string& b);
    private:
        string name;
        string block;
};

#endif