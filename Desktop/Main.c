#include <stdio.h>
#include <string.h>

// ============================================================
// KONSTANTA: Batas maksimal makanan yang bisa diinput
// ============================================================
#define MAX_MAKANAN 50

// ============================================================
// ENUM: Mendefinisikan status kelayakan makanan
// ============================================================
typedef enum {
    // TODO: Tambahkan status kelayakan makanan
    // LAYAK_KIRIM, MAKANAN_KARYAWAN, DAUR_ULANG
} StatusKelayakan;

// ============================================================
// UNION: Menyimpan informasi tambahan sesuai status makanan
// ============================================================
typedef union {
    // TODO: field tujuan pengiriman (jika LAYAK_KIRIM)
    // TODO: field divisi karyawan  (jika MAKANAN_KARYAWAN)
    // TODO: field jenis daur ulang (jika DAUR_ULANG)
} InfoTambahan;

// ============================================================
// STRUCT: Menyimpan data lengkap satu makanan
// Input user  : gram aktual (float)
// Dihitung    : skor per komponen (int 1-5) & rata-rata (float)
// ============================================================
typedef struct {
    // --- Input dari user ---
    // TODO: field nama makanan         (char array)
    // TODO: field gram karbohidrat     (float)
    // TODO: field gram protein         (float)
    // TODO: field gram lemak           (float)

    // --- Dihitung otomatis ---
    // TODO: field skor karbohidrat     (int, hasil konversi gram)
    // TODO: field skor protein         (int, hasil konversi gram)
    // TODO: field skor lemak           (int, hasil konversi gram)
    // TODO: field rata-rata skor       (float)

    // --- Status & info distribusi ---
    // TODO: field status kelayakan     (StatusKelayakan)
    // TODO: field info tambahan        (InfoTambahan)
} Makanan;

// ============================================================
// FUNGSI: Konversi gram karbohidrat → skor 1-5
// Tabel:
//   > 20g        → 5
//   15g - 20g    → 4
//   10g - 15g    → 3
//   5g  - 10g    → 2
//   < 5g         → 1
// Parameter: gram (float)
// Return: skor (int)
// ============================================================
int hitungSkorKarbohidrat(float gram) {
    // TODO: if-else sesuai tabel karbohidrat
}

// ============================================================
// FUNGSI: Konversi gram protein → skor 1-5
// Tabel:
//   > 15g        → 5
//   10g - 15g    → 4
//   5g  - 10g    → 3
//   2g  - 5g     → 2
//   < 2g         → 1
// Parameter: gram (float)
// Return: skor (int)
// ============================================================
int hitungSkorProtein(float gram) {
    // TODO: if-else sesuai tabel protein
}

// ============================================================
// FUNGSI: Konversi gram lemak → skor 1-5
// CATATAN: Arah terbalik — semakin SEDIKIT lemak, skor MAKIN TINGGI
// Tabel:
//   < 3g         → 5
//   3g  - 7g     → 4
//   7g  - 12g    → 3
//   12g - 20g    → 2
//   > 20g        → 1
// Parameter: gram (float)
// Return: skor (int)
// ============================================================
int hitungSkorLemak(float gram) {
    // TODO: if-else sesuai tabel lemak (ingat: arah terbalik!)
}

// ============================================================
// FUNGSI: Menghitung semua skor dan rata-rata dari gram input
// Urutan: hitung skor tiap komponen → hitung rata-rata
// Parameter: pointer ke struct Makanan
// Return: void (semua hasil disimpan ke struct via pointer)
// ============================================================
void hitungKomposisi(Makanan *makanan) {
    // TODO: Panggil hitungSkorKarbohidrat, simpan ke field skorKarbohidrat
    // TODO: Panggil hitungSkorProtein,     simpan ke field skorProtein
    // TODO: Panggil hitungSkorLemak,       simpan ke field skorLemak
    // TODO: Hitung rata-rata dari ketiga skor, simpan ke field rataRata
}

// ============================================================
// FUNGSI: Menentukan kelayakan makanan dari rata-rata skor
// Logika:
//   >= 4.0 → LAYAK_KIRIM
//   >= 3.0 → MAKANAN_KARYAWAN
//   <  3.0 → DAUR_ULANG
// Parameter: pointer ke struct Makanan
// Return: void (status disimpan ke struct via pointer)
// ============================================================
void kelolosanSkorMakanan(Makanan *makanan) {
    // TODO: if-else untuk menentukan status dari rataRata
}

// ============================================================
// FUNGSI: Menentukan distribusi & meminta info tambahan
// Parameter: pointer ke struct Makanan
// Return: void
// ============================================================
void penentuanDistribusi(Makanan *makanan) {
    // TODO: switch-case berdasarkan status:
    //   LAYAK_KIRIM      → input tujuan pengiriman
    //   MAKANAN_KARYAWAN → input divisi karyawan
    //   DAUR_ULANG       → input jenis daur ulang
}

// ============================================================
// FUNGSI: Input data gram makanan dari pengguna
// Hanya input gram — skor dihitung otomatis oleh hitungKomposisi
// Parameter: pointer ke struct Makanan
// Return: void
// ============================================================
void inputMakanan(Makanan *makanan) {
    // TODO: Input nama makanan
    // TODO: Input gram karbohidrat (float, harus > 0)
    // TODO: Input gram protein     (float, harus > 0)
    // TODO: Input gram lemak       (float, harus > 0)
}

// ============================================================
// FUNGSI: Menampilkan hasil lengkap satu makanan
// Menampilkan gram input, skor hasil konversi, rata-rata, status
// Parameter: pointer ke struct Makanan (const, hanya baca)
// Return: void
// ============================================================
void tampilHasilMakanan(const Makanan *makanan) {
    // TODO: Tampilkan nama makanan
    // TODO: Tampilkan gram & skor tiap komponen (karbohidrat, protein, lemak)
    // TODO: Tampilkan rata-rata skor
    // TODO: Tampilkan status kelayakan
    // TODO: Tampilkan info tambahan sesuai status
}

// ============================================================
// FUNGSI: Menampilkan ringkasan semua makanan (laporan akhir)
// Parameter: array of Makanan, jumlah makanan (int)
// Return: void
// ============================================================
void tampilRingkasan(Makanan *daftarMakanan, int jumlah) {
    // TODO: Deklarasi counter: totalLayak, totalKaryawan, totalDaur
    // TODO: Loop semua makanan:
    //         panggil tampilHasilMakanan
    //         tambah counter sesuai status
    // TODO: Tampilkan ringkasan jumlah per kategori
}

// ============================================================
// FUNGSI: Menampilkan menu utama program
// Return: void
// ============================================================
void tampilanMenu() {
    // TODO: Tampilkan judul program
    // TODO: Tampilkan pilihan: [1] input, [2] laporan, [0] keluar
}

// ============================================================
// MAIN: Entry point program
// ============================================================
int main() {
    // TODO: Deklarasi array of Makanan (MAX_MAKANAN)
    // TODO: Deklarasi jumlahMakanan = 0
    // TODO: Deklarasi variabel pilihan menu

    // TODO: do-while loop menu utama:
    //   tampilanMenu → input pilihan → switch:
    //     case 1: inputMakanan → hitungKomposisi →
    //             kelolosanSkorMakanan → penentuanDistribusi
    //     case 2: tampilRingkasan
    //     case 0: keluar

    return 0;
}