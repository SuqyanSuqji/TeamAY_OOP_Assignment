#include "../include/Makanan.h"
#include <iostream>

using namespace std;

Makanan::Makanan(string nm, double hrg, int stk, bool p)
    : MenuItem(nm, hrg, stk), isPedas(p) {}

Makanan::~Makanan() {}

bool Makanan::cekPedas() const { return isPedas; }

void Makanan::tampilkanDetail() {
  cout << "Nama menu: " << namaMenu << endl
       << "Harga: Rp" << getHarga() << endl;

  if (isPedas) {
    cout << "Pedas\n";
  } else {
    cout << "Tidak Pedas\n";
  }
}

void Makanan::siapkanPesanan() {
  cout << "Sedang memasak " << namaMenu << ".\n";
}