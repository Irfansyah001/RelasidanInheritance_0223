// HEADER GUARD: mencegah file ini di-include lebih dari sekali dalam satu kompilasi
// Jika ANAK_H belum pernah didefinisikan, maka jalankan kode di bawahnya
#ifndef ANAK_H
// Tandai bahwa ANAK_H sudah didefinisikan agar tidak diproses dua kali
#define ANAK_H

// Library untuk menampilkan teks ke layar (cout)
#include <iostream>
// Library untuk tipe data teks (string)
#include <string>
// Agar tidak perlu menulis "std::cout", cukup "cout"
using namespace std;

// Definisi class anak
class anak
{
public:
    string nama; // menyimpan nama anak

    // Constructor: dipanggil saat objek anak dibuat
    // ": nama(pNama)" = initializer list, langsung mengisi variabel "nama"
    anak(string pNama) : nama(pNama)
    {
        cout << "Anak \"" << nama << "\" ada\n";
        // \"  = karakter kutip ganda yang dicetak di layar
    }
    // Destructor: dipanggil saat objek anak dihapus dari memori
    ~anak()
    {
        cout << "Anak \"" << nama << "\" tidak ada\n";
    }
};
// Akhir dari header guard — pasangan dari #ifndef di atas
#endif
