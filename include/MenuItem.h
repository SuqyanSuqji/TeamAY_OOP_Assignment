#pragma once
#include "IPrintable.h"
#include <string>

class MenuItem : public IPrintable {
private:
  double harga;
  int stok;

protected:
  std::string namaMenu;

public:
  MenuItem(const std::string& n, double h, int s);
  virtual ~MenuItem();

  std::string getNamaMenu() const;
  double getHarga() const;
  int getStok() const;

  void setHarga(double hargaBaru);
  void kurangiStok(int jumlah);

  virtual void siapkanPesanan() = 0;
};