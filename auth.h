#ifndef AUTH_H
#define AUTH_H

#include <string>
using namespace std;

class Auth {
public:
    bool registerUser(const string& username, const string& password);
    bool loginUser(const string& username, const string& password);
    bool userExists(const string& username);
};

#endif
