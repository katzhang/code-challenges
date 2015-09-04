/*
ID: arcadyc1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

char convert_number_to_char(const int& number) {
    if (number > 9) {
        return (char)(55 + number);
    } else {
        return (char)(48 + number);
    }
};

string convert_given_base(const int& base, const int& number) {
    int start = number;
    vector<int> mods;
    while(start / base) {
        int mod = start % base;
        mods.push_back(mod);
        start = start / base;
    }

    mods.push_back(start % base);
    string result;

    for (int i = mods.size() - 1; i >= 0 ; --i) {
        result += convert_number_to_char(mods[i]);
    }
    return result;
}

bool is_palindromic(const string& str) {
    string rev;
    for (int i = str.length() - 1; i >= 0; --i) {
        rev += str[i];
    }

    return str.compare(rev) == 0;
}

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");

    int base;
    fin >> base;

    for (int i = 1; i <= 300; ++i) {
        string based_squared = convert_given_base(base, i * i);
        if (is_palindromic(based_squared)) {
            fout << convert_given_base(base, i) << " " << based_squared << endl;
        }
    }
}
