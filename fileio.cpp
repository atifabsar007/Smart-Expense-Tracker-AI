#include "fileio.h"
#include <fstream>

void saveData(string username, vector<Expense> data) {
    ofstream file(username + "_data.txt");

    for (auto &e : data)
        file << e.category << " " << e.amount << "\n";
}

vector<Expense> loadData(string username) {
    vector<Expense> data;
    ifstream file(username + "_data.txt");

    string c;
    double a;

    while (file >> c >> a)
        data.push_back({c, a});

    return data;
}

void exportCSV(string username, vector<Expense> data) {
    ofstream file(username + "_report.csv");

    file << "Category,Amount\n";

    for (auto &e : data)
        file << e.category << "," << e.amount << "\n";
}
