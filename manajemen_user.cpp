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

int user::globalId = 0;

class member : public user
{
public:
    string status;

    member(string pNama, string pEmail) : user(pNama, pEmail), status("aktif")
    {
        cout << "Member baru dibuat: " << nama << "\n";
    }

    void showProfile()
    {
        cout << "\n=== Profil Member ===\n";
        cout << "ID     : " << id << "\n";
        cout << "Nama   : " << nama << "\n";
        cout << "Email  : " << email << "\n";
        cout << "Status : " << status << "\n";
    }
};

