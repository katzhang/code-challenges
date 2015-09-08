/*
ID: arcadyc1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Farmer {
    int price;
    int amount;
};

bool sortFarmersGivenPrice(const Farmer& f1, const Farmer& f2) {
    return f1.price < f2.price;
}

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    int totalAmount, numberOfFarmers;
    fin >> totalAmount;
    fin >> numberOfFarmers;

    vector<Farmer> farmers;

    int index = 0;
    while (index < numberOfFarmers) {
        Farmer f;
        fin >> f.price;
        fin >> f.amount;
        farmers.push_back(f);
        index++;
    }

    // before sort 
    for(int i = 0; i < farmers.size(); ++i) {
        cout << "farmer " << i << ": " << farmers[i].price << " " << farmers[i].amount << endl;
    }

    sort(farmers.begin(), farmers.end(), sortFarmersGivenPrice);

    // after sort
    for(int i = 0; i < farmers.size(); ++i) {
        cout << "farmer " << i << ": " << farmers[i].price << " " << farmers[i].amount << endl;
    }

    int totalCost = 0;

    for(int i = 0; i < farmers.size(); ++i) {
        int amountUsed = totalAmount > farmers[i].amount ? farmers[i].amount : totalAmount;
        cout << "amount used : " << amountUsed << " " << farmers[i].price << endl;
        totalCost += (amountUsed * farmers[i].price);
        cout << "total cost: " << totalCost << endl;
        totalAmount -= amountUsed;
    }

    cout << "total cost: " << totalCost << endl;
    fout << totalCost << endl;

}
