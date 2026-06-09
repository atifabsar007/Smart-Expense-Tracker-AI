#include <iostream>
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

    cout << "\n🤖 AI Budget Advice:\n";

    if (sum == 0) return;

    for (auto &t : total) {
        double percent = (t.second / sum) * 100;

        if (percent > 50) {
            cout << "- Critical: " << t.first << " uses " << percent << "% of budget\n";
        } else if (percent > 30) {
            cout << "- Warning: High spending in " << t.first << "\n";
        }
    }

    cout << "- Tip: Maintain diversified spending habits\n";
}
