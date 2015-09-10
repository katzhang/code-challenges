/*
ID: arcadyc1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

string bigGap(string & stalls) {
    int biggestGap = 0;
    int gapStart = 0;
    int gapEnd = 0;

    int S = stalls.length();

    for(int i = 0; i < S; ++i) {
        int gapLen = 0;
        int curr_gapStart = i; //Used when removing the gap from the string

        int j = i;
        while(stalls[j] == '0'){
            gapLen++;
            j++;
        }
        int curr_gapEnd = j;
        if (gapLen > biggestGap) {
            biggestGap = gapLen;
            gapStart = curr_gapStart;
            gapEnd = curr_gapEnd;
        }
        i = j;
    }

    stalls = stalls.substr(0, gapStart) + stalls.substr(gapEnd, S);
    cout << stalls << endl;
    return stalls;
}


int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");

    int M, S, C;
    fin >> M >> S >> C;

    // 0 is not occupied, 1 is occupied
    string stalls;

    for(int i = 0; i < S; ++i){ //sets up initial string with all 0's
        stalls += "0";
    }
    for(int i = 0; i < C; ++i){
        int occupiedNumber;
        fin >> occupiedNumber;
        stalls[occupiedNumber - 1] = '1';
    }

    int start = 0, end = 0;
    for(int i = 0; i < S; ++i){ //first one that is occupied
        if(stalls[i] == '1'){
            start = i;
            break;
        }
    }
    for(int i = S; i > 0; --i){ //last one that is occupied
        if(stalls[i - 1] == '1'){
            end = i;
            break;
        }
    }

    stalls = stalls.substr(start, end - start);

    for(int i = 0; i < M - 1; ++i){ //splits boards M - 1 times (M boards at end)
        bigGap(stalls);
    }

    fout << stalls.length() << endl;
}
