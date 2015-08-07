/*
ID: arcadyc1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    int N;
    fin >> N;

    string beads;
    fin >> beads;

    int max = 1;

    for (int i = 0; i < N; i++) {
        int count = 0;
        char current_color, other_color;
        int pointer = 0;
        while (beads[pointer] == 'w' && pointer <= N - 1) {
            pointer++;
        }
        if (pointer == N) {
            pointer--;
        }
        current_color = beads[pointer];
        other_color = current_color == 'r' ? 'b' : 'r';
        // forward
        for (int j = 0; j < N; j++) {
            if (beads[j] == other_color) {
                pointer = j;
                break;
            }
            count++;
        }
        // backward
        for (int k = N - 1; k >= pointer; k--) {
            if (beads[k] == current_color) {
                break;
            }
            count++;
        }
        if (count > max) {
            max = count;
        }
        char temp_first_char = beads[0];
        beads.erase(beads.begin());
        beads.push_back(temp_first_char);
    }

    cout << max << endl;

    fout << max << endl;
}
