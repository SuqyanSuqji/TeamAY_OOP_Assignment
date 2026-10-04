#include "../include/Minuman.h"
#include <iostream>

using namespace std;

Minuman::Minuman(string nm, double hrg, int stk, bool d)
    : MenuItem(nm, hrg, stk), isDingin(d) {}

Minuman::~Minuman() {}

bool Minuman::cekDingin() const { return isDingin; }

void Minuman::tampilkanDetail() {
  cout << "Nama menu: " << namaMenu << endl
       << "Harga: Rp" << getHarga() << endl;

  if (isDingin) {
    cout << "Dingin\n";
  } else {
    cout << "Tidak Dingin\n";
  }
}

void Minuman::siapkanPesanan() {
  cout << "Sedang menyiapkan " << namaMenu << ".\n";
}