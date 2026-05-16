// Library untuk menampilkan teks ke layar (cout)
#include <iostream>
// Agar tidak perlu menulis "std::cout", cukup "cout"
using namespace std;

// AGREGASI = relasi "mempunyai" (has-a) yang longgar
// Ibu punya anak, tapi jika ibu dihapus, anak tetap bisa hidup sendiri
// Objek yang "dimiliki" dibuat di luar, lalu "didaftarkan" ke pemilik

// Menyertakan file header eksternal (file .h buatan sendiri)
// Tanda kutip "" berarti file ada di folder yang sama dengan file ini
#include "ibu.h"  // berisi class ibu beserta fungsinya
#include "anak.h" // berisi class anak

// Fungsi utama, program mulai dari sini
int main()
{
    // Buat 2 objek ibu menggunakan pointer dan "new"
    // Artinya objek disimpan di memori heap, tidak otomatis terhapus
    ibu *varIbu  = new ibu("Dini");
    ibu *varIbu2 = new ibu("Novi");

    // Buat 3 objek anak menggunakan pointer dan "new"
    anak *varAnak1 = new anak("Tono");
    anak *varAnak2 = new anak("Rini");
    anak *varAnak3 = new anak("Dewi");

    // Daftarkan anak ke ibu (anak tidak dibuat DI DALAM ibu, hanya didaftarkan)
    // Ini ciri khas AGREGASI: objek anak hidup di luar dan hanya "dipinjam" oleh ibu
    varIbu->tambahAnak(varAnak1);  // Dini punya anak: Tono
    varIbu->tambahAnak(varAnak2);  // Dini punya anak: Rini
    varIbu2->tambahAnak(varAnak3); // Novi punya anak: Dewi
    varIbu2->tambahAnak(varAnak1); // Tono juga terdaftar di Novi (1 anak, 2 ibu)

    // Tampilkan daftar anak dari masing-masing ibu
    varIbu->cetakAnak();
    varIbu2->cetakAnak();

    // Hapus objek dari memori secara manual karena dibuat dengan "new"
    // Perhatikan: menghapus ibu TIDAK menghapus anak (ciri khas agregasi)
    delete varIbu;   // destructor ibu dipanggil
    delete varIbu2;  // destructor ibu2 dipanggil
    delete varAnak1; // anak baru dihapus setelah ibu dihapus — bisa hidup sendiri
    delete varAnak2;
    delete varAnak3;

    system("pause"); // menunggu user menekan tombol (hanya berjalan di Windows)

    return 0; // program selesai tanpa error
}
