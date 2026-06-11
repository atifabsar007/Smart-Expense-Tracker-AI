#include <iostream>
#include "auth.h"
#include "tracker.h"
#include "fileio.h"

using namespace std;

int main() {

    Auth auth;

    string user, pass;

    cout << "=== SMART EXPENSE TRACKER ===\n";

    cout << "Username: ";
    cin >> user;

    cout << "Password: ";
    cin >> pass;

    if (!auth.loginUser(user, pass)) {

        cout << "User not found. Creating account...\n";
        auth.registerUser(user, pass);
    }

    Tracker tracker(user);

    tracker.setBudget(5000);

    int choice;
    string cat, note;
    double amt;

    while (true) {

        cout << "\n1. Add Expense";
        cout << "\n2. Show Report";
        cout << "\n3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {

            cout << "Category: ";
            cin >> cat;

            cout << "Amount: ";
            cin >> amt;

            cout << "Note: ";
            cin >> note;

            tracker.addExpense(cat, amt, note);
        }

        else if (choice == 2) {
            tracker.showReport();
        }

        else if (choice == 3) {

            saveData(user, tracker.getAll());
            cout << "Data saved. Goodbye!\n";
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
