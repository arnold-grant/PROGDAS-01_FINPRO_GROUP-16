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
    else if ((kalori >= 450 && kalori < 500) || (kalori > 650)) {
	    return 4;
	}
    else if ((kalori >= 400 && kalori < 450) || (kalori > 750)) {
	    return 3;
	}
    else if ((kalori >= 300 && kalori < 400) || (kalori > 850)) {
	    return 2;
	}
    return 1;
}

int hitungSkorKarbohidrat(float karbo) {
    if (karbo >= 70 && karbo <= 90) {
        return 5;
    }
    else if (karbo >= 60 && karbo <= 70) {
        return 4;
    }
    else if ((karbo >= 50 && karbo <= 60) || (karbo >= 90)) {
        return 3;
    }
    else if ((karbo >= 40 && karbo <= 50) || (karbo >= 110)) {
        return 2;
    }
    else if ((karbo < 40 || karbo > 130)) {
        return 1;
    }
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

void tampilkanTabelReferensi() {
    printf("\n========================================================================\n");
    printf("            STANDAR QC & REFERENSI PEMBOBOTAN NUTRISI MBG\n");
    printf("========================================================================\n");
    printf("| Skor | Kalori (30%%) | Protein (40%%) | Karbo (20%%) | Lemak (10%%) |\n");
    printf("|------|--------------|---------------|-------------|-------------|\n");
    printf("|  5   | 500-650 kkal | >= 25 g       | 70-90 g     | 14-20 g     |\n");
    printf("|  4   | 450-500/650+ | 20-24 g       | 60-70 g     | 10-13 g     |\n");
    printf("|  3   | 400-450/750+ | 15-19 g       | 50-60/90+   | 7-9 g       |\n");
    printf("|  2   | 300-400/850+ | 10-14 g       | 40-50/110+  | 4-6 g       |\n");
    printf("|  1   | <300 / >950  | < 10 g        | <40 / >130  | < 4 g       |\n");
    printf("========================================================================\n");
    printf(" INFO PEMBOBOTAN:\n");
    printf(" 1. Protein (40%%)\n");
    printf(" 2. Kalori (30%%)\n");
    printf(" 3. Karbo (20%%)\n");
    printf(" 4. Lemak (10%%)\n");
    printf(" CATATAN: Jika Uji Keamanan = BERBAHAYA, Skor otomatis 0.00.\n");
    printf("========================================================================\n");
}

void tampilanMenu() {

}

int main() {

    return 0;
}