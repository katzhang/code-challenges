/*
ID: arcadyc1
PROG: dualpal
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
    if (str[0] == '0' || str[str.length() - 1] == '0') {
        return false;
    }
    string rev;
    for (int i = str.length() - 1; i >= 0; --i) {
        rev += str[i];
    }

    return str.compare(rev) == 0;
}

int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");

    int N, S;
    fin >> N;
    fin >> S;

    int number_counter = 0;
    for (int i = S + 1;; ++i) {
        int pal_counter = 0;
        for (int j = 2; j <= 10; ++j) {
            string converted = convert_given_base(j, i);
            if (is_palindromic(converted)) {
                ++pal_counter;
            }
            if (pal_counter >= 2) {
                fout << i << endl;
                ++number_counter;
                break;
            }
        }
        if (number_counter >= N) {
            break;
        }
    }
}
