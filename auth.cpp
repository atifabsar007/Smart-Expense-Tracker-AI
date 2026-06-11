#include "auth.h"
#include <fstream>
#include <iostream>

using namespace std;

bool Auth::userExists(const string& username) {
    ifstream file("data/users.txt");

    string u, p;
    while (file >> u >> p) {
        if (u == username) return true;
    }
    return false;
}

bool Auth::registerUser(const string& username, const string& password) {

    if (username.empty() || password.empty())
        return false;

    if (userExists(username))
        return false;

    ofstream file("data/users.txt", ios::app);
    file << username << " " << password << "\n";

    return true;
}

bool Auth::loginUser(const string& username, const string& password) {

    ifstream file("data/users.txt");

    string u, p;
    int attempts = 0;

    while (file >> u >> p) {
        if (u == username && p == password)
            return true;
    }

    return false;
}
