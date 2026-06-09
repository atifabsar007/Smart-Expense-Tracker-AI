#include <iostream>
#include <vector>
#include <map>
#include "expense.h"

using namespace std;

void smartAdvice(const vector<Expense>& expenses) {
    map<string, double> total;
    double sum = 0;

    for (auto &e : expenses) {
        total[e.category] += e.amount;
        sum += e.amount;
    }

    cout << "\n🤖 AI ANALYSIS\n";

    if (sum == 0) {
        cout << "No expenses yet.\n";
        return;
    }

    for (auto &t : total) {
        double percent = (t.second / sum) * 100;

        if (percent > 60) {
            cout << "🚨 Critical: " << t.first << " dominates spending (" << percent << "%)\n";
        }
        else if (percent > 40) {
            cout << "⚠ Warning: High spending in " << t.first << "\n";
        }
    }

    cout << "💡 Tip: Try balancing your budget across categories\n";
}
