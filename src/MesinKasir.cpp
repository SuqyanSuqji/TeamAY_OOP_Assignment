#include "../include/MesinKasir.h"
#include <iostream>

using namespace std;

MesinKasir::MesinKasir() { totalHarga = 0.0; }

MesinKasir::~MesinKasir() {
  for (MenuItem* item : daftarMenu) {
    delete item;
  }
  daftarMenu.clear();
}

double MesinKasir::hitungPajak(double subtotal) { return subtotal * 0.11; }

void MesinKasir::setupMenuAwal(MenuItem* item) { daftarMenu.push_back(item); }

void MesinKasir::tampilkanKatalog() {
  cout << "\nKATALOG MENU WARMINDO AY" << endl;
  for (size_t i = 0; i < daftarMenu.size(); i++) {
    cout << "[" << i + 1 << "] ";
    daftarMenu[i]->tampilkanDetail();
    cout << "Stok tersedia: " << daftarMenu[i]->getStok() << endl;
    cout << "---------------------------------" << endl;
  }
  cout << endl;
}

void MesinKasir::tambahKePesanan(int indexMenu, int jumlahPorsi) {
  if (indexMenu < 1 || indexMenu > (int)daftarMenu.size()) {
    cout << "Nomor menu tidak valid!\n";
    return;
  }

  int indexNyata = indexMenu - 1;
  MenuItem* menuPilihan = daftarMenu[indexNyata];

  if (menuPilihan->getStok() >= jumlahPorsi) {
    menuPilihan->kurangiStok(jumlahPorsi);

    for (int i = 0; i < jumlahPorsi; i++) {
      daftarPesanan.push_back(menuPilihan);
    }

    cout << "Berhasil menambahkan " << jumlahPorsi << " porsi "
         << menuPilihan->getNamaMenu() << " ke keranjang!\n";
  } else {
    cout << "Stok tidak mencukupi! Sisa stok: " << menuPilihan->getStok()
         << endl;
  }
  cout << endl;
}

void MesinKasir::cetakNota() {
  if (daftarPesanan.empty()) {
    cout << "\nKeranjang pesanan masih kosong!\n";
    return;
  }

  cout << "\nNOTA PEMESANAN" << endl;
  cout << "=================================" << endl;

  double subtotal = 0.0;

  for (MenuItem* item : daftarPesanan) {
    item->tampilkanDetail();
    item->siapkanPesanan();
    cout << "---------------------------------" << endl;
    subtotal += item->getHarga();
  }

  double pajak = hitungPajak(subtotal);
  totalHarga = subtotal + pajak;

  cout << "Subtotal    : Rp" << subtotal << endl;
  cout << "Pajak (11%) : Rp" << pajak << endl;
  cout << "=================================" << endl;
  cout << "TOTAL BAYAR : Rp" << totalHarga << endl;
  cout << "Terima kasih atas kunjungannya!\n\n";

  daftarPesanan.clear();
}