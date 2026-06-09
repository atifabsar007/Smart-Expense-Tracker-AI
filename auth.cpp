#include "auth.h"
#include <fstream>

bool registerUser(string username, string password) {
    ofstream file("users.txt", ios::app);
    file << username << " " << password << "\n";
    file.close();
    return true;
}

bool loginUser(string username, string password) {
    ifstream file("users.txt");
    string u, p;

    while (file >> u >> p) {
        if (u == username && p == password) return true;
    }
    return false;
}
