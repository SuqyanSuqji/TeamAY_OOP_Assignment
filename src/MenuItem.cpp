#include "../include/MenuItem.h"
#include <iostream>

using namespace std;

MenuItem::MenuItem(const string& n, double h, int s)
    : namaMenu(n), harga(h), stok(s) {}

MenuItem::~MenuItem() {}

string MenuItem::getNamaMenu() const { return namaMenu; }

double MenuItem::getHarga() const { return harga; }

int MenuItem::getStok() const { return stok; }

void MenuItem::setHarga(double hargaBaru) {
  if (hargaBaru > 0) {
    harga = hargaBaru;
  } else {
    cout << "Harga tidak boleh negatif!\n";
  }
}

void MenuItem::kurangiStok(int jumlah) {
  if (stok >= jumlah) {
    stok -= jumlah;
  } else {
    cout << "Jumlah tidak cukup!\n";
  }
}