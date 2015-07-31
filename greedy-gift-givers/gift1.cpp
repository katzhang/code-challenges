/*
ID: arcadyc1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
#include <vector>

using namespace std;


void calculateGifts(ifstream &fin, map<string, int> &peopleMap) {
	string giver;
	int numOfReceivers, all, leftOver, gift;
	fin >> giver;
	fin >> all >> numOfReceivers;
	if (all == 0 || numOfReceivers == 0) {
		return;
	}
	leftOver = all % numOfReceivers;
	peopleMap[giver] += (leftOver - all);
	gift = all / numOfReceivers;
	vector<string> receivers(numOfReceivers);
    for (int i = 0; i < numOfReceivers; i++) {
    	fin >> receivers[i];
    	peopleMap[receivers[i]] += gift;
    }
}

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int numOfPeople;
    fin >> numOfPeople;
    vector<string> people(numOfPeople);
    map<string, int> peopleMap;

    for (int i = 0; i < numOfPeople; i++) {
    	fin >> people[i];
    	peopleMap.insert(pair<string, int>(people[i], 0));
    }

    for (int i = 0; i < numOfPeople; i++) {
    	calculateGifts(fin, peopleMap);
    }

    for (int i = 0; i < numOfPeople; i++) {
    	fout << people[i] << " " << peopleMap[people[i]] << endl;
    }

    return 0;
}