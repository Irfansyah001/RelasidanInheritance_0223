// Library untuk menampilkan teks ke layar (cout)
#include <iostream>
// Library untuk tipe data teks (string)
#include <string>
// Library untuk tipe data vector (list/array yang ukurannya bisa berubah)
#include <vector>
// Agar tidak perlu menulis "std::cout", cukup "cout"
using namespace std;

// ASOSIASI = relasi dua arah antara dua class yang saling kenal
// Dokter kenal pasien, pasien juga kenal dokter
// Keduanya bisa hidup sendiri-sendiri (tidak saling bergantung)

// "Forward declaration": memberitahu compiler bahwa class "dokter" ada,
// meskipun definisi lengkapnya belum ditulis di sini
// Ini diperlukan karena class "pasien" butuh tahu class "dokter" sebelum dokter didefinisikan
class dokter;

// Definisi class pasien
class pasien
{
public:
    string nama;                    // nama pasien
    vector<dokter *> daftar_dokter; // list pointer ke dokter-dokter yang menangani pasien ini

    // Constructor: diisi nama saat objek pasien dibuat
    pasien(string pNama) : nama(pNama)
    {
        cout << "Pasien \"" << nama << "\" ada\n";
        // Tanda \" digunakan untuk mencetak karakter kutip (") di dalam string
    }
    // Destructor: dipanggil saat objek pasien dihapus
    ~pasien()
    {
        cout << "Pasien \"" << nama << "\" tidak ada\n";
    }
    // Deklarasi fungsi di dalam class, definisinya ditulis di luar class (baris 44)
    void tambahDokter(dokter *); // menerima pointer ke dokter
    void cetakDokter();          // menampilkan semua dokter yang menangani pasien ini
};

// Definisi class dokter
class dokter
{
public:
    string nama;                     // nama dokter
    vector<pasien *> daftar_pasien;  // list pointer ke pasien-pasien yang ditangani dokter ini

    // Constructor dokter
    dokter(string pNama) : nama(pNama)
    {
        cout << "Dokter \"" << nama << "\" ada\n";
    }
    // Destructor dokter
    ~dokter()
    {
        cout << "Dokter \"" << nama << "\" tidak ada\n";
    }

    // Deklarasi fungsi, definisinya ditulis di luar class (baris 59)
    void tambahPasien(pasien *); // menerima pointer ke pasien
    void cetakPasien();          // menampilkan semua pasien milik dokter ini
};

// Definisi fungsi tambahDokter milik class pasien, ditulis di luar class
// Format: tipe namaClass::namaFungsi(parameter)
void pasien::tambahDokter(dokter *pDokter)
{
    daftar_dokter.push_back(pDokter); // tambahkan pointer dokter ke list daftar_dokter
}

// Definisi fungsi cetakDokter milik class pasien
void pasien::cetakDokter()
{
    cout << "Daftar Dokter yang menangani Pasien \"" << this->nama << "\":\n";
    // "this" = pointer ke objek saat ini (pasien yang sedang memanggil fungsi ini)
    // "this->nama" = akses variabel "nama" dari objek saat ini

    // Range-based for loop: "auto &a" otomatis menyesuaikan tipe data elemen vector
    // "&" artinya "a" adalah referensi (alias) ke elemen, bukan salinan
    for (auto &a : daftar_dokter)
    {
        cout << a->nama << "\n"; // akses nama dokter lewat pointer menggunakan "->"
    }
    cout << endl; // tambah baris kosong di akhir
}

// Definisi fungsi tambahPasien milik class dokter
void dokter::tambahPasien(pasien *pPasien)
{
    daftar_pasien.push_back(pPasien);  // tambahkan pasien ke list milik dokter
    pPasien->tambahDokter(this);       // sekaligus daftarkan dokter ini ke list milik pasien
    // "this" di sini = pointer ke objek dokter yang sedang memanggil fungsi ini
}

// Definisi fungsi cetakPasien milik class dokter
void dokter::cetakPasien()
{
    cout << "Daftar Pasien dari Dokter \"" << this->nama << "\":\n";
    for (auto &a : daftar_pasien)
    {
        cout << a->nama << "\n"; // akses nama pasien lewat pointer
    }
    cout << endl;
}

// Fungsi utama
int main()
{
    // Buat 2 objek dokter menggunakan pointer dan "new"
    dokter *varDokter1 = new dokter("Dr. Siti");
    dokter *varDokter2 = new dokter("Dr. Budi");

    // Buat 3 objek pasien menggunakan pointer dan "new"
    pasien *varPasien1 = new pasien("Andi");
    pasien *varPasien2 = new pasien("Rina");
    pasien *varPasien3 = new pasien("Dewi");

    // Daftarkan pasien ke dokter (otomatis daftarkan dokter ke pasien juga)
    varDokter1->tambahPasien(varPasien1); // Dr. Siti menangani Andi
    varDokter1->tambahPasien(varPasien2); // Dr. Siti menangani Rina
    varDokter2->tambahPasien(varPasien3); // Dr. Budi menangani Dewi
    varDokter2->tambahPasien(varPasien1); // Dr. Budi juga menangani Andi (1 pasien, 2 dokter)

    // Tampilkan daftar pasien dari sisi dokter
    varDokter1->cetakPasien();
    varDokter2->cetakPasien();

    // Tampilkan daftar dokter dari sisi pasien
    varPasien1->cetakDokter();
    varPasien2->cetakDokter();
    varPasien3->cetakDokter();

    // Hapus semua objek dari memori karena dibuat dengan "new"
    // Wajib dilakukan agar tidak terjadi memory leak
    delete varDokter1;
    delete varDokter2;
    delete varPasien1;
    delete varPasien2;
    delete varPasien3;

    system("pause"); // menunggu user menekan tombol (hanya berjalan di Windows)

    return 0; // program selesai tanpa error
}
