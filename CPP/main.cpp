#include <iostream>
#include <iomanip>
#include <list>
#include <algorithm>
#include <limits>
#include "Baju.cpp"

using namespace std;

int currentID = 1;

void tampilkanTabel(const list<Baju> &daftarBaju) {
    size_t maxID = 2, maxNama = 10, maxHarga = 5, maxStok = 4, maxJenis = 5, maxBahan = 5, maxWarna = 5, maxUntuk = 5, maxSize = 4, maxMerk = 4;
    
    for (const auto &baju : daftarBaju) {
        maxID = max(maxID, to_string(baju.getId()).size());
        maxNama = max(maxNama, baju.getNamaProduk().size());
        maxHarga = max(maxHarga, to_string(baju.getHargaProduk()).size());
        maxStok = max(maxStok, to_string(baju.getStokProduk()).size());
        maxJenis = max(maxJenis, baju.getJenis().size());
        maxBahan = max(maxBahan, baju.getBahan().size());
        maxWarna = max(maxWarna, baju.getWarna().size());
        maxUntuk = max(maxUntuk, baju.getUntuk().size());
        maxSize = max(maxSize, baju.getSize().size());
        maxMerk = max(maxMerk, baju.getMerk().size());
    }
    
    // Membuat garis pemisah
    auto printSeparator = [&]() {
        cout << "+-" << string(maxID, '-') 
             << "-+-" << string(maxNama, '-') 
             << "-+-" << string(maxHarga, '-') 
             << "-+-" << string(maxStok, '-') 
             << "-+-" << string(maxJenis, '-') 
             << "-+-" << string(maxBahan, '-') 
             << "-+-" << string(maxWarna, '-') 
             << "-+-" << string(maxUntuk, '-') 
             << "-+-" << string(maxSize, '-') 
             << "-+-" << string(maxMerk, '-') 
             << "-+" << endl;
    };
    
    // Header tabel
    printSeparator();
    cout << "| " << left << setw(maxID) << "ID"
         << " | " << setw(maxNama) << "Nama Produk"
         << " | " << setw(maxHarga) << "Harga"
         << " | " << setw(maxStok) << "Stok"
         << " | " << setw(maxJenis) << "Jenis"
         << " | " << setw(maxBahan) << "Bahan"
         << " | " << setw(maxWarna) << "Warna"
         << " | " << setw(maxUntuk) << "Untuk"
         << " | " << setw(maxSize) << "Size"
         << " | " << setw(maxMerk) << "Merk"
         << " |" << endl;
    printSeparator();
    
    // Data produk
    for (const auto &baju : daftarBaju) {
        cout << "| " << left << setw(maxID) << baju.getId()
             << " | " << setw(maxNama) << baju.getNamaProduk()
             << " | " << setw(maxHarga) << baju.getHargaProduk()
             << " | " << setw(maxStok) << baju.getStokProduk()
             << " | " << setw(maxJenis) << baju.getJenis()
             << " | " << setw(maxBahan) << baju.getBahan()
             << " | " << setw(maxWarna) << baju.getWarna()
             << " | " << setw(maxUntuk) << baju.getUntuk()
             << " | " << setw(maxSize) << baju.getSize()
             << " | " << setw(maxMerk) << baju.getMerk()
             << " |" << endl;
    }
    printSeparator();
}

void inputData(Baju &baju) {
    int harga, stok;
    string nama, jenis, bahan, warna, untuk, size, merk;

    baju.setId(currentID++);

    cout << "Masukkan Nama Produk: ";
    cin >> nama;
    baju.setNamaProduk(nama);

    while (true) {
        cout << "Masukkan Harga: ";
        cin >> harga;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Input tidak valid. Masukkan angka untuk harga.\n";
        } else {
            baju.setHargaProduk(harga);
            break;
        }
    }

    while (true) {
        cout << "Masukkan Stok: ";
        cin >> stok;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        } else {
            baju.setStokProduk(stok);
            break;
        }
    }

    cout << "Masukkan Jenis: ";
    cin >> jenis;
    baju.setJenis(jenis);

    cout << "Masukkan Bahan: ";
    cin >> bahan;
    baju.setBahan(bahan);

    cout << "Masukkan Warna: ";
    cin >> warna;
    baju.setWarna(warna);

    cout << "Masukkan Untuk: ";
    cin >> untuk;
    baju.setUntuk(untuk);

    cout << "Masukkan Size: ";
    cin >> size;
    baju.setSize(size);

    cout << "Masukkan Merk: ";
    cin >> merk;
    baju.setMerk(merk);
}


int main() {
    list<Baju> daftarBaju = {
        Baju(currentID++, "Baju_Anjing", 100000, 10, "Pakaian", "Katun", "Merah", "Anjing", "M", "PetWear"),
        Baju(currentID++, "Baju_Kucing", 120000, 15, "Pakaian", "Wol", "Biru", "Kucing", "L", "MeowStyle"),
        Baju(currentID++, "Jaket_Anjing", 150000, 8, "Pakaian", "Polyester", "Hitam", "Anjing", "XL", "PetCozy"),
        Baju(currentID++, "Kaos_Kucing", 80000, 20, "Pakaian", "Spandex", "Putih", "Kucing", "S", "FurFashion"),
        Baju(currentID++, "Rompi_Anjing", 130000, 12, "Pakaian", "Denim", "Abu-abu", "Anjing", "M", "PawTrend")
    };

    int choice;
    do {
        cout << "1. Tampilkan Data\n";
        cout << "2. Tambah Data\n";
        cout << "3. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "\nDaftar Produk Baju:\n";
                tampilkanTabel(daftarBaju);
                break;
            case 2: {
                Baju bajuBaru;
                inputData(bajuBaru);
                daftarBaju.push_back(bajuBaru);
                cout << "Produk berhasil ditambahkan!\n";
                break;
            }
            case 3:
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 3);
    
    return 0;
}