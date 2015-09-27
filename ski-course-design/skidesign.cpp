/*
ID: arcadyc1
PROG: skidesign
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX_DIFF 17

using namespace std;

int calculateCost(int ideal_short, const vector<int>& heights) {
    int cost = 0;
    int ideal_long = ideal_short + MAX_DIFF;

    for (int i = 0; i < heights.size(); ++i) {
        if (heights[i] < ideal_short) {
            cost += ((ideal_short - heights[i]) * (ideal_short - heights[i]));
        } else if (heights[i] > ideal_long) {
            cost += ((heights[i] - ideal_long) * (heights[i] - ideal_long));
        }
    }

    return cost;
}

int main() {
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");

    int N, shortest, tallest, short_min, short_max;
    vector<int> costs;
    vector<int> heights;
    fin >> N;
    for (int i = 0; i < N; ++i) {
        int height;
        fin >> height;
        heights.push_back(height);
    };

    sort(heights.begin(), heights.end());

    shortest = heights[0];
    tallest = heights[N - 1];

    if ((tallest - shortest) > MAX_DIFF) {
        short_min = shortest;
        short_max = tallest - MAX_DIFF;
        while(short_min <= short_max) {
            int cost = calculateCost(short_min, heights);
            costs.push_back(cost);
            short_min++;
        }
        sort(costs.begin(), costs.end());
        fout << costs[0] << endl;
    } else {
        fout << 0 << endl;
    }


}