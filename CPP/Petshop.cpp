#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <vector>

using namespace std;

class PetShop {
private:
    int id;
    string nama_produk;
    int harga_produk;
    int stok_produk;

public:
    PetShop() {
        this->id = 0;
        this->nama_produk = "";
        this->harga_produk = 0;
        this->stok_produk = 0;
    }

    PetShop(int id, string nama_produk, int harga_produk, int stok_produk) {
        this->id = id;
        this->nama_produk = nama_produk;
        this->harga_produk = harga_produk;
        this->stok_produk = stok_produk;
    }

    void setId(int id) {this->id = id;}
    int getId() const {return id;}

    void setNamaProduk(string nama_produk) {this->nama_produk = nama_produk;}
    string getNamaProduk() const {return nama_produk;}

    void setHargaProduk(int harga_produk) {this->harga_produk = harga_produk;}
    int getHargaProduk() const {return harga_produk;}

    void setStokProduk(int stok_produk) {this->stok_produk = stok_produk;}
    int getStokProduk() const {return stok_produk;}

    void tampilkanData(int panjang_id, int panjang_nama, int panjang_harga, int panjang_stok) const {
        cout << left << setw(panjang_id) << id
             << setw(panjang_nama) << nama_produk
             << setw(panjang_harga) << harga_produk
             << setw(panjang_stok) << stok_produk;
    }

    ~PetShop() {}
};