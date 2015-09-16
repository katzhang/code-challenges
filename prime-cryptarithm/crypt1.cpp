/*
ID: arcadyc1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool hasDigit(int digit, int number) {
	bool result = false;
	int n = 0;
	while (number > 0) {
		n = number % 10;
		number = number / 10;
		if (n == digit) {
			result = true;
			break;
		}
	}
	return result;
}

bool isValid(const vector<int>& invalid_digits, int number) {
	bool result = true;
	for (int i = 0; i < invalid_digits.size(); ++i) {
		if (hasDigit(invalid_digits[i], number)) {
			result = false;
			break;
		}
	}
	return result;
}

int main() {
	ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");

    int N;
    int result = 0;
    fin >> N;
    vector<int> valid_digits, invalid_digits;

    for(int i = 0; i < N; ++i) {
		int digit;
		fin >> digit;
		valid_digits.push_back(digit);
		cout << digit << endl;
    }

    for(int i = 0; i <= 9; ++i) {
    	bool match = false;
    	for (int j = 0; j < N; ++j) {
    		if (i == valid_digits[j]) {
    			match = true;
    			break;
    		}
    	}
    	if (!match) {
    		invalid_digits.push_back(i);
    	}
    }

    for (int i = 100; i <= 999 ; ++i) {
    	for (int j = 10; j <= 99; ++j) {
    		int a = j % 10;
    		int b = j / 10;
    		int pp_1 = a * i;
    		int pp_2 = b * i;
    		if (isValid(invalid_digits, j) 
    			&& isValid(invalid_digits, i) 
    			&& isValid(invalid_digits, pp_1) && (pp_1 < 1000)
    			&& isValid(invalid_digits, pp_2) && (pp_2 < 1000)
    			&& isValid(invalid_digits, (pp_1 + pp_2 * 10)) && ((pp_1 + pp_2 * 10) < 10000)) {
    			cout << "i: " << i << endl;
    			cout << "j: " << j << endl;
    			cout << "pp1: " << pp_1 << endl;
    			cout << "pp2: " << pp_2 << endl;
    			cout << "(pp_1 + pp_2) % 10000): " << (pp_1 + pp_2 * 10) % 10000 << endl;
    			++result;
    		}
    	}
    }

    fout << result << endl;



}

