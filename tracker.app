#include "tracker.h"
#include <iostream>

using namespace std;

void Tracker::addExpense(string category, double amount) {
    Expense e = {category, amount};
    expenses.push_back(e);
    history.push(e);

    cout << "✔ Expense added successfully!\n";
}

void Tracker::undoLast() {
    if (!history.empty()) {
        Expense last = history.top();
        history.pop();
        expenses.pop_back();

        cout << "↩ Last expense removed: " << last.category << " - " << last.amount << "\n";
    } else {
        cout << "No history to undo!\n";
    }
}

void Tracker::showReport() {
    map<string, double> total;
    double sum = 0;

    cout << "\n📊 Expense Report:\n";

    for (auto &e : expenses) {
        total[e.category] += e.amount;
        sum += e.amount;
    }

    for (auto &t : total) {
        cout << t.first << " → " << t.second << "\n";
    }

    cout << "----------------------\n";
    cout << "Total Spent: " << sum << "\n";

    cout << "\n🧠 Smart Insights:\n";

    for (auto &t : total) {
        if (sum > 0 && t.second / sum > 0.4) {
            cout << "⚠ Overspending detected in " << t.first << "\n";
            cout << "👉 Suggestion: Try reducing " << t.first << " expenses\n";
        }
    }
}
