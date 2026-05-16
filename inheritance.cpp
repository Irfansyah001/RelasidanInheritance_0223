// Library untuk menampilkan teks ke layar (cout)
#include <iostream>
// Library untuk menggunakan tipe data teks (string)
#include <string>
// Agar tidak perlu menulis "std::cout", cukup "cout"
using namespace std;

// Membuat class "orang" sebagai induk (parent)
class orang
{
// Semua yang di bawah "public" bisa diakses dari luar class
public:
    string nama; // variabel untuk menyimpan nama orang

    // Constructor: otomatis dipanggil saat objek "orang" dibuat
    // ": nama(pNama)" = initializer list, langsung mengisi variabel "nama"
    orang(string pNama) : nama(pNama)
    {
        cout << "Orang dibuat\n" // tampilkan pesan saat objek dibuat
             << endl;            // "endl" sama seperti "\n", pindah baris + flush buffer
    }
    // Destructor: otomatis dipanggil saat objek dihapus dari memori
    // Ditandai dengan tanda "~" sebelum nama class
    ~orang()
    {
        cout << "Orang dihapus\n"
             << endl;
    }

    // Fungsi biasa milik class orang
    // Menerima 2 angka dan mengembalikan hasil penjumlahannya
    int jumlah(int a, int b)
    {
        return a + b; // kembalikan hasil a + b ke pemanggil fungsi
    }
};

// Class "pelajar" mewarisi (inherit) class "orang"
// ": public orang" artinya semua anggota public orang bisa dipakai oleh pelajar
class pelajar : public orang
{
public:
    string sekolah; // variabel tambahan khusus pelajar, tidak ada di class orang

    // Constructor pelajar menerima 2 parameter: nama dan sekolah
    // ": orang(pNama)" = memanggil constructor induk (orang) terlebih dahulu
    // ", sekolah(pSekolah)" = lalu mengisi variabel sekolah
    pelajar(string pNama, string pSekolah) : orang(pNama), sekolah(pSekolah)
    {
        cout << "Pelajar dibuat\n"
             << endl;
    }
    // Destructor pelajar, dipanggil sebelum destructor orang saat objek dihapus
    ~pelajar()
    {
        cout << "Pelajar dihapus\n"
             << endl;
    }
    // Fungsi yang mengembalikan teks (string) berisi kalimat perkenalan
    string perkenalan()
    {
        // "+" dipakai untuk menyambung (menggabungkan) beberapa teks menjadi satu
        // "nama" diwarisi dari class orang, tidak perlu dideklarasikan ulang
        return "Hallo, nama saya " + nama + " dan saya sekolah di " + sekolah + "\n\n";
    }
};

// Fungsi utama, program mulai berjalan dari sini
int main()
{
    // Membuat objek "pelajar" bernama siswa1
    // Constructor pelajar dipanggil → constructor orang dipanggil lebih dulu
    pelajar siswa1("Andi Laksono", "SMAN 1 Bantul");

    // Memanggil fungsi perkenalan() dan langsung menampilkan hasilnya
    cout << siswa1.perkenalan();

    // Fungsi jumlah() diwarisi dari class orang, bisa langsung dipakai oleh pelajar
    cout << "Hasil = " << siswa1.jumlah(10, 90) << endl;

    // Saat main() selesai, destructor dipanggil otomatis (urutan kebalikan dari constructor):
    // destructor pelajar dulu → baru destructor orang
    return 0; // program selesai tanpa error
}
