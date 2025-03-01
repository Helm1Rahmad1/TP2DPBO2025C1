<?php
include 'Baju.php';
session_start();

if (!isset($_SESSION['daftarBaju'])) {
    $_SESSION['daftarBaju'] = [
        new Baju(1, "Baju_Anjing", 100000, 10, "images/bajuanjing.jpg", "Pakaian", "Katun", "Merah", "Anjing", "M", "PetWear"),
        new Baju(2, "Baju_Kucing", 120000, 15, "images/bajukucing.jpg", "Pakaian", "Wol", "Biru", "Kucing", "L", "MeowStyle"),
        new Baju(3, "Jaket_Anjing", 150000, 8, "images/jaketanjing.jpg", "Pakaian", "Polyester", "Hitam", "Anjing", "XL", "PetCozy"),
        new Baju(4, "Kaos_Kucing", 80000, 20, "images/kaoskucing.jpg", "Pakaian", "Spandex", "Putih", "Kucing", "S", "FurFashion"),
        new Baju(5, "Rompi_Anjing", 130000, 12, "images/rompianjing.jpg", "Pakaian", "Denim", "Abu-abu", "Anjing", "M", "PawTrend")
    ];
}

$daftarBaju = $_SESSION['daftarBaju'];
$message = isset($_SESSION['message']) ? $_SESSION['message'] : "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $id = count($daftarBaju) + 1;
    $nama_produk = $_POST['nama_produk'];
    $harga_produk = $_POST['harga_produk'];
    $stok_produk = $_POST['stok_produk'];
    $jenis = $_POST['jenis'];
    $bahan = $_POST['bahan'];
    $warna = $_POST['warna'];
    $untuk = $_POST['untuk'];
    $size = $_POST['size'];
    $merk = $_POST['merk'];

    // Validasi dan proses upload gambar
    $foto_produk = "images/default.png"; // Default image
    if (!empty($_FILES['foto_produk']['name'])) {
        $allowed_extensions = ['jpg', 'jpeg', 'png'];
        $file_extension = pathinfo($_FILES['foto_produk']['name'], PATHINFO_EXTENSION);

        if (in_array(strtolower($file_extension), $allowed_extensions)) {
            $target_dir = "images/";
            $new_filename = uniqid() . "." . $file_extension; // Hindari nama file duplikat
            $target_file = $target_dir . $new_filename;

            if (move_uploaded_file($_FILES['foto_produk']['tmp_name'], $target_file)) {
                $foto_produk = $target_file;
            } else {
                $_SESSION['message'] = "Gagal mengunggah gambar!";
            }
        } else {
            $_SESSION['message'] = "Format gambar tidak didukung!";
        }
    }

    $daftarBaju[] = new Baju($id, $nama_produk, $harga_produk, $stok_produk, $foto_produk, $jenis, $bahan, $warna, $untuk, $size, $merk);
    $_SESSION['daftarBaju'] = $daftarBaju;
    $_SESSION['message'] = "Produk berhasil ditambahkan";
    header("Location: index.php");
    exit();
} else {
    unset($_SESSION['message']);
}
?>

<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PetShop</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <style>
        .container {
            display: flex;
            justify-content: space-between;
        }
        .form-container {
            width: 45%;
        }
        .table-container {
            width: 50%;
        }
        img {
            max-width: 100px;
            max-height: 100px;
            object-fit: cover;
        }
    </style>
</head>
<body>
    <div class="container mt-5">
        <div class="form-container">
            <h2 class="text-center">Tambah Produk</h2>
            <?php if (!empty($message)): ?>
                <div class="alert alert-success" role="alert">
                    <?= $message ?>
                </div>
            <?php endif; ?>
            <form method="post" enctype="multipart/form-data">
                <div class="mb-3">
                    <label>Nama Produk:</label>
                    <input type="text" name="nama_produk" class="form-control" required>
                </div>
                <div class="mb-3">
                    <label>Harga Produk:</label>
                    <input type="number" name="harga_produk" class="form-control" required>
                </div>
                <div class="mb-3">
                    <label>Stok Produk:</label>
                    <input type="number" name="stok_produk" class="form-control" required>
                </div>
                <div class="mb-3">
                    <label>Foto Produk:</label>
                    <input type="file" name="foto_produk" class="form-control">
                </div>
                <div class="mb-3">
                    <label>Jenis:</label>
                    <input type="text" name="jenis" class="form-control" required>
                </div>
                <div class="mb-3">
                    <label>Bahan:</label>
                    <input type="text" name="bahan" class="form-control" required>
                </div>
                <div class="mb-3">
                    <label>Warna:</label>
                    <input type="text" name="warna" class="form-control" required>
                </div>
                <div class="mb-3">
                    <label>Untuk:</label>
                    <input type="text" name="untuk" class="form-control" required>
                </div>
                <div class="mb-3">
                    <label>Size:</label>
                    <input type="text" name="size" class="form-control" required>
                </div>
                <div class="mb-3">
                    <label>Merk:</label>
                    <input type="text" name="merk" class="form-control" required>
                </div>
                <button type="submit" class="btn btn-primary">Tambah Produk</button>
            </form>
        </div>
        <div class="table-container">
            <h2 class="text-center">Daftar Produk PetShop</h2>
            <table class="table table-bordered table-striped mt-3">
                <thead class="table-dark">
                    <tr>
                        <th>ID</th>
                        <th>Nama Produk</th>
                        <th>Harga</th>
                        <th>Stok</th>
                        <th>Jenis</th>
                        <th>Bahan</th>
                        <th>Warna</th>
                        <th>Untuk</th>
                        <th>Size</th>
                        <th>Merk</th>
                        <th>Foto</th>
                    </tr>
                </thead>
                <tbody>
                    <?php foreach ($daftarBaju as $baju) : ?>
                        <tr>
                            <td><?= $baju->getId(); ?></td>
                            <td><?= $baju->getNamaProduk(); ?></td>
                            <td>Rp<?= number_format($baju->getHargaProduk(), 0, ',', '.'); ?></td>
                            <td><?= $baju->getStokProduk(); ?></td>
                            <td><?= $baju->getJenis(); ?></td>
                            <td><?= $baju->getBahan(); ?></td>
                            <td><?= $baju->getWarna(); ?></td>
                            <td><?= $baju->getUntuk(); ?></td>
                            <td><?= $baju->getSize(); ?></td>
                            <td><?= $baju->getMerk(); ?></td>
                            <td><img src="./<?= $baju->getFotoProduk(); ?>" alt="Foto Produk"></td>
                        </tr>
                    <?php endforeach; ?>
                </tbody>
            </table>
        </div>
    </div>
</body>
</html>