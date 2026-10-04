#include <iostream>
#include <string>
#include <vector>
using namespace std;

class IPrintable {
public:
  virtual void tampilkanDetail() = 0;
};

class MenuItem : public IPrintable {
private:
  double harga;
  int stok;

protected:
  string namaMenu;

public:
  MenuItem(const string& n, double h, int s) : namaMenu(n), harga(h), stok(s) {}
  virtual ~MenuItem() {}
  string getNamaMenu() const { return namaMenu; }
  double getHarga() const { return harga; }
  int getStok() const { return stok; }
  void setHarga(double hargaBaru) {
    if (hargaBaru > 0) {
      harga = hargaBaru;
    } else {
      cout << "Harga tidak boleh negatif!";
    };
  }
  void kurangiStok(int jumlah) {
    if (stok >= jumlah) {
      stok -= jumlah;
    } else {
      cout << "Jumlah tidak cukup!";
    };
  }
  virtual void siapkanPesanan() = 0;
};

class Makanan : public MenuItem {
private:
  bool isPedas;

public:
  Makanan(string nm, double hrg, int stk, bool p)
      : MenuItem(nm, hrg, stk), isPedas(p) {}
  ~Makanan() {}
  bool cekPedas() const { return isPedas; }
  void tampilkanDetail() override {
    cout << "Nama menu: " << namaMenu << endl
         << "Harga: Rp" << getHarga() << endl;
    if (isPedas == true) {
      cout << "Pedas\n";
    } else {
      cout << "Tidak Pedas\n";
    }
  }
  void siapkanPesanan() override {
    cout << "Sedang memasak " << namaMenu << ".\n";
  }
};

class Minuman : public MenuItem {
private:
  bool isDingin;

public:
  Minuman(string nm, double hrg, int stk, bool d)
      : MenuItem(nm, hrg, stk), isDingin(d) {}
  ~Minuman() {}
  bool cekDingin() const { return isDingin; }
  void tampilkanDetail() override {
    cout << "Nama menu: " << namaMenu << endl
         << "Harga: Rp" << getHarga() << endl;
    if (isDingin == true) {
      cout << "Dingin\n";
    } else {
      cout << "Tidak Dingin\n";
    }
  }
  void siapkanPesanan() override {
    cout << "Sedang menyiapkan " << namaMenu << ".\n";
  }
};

class MesinKasir {
private:
  vector<MenuItem*> daftarMenu;
  vector<MenuItem*> daftarPesanan;
  double totalHarga;

  double hitungPajak(double subtotal) { return subtotal * 0.11; }

public:
  MesinKasir() { totalHarga = 0.0; }

  ~MesinKasir() {
    for (MenuItem* item : daftarMenu) {
      delete item;
    }
    daftarMenu.clear();
  }

  void setupMenuAwal(MenuItem* item) { daftarMenu.push_back(item); }

  void tampilkanKatalog() {
    cout << "\nKATALOG MENU WARMINDO AY" << endl;
    for (size_t i = 0; i < daftarMenu.size(); i++) {
      cout << "[" << i + 1 << "] ";
      daftarMenu[i]->tampilkanDetail();
      cout << "Stok tersedia: " << daftarMenu[i]->getStok() << endl;
      cout << "---------------------------------" << endl;
    }
    cout << endl;
  }

  void tambahKePesanan(int indexMenu, int jumlahPorsi) {
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

  void cetakNota() {
    if (daftarPesanan.empty()) {
      cout << "\nKeranjang pesanan masih kosong!\n";
      return;
    }

    cout << "\nSTRUK PEMESANAN" << endl;
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
};

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

    // Validasi pengaman kalau user iseng ngetik huruf
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
      cout << "\nProgram ditutup. Terima kasih!\n";
      break;
    default:
      cout << "\nPilihan tidak valid! Silakan coba lagi.\n";
    }
  } while (pilihan != 4);
}