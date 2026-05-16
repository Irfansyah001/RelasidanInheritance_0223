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

class admin : public user
{
public:
    static vector<member *> daftarMember;

    admin(string pNama, string pEmail) : user(pNama, pEmail)
    {
        cout << "Admin dibuat: " << nama << "\n";
    }

    void showAllMember()
    {
        cout << "\n=== Daftar Semua Member ===\n";
        if (daftarMember.empty())
        {
            cout << "Belum ada member.\n";
            return;
        }
        for (int i = 0; i < daftarMember.size(); i++)
        {
            cout << i + 1 << ". "
                 << daftarMember[i]->nama
                 << " | Status: " << daftarMember[i]->status
                 << "\n";
        }
    }

    void toggleActivationMember(member *m)
    {
        if (m->status == "aktif")
        {
            m->status = "nonaktif";
        }
        else
        {
            m->status = "aktif";
        }
        cout << "Status " << m->nama << " diubah menjadi: " << m->status << "\n";
    }
};

vector<member *> admin::daftarMember;

int main()
{
    admin varAdmin("Budi", "budi@email.com");

    member *m1 = new member("Andi", "andi@email.com");
    member *m2 = new member("Siti", "siti@email.com");
    member *m3 = new member("Dewi", "dewi@email.com");

    admin::daftarMember.push_back(m1);
    admin::daftarMember.push_back(m2);
    admin::daftarMember.push_back(m3);

    varAdmin.showAllMember();

    cout << "\n--- Admin menonaktifkan Siti ---\n";
    varAdmin.toggleActivationMember(m2);

    varAdmin.showAllMember();

    m1->showProfile();
    m2->showProfile();
    m3->showProfile();

    delete m1;
    delete m2;
    delete m3;

    return 0;
}
