#include "tracker.h"
#include <iostream>
#include <map>

using namespace std;

void Tracker::addExpense(string category, double amount) {
    Expense e = {category, amount};
    expenses.push_back(e);
    history.push(e);

    cout << "✔ Expense added successfully!\n";
}

void Tracker::undoLast() {
    if (!history.empty()) {
        history.pop();
        expenses.pop_back();
        cout << "↩ Last expense removed!\n";
    } else {
        cout << "⚠ No history to undo!\n";
    }
}

void Tracker::showReport() {
    map<string, double> total;
    double sum = 0;

    cout << "\n📊 EXPENSE REPORT\n";

    for (auto &e : expenses) {
        total[e.category] += e.amount;
        sum += e.amount;
    }

    for (auto &t : total) {
        cout << t.first << " → " << t.second << "\n";
    }

    cout << "----------------------\n";
    cout << "Total Spending: " << sum << "\n";

    cout << "\n🧠 SMART INSIGHTS\n";

    for (auto &t : total) {
        double percent = (sum == 0) ? 0 : (t.second / sum) * 100;

        if (percent > 50) {
            cout << "⚠ High spending in " << t.first << " (" << percent << "%)\n";
            cout << "👉 Suggestion: Reduce " << t.first << " expenses\n";
        }
        else if (percent > 30) {
            cout << "⚠ Moderate spending in " << t.first << "\n";
        }
    }
}
