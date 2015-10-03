/*
ID: arcadyc1
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

bool contains(const vector<int>& s, int n) {
    for (int i = 0; i < s.size(); ++i) {
    	if (s[i] == n) {
    		return true;
    	}
    	if (s[i] > n) {
    		return false;
    	}
    };
    return false;
}

vector<int> computeProg(int a, int b, int n) {
	vector<int> prog;
	for (int i = 0; i < n; ++i) {
		prog.push_back(a + i * b);
	}
	return prog;
}

int main() {
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
    clock_t begin = clock();

    int N, M;
    fin >> N >> M;
    int MAX_BISQUARES = M * M + M * M;
    vector<int> bisquares;
    vector<int> bisquare_diffs;
    vector<int> result;

    for (int i = 0; i <= M; ++i) {
    	for (int j = i + 1; j <= M; ++j) {
    		bisquares.push_back(i * i + j * j);
    	}
    	bisquares.push_back(i * i + i * i);
    };

    sort(bisquares.begin(), bisquares.end());

    for (int i = 0; i < bisquares.size(); ++i) {
    	for (int j = i + 1; j < bisquares.size(); ++j) {
    		int diff = bisquares[j] - bisquares[i];
    		if (!contains(bisquare_diffs, diff)) {
    			bisquare_diffs.push_back(diff);
    		}
    	}
    }

    sort(bisquare_diffs.begin(), bisquare_diffs.end());
    bisquare_diffs.erase(unique(bisquare_diffs.begin(), bisquare_diffs.end()), bisquare_diffs.end());

    int everValid = false;

    for (int j = 0; j < bisquare_diffs.size(); ++j) {
    	int b = bisquare_diffs[j];
    	if (b == 0) continue;

    	for (int i = 0; i < bisquares.size(); ++i) {
    		int a = bisquares[i];
    		bool valid = true;
    		vector<int> prog = computeProg(a, b, N);

    		for (int m = 0; m < prog.size(); ++m) {
    			if (!contains(bisquares, prog[m])) {
    				valid = false;
    				break;
    			}
    		}
    		if (valid) {
    			if (!everValid) {
    				everValid = true;
    			}
    			fout << a << " " << b << endl;
    		}
    	}
    }
    if (!everValid) {
    	fout << "NONE" << endl;
    }

    clock_t end = clock();
    double elapsed = double(end - begin);
    cout << "time elapsed: " << elapsed << endl;

}

