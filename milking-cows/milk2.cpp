/*
ID: arcadyc1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int combine(int* timeTable, int N) {
    int found = 0;
    for (int i = 0; i < 2 * N - 1; i += 2) {
        for (int j = 0; j < 2 * N - 1; j += 2) {
            if (i != j) {
                if (timeTable[i + 1] >= timeTable[j] && timeTable[i] < timeTable[j] && timeTable[j + 1] > timeTable[i + 1]) {
                    found = 1;
                    timeTable[i + 1] = timeTable[j + 1];
                    timeTable[j] = timeTable[j + 1] = 0;
                }
            }
        }
    }
    return found;
}

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

    int N;
    fin >> N;

    int max = 0;
    int max2 = 0;

    int havingCowInterval, noCowInterval = 0;
    int timeTable[2 * N - 1];
    int starts[ N - 1];

    for (int i = 0; i < 2*N - 1; i += 2) {
        cout << "i : " << i << endl;
        int start, end;
        fin >> start;
        fin >> end;
        timeTable[i] = start;
        timeTable[i + 1] = end;
        starts[i / 2] = start;
    }

    for (int i = 0; i < 2*N - 1; i += 2) {
        cout << timeTable[i] << " " << timeTable[i + 1] << endl;
    }
    while (combine(timeTable, N)) {
        cout << "while combining" << endl;
    }

    for (int i = 0; i < 2*N - 1; i += 2) {
        if (timeTable[i + 1] - timeTable[i] > max) {
            max = timeTable[i + 1] - timeTable[i];
        }
        cout << timeTable[i] << " " << timeTable[i + 1] << endl;
    }

    for (int i = 0; i < 2 * N - 1; i += 2) {
        // for (int j = 0; j < 2 * N - 1; j += 2) {
        //     if (i != j && timeTable[i] != 0 && timeTable[j] != 0 && timeTable[j] - timeTable[i + 1] > max2) {
        //         cout << "timeTable[j]: " << timeTable[j] << endl;
        //         cout << "timeTable[i+1]: " << timeTable[i+1] << endl;
        //         max2 = timeTable[j] - timeTable[i + 1];
        //     }
        // }
        
    }


    cout << max << endl;
    cout << max2 << endl;

    fout << max << " " << max2 << endl;
}
