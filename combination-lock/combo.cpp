/*
ID: arcadyc1
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool isValid(int num_true, int num_test, int MAX, const vector<int> digits) {
	int lo_index = MAX + num_true - 1 - 2;
	int hi_index = MAX + num_true - 1 + 2;
	bool found = false;
	for (int i = lo_index; i <= hi_index; ++i) {
		if (num_test == digits[i]) {
			found = true;
			break;
		}
	}
	return found;
}

int main() {
	ofstream fout ("combo.out");
    ifstream fin ("combo.in");
    int MAX;
    int LEN = 3;
    vector<vector<int> > combos;
    vector<int> JOHN_COMBO;
    vector<int> MASTER_COMBO;
    fin >> MAX;
    vector<int> digits;
    if (MAX != 1) {
    	for (int j = 0; j < 3; ++j) {
	    	for (int i = 1; i <= MAX; ++i) {
	    		digits.push_back(i);
	    	}
    	}
    } else {
    	digits.push_back(1);
    }

    for (int i = 0; i < LEN; ++i) {
		int dial;
		fin >> dial;
		JOHN_COMBO.push_back(dial);
		cout << dial << endl;
    }
    for (int i = 0; i < LEN; ++i) {
		int dial;
		fin >> dial;
		MASTER_COMBO.push_back(dial);
		cout << dial << endl;
    }

    for (int i = 1; i <= MAX; ++i) {
    	for (int j = 1; j <= MAX; ++j) {
    		for (int k = 1; k <= MAX; ++k) {
    			if (isValid(JOHN_COMBO[0], i, MAX, digits) 
    				&& isValid(JOHN_COMBO[1], j, MAX, digits)
    				&& isValid(JOHN_COMBO[2], k, MAX, digits)) {
    				int valid_combo[] = {i, j, k};
					combos.push_back(vector<int> (valid_combo, valid_combo + sizeof(valid_combo) / sizeof(int)));
					continue;
    			}
    			if (isValid(MASTER_COMBO[0], i, MAX, digits) 
    				&& isValid(MASTER_COMBO[1], j, MAX, digits)
    				&& isValid(MASTER_COMBO[2], k, MAX, digits)) {
    				int valid_combo[] = {i, j, k};
    				combos.push_back(vector<int> (valid_combo, valid_combo + sizeof(valid_combo) / sizeof(int)));
    			}
    		}
    	}
    }

    cout << "combos size: " << combos.size() << endl;
    fout << combos.size() << endl;

}