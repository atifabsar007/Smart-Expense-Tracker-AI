#include <fstream>
#include "expense.h"
#include <vector>

using namespace std;

void saveData(vector<Expense> &expenses) {
    ofstream file("data.txt");

    for (auto &e : expenses) {
        file << e.category << " " << e.amount << "\n";
    }

    file.close();
}

vector<Expense> loadData() {
    vector<Expense> expenses;
    ifstream file("data.txt");

    string cat;
    double amt;

    while (file >> cat >> amt) {
        expenses.push_back({cat, amt});
    }

    file.close();
    return expenses;
}
