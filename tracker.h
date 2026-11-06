#ifndef TRACKER_H
#define TRACKER_H

#include <vector>
#include <string>
#include "expense.h"

using namespace std;

class Tracker {
private:
    vector<Expense> expenses;
    double budget;
    int counter;

public:
    string username;

    Tracker(string user);

    bool addExpense(const string& category, double amount, const string& note);
    void showReport();
    void setBudget(double b);
    double getTotal();
    vector<Expense> getAll();
};

#endif
