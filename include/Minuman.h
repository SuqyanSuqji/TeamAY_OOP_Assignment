#pragma once
#include "MenuItem.h"
#include <string>

class Minuman : public MenuItem {
private:
  bool isDingin;

public:
  Minuman(std::string nm, double hrg, int stk, bool d);
  ~Minuman();

  bool cekDingin() const;
  void tampilkanDetail() override;
  void siapkanPesanan() override;
};