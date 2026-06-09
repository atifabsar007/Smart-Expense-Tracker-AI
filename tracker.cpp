#include "tracker.h"
#include <iostream>
#include <map>

using namespace std;

Tracker::Tracker(string user) {
    username = user;
    budget = 0;
}

void Tracker::addExpense(string category, double amount) {
    expenses.push_back({category, amount});
}

void Tracker::setBudget(double b) {
    budget = b;
}

double Tracker::getTotal() {
    double sum = 0;
    for (auto &e : expenses) sum += e.amount;
    return sum;
}

vector<Expense> Tracker::getAll() {
    return expenses;
}

void Tracker::showReport() {
    map<string, double> mp;
    double total = getTotal();

    cout << "\n📊 REPORT FOR " << username << "\n";

    for (auto &e : expenses)
        mp[e.category] += e.amount;

    for (auto &x : mp)
        cout << x.first << " -> " << x.second << "\n";

    cout << "-----------------\n";
    cout << "Total: " << total << "\n";
    cout << "Budget: " << budget << "\n";

    if (budget > 0 && total > budget)
        cout << "⚠ OVER BUDGET!\n";
}
