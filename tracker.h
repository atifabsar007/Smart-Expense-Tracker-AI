#ifndef TRACKER_H
#define TRACKER_H

#include "expense.h"
#include <vector>
#include <stack>
#include <map>

class Tracker {
private:
    vector<Expense> expenses;
    stack<Expense> history;

public:
    void addExpense(string category, double amount);
    void showReport();
    void undoLast();
};

#endif
