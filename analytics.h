#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <vector>
#include "expense.h"

using namespace std;

class Analytics {
public:
    double totalSpent(const vector<Expense>& expenses);
    string topCategory(const vector<Expense>& expenses);
    double averageSpend(const vector<Expense>& expenses);
    double categoryPercentage(const vector<Expense>& expenses, string category);
};

#endif
