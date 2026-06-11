#include "analytics.h"
#include <map>

double Analytics::totalSpent(const vector<Expense>& expenses) {

    double sum = 0;

    for (auto &e : expenses)
        sum += e.amount;

    return sum;
}

string Analytics::topCategory(const vector<Expense>& expenses) {

    map<string, double> mp;

    for (auto &e : expenses)
        mp[e.category] += e.amount;

    string top;
    double maxv = 0;

    for (auto &x : mp) {

        if (x.second > maxv) {
            maxv = x.second;
            top = x.first;
        }
    }

    return top;
}

double Analytics::averageSpend(const vector<Expense>& expenses) {

    if (expenses.empty())
        return 0;

    return totalSpent(expenses) / expenses.size();
}

double Analytics::categoryPercentage(
    const vector<Expense>& expenses,
    string category
) {

    double total = totalSpent(expenses);
    double catSum = 0;

    for (auto &e : expenses) {
        if (e.category == category)
            catSum += e.amount;
    }

    if (total == 0)
        return 0;

    return (catSum / total) * 100;
}
