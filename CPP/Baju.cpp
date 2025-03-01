#include "Aksesoris.cpp"

using namespace std;

class Baju : public Aksesoris {
private:
    string untuk;
    string size;
    string merk;

public:
    Baju() {
        this->untuk = "";
        this->size = "";
        this->merk = "";
    }

    Baju(int id, string nama, int harga, int stok, string jenis, string bahan, string warna, 
         string untuk, string size, string merk)
        : Aksesoris(id, nama, harga, stok, jenis, bahan, warna), untuk(untuk), size(size), merk(merk) {
            this->untuk = untuk;    
            this->size = size;
            this->merk = merk;
        }

    void setUntuk(const string &untuk) { this->untuk = untuk; }
    string getUntuk() const { return untuk; }

    void setSize(const string &size) { this->size = size; }
    string getSize() const { return size; }

    void setMerk(const string &merk) { this->merk = merk; }
    string getMerk() const { return merk; }

    void tampilkanData(int panjang_id, int panjang_nama, int panjang_harga, int panjang_stok, int panjang_jenis, int panjang_bahan, int panjang_warna, int panjang_untuk, int panjang_size, int panjang_merk) const {
        Aksesoris::tampilkanData(panjang_id, panjang_nama, panjang_harga, panjang_stok, panjang_jenis, panjang_bahan, panjang_warna);
        cout << setw(panjang_untuk) << untuk
             << setw(panjang_size) << size
             << setw(panjang_merk) << merk
             << endl;
    }

    ~Baju() {}
};
