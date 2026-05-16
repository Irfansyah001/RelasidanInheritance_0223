// HEADER GUARD: mencegah file ini di-include lebih dari sekali dalam satu kompilasi
#ifndef MANUSIA_H
#define MANUSIA_H

// Library untuk menampilkan teks ke layar (cout)
#include <iostream>
// Library untuk tipe data teks (string)
#include <string>
// Menyertakan class jantung karena manusia memiliki objek jantung di dalamnya
#include "jantung.h"
// Agar tidak perlu menulis "std::" di depan cout, string, dll.
using namespace std;

// Class manusia, contoh penerapan KOMPOSISI
class manusia
{
public:
    string name;       // nama manusia
    jantung varJantung; // objek jantung yang hidup DI DALAM class manusia
    // Ini adalah KOMPOSISI: jantung dibuat sebagai variabel member (bukan pointer)
    // Artinya jantung dan manusia mempunyai "umur" yang sama:
    // - Saat manusia dibuat → constructor jantung dipanggil otomatis lebih dulu
    // - Saat manusia dihapus → destructor jantung dipanggil otomatis setelahnya

    // Constructor manusia
    // ": name(pName)" = mengisi variabel name lewat initializer list
    // varJantung tidak perlu ditulis di sini karena constructor jantung tidak butuh parameter
    manusia(string pName) : name(pName)
    {
        cout << name << " hidup\n"; // cetak nama manusia yang baru dibuat
    }
    // Destructor manusia: dipanggil saat objek manusia dihapus
    ~manusia()
    {
        cout << name << " mati\n";
        // Setelah baris ini selesai, destructor jantung otomatis dipanggil
    }
};
// Akhir dari header guard
#endif
