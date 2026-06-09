#ifndef TRACKER_H
#define TRACKER_H

#include <vector>
#include <stack>
#include <string>
#include "expense.h"

using namespace std;

class Tracker {
public:
    vector<Expense> expenses;
    stack<Expense> history;

    void addExpense(string category, double amount);
    void showReport();
    void undoLast();
};

#endif
