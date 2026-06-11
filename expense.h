#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
using namespace std;

struct Expense {
    string transactionId;
    string category;
    double amount;
    string note;
};

#endif
