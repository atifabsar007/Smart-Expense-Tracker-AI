#include "analytics.h"
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

  void Tracker::showReport() {

    Analytics analytics;

    double total = analytics.totalSpent(expenses);
    string top = analytics.topCategory(expenses);
    double avg = analytics.averageSpend(expenses);

    map<string, double> mp;

    cout << "\n====================\n";
    cout << " EXPENSE REPORT\n";
    cout << "====================\n";

    // breakdown
    for (auto &e : expenses)
        mp[e.category] += e.amount;

    for (auto &x : mp)
        cout << x.first << " -> " << x.second << "\n";

    cout << "--------------------\n";
    cout << "TOTAL: " << total << "\n";

    if (budget > 0) {
        double percent = (total / budget) * 100;
        cout << "Budget Used: " << percent << "%\n";

        if (total > budget)
            cout << "⚠ OVER BUDGET!\n";
    }

    // 🔥 ANALYTICS ENGINE OUTPUT
    cout << "\n📊 ANALYTICS:\n";
    cout << "- Top Category: " << top << "\n";
    cout << "- Average Expense: " << avg << "\n";
    }
}
