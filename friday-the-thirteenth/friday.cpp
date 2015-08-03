/*
ID: arcadyc1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int iterateMonth(int firstDayIndex, int (&dayFrequency)[7], int numOfDays) {
    int counter = firstDayIndex - 1;
    for (int i = 1; i <= numOfDays; i++) {
        ++counter;
        if (counter > 6) {
            counter = 0;
        }
        if (i == 13) {
            dayFrequency[counter]++;
        }
    }
    return (counter + 1 > 6) ? 0 : counter + 1;
}

int calculateYear(int firstDayIndex, int (&dayFrequency)[7], bool isNormalYear) {
    int normalYearMonthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leapYearMonthDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int *yearMonthDays;

    if (isNormalYear == true) {
        yearMonthDays = normalYearMonthDays;
    } else {
        yearMonthDays = leapYearMonthDays;
    }

    int firstDay = firstDayIndex;
    for (int i = 0; i < 12; i++) {
        firstDay = iterateMonth(firstDay, dayFrequency, yearMonthDays[i]);
    }
    return (firstDay > 6) ? 0 : firstDay;
}


int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int N, firstDay = 2;
    const int startingYear = 1900;
    int currentYear = 1900;

    int dayFrequency[] = {0, 0, 0, 0, 0, 0, 0};

    fin >> N;

    while (currentYear <= startingYear + N - 1) {
        // check if current year is a century year
        if (currentYear % 100 == 0) {
            if (currentYear % 400 == 0) {
                // leap year
                firstDay = calculateYear(firstDay, dayFrequency, false);
            } else {
                // normal year
                firstDay = calculateYear(firstDay, dayFrequency, true);
            }
        } else if (currentYear % 4 == 0) {
            // leap year
            firstDay = calculateYear(firstDay, dayFrequency, false);
        } else {
            // normal year
            firstDay = calculateYear(firstDay, dayFrequency, true);
        }
        currentYear++;

    }

    for (int i = 0; i < 7; i++) {
        fout << dayFrequency[i];
        if (i != 6) {
            fout << " ";
        }
    }

    fout << endl;
    
    return 0;

}