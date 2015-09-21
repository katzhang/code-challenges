/*
ID: arcadyc1
PROG: wormhole
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
};

struct Pair {
	Point p1;
	Point p2;
};

bool points_are_equal(const Point& p1, const Point& p2) {
	return p1.x == p2.x && p1.y == p2.y;
}

bool pairs_are_equal(const Pair& pair1, const Pair& pair2) {
	return (points_are_equal(pair1.p1, pair2.p1) && points_are_equal(pair1.p2, pair2.p2))
	|| (points_are_equal(pair1.p1, pair2.p2) && points_are_equal(pair1.p2, pair2.p1));
}

int main() {
	ofstream fout ("wormhole.out");
	ifstream fin ("wormhole.in");

	int N;
	fin >> N;
	vector<Point> points;
	vector<Pair> pairs;
	vector<vector<Pair> > groups;
	for (int i = 0; i < N; ++i) {
		Point p;
		fin >> p.x >> p.y;
		points.push_back(p);
	}

	for (int i = 0; i < points.size(); ++i) {
		cout << "point: " << points[i].x << ", " << points[i].y << endl;
	}

	// all pairs
	for (int i = 0; i < points.size(); ++i) {
		for (int j = i; ++j < points.size();) {
			Pair pair;
			pair.p1 = points[i];
			pair.p2 = points[j];
			pairs.push_back(pair);
		}
	}

	for (int i = 0; i < pairs.size(); ++i) {

	}
}





