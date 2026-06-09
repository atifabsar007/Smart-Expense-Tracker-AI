#ifndef FILEIO_H
#define FILEIO_H

#include <vector>
#include "expense.h"

using namespace std;

void saveData(string username, vector<Expense> data);
vector<Expense> loadData(string username);
void exportCSV(string username, vector<Expense> data);

#endif
