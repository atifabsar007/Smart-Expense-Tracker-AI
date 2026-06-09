#include <bits/stdc++.h>
#include "tracker.h"

using namespace std;

int main() {
    Tracker tracker;

    int choice;
    string category;
    double amount;

    while (true) {
        cout << "\n===== SMART EXPENSE TRACKER =====\n";
        cout << "1. Add Expense\n";
        cout << "2. Show Report\n";
        cout << "3. Undo Last Expense\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter category: ";
            cin >> category;
            cout << "Enter amount: ";
            cin >> amount;

            tracker.addExpense(category, amount);
        }
        else if (choice == 2) {
            tracker.showReport();
        }
        else if (choice == 3) {
            tracker.undoLast();
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
