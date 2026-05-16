// HEADER GUARD: mencegah file ini di-include lebih dari sekali dalam satu kompilasi
#ifndef IBU_H
#define IBU_H

// Library untuk vector (list dinamis)
#include <vector>
// Library untuk cout
#include <iostream>
// Library untuk string
#include <string>
// Menyertakan class anak karena ibu menyimpan pointer ke objek anak
#include "anak.h"
// Agar tidak perlu menulis "std::" di depan cout, string, dll.
using namespace std;

// Definisi class ibu
class ibu
{
public:
    string nama;               // nama ibu
    vector<anak *> daftar_anak; // list yang menyimpan pointer ke objek-objek anak
    // Menggunakan pointer (anak *) karena objek anak hidup di luar class ibu (agregasi)

    // Constructor ibu
    ibu(string pNama) : nama(pNama)
    {
        cout << "Ibu \"" << nama << "\" ada\n";
    }
    // Destructor ibu
    // Catatan: destructor ini TIDAK menghapus anak, hanya menghapus ibu sendiri
    // Inilah ciri khas agregasi: anak tetap hidup walau ibu dihapus
    ~ibu()
    {
        cout << "Ibu \"" << nama << "\" tidak ada\n";
    }
    // Deklarasi fungsi saja di sini, definisinya ditulis di bawah setelah class
    void tambahAnak(anak *); // menerima pointer ke objek anak
    void cetakAnak();        // menampilkan semua anak yang dimiliki ibu ini
};

// Definisi fungsi tambahAnak di luar class
// Format: tipe namaClass::namaFungsi(parameter)
void ibu::tambahAnak(anak *pAnak)
{
    daftar_anak.push_back(pAnak); // tambahkan pointer anak ke list daftar_anak
}

// Definisi fungsi cetakAnak di luar class
void ibu::cetakAnak()
{
    cout << "Daftar Anak dari Ibu \"" << this->nama << "\":\n";
    // "this" = pointer ke objek ibu yang sedang memanggil fungsi ini
    // "this->nama" = akses variabel nama dari objek ibu saat ini

    /*
    Kode di bawah ini di-nonaktifkan (dikomentari dengan tanda /* ... *\/)
    Ini adalah cara alternatif menggunakan range-based for loop:
    for (auto& a : daftar_anak) {
        cout << a->nama << "\n";
    }
    Hasilnya sama dengan for loop di bawah, hanya penulisannya berbeda
    */

    // For loop biasa: ulangi dari i=0 sampai i kurang dari jumlah elemen
    // daftar_anak.size() = jumlah anak yang ada dalam list
    for (int i = 0; i < daftar_anak.size(); i++)
    {
        cout << daftar_anak[i]->nama << endl;
        // daftar_anak[i] = akses elemen ke-i dari vector (berupa pointer)
        // ->nama         = akses variabel nama dari pointer tersebut
    }
    cout << endl; // tambah baris kosong setelah semua nama dicetak
}
// Akhir dari header guard
#endif
