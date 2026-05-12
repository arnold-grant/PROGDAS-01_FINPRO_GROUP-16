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
} Distribusi;

typedef struct {
	char nama[50];
    float karbo, protein, lemak, kalori;
    int skorKarbo, skorProtein, skorLemak, skorKalori;
    int bersih;
    float averageBobot;
    StatusKelayakan status;
    Distribusi info;
} Makanan;

int hitungSkorKalori (float kalori) {
	if (kalori >= 500 && kalori <= 650) {
	return 5;
	}
    if ((kalori >= 450 && kalori < 500) || (kalori > 650 && kalori <= 750)) {
	return 4;
	}
    if ((kalori >= 400 && kalori < 450) || (kalori > 750 && kalori <= 850)) {
	return 3;
	}
    if ((kalori >= 300 && kalori < 400) || (kalori > 850 && kalori <= 950)) {
	return 2;
	}
    return 1;
}

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