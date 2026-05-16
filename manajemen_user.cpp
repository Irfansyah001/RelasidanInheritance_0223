#include <iostream>
#include <string>
#include <vector>
using namespace std;

class user
{
public:
    static int globalId;
    int id;
    string nama;
    string email;

    user(string pNama, string pEmail) : nama(pNama), email(pEmail)
    {
        id = generateId();
    }

    int generateId()
    {
        globalId++;
        return globalId;
    }
};

