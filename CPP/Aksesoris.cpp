#include "Petshop.cpp"

using namespace std;

class Aksesoris : public PetShop {
private:
    string jenis;
    string bahan;
    string warna;

public:
    Aksesoris() {
        this->jenis = "";
        this->bahan = "";
        this->warna = "";
    }

    Aksesoris(int id, string namaProduk, int hargaProduk, int stokProduk, string jenis, string bahan, string warna) 
        : PetShop(id, namaProduk, hargaProduk, stokProduk), jenis(jenis), bahan(bahan), warna(warna) {
            this->jenis = jenis;
            this->bahan = bahan;
            this->warna = warna;
        }

    void setJenis(const string &jenis) {this->jenis = jenis;}
    string getJenis() const {return jenis;}

    void setBahan(const string &bahan) {this->bahan = bahan;}
    string getBahan() const {return bahan;}

    void setWarna(const string &warna) {this->warna = warna;}
    string getWarna() const {return warna;}

    void tampilkanData(int panjang_id, int panjang_nama, int panjang_harga, int panjang_stok, int panjang_jenis, int panjang_bahan, int panjang_warna) const {
        PetShop::tampilkanData(panjang_id, panjang_nama, panjang_harga, panjang_stok);
        cout << setw(panjang_jenis) << jenis
             << setw(panjang_bahan) << bahan
             << setw(panjang_warna) << warna;
    }

    ~Aksesoris() {}
};