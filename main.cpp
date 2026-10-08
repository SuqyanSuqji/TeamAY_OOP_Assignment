#include "include/Makanan.h"
#include "include/MesinKasir.h"
#include "include/Minuman.h"
#include <iostream>

using namespace std;

void interface(MesinKasir& kasir);

int main() {
  MesinKasir kasir;

  kasir.setupMenuAwal(new Makanan("Nasi Goreng", 11000, 15, true));
  kasir.setupMenuAwal(new Makanan("Magelangan", 13000, 20, true));
  kasir.setupMenuAwal(new Makanan("Nasi Ayam Orak-arik", 13000, 15, false));
  kasir.setupMenuAwal(new Makanan("Nasi Ayam Geprek", 10000, 25, true));
  kasir.setupMenuAwal(new Makanan("Mie Instan", 8000, 25, false));

  kasir.setupMenuAwal(new Minuman("Es Teh", 3000, 30, true));
  kasir.setupMenuAwal(new Minuman("Es Jeruk", 5000, 20, true));
  kasir.setupMenuAwal(new Minuman("Kopi", 4000, 15, false));

  interface(kasir);

  system("pause");
  return 0;
}

void interface(MesinKasir& kasir) {
  int pilihan;
  do {
    cout << "APLIKASI KASIR WARMINDO AY" << endl;
    cout << "1. Tampilkan Katalog Menu" << endl;
    cout << "2. Tambah Pesanan ke Keranjang" << endl;
    cout << "3. Cetak Nota & Selesaikan Transaksi" << endl;
    cout << "4. Keluar Program" << endl;
    cout << "Pilihan Anda (1-4): ";
    cin >> pilihan;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Input tidak valid! Harap masukkan angka.\n";
      continue;
    }

    switch (pilihan) {
    case 1:
      kasir.tampilkanKatalog();
      break;
    case 2: {
      kasir.tampilkanKatalog();
      int nomorMenu, porsi;
      cout << "Masukkan nomor menu yang ingin dipesan: ";
      cin >> nomorMenu;
      cout << "Masukkan jumlah porsi: ";
      cin >> porsi;
      kasir.tambahKePesanan(nomorMenu, porsi);
      break;
    }
    case 3:
      kasir.cetakNota();
      break;
    case 4:
      cout << "\nProgram ditutup. Terima kasih!\n\n";
      break;
    default:
      cout << "\nPilihan tidak valid! Silakan coba lagi.\n\n";
    }
  } while (pilihan != 4);
}