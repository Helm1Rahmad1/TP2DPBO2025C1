class PetShop {
    private int id;
    private String namaProduk;
    private int hargaProduk;
    private int stokProduk;

    public PetShop() {
        this.id = 0;
        this.namaProduk = "";
        this.hargaProduk = 0;
        this.stokProduk = 0;
    }

    public PetShop(int id, String namaProduk, int hargaProduk, int stokProduk) {
        this.id = id;
        this.namaProduk = namaProduk;
        this.hargaProduk = hargaProduk;
        this.stokProduk = stokProduk;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getId() {
        return id;
    }

    public void setNamaProduk(String namaProduk) {
        this.namaProduk = namaProduk;
    }

    public String getNamaProduk() {
        return namaProduk;
    }

    public void setHargaProduk(int hargaProduk) {
        this.hargaProduk = hargaProduk;
    }

    public int getHargaProduk() {
        return hargaProduk;
    }

    public void setStokProduk(int stokProduk) {
        this.stokProduk = stokProduk;
    }

    public int getStokProduk() {
        return stokProduk;
    }

    public void tampilkanData(int panjangId, int panjangNama, int panjangHarga, int panjangStok) {
        System.out.printf("%-" + panjangId + "d%-" + panjangNama + "s%-" + panjangHarga + "d%-" + panjangStok + "d", id, namaProduk, hargaProduk, stokProduk);
    }
}