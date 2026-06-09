#include <iostream>
#include "auth.h"
#include "tracker.h"
#include "fileio.h"

using namespace std;

int main() {
    string user, pass;

    cout << "=== SMART EXPENSE TRACKER ===\n";

    cout << "Username: ";
    cin >> user;

    cout << "Password: ";
    cin >> pass;

    if (!loginUser(user, pass)) {
        cout << "User not found. Creating account...\n";
        registerUser(user, pass);
    }

    Tracker tracker(user);

    tracker.setBudget(5000);

    int choice;
    string cat;
    double amt;

    while (true) {
        cout << "\n1.Add Expense\n2.Show Report\n3.Export CSV\n4.Exit\n";
        cin >> choice;

        if (choice == 1) {
            cout << "Category: ";
            cin >> cat;
            cout << "Amount: ";
            cin >> amt;

            tracker.addExpense(cat, amt);
        }

        else if (choice == 2) {
            tracker.showReport();
        }

        else if (choice == 3) {
            exportCSV(user, tracker.getAll());
            cout << "✔ Exported!\n";
        }

        else break;
    }

    saveData(user, tracker.getAll());
    cout << "Data saved.\n";

    return 0;
}
