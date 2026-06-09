#ifndef AUTH_H
#define AUTH_H

#include <string>
using namespace std;

bool registerUser(string username, string password);
bool loginUser(string username, string password);

#endif
