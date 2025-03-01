from Aksesoris import Aksesoris

class Baju(Aksesoris):
    def __init__(self, id=0, nama_produk="", harga_produk=0, stok_produk=0, jenis="", bahan="", warna="", untuk="", size="", merk=""):
        super().__init__(id, nama_produk, harga_produk, stok_produk, jenis, bahan, warna)
        self.untuk = untuk
        self.size = size
        self.merk = merk

    def set_untuk(self, untuk):
        self.untuk = untuk

    def get_untuk(self):
        return self.untuk

    def set_size(self, size):
        self.size = size

    def get_size(self):
        return self.size

    def set_merk(self, merk):
        self.merk = merk

    def get_merk(self):
        return self.merk

    def tampilkan_data(self, panjang_id, panjang_nama, panjang_harga, panjang_stok, panjang_jenis, panjang_bahan, panjang_warna, panjang_untuk, panjang_size, panjang_merk):
        super().tampilkan_data(panjang_id, panjang_nama, panjang_harga, panjang_stok, panjang_jenis, panjang_bahan, panjang_warna)
        print(f"{self.untuk:<{panjang_untuk}} {self.size:<{panjang_size}} {self.merk:<{panjang_merk}}")
