/*
ID: arcadyc1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int N;

char **rotate90Degrees(char **before, int N) {
    char **rotated;
    rotated = new char *[N];
    for (int i = 0; i < N; i++) {
        rotated[i] = new char[N];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotated[i][j] = before[N - 1 - j][i];
        }
    }
    return rotated;
}

char **reflectHorizontaly(char **before, int N) {
    char **reflected;
    reflected = new char *[N];
    for (int i = 0; i < N; i++) {
        reflected[i] = new char[N];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            reflected[i][j] = before[i][N - 1 - j];
        }
    }
    return reflected;
}

bool areSameMatrices(char **one, char **two, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (one[i][j] != two[i][j]) {
                return false;
            }
        }
    }
    return true;
}


int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");

    fin >> N;

    char **before;
    char **after;
    char **transformed;

    before = new char *[N];
    after = new char *[N];
    transformed = new char *[N];

    bool rotateMatchAfter = true;

    for (int i = 0; i < N; i++) {
        before[i] = new char[N];
        after[i] = new char[N];
        transformed[i] = new char[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char currentChar;
            fin >> currentChar;
            before[i][j] = currentChar;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char currentChar;
            fin >> currentChar;
            after[i][j] = currentChar;
        }
    }

    cout << "before: " << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << before[i][j];
        }
        cout << endl;
    }

    cout << "after: " << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << after[i][j];
        }
        cout << endl;
    }


    // Rotate 90 degrees clockwise
    transformed = rotate90Degrees(before, N);
    if (areSameMatrices(after, transformed, N)) {
        fout << "1" << endl;
        cout << "1" << endl;
        return 0;
    }

    // Rotate 180 degrees clockwise
    transformed = rotate90Degrees(transformed, N);

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << transformed[i][j];
    //     }
    //     cout << endl;
    // }
    if (areSameMatrices(after, transformed, N)) {
        fout << "2" << endl;
        cout << "2" << endl;
        return 0;
    }

    // Rotate 270 degrees clockwise
    transformed = rotate90Degrees(transformed, N);
    if (areSameMatrices(after, transformed, N)) {
        fout << "3" << endl;
        cout << "3" << endl;
        return 0;
    }

    // Reflect horizontally 
    transformed = reflectHorizontaly(before, N);
    if (areSameMatrices(after, transformed, N)) {
        fout << "4" << endl;
        cout << "4" << endl;
        return 0;
    }

    // Combination #1
    transformed = rotate90Degrees(before, N);
    transformed = reflectHorizontaly(transformed, N);
    if (areSameMatrices(after, transformed, N)) {
        fout << "5" << endl;
        cout << "5" << endl;
        return 0;
    }

    // Combination #2
    transformed = rotate90Degrees(before, N);
    transformed = rotate90Degrees(transformed, N);
    transformed = reflectHorizontaly(transformed, N);
    if (areSameMatrices(after, transformed, N)) {
        fout << "5" << endl;
        cout << "5" << endl;
        return 0;
    }

    // Combination #3
    transformed = rotate90Degrees(before, N);
    transformed = rotate90Degrees(transformed, N);
    transformed = rotate90Degrees(transformed, N);
    transformed = reflectHorizontaly(transformed, N);
    if (areSameMatrices(after, transformed, N)) {
        fout << "5" << endl;
        cout << "5" << endl;
        return 0;
    }

    // No change
    if (areSameMatrices(after, before, N)) {
        fout << "6" << endl;
        cout << "6" << endl;
        return 0;
    }


    fout << "7" << endl;
    cout << "7" << endl;
}
