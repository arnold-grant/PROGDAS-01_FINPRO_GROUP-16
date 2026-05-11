#include <stdio.h>
#include <string.h>
#define MAX_MAKANAN 50

typedef enum {
	LayakKirim, 
    MakananKaryawan, 
    DaurUlang
} StatusKelayakan;

typedef union {
	char tujuanPengiriman[50]; 
    char divisiKaryawan[50];   
    char jenisDaurUlang[50];
} InfoTambahan;

typedef struct {
	char nama[50];
    float karbo, protein, lemak;
    int skorKarbo, skorProtein, skorLemak;
    float rataRata;
    StatusKelayakan status;
    InfoTambahan info;
} Makanan;

int hitungSkorKarbohidrat(float gram) {

}

int hitungSkorProtein(float gram) {

}

int hitungSkorLemak(float gram) {

}

void hitungKomposisi(Makanan *makanan) {

}

void kelolosanSkorMakanan(Makanan *makanan) {

}

void penentuanDistribusi(Makanan *makanan) {

}

void inputMakanan(Makanan *makanan) {

}

void tampilHasilMakanan(const Makanan *makanan) {

}

void tampilRingkasan(Makanan *daftarMakanan, int jumlah) {
	
}

void tampilanMenu() {

}

int main() {

    return 0;
}