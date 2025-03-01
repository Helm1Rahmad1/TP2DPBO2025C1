class PetShop:
    def __init__(self, id=0, nama_produk="", harga_produk=0, stok_produk=0):
        self.id = id
        self.nama_produk = nama_produk
        self.harga_produk = harga_produk
        self.stok_produk = stok_produk

    def set_id(self, id):
        self.id = id

    def get_id(self):
        return self.id

    def set_nama_produk(self, nama_produk):
        self.nama_produk = nama_produk

    def get_nama_produk(self):
        return self.nama_produk

    def set_harga_produk(self, harga_produk):
        self.harga_produk = harga_produk

    def get_harga_produk(self):
        return self.harga_produk

    def set_stok_produk(self, stok_produk):
        self.stok_produk = stok_produk

    def get_stok_produk(self):
        return self.stok_produk

    def tampilkan_data(self, panjang_id, panjang_nama, panjang_harga, panjang_stok):
        print(f"{self.id:<{panjang_id}} {self.nama_produk:<{panjang_nama}} {self.harga_produk:<{panjang_harga}} {self.stok_produk:<{panjang_stok}}", end=' ')


class Aksesoris(PetShop):
    def __init__(self, id=0, nama_produk="", harga_produk=0, stok_produk=0, jenis="", bahan="", warna=""):
        super().__init__(id, nama_produk, harga_produk, stok_produk)
        self.jenis = jenis
        self.bahan = bahan
        self.warna = warna

    def set_jenis(self, jenis):
        self.jenis = jenis

    def get_jenis(self):
        return self.jenis

    def set_bahan(self, bahan):
        self.bahan = bahan

    def get_bahan(self):
        return self.bahan

    def set_warna(self, warna):
        self.warna = warna

    def get_warna(self):
        return self.warna

    def tampilkan_data(self, panjang_id, panjang_nama, panjang_harga, panjang_stok, panjang_jenis, panjang_bahan, panjang_warna):
        super().tampilkan_data(panjang_id, panjang_nama, panjang_harga, panjang_stok)
        print(f"{self.jenis:<{panjang_jenis}} {self.bahan:<{panjang_bahan}} {self.warna:<{panjang_warna}}")
