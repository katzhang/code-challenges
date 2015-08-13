/*
ID: arcadyc1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int count_element(int element, int array[], int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (array[i] == element) {
            count++;
        }
        if (element < array[i]) {
            break;
        }
    }
    return count;
}

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

    int N;
    fin >> N;

    int max = 0;
    int max2 = 0;

    int starts[N];
    int ends[N];

    for (int i = 0; i < N; i ++) {
        int start, end;
        fin >> start;
        fin >> end;
        starts[i] = start;
        ends[i] = end;
    }

    // Sort starts and ends
    std::sort(starts, starts+sizeof(starts)/sizeof(int));
    std::sort(ends, ends+sizeof(ends)/sizeof(int));

    int total_start = starts[0];
    int total_end = ends[N - 1];
    int num_start = 0;
    int num_end = 0;

    int milking_interval_max = 0;
    int milking_interval_counter = 0;
    int non_milking_interval_max = 0;
    int non_milking_interval_counter = 0;

    for (int t = total_start; t <= total_end; t++) {
        num_start += count_element(t, starts, N);
        num_end += count_element(t, ends, N);

        if (num_start > num_end) {
            // there are more than one farmer milking cows
            if (non_milking_interval_counter > non_milking_interval_max) {
                non_milking_interval_max = non_milking_interval_counter;
            }
            non_milking_interval_counter = 0;
            milking_interval_counter++;
        } else if (num_start == num_end) {
            // no body's milking cow now
            if (milking_interval_counter > milking_interval_max) {
                milking_interval_max = milking_interval_counter;
            }
            milking_interval_counter = 0;
            non_milking_interval_counter++;
        }
    }


    cout << milking_interval_max << endl;
    cout << non_milking_interval_max << endl;

    fout << milking_interval_max << " " << non_milking_interval_max << endl;
}
