// HEADER GUARD: mencegah file ini di-include lebih dari sekali dalam satu kompilasi
#ifndef JANTUNG_H
#define JANTUNG_H

// Library untuk menampilkan teks ke layar (cout)
#include <iostream>
// Agar tidak perlu menulis "std::cout", cukup "cout"
using namespace std;

// Class jantung, dipakai sebagai contoh KOMPOSISI di dalam class manusia
// Jantung tidak bisa hidup tanpa manusia — jika manusia dihapus, jantung ikut dihapus
class jantung
{
public:
    // Constructor: dipanggil otomatis saat objek jantung dibuat
    // Karena jantung adalah variabel member di dalam manusia,
    // constructor ini dipanggil saat objek manusia dibuat (sebelum constructor manusia)
    jantung()
    {
        cout << "Jantung dihidupkan\n";
    }
    // Destructor: dipanggil otomatis saat objek jantung dihapus
    // Karena jantung ada di dalam manusia,
    // destructor ini dipanggil setelah destructor manusia selesai
    ~jantung()
    {
        cout << "Jantung dimatikan\n";
    }
};
// Akhir dari header guard
#endif
