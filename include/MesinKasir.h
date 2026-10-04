#pragma once
#include "MenuItem.h"
#include <vector>

class MesinKasir {
private:
  std::vector<MenuItem*> daftarMenu;
  std::vector<MenuItem*> daftarPesanan;
  double totalHarga;

  double hitungPajak(double subtotal);

public:
  MesinKasir();
  ~MesinKasir();

  void setupMenuAwal(MenuItem* item);
  void tampilkanKatalog();
  void tambahKePesanan(int indexMenu, int jumlahPorsi);
  void cetakNota();
};