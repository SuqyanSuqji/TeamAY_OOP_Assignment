# Aplikasi Kasir Warmindo AY

## Deskripsi Aplikasi

Judul Projek: Aplikasi Kasir Warmindo AY Berbasis CLI Menggunakan Konsep Pemrograman Berorientasi Objek (Object-Oriented Programming/OOP) dalam C++

Aplikasi ini adalah sistem kasir berbasis Command-Line Interface (CLI) yang bersifat modular dan memungkinkan pengguna untuk:

- Menampilkan katalog menu makanan dan minuman secara dinamis
- Menambahkan menu pilihan beserta jumlah porsi ke dalam keranjang belanja
- Memvalidasi ketersediaan stok secara otomatis agar pemesanan tidak melebihi batas stok
- Menghitung subtotal transaksi beserta pajak tetap sebesar 11%
- Mencetak nota pembayaran dan mengosongkan keranjang secara otomatis setelah transaksi selesai

Konsep OOP yang diterapkan:

- **Encapsulation**: Menyembunyikan data sensitif seperti harga dan perhitungan pajak
- **Inheritance**: Memanfaatkan struktur hierarki (`MenuItem` sebagai induk, `Makanan` dan `Minuman` sebagai anak)
- **Polymorphism**: Pemanggilan fungsi `tampilkanDetail()` dan `siapkanPesanan()` yang menyesuaikan perilakunya dengan tipe objek (Makanan atau Minuman)
- **Abstraction**: Menggunakan interface (`IPrintable`) dan abstract class (`MenuItem`)

---

## Anggota Projek (NIM | Nama)

- 25/557140/TK/62874 | Muhammad Yusuf Akbar
- 25/564730/TK/63707 | Suqyan Yanur Aji

---

## Struktur Direktori

Struktur direktori proyek dipisahkan ke dalam folder modular `include` dan `src`:

```text
.
├── compile_win.bat           # Skrip otomatis untuk kompilasi dan eksekusi (Windows)
├── main.cpp                  # Berkas utama untuk antarmuka pengguna CLI
├── README.md                 # Dokumentasi resmi proyek
├── include/                  # Direktori berkas header (.h)
│   ├── IPrintable.h          # Antarmuka dasar (Interface)
│   ├── MenuItem.h            # Kelas abstrak induk (Abstract Base Class)
│   ├── Makanan.h             # Kelas turunan untuk menu makanan
│   ├── Minuman.h             # Kelas turunan untuk menu minuman
│   └── MesinKasir.h          # Kelas pengelola transaksi dan keranjang
└── src/                      # Direktori berkas sumber (.cpp)
    ├── Makanan.cpp           # Implementasi metode kelas Makanan
    ├── MenuItem.cpp          # Implementasi metode kelas MenuItem
    ├── MesinKasir.cpp        # Implementasi metode kelas MesinKasir
    └── Minuman.cpp           # Implementasi metode kelas Minuman
```

---

## Cara Menjalankan Projek

### Persyaratan Sistem

- Pastikan Anda memiliki compiler C++ (contoh: `g++` yang mendukung standar C++11 atau lebih baru).
- Pastikan Anda berada di dalam direktori utama proyek melalui terminal (Command Prompt, PowerShell, atau terminal berbasis MinGW/MSYS2).

### 1) Kompilasi Program (Manual)

Jalankan perintah berikut pada terminal untuk menggabungkan seluruh berkas sumber:

```bash
g++ main.cpp src/MenuItem.cpp src/Makanan.cpp src/Minuman.cpp src/MesinKasir.cpp -o program_kasir
```

### 2) Kompilasi Program (Otomatis, khusus Windows)

Sebagai alternatif, jalankan berkas batch yang telah disediakan di direktori utama:

```bat
compile_win.bat
```

Perintah di atas akan menghasilkan berkas aplikasi (executable) bernama `program_kasir.exe`.

### 3) Menjalankan Aplikasi

Windows:

```bat
program_kasir.exe
```

macOS / Linux:

```bash
./program_kasir
```

---
