/*
ID: arcadyc1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAXDIGIT 12

string convertNameToNumber(const string &name) {
    string number = "";
    for (int i = 0; i < name.length(); i++) {
        if (name[i] == 'Q' || name[i] == 'Z') {
            return "1";
        }
        if (name[i] < 'Q') {
            number += ((name[i] - 'A') / 3) + '2';
        } else {
            number += ((name[i] - 'Q') / 3) + '7';
        }
    }
    return number;
}

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream fdict ("dict.txt");

    string number;

    fin >> number;

    bool foundMatchedNumber = false;

    string name;
    while (fdict >> name) {
        if (name.length() == number.length() && convertNameToNumber(name) == number) {
            foundMatchedNumber = true;
            cout << name << endl;
            fout << name << endl;
        }
    }

    if (!foundMatchedNumber) {
        cout << "NONE" << endl;
        fout << "NONE" << endl;
    }
}
