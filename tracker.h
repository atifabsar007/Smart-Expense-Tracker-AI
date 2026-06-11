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

    void addExpense(string category, double amount, string note);
    void showReport();
    void setBudget(double b);
    double getTotal();
    vector<Expense> getAll();
};

#endif
