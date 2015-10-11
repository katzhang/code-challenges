/*
ID: arcadyc1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define MAX_OPACITY 21

using namespace std;

bool result[MAX_OPACITY];

bool searched[MAX_OPACITY][MAX_OPACITY];

int A, B, C;

void search(int a, int b, int c) {
	if (searched[a][b]) {
		return;
	}
	searched[a][b] = true;

	if (a == 0) {
		result[c] = true;
	}

	if (a > 0 && b < B) {
		search(max(0, a + b - B), min(B, a + b), c);
	}

	if (a > 0 && c < C) {
		search(max(0, a + c - C), b, min(C, a + c));
	}

	if (b > 0 && a < A) {
		search(min(A, a + b), max(0, a + b - A), c);
	}

	if (b > 0 && c < C) {
		search(a, max(0, b + c - C), min(C, b + c));
	}

	if (c > 0 && a < A) {
		search(min(A, a + c), b, max(0, a + c - A));
	}

	if (c > 0 && b < B) {
		search(a, min(B, b + c), max(0, b + c - B));
	}
}

int main() {
	ofstream fout ("milk3.out");
	ifstream fin ("milk3.in");

	fin >> A >> B >> C;

	search(0, 0, C);

	vector<int> results;

	for (int i = 0; i < MAX_OPACITY; ++i) {
		if (result[i] == true) {
			results.push_back(i);
		}
	}
	
	for (int i = 0; i < results.size(); ++i) {
		fout << results[i];
		if (i != results.size() - 1) {
			fout << ' ';
		}
	}
	fout << endl;
}