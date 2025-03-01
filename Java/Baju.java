class Baju extends Aksesoris {
    private String untuk;
    private String size;
    private String merk;

    public Baju() {
        this.untuk = "";
        this.size = "";
        this.merk = "";
    }

    public Baju(int id, String nama, int harga, int stok, String jenis, String bahan, String warna, String untuk, String size, String merk) {
        super(id, nama, harga, stok, jenis, bahan, warna);
        this.untuk = untuk;
        this.size = size;
        this.merk = merk;
    }

    public void setUntuk(String untuk) {
        this.untuk = untuk;
    }

    public String getUntuk() {
        return untuk;
    }

    public void setSize(String size) {
        this.size = size;
    }

    public String getSize() {
        return size;
    }

    public void setMerk(String merk) {
        this.merk = merk;
    }

    public String getMerk() {
        return merk;
    }

    public void tampilkanData(int panjangId, int panjangNama, int panjangHarga, int panjangStok, int panjangJenis, int panjangBahan, int panjangWarna, int panjangUntuk, int panjangSize, int panjangMerk) {
        super.tampilkanData(panjangId, panjangNama, panjangHarga, panjangStok, panjangJenis, panjangBahan, panjangWarna);
        System.out.printf("%-" + panjangUntuk + "s%-" + panjangSize + "s%-" + panjangMerk + "s%n", untuk, size, merk);
    }
}