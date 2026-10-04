#pragma once
#include "MenuItem.h"
#include <string>

class Makanan : public MenuItem {
private:
  bool isPedas;

public:
  Makanan(std::string nm, double hrg, int stk, bool p);
  ~Makanan();

  bool cekPedas() const;
  void tampilkanDetail() override;
  void siapkanPesanan() override;
};