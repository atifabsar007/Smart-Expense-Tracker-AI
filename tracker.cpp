#include "tracker.h"
#include "analytics.h"
#include <iostream>
#include <map>

using namespace std;

// Constructor
Tracker::Tracker(string user) {
    username = user;
    budget = 0;
    counter = 0;
}

// Set budget
void Tracker::setBudget(double b) {
    budget = b;
}

// Add expense
void Tracker::addExpense(string category, double amount, string note) {

    counter++;

    Expense e;
    e.transactionId = "TXN-" + to_string(counter);
    e.category = category;
    e.amount = amount;
    e.note = note;

    expenses.push_back(e);
}

// Total calculation
double Tracker::getTotal() {

    double sum = 0;

    for (auto &e : expenses)
        sum += e.amount;

    return sum;
}

// Return all expenses
vector<Expense> Tracker::getAll() {
    return expenses;
}

// =======================
// SHOW REPORT (FIXED)
// =======================
void Tracker::showReport() {

    Analytics analytics;

    double total = analytics.totalSpent(expenses);
    string top = analytics.topCategory(expenses);
    double avg = analytics.averageSpend(expenses);

    map<string, double> mp;

    cout << "\n====================\n";
    cout << " EXPENSE REPORT\n";
    cout << "====================\n";

    // category breakdown
    for (auto &e : expenses) {
        mp[e.category] += e.amount;
    }

    for (auto &x : mp) {
        cout << x.first << " -> " << x.second << "\n";
    }

    cout << "--------------------\n";
    cout << "TOTAL: " << total << "\n";

    // budget check
    if (budget > 0) {
        double percent = (total / budget) * 100;

        cout << "Budget Used: " << percent << "%\n";

        if (total > budget)
            cout << "⚠ OVER BUDGET!\n";
    }

    // analytics section
    cout << "\n📊 ANALYTICS:\n";
    cout << "- Top Category: " << top << "\n";
    cout << "- Average Expense: " << avg << "\n";
}
