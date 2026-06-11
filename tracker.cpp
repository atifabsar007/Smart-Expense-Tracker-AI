#include "tracker.h"
#include <iostream>
#include <map>

using namespace std;

Tracker::Tracker(string user) {
    username = user;
    budget = 0;
    counter = 0;
}

void Tracker::setBudget(double b) {
    budget = b;
}

void Tracker::addExpense(string category, double amount, string note) {

    counter++;

    Expense e;
    e.transactionId = "TXN-" + to_string(counter);
    e.category = category;
    e.amount = amount;
    e.note = note;

    expenses.push_back(e);
}

double Tracker::getTotal() {
    double sum = 0;

    for (auto &e : expenses)
        sum += e.amount;

    return sum;
}

vector<Expense> Tracker::getAll() {
    return expenses;
}

void Tracker::showReport() {

    map<string, double> mp;
    double total = getTotal();

    cout << "\n====================\n";
    cout << " EXPENSE REPORT\n";
    cout << "====================\n";

    for (auto &e : expenses)
        mp[e.category] += e.amount;

    string top;
    double maxv = 0;

    for (auto &x : mp) {
        cout << x.first << " -> " << x.second << "\n";

        if (x.second > maxv) {
            maxv = x.second;
            top = x.first;
        }
    }

    cout << "--------------------\n";
    cout << "TOTAL: " << total << "\n";

    cout << "\n📊 INSIGHTS:\n";
    cout << "- Top Category: " << top << "\n";

    if (budget > 0) {
        double percent = (total / budget) * 100;

        cout << "- Budget Used: " << percent << "%\n";

        if (total > budget)
            cout << "⚠ OVER BUDGET!\n";
    }
}
