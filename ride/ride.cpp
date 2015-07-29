/*
ID: arcadyc1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getStringProduct(string str) {
	int charNum, product;
	product = 1;
	for (int i = 0; i < str.length(); i++) {
		charNum = str[i] - 'A' + 1;
		product *= charNum;
	}
	return product;
}

int main() {
    ofstream fout ("ride.out");
    ifstream infile("ride.in");
    string comet, group;
    getline(infile, comet);
    getline(infile, group);
    int cometResult = getStringProduct(comet) % 47;
    int groupResult  = getStringProduct(group) % 47;
    if (cometResult == groupResult) {
    	fout << "GO" << endl;
    } else {
    	fout << "STAY" << endl;
    }
    return 0;
}