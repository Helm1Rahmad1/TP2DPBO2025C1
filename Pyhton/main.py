from Baju import Baju

def get_next_id(daftar_baju):
    if not daftar_baju:
        return 1
    return max(baju.get_id() for baju in daftar_baju) + 1

def is_valid_input(input_str):
    return " " not in input_str

def tampilkan_tabel(daftar_baju):
    max_id = 2
    max_nama = 10
    max_harga = 5
    max_stok = 4
    max_jenis = 5
    max_bahan = 5
    max_warna = 5
    max_untuk = 5
    max_size = 4
    max_merk = 4

    for baju in daftar_baju:
        max_id = max(max_id, len(str(baju.get_id())))
        max_nama = max(max_nama, len(baju.get_nama_produk()))
        max_harga = max(max_harga, len(str(baju.get_harga_produk())))
        max_stok = max(max_stok, len(str(baju.get_stok_produk())))
        max_jenis = max(max_jenis, len(baju.get_jenis()))
        max_bahan = max(max_bahan, len(baju.get_bahan()))
        max_warna = max(max_warna, len(baju.get_warna()))
        max_untuk = max(max_untuk, len(baju.get_untuk()))
        max_size = max(max_size, len(baju.get_size()))
        max_merk = max(max_merk, len(baju.get_merk()))

    def print_separator():
        print("+-" + "-" * max_id + "-+-" + "-" * max_nama + "-+-" + "-" * max_harga + "-+-" + "-" * max_stok + "-+-" + "-" * max_jenis + "-+-" + "-" * max_bahan + "-+-" + "-" * max_warna + "-+-" + "-" * max_untuk + "-+-" + "-" * max_size + "-+-" + "-" * max_merk + "-+")

    print_separator()
    print(f"| {'ID':<{max_id}} | {'Nama Produk':<{max_nama}} | {'Harga':<{max_harga}} | {'Stok':<{max_stok}} | {'Jenis':<{max_jenis}} | {'Bahan':<{max_bahan}} | {'Warna':<{max_warna}} | {'Untuk':<{max_untuk}} | {'Size':<{max_size}} | {'Merk':<{max_merk}} |")
    print_separator()

    for baju in daftar_baju:
        print(f"| {baju.get_id():<{max_id}} | {baju.get_nama_produk():<{max_nama}} | {baju.get_harga_produk():<{max_harga}} | {baju.get_stok_produk():<{max_stok}} | {baju.get_jenis():<{max_jenis}} | {baju.get_bahan():<{max_bahan}} | {baju.get_warna():<{max_warna}} | {baju.get_untuk():<{max_untuk}} | {baju.get_size():<{max_size}} | {baju.get_merk():<{max_merk}} |")
    print_separator()

def input_data(baju, daftar_baju):
    baju.set_id(get_next_id(daftar_baju))

    while True:
        nama = input("Masukkan Nama Produk: ")
        if is_valid_input(nama):
            baju.set_nama_produk(nama)
            break

    while True:
        try:
            harga = int(input("Masukkan Harga: "))
            baju.set_harga_produk(harga)
            break
        except ValueError:
            print("Input tidak valid. Masukkan angka untuk harga.")

    while True:
        try:
            stok = int(input("Masukkan Stok: "))
            baju.set_stok_produk(stok)
            break
        except ValueError:
            print("Input tidak valid. Masukkan angka untuk stok.")

    while True:
        jenis = input("Masukkan Jenis: ")
        if is_valid_input(jenis):
            baju.set_jenis(jenis)
            break

    while True:
        bahan = input("Masukkan Bahan: ")
        if is_valid_input(bahan):
            baju.set_bahan(bahan)
            break

    while True:
        warna = input("Masukkan Warna: ")
        if is_valid_input(warna):
            baju.set_warna(warna)
            break

    while True:
        untuk = input("Masukkan Untuk: ")
        if is_valid_input(untuk):
            baju.set_untuk(untuk)
            break

    while True:
        size = input("Masukkan Size: ")
        if is_valid_input(size):
            baju.set_size(size)
            break

    while True:
        merk = input("Masukkan Merk: ")
        if is_valid_input(merk):
            baju.set_merk(merk)
            break

def main():
    daftar_baju = [
        Baju(1, "Baju_Anjing", 100000, 10, "Pakaian", "Katun", "Merah", "Anjing", "M", "PetWear"),
        Baju(2, "Baju_Kucing", 120000, 15, "Pakaian", "Wol", "Biru", "Kucing", "L", "MeowStyle"),
        Baju(3, "Jaket_Anjing", 150000, 8, "Pakaian", "Polyester", "Hitam", "Anjing", "XL", "PetCozy"),
        Baju(4, "Kaos_Kucing", 80000, 20, "Pakaian", "Spandex", "Putih", "Kucing", "S", "FurFashion"),
        Baju(5, "Rompi_Anjing", 130000, 12, "Pakaian", "Denim", "Abu-abu", "Anjing", "M", "PawTrend")
    ]

    while True:
        print("\nMenu:")
        print("1. Tampilkan Data")
        print("2. Tambah Data")
        print("3. Keluar")
        choice = input("Pilih opsi: ")

        if choice == '1':
            print("\nDaftar Produk Baju:")
            tampilkan_tabel(daftar_baju)
        elif choice == '2':
            baju_baru = Baju()
            input_data(baju_baru, daftar_baju)
            daftar_baju.append(baju_baru)
            print("Produk berhasil ditambahkan!")
        elif choice == '3':
            print("Keluar dari program...")
            break
        else:
            print("Pilihan tidak valid!")

if __name__ == "__main__":
    main()
