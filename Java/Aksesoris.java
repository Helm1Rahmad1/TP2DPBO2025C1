class Aksesoris extends PetShop {
    private String jenis;
    private String bahan;
    private String warna;

    public Aksesoris() {
        this.jenis = "";
        this.bahan = "";
        this.warna = "";
    }

    public Aksesoris(int id, String namaProduk, int hargaProduk, int stokProduk, String jenis, String bahan, String warna) {
        super(id, namaProduk, hargaProduk, stokProduk);
        this.jenis = jenis;
        this.bahan = bahan;
        this.warna = warna;
    }

    public void setJenis(String jenis) {
        this.jenis = jenis;
    }

    public String getJenis() {
        return jenis;
    }

    public void setBahan(String bahan) {
        this.bahan = bahan;
    }

    public String getBahan() {
        return bahan;
    }

    public void setWarna(String warna) {
        this.warna = warna;
    }

    public String getWarna() {
        return warna;
    }

    public void tampilkanData(int panjangId, int panjangNama, int panjangHarga, int panjangStok, int panjangJenis, int panjangBahan, int panjangWarna) {
        super.tampilkanData(panjangId, panjangNama, panjangHarga, panjangStok);
        System.out.printf("%-" + panjangJenis + "s%-" + panjangBahan + "s%-" + panjangWarna + "s", jenis, bahan, warna);
    }
}