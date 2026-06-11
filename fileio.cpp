#include "fileio.h"
#include <fstream>

void saveData(string username, vector<Expense> data) {

    ofstream file("data/" + username + ".txt");

    for (auto &e : data) {
        file << e.transactionId << " "
             << e.category << " "
             << e.amount << " "
             << e.note << "\n";
    }
}

vector<Expense> loadData(string username) {

    vector<Expense> data;
    ifstream file("data/" + username + ".txt");

    string id, cat, note;
    double amt;

    while (file >> id >> cat >> amt >> note) {

        Expense e;
        e.transactionId = id;
        e.category = cat;
        e.amount = amt;
        e.note = note;

        data.push_back(e);
    }

    return data;
}
