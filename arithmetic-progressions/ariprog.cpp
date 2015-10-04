/*
ID: arcadyc1
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


#define MAX_M 250
#define MAX_N 25

using namespace std;

struct prog {
    int a;
    int b;
    bool operator < (const prog& other) const{
        return b < other.b;
    }
};

int main() {
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");

    int N, M;
    fin >> N >> M;
    int MAX_BISQUARE = M * M * 2;
    vector<prog> progs;

    bool isBisquare[MAX_M * MAX_M * 2 + 10] = {false};

    for (int i = 0; i <= M; ++i) {
    	for (int j = 0; j <= M; ++j) {
    		int bisquare = i * i + j * j;
    		isBisquare[bisquare] = true;
    	}
    };


    for (int a = 0; a < MAX_BISQUARE; ++a) {
    	if (isBisquare[a]) {
    		for (int b = 1; b < (MAX_BISQUARE - a)/ N + 2 * N; ++b) {
	    		bool isValid = true;
	    		for (int n = 0; n < N; ++n) {
	    			int prog = a + n * b;
	    			if (!isBisquare[prog]) {
	    				isValid = false;
	    				break;
	    			}
	    		}
	    		if (isValid) {
	    			prog p;
	    			p.a = a;
	    			p.b = b;
	    			progs.push_back(p);
	    		}
    		}
    	}
    }

    if(progs.size() != 0){
        sort(progs.begin(), progs.end());
        for(int i = 0; i < progs.size(); ++i){
            fout << progs[i].a << " " << progs[i].b << endl;
        }
    } else {
    	fout << "NONE" << endl;
    }


}

