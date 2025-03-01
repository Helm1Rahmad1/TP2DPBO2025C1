import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static int currentID = 1;

    public static void tampilkanTabel(List<Baju> daftarBaju) {
        int maxID = 2, maxNama = 10, maxHarga = 5, maxStok = 4, maxJenis = 5, maxBahan = 5, maxWarna = 5, maxUntuk = 5, maxSize = 4, maxMerk = 4;

        for (Baju baju : daftarBaju) {
            maxID = Math.max(maxID, String.valueOf(baju.getId()).length());
            maxNama = Math.max(maxNama, baju.getNamaProduk().length());
            maxHarga = Math.max(maxHarga, String.valueOf(baju.getHargaProduk()).length());
            maxStok = Math.max(maxStok, String.valueOf(baju.getStokProduk()).length());
            maxJenis = Math.max(maxJenis, baju.getJenis().length());
            maxBahan = Math.max(maxBahan, baju.getBahan().length());
            maxWarna = Math.max(maxWarna, baju.getWarna().length());
            maxUntuk = Math.max(maxUntuk, baju.getUntuk().length());
            maxSize = Math.max(maxSize, baju.getSize().length());
            maxMerk = Math.max(maxMerk, baju.getMerk().length());
        }

        String separator = "+-" + "-".repeat(maxID) + "-+-" + "-".repeat(maxNama) + "-+-" + "-".repeat(maxHarga) + "-+-" + "-".repeat(maxStok) + "-+-" + "-".repeat(maxJenis) + "-+-" + "-".repeat(maxBahan) + "-+-" + "-".repeat(maxWarna) + "-+-" + "-".repeat(maxUntuk) + "-+-" + "-".repeat(maxSize) + "-+-" + "-".repeat(maxMerk) + "-+";

        System.out.println(separator);
        System.out.printf("| %-" + maxID + "s | %-" + maxNama + "s | %-" + maxHarga + "s | %-" + maxStok + "s | %-" + maxJenis + "s | %-" + maxBahan + "s | %-" + maxWarna + "s | %-" + maxUntuk + "s | %-" + maxSize + "s | %-" + maxMerk + "s |%n", "ID", "Nama Produk", "Harga", "Stok", "Jenis", "Bahan", "Warna", "Untuk", "Size", "Merk");
        System.out.println(separator);

        for (Baju baju : daftarBaju) {
            System.out.printf("| %-" + maxID + "d | %-" + maxNama + "s | %-" + maxHarga + "d | %-" + maxStok + "d | %-" + maxJenis + "s | %-" + maxBahan + "s | %-" + maxWarna + "s | %-" + maxUntuk + "s | %-" + maxSize + "s | %-" + maxMerk + "s |%n", baju.getId(), baju.getNamaProduk(), baju.getHargaProduk(), baju.getStokProduk(), baju.getJenis(), baju.getBahan(), baju.getWarna(), baju.getUntuk(), baju.getSize(), baju.getMerk());
        }
        System.out.println(separator);
    }

    public static void inputData(Baju baju) {
        Scanner scanner = new Scanner(System.in);

        baju.setId(currentID++);
        System.out.print("Masukkan Nama Produk: ");
        baju.setNamaProduk(scanner.nextLine());

        while (true) {
            try {
                System.out.print("Masukkan Harga: ");
                baju.setHargaProduk(Integer.parseInt(scanner.nextLine()));
                break;
            } catch (NumberFormatException e) {
                System.out.println("Input tidak valid. Masukkan angka untuk harga.");
            }
        }

        while (true) {
            try {
                System.out.print("Masukkan Stok: ");
                baju.setStokProduk(Integer.parseInt(scanner.nextLine()));
                break;
            } catch (NumberFormatException e) {
                System.out.println("Input tidak valid. Masukkan angka untuk stok.");
            }
        }

        System.out.print("Masukkan Jenis: ");
        baju.setJenis(scanner.nextLine());

        System.out.print("Masukkan Bahan: ");
        baju.setBahan(scanner.nextLine());

        System.out.print("Masukkan Warna: ");
        baju.setWarna(scanner.nextLine());

        System.out.print("Masukkan Untuk: ");
        baju.setUntuk(scanner.nextLine());

        System.out.print("Masukkan Size: ");
        baju.setSize(scanner.nextLine());

        System.out.print("Masukkan Merk: ");
        baju.setMerk(scanner.nextLine());
    }

    public static void main(String[] args) {
        List<Baju> daftarBaju = new ArrayList<>();
        daftarBaju.add(new Baju(currentID++, "Baju_Anjing", 100000, 10, "Pakaian", "Katun", "Merah", "Anjing", "M", "PetWear"));
        daftarBaju.add(new Baju(currentID++, "Baju_Kucing", 120000, 15, "Pakaian", "Wol", "Biru", "Kucing", "L", "MeowStyle"));
        daftarBaju.add(new Baju(currentID++, "Jaket_Anjing", 150000, 8, "Pakaian", "Polyester", "Hitam", "Anjing", "XL", "PetCozy"));
        daftarBaju.add(new Baju(currentID++, "Kaos_Kucing", 80000, 20, "Pakaian", "Spandex", "Putih", "Kucing", "S", "FurFashion"));
        daftarBaju.add(new Baju(currentID++, "Rompi_Anjing", 130000, 12, "Pakaian", "Denim", "Abu-abu", "Anjing", "M", "PawTrend"));

        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("1. Tampilkan Data");
            System.out.println("2. Tambah Data");
            System.out.println("3. Keluar");
            System.out.print("Pilih opsi: ");
            choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    System.out.println("\nDaftar Produk Baju:");
                    tampilkanTabel(daftarBaju);
                    break;
                case 2:
                    Baju bajuBaru = new Baju();
                    inputData(bajuBaru);
                    daftarBaju.add(bajuBaru);
                    System.out.println("Produk berhasil ditambahkan!");
                    break;
                case 3:
                    System.out.println("Keluar dari program...");
                    break;
                default:
                    System.out.println("Pilihan tidak valid!");
            }
        } while (choice != 3);
    }
}