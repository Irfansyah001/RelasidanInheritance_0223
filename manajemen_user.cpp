// #include adalah perintah untuk menyertakan library (pustaka) bawaan C++
#include <iostream> // untuk cout (menampilkan teks ke layar)
#include <string>   // untuk tipe data string (teks)
#include <vector>   // untuk tipe data vector (array dinamis / list)
using namespace std; // agar tidak perlu menulis "std::cout", cukup "cout"

// "class" adalah kata kunci untuk membuat blueprint / cetak biru sebuah objek
// "user" adalah nama class-nya
class user
{
// "public" berarti semua yang di bawahnya bisa diakses dari luar class
public:
    static int globalId; // "static" = variabel ini SATU dan dipakai BERSAMA oleh semua objek user
    int id;              // menyimpan ID unik masing-masing user
    string nama;         // menyimpan nama user (tipe teks)
    string email;        // menyimpan email user (tipe teks)

    // Constructor: fungsi khusus yang otomatis dipanggil saat objek dibuat
    // Parameter "pNama" dan "pEmail" adalah nilai yang dikirim saat pembuatan objek
    // ": nama(pNama), email(pEmail)" disebut initializer list, cara cepat mengisi variabel
    user(string pNama, string pEmail) : nama(pNama), email(pEmail)
    {
        id = generateId(); // panggil fungsi generateId() dan simpan hasilnya ke "id"
    }

    // Fungsi untuk menghasilkan ID baru secara otomatis
    // "int" berarti fungsi ini mengembalikan nilai berupa angka bulat
    int generateId()
    {
        globalId++;        // tambah globalId sebesar 1 setiap kali ada user baru
        return globalId;   // kembalikan nilai globalId sebagai ID user ini
    }
}; // tanda ";" wajib ada di akhir class

// Inisialisasi (pemberian nilai awal) untuk variabel static di luar class
// Harus dilakukan di luar class karena "static" bukan milik satu objek, tapi milik class
// Format: tipe namaClass::namaVariabel = nilaiAwal
int user::globalId = 0; // dimulai dari 0, akan naik tiap ada user baru

// "class member" adalah class turunan (child)
// ": public user" artinya class member MEWARISI semua isi public dari class user
class member : public user
{
public:
    string status; // tambahan variabel khusus member, berisi "aktif" atau "nonaktif"

    // Constructor member memanggil constructor user lewat ": user(pNama, pEmail)"
    // Sekaligus mengisi status awal dengan "aktif" lewat ", status("aktif")"
    member(string pNama, string pEmail) : user(pNama, pEmail), status("aktif")
    {
        cout << "Member baru dibuat: " << nama << "\n"; // "nama" diwarisi dari class user
    }

    // "void" berarti fungsi ini tidak mengembalikan nilai apapun
    void showProfile()
    {
        cout << "\n=== Profil Member ===\n"; // "\n" adalah karakter ganti baris (enter)
        cout << "ID     : " << id << "\n";   // "id" diwarisi dari class user
        cout << "Nama   : " << nama << "\n"; // "nama" diwarisi dari class user
        cout << "Email  : " << email << "\n";// "email" diwarisi dari class user
        cout << "Status : " << status << "\n";// "status" milik class member sendiri
    }
};

// "class admin" juga turunan dari "user", sama seperti member
class admin : public user
{
public:
    // vector<member *> = list yang isinya pointer (alamat) ke objek member
    // "static" berarti daftar ini satu dan dipakai bersama oleh semua objek admin
    static vector<member *> daftarMember;

    // Constructor admin, hanya memanggil constructor user
    admin(string pNama, string pEmail) : user(pNama, pEmail)
    {
        cout << "Admin dibuat: " << nama << "\n";
    }

    void showAllMember()
    {
        cout << "\n=== Daftar Semua Member ===\n";
        if (daftarMember.empty()) // ".empty()" mengecek apakah list kosong, hasilnya true/false
        {
            cout << "Belum ada member.\n";
            return; // keluar dari fungsi lebih awal jika tidak ada member
        }
        // for loop: ulangi dari i=0 sampai i kurang dari jumlah isi daftarMember
        // ".size()" mengembalikan jumlah elemen dalam vector
        for (int i = 0; i < daftarMember.size(); i++)
        {
            cout << i + 1 << ". "             // nomor urut (mulai dari 1)
                 << daftarMember[i]->nama     // "->" dipakai untuk akses member lewat pointer
                 << " | Status: " << daftarMember[i]->status // akses status lewat pointer
                 << "\n";
        }
    }

    // Parameter "member *m" adalah pointer ke objek member yang ingin diubah statusnya
    void toggleActivationMember(member *m)
    {
        if (m->status == "aktif") // cek apakah status saat ini "aktif"
        {
            m->status = "nonaktif"; // kalau aktif, ubah jadi nonaktif
        }
        else // kalau tidak aktif (berarti nonaktif)
        {
            m->status = "aktif"; // ubah kembali jadi aktif
        }
        cout << "Status " << m->nama << " diubah menjadi: " << m->status << "\n";
    }
};

// Inisialisasi variabel static daftarMember di luar class (sama seperti globalId)
// Dimulai sebagai vector kosong (tidak perlu nilai awal eksplisit)
vector<member *> admin::daftarMember;

// "main" adalah fungsi utama, program selalu mulai berjalan dari sini
int main()
{
    // Buat objek admin secara langsung (bukan pakai pointer)
    admin varAdmin("Budi", "budi@email.com");

    // "new" = alokasi memori di heap, menghasilkan pointer ke objek yang dibuat
    // "member *m1" = variabel pointer bertipe member, menyimpan alamat objek
    member *m1 = new member("Andi", "andi@email.com");
    member *m2 = new member("Siti", "siti@email.com");
    member *m3 = new member("Dewi", "dewi@email.com");

    // ".push_back()" = menambahkan elemen baru ke bagian paling belakang vector
    // "admin::daftarMember" = akses variabel static langsung lewat nama class
    admin::daftarMember.push_back(m1); // masukkan m1 ke daftar
    admin::daftarMember.push_back(m2); // masukkan m2 ke daftar
    admin::daftarMember.push_back(m3); // masukkan m3 ke daftar

    varAdmin.showAllMember(); // tampilkan semua member yang sudah didaftarkan

    cout << "\n--- Admin menonaktifkan Siti ---\n";
    varAdmin.toggleActivationMember(m2); // ubah status m2 (Siti)

    varAdmin.showAllMember(); // tampilkan lagi, status Siti sudah berubah

    m1->showProfile(); // tampilkan profil Andi lewat pointer
    m2->showProfile(); // tampilkan profil Siti lewat pointer
    m3->showProfile(); // tampilkan profil Dewi lewat pointer

    // "delete" = hapus objek dari memori yang dialokasikan dengan "new"
    // Wajib dilakukan agar tidak terjadi memory leak (memori bocor)
    delete m1;
    delete m2;
    delete m3;

    return 0; // program selesai dengan sukses (0 = tidak ada error)
}
