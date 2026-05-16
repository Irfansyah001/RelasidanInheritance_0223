// Library untuk menampilkan teks ke layar (cout)
#include <iostream>
// Library untuk tipe data teks (string)
#include <string>
// Agar tidak perlu menulis "std::cout", cukup "cout"
using namespace std;

// KOMPOSISI = relasi "mempunyai" (has-a) yang kuat / erat
// Manusia punya jantung, dan jika manusia mati (dihapus), jantung ikut mati
// Objek yang "dimiliki" dibuat DI DALAM objek pemilik (sebagai variabel member biasa)

// Menyertakan file header eksternal (file .h buatan sendiri)
#include "jantung.h" // berisi class jantung
#include "manusia.h" // berisi class manusia (yang di dalamnya ada objek jantung)

// Fungsi utama, program mulai dari sini
int main()
{
    // Buat objek manusia menggunakan pointer dan "new"
    // Saat manusia dibuat → constructor manusia dipanggil
    // Di dalam manusia ada variabel "varJantung" bertipe jantung
    // → constructor jantung otomatis dipanggil lebih dulu
    manusia *varManusia = new manusia("Markus");

    // Hapus objek manusia dari memori
    // Saat manusia dihapus → destructor manusia dipanggil
    // → destructor jantung otomatis ikut dipanggil setelahnya
    // Ini ciri khas KOMPOSISI: jantung tidak bisa hidup tanpa manusia
    delete varManusia;
}
