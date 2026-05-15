#include <stdio.h>
#include <string.h>
#define MaksimumJenis 50

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

typedef enum {
    Expired,
    MendekatiExpired,
    JauhDariExpired
}StatusMakanan;

typedef struct {
	char nama[50];
    float karbo, protein, lemak, kalori;
    int skorKarbo, skorProtein, skorLemak, skorKalori;
    int bersih;
    float averageBobot;
    int segar;
    StatusMakanan kesegaran;
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

int hitungSkorProtein(float protein) {
    if (protein >= 40) {
        return 5;
    }
    else if (protein >= 30 && protein <= 40) {
        return 4;
    }
    else if (protein >= 20 && protein <= 30) {
        return 3;
    }
    else if (protein >= 10 && protein <= 20) {
        return 2;
    }
    else if (protein < 10) {
        return 1;
    }
}

int hitungSkorLemak(float lemak) {
    if (lemak >= 14 && lemak <= 20) {
        return 5;
    }
    else if (lemak >= 10 && lemak <= 13) {
        return 4;
    }
    else if ((lemak >= 7 && lemak <= 9) || (lemak >= 21 && lemak <= 25)) {
        return 3;
    }
    else if ((lemak >= 4 && lemak <= 6) || (lemak >= 26 && lemak <= 30)) {
        return 2;
    }
    else if ((lemak < 4) || (lemak > 30)) {
        return 1;
    }
}

void hitungKomposisi(Makanan *Makanan) {
    Makanan->kalori = (Makanan->karbo * 4.0) + (Makanan->protein * 4.0) + (Makanan->lemak * 9.0);
    Makanan->skorKarbo = hitungSkorKarbohidrat(Makanan->karbo);
    Makanan->skorProtein = hitungSkorProtein(Makanan->protein);
    Makanan->skorLemak = hitungSkorLemak(Makanan->lemak);
    Makanan->skorKalori = hitungSkorKalori(Makanan->kalori);

    if (Makanan->bersih == 0) {
        Makanan->averageBobot = 0.0;
    }
    else {
        Makanan->averageBobot = (Makanan->skorProtein * 0.4) + (Makanan->skorKalori * 0.3) + (Makanan->skorKarbo * 0.2) + (Makanan->skorLemak * 0.1);
    }
}

void kelolosanSkorMakanan(Makanan *Makanan) {
    if (Makanan->averageBobot >= 4.0){
        Makanan->status = LayakKirim;
    }
    else if (Makanan->averageBobot >= 3.0){
    Makanan->status = MakananKaryawan;    
    }
    else{
        Makanan->status = DaurUlang;
    }

}

void KesegaranMakanan(Makanan *Makanan) {
    if (Makanan->segar == 1) {
        Makanan->kesegaran = JauhDariExpired; 
    }
    else if (Makanan->segar == 2) {
        Makanan->kesegaran = MendekatiExpired;
        Makanan->status = MakananKaryawan;
    }
    else if (Makanan->segar == 3) {
        Makanan->kesegaran = Expired;
        Makanan->averageBobot = 0.0;
        Makanan->status = DaurUlang;
    }
}

void penentuanDistribusi(Makanan *Makanan) {
	getchar();
	switch (Makanan->status) {
		case LayakKirim: 
			printf("Masukkan Kota Tujuan Pengiriman: ");
            fgets(Makanan->info.tujuanPengiriman, 50, stdin);
            Makanan->info.tujuanPengiriman[strcspn(Makanan->info.tujuanPengiriman, "\n")] = 0;
            break;
        case MakananKaryawan:
        	printf("Masukkan Divisi Karyawan Penerima: ");
            fgets(Makanan->info.divisiKaryawan, 50, stdin);
            Makanan->info.divisiKaryawan[strcspn(Makanan->info.divisiKaryawan, "\n")] = 0;
            break;
        case DaurUlang:
            if (Makanan->bersih == 0) strcpy(Makanan->info.jenisDaurUlang, "LIMBAH B3 - MUSNAHKAN");
            else {
            	printf("Masukkan Jenis Daur Ulang (Pupuk/Pakan): ");
                fgets(Makanan->info.jenisDaurUlang, 50, stdin);
                Makanan->info.jenisDaurUlang[strcspn(Makanan->info.jenisDaurUlang, "\n")] = 0;
			}
			break;
	}

}

void inputMakanan(Makanan *Makanan) {
	printf("\n--- FORM INPUT MAKANAN ---\n");
    printf("Nama Menu: ");
    scanf(" %[^\n]s", Makanan->nama);
    printf("Gramasi Protein : "); 
    scanf("%f", &Makanan->protein);
    printf("Gramasi Karbo   : "); 
    scanf("%f", &Makanan->karbo);
    printf("Gramasi Lemak   : "); 
    scanf("%f", &Makanan->lemak);
    printf("Status kebersihan (1.Bersih, 0.Kotor): "); 
	scanf("%d", &Makanan->bersih);
    printf("Kesegaran Menu (1.JauhDariExpired, 2.MendekatiExpired, 3.Expired): "); 
    scanf("%d", &Makanan->segar);
}

void tampilHasilMakanan(const Makanan *Makanan) {
	printf("\n>> LAPORAN QC: %s\n", Makanan->nama);
    printf("   [KEAMANAN]     : %s\n", (Makanan->bersih ? "AMAN" : "!!! TERKONTAMINASI !!!"));
    printf("   [ENERGI TOTAL] : %.2f kkal\n", Makanan->kalori);
    printf("   [RINCIAN SKOR] : P:%d(40%%) | Kal:%d(30%%) | K:%d(20%%) | L:%d(10%%)\n", Makanan->skorProtein, Makanan->skorKalori, Makanan->skorKarbo, Makanan->skorLemak);
    printf("   [INDEKS AKHIR] : %.2f / 5.00\n", Makanan->averageBobot);
    printf("   [KESEGARAN]    : ");
    if (Makanan->kesegaran == JauhDariExpired) printf("Jauh Dari Tanggal Expired\n");
    else if (Makanan->kesegaran == MendekatiExpired) printf("Sudah Mendekati Tanggal Expired\n");
    else if (Makanan->kesegaran == Expired) printf("Makanan Sudah Expired\n");
    printf("   [STATUS]       : ");
    if (Makanan->status == LayakKirim) printf("LAYAK KIRIM [%s]\n", Makanan->info.tujuanPengiriman);
    else if (Makanan->status == MakananKaryawan) printf("MAKANAN KARYAWAN [%s]\n", Makanan->info.divisiKaryawan);
    else printf("DAUR ULANG [%s]\n", Makanan->info.jenisDaurUlang);
}

void tampilkanTabelReferensi() {
    printf("\n========================================================================\n");
    printf("            STANDAR QC & REFERENSI PEMBOBOTAN NUTRISI MBG\n");
    printf("========================================================================\n");
    printf("| Skor | Kalori (30%%) | Protein (40%%) | Karbo (20%%) | Lemak (10%%) |\n");
    printf("|------|--------------|---------------|-------------|-------------|\n");
    printf("|  5   | 500-650 kkal | 40+ g         | 70-90 g     | 14-20 g     |\n");
    printf("|  4   | 450-500/650+ | 30-40 g       | 60-70 g     | 10-13 g     |\n");
    printf("|  3   | 400-450/750+ | 20-30 g       | 50-60/90+   | 7-9/21-25 g |\n");
    printf("|  2   | 300-400/850+ | 10-20 g       | 40-50/110+  | 4-6/26-30 g |\n");
    printf("|  1   | <300 / >950  | <10 g         | <40 / >130  | <4/30+ g    |\n");
    printf("========================================================================\n");
    printf(" INFO PEMBOBOTAN:\n");
    printf(" 1. Protein (40%%)\n");
    printf(" 2. Kalori  (30%%)\n");
    printf(" 3. Karbo   (20%%)\n");
    printf(" 4. Lemak   (10%%)\n");
    printf(" CATATAN: Jika Status Makanan = Expired, Skor otomatis 0.00.\n");
    printf("\t  Jika Status Makanan = MendekatiExpired, Kelayakan automatis menjadi MakananKaryawan.\n");
    printf("========================================================================\n");
}

int main() {
    Makanan daftar[MaksimumJenis];
    int jumlah = 0, pilihan;

    do {
        printf("\n================Kontrol Kualitas Makanan Bergizi Gratis================\n");
        printf("1. Analisis Menu Baru\n2. Lihat Tabel Detail Referensi\n3. Tampilkan Seluruh Menu\n0. Keluar\nPilihan: ");
        scanf("%d", &pilihan);
        if (pilihan == 1 && jumlah < MaksimumJenis) {
            inputMakanan(&daftar[jumlah]);
            hitungKomposisi(&daftar[jumlah]);
            KesegaranMakanan(&daftar[jumlah]);
            kelolosanSkorMakanan(&daftar[jumlah]);
            penentuanDistribusi(&daftar[jumlah]);
            tampilHasilMakanan(&daftar[jumlah]);
            jumlah++;
        }
        else if(pilihan == 2){
            tampilkanTabelReferensi();
        }
        else if(pilihan == 3){
            for(int i = 0; i < jumlah; i++) {
                tampilHasilMakanan(&daftar[i]);
            }
        }
    }while(pilihan != 0);
    return 0;
}
