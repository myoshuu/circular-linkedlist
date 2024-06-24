#include <iostream>
#include <cstring>
#include <limits>

struct PeminjamanRuang
{
  char pinjamID[10];
  char namaRuang[255];
  char lokasi[100];
  char tanggalMulaiPinjam[10];
  char jamMulaiPinjam[5];
  char tanggalSelesaiPinjam[10];
  char jamSelesaiPinjam[5];
  char namaPeminjam[255];
  char keperluan[255];
  PeminjamanRuang *next;
};

PeminjamanRuang *head = nullptr;
PeminjamanRuang *last = nullptr;

void clearScreen()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void tambahData(const char *pinjamID, const char *namaRuang, const char *lokasi, const char *tanggalMulaiPinjam, const char *jamMulaiPinjam, const char *tanggalSelesaiPinjam, const char *jamSelesaiPinjam, const char *namaPeminjam, const char *keperluan)
{
  PeminjamanRuang *newNode = new PeminjamanRuang;
  strcpy(newNode->pinjamID, pinjamID);
  strcpy(newNode->namaRuang, namaRuang);
  strcpy(newNode->lokasi, lokasi);
  strcpy(newNode->tanggalMulaiPinjam, tanggalMulaiPinjam);
  strcpy(newNode->jamMulaiPinjam, jamMulaiPinjam);
  strcpy(newNode->tanggalSelesaiPinjam, tanggalSelesaiPinjam);
  strcpy(newNode->jamSelesaiPinjam, jamSelesaiPinjam);
  strcpy(newNode->namaPeminjam, namaPeminjam);
  strcpy(newNode->keperluan, keperluan);
  newNode->next = nullptr;

  if (head == nullptr)
  {
    head = newNode;
    last = newNode;
    last->next = head;
  }
  else
  {
    last->next = newNode;
    newNode->next = head;
    last = newNode;
  }
}

PeminjamanRuang *cariDataByPinjamID(const char *pinjamID)
{
  if (head == nullptr)
    return nullptr;

  PeminjamanRuang *curr = head;
  do
  {
    if (strcmp(curr->pinjamID, pinjamID) == 0)
      return curr;
    curr = curr->next;
  } while (curr != head);

  return nullptr;
}

void ubahData(const char *pinjamID, const char *namaRuang, const char *lokasi, const char *tanggalMulaiPinjam, const char *jamMulaiPinjam, const char *tanggalSelesaiPinjam, const char *jamSelesaiPinjam, const char *namaPeminjam, const char *keperluan)
{
  PeminjamanRuang *peminjaman = cariDataByPinjamID(pinjamID);
  if (peminjaman)
  {
    strcpy(peminjaman->namaRuang, namaRuang);
    strcpy(peminjaman->lokasi, lokasi);
    strcpy(peminjaman->tanggalMulaiPinjam, tanggalMulaiPinjam);
    strcpy(peminjaman->jamMulaiPinjam, jamMulaiPinjam);
    strcpy(peminjaman->tanggalSelesaiPinjam, tanggalSelesaiPinjam);
    strcpy(peminjaman->jamSelesaiPinjam, jamSelesaiPinjam);
    strcpy(peminjaman->namaPeminjam, namaPeminjam);
    strcpy(peminjaman->keperluan, keperluan);
  }
  else
  {
    std::cout << "Data dengan PinjamID " << pinjamID << " tidak ditemukan.\n";
  }
}

void hapusData(const char *pinjamID)
{
  if (head == nullptr)
    return;

  PeminjamanRuang *curr = head;
  PeminjamanRuang *previous = last;

  do
  {
    if (strcmp(curr->pinjamID, pinjamID) == 0)
    {
      if (curr == head && curr == last)
      {
        delete curr;
        head = nullptr;
        last = nullptr;
      }
      else if (curr == head)
      {
        head = head->next;
        last->next = head;
        delete curr;
      }
      else if (curr == last)
      {
        previous->next = head;
        last = previous;
        delete curr;
      }
      else
      {
        previous->next = curr->next;
        delete curr;
      }
      return;
    }
    previous = curr;
    curr = curr->next;
  } while (curr != head);
}

void cetakData()
{
  if (head == nullptr)
  {
    std::cout << "Tidak ada data peminjaman ruang.\n";
    std::cout << "Tekan tombol apapun untuk melanjutkan...";
    std::cin.ignore();
    std::cin.get();
    return;
  }

  PeminjamanRuang *curr = head;
  do
  {
    std::cout << "PinjamID: " << curr->pinjamID << std::endl
              << "Nama Ruang: " << curr->namaRuang << std::endl
              << "Lokasi: " << curr->lokasi
              << std::endl
              << "Tanggal Mulai Pinjam: " << curr->tanggalMulaiPinjam << std::endl
              << "Jam Mulai Pinjam: " << curr->jamMulaiPinjam
              << std::endl
              << "Tanggal Selesai Pinjam: " << curr->tanggalSelesaiPinjam << std::endl
              << "Jam Selesai Pinjam: " << curr->jamSelesaiPinjam
              << std::endl
              << "Nama Peminjam: " << curr->namaPeminjam << std::endl
              << "Keperluan: " << curr->keperluan << std::endl;
    curr = curr->next;
  } while (curr != head);
  std::cout << "Tekan tombol apapun untuk melanjutkan...";
  std::cin.ignore();
  std::cin.get();
}

void tungguInput()
{
  std::cout << "Tekan tombol apapun untuk melanjutkan...";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
}

int main()
{
  int pilihan;
  char pinjamID[20], namaRuang[50], lokasi[50], tanggalMulaiPinjam[15], jamMulaiPinjam[10], tanggalSelesaiPinjam[15], jamSelesaiPinjam[10], namaPeminjam[50], keperluan[100];

  do
  {
    clearScreen();
    std::cout << "Menu:\n";
    std::cout << "1. Input/tambah data\n";
    std::cout << "2. Cari data berdasarkan PinjamID\n";
    std::cout << "3. Ubah data\n";
    std::cout << "4. Hapus data\n";
    std::cout << "5. Cetak semua data\n";
    std::cout << "6. Keluar\n";
    std::cout << "Pilihan: ";
    std::cin >> pilihan;

    switch (pilihan)
    {
    case 1:
      clearScreen();
      std::cout << "Masukkan PinjamID: ";
      std::cin >> pinjamID;
      std::cout << "Masukkan Nama Ruang: ";
      std::cin.ignore();
      std::cin.getline(namaRuang, 50);
      std::cout << "Masukkan Lokasi: ";
      std::cin.getline(lokasi, 50);
      std::cout << "Masukkan Tanggal Mulai Pinjam (DD-MM-YYYY): ";
      std::cin.getline(tanggalMulaiPinjam, 15);
      std::cout << "Masukkan Jam Mulai Pinjam (HH:MM): ";
      std::cin.getline(jamMulaiPinjam, 10);
      std::cout << "Masukkan Tanggal Selesai Pinjam (DD-MM-YYYY): ";
      std::cin.getline(tanggalSelesaiPinjam, 15);
      std::cout << "Masukkan Jam Selesai Pinjam (HH:MM): ";
      std::cin.getline(jamSelesaiPinjam, 10);
      std::cout << "Masukkan Nama Peminjam: ";
      std::cin.getline(namaPeminjam, 50);
      std::cout << "Masukkan Keperluan: ";
      std::cin.getline(keperluan, 100);
      tambahData(pinjamID, namaRuang, lokasi, tanggalMulaiPinjam, jamMulaiPinjam, tanggalSelesaiPinjam, jamSelesaiPinjam, namaPeminjam, keperluan);
      break;
    case 2:
      clearScreen();
      std::cout << "Masukkan PinjamID yang dicari: ";
      std::cin >> pinjamID;
      if (PeminjamanRuang *pr = cariDataByPinjamID(pinjamID))
      {
        std::cout << "PinjamID: " << pr->pinjamID << std::endl
                  << "Nama Ruang: " << pr->namaRuang << std::endl
                  << "Lokasi: " << pr->lokasi
                  << std::endl
                  << "Tanggal Mulai Pinjam: " << pr->tanggalMulaiPinjam << std::endl
                  << "Jam Mulai Pinjam: " << pr->jamMulaiPinjam
                  << std::endl
                  << "Tanggal Selesai Pinjam: " << pr->tanggalSelesaiPinjam << std::endl
                  << "Jam Selesai Pinjam: " << pr->jamSelesaiPinjam
                  << std::endl
                  << "Nama Peminjam: " << pr->namaPeminjam << std::endl
                  << "Keperluan: " << pr->keperluan << std::endl;
      }
      else
      {
        std::cout << "Data tidak ditemukan.\n";
      }
      tungguInput();
      break;
    case 3:
      clearScreen();
      std::cout << "Masukkan PinjamID yang akan diubah: ";
      std::cin >> pinjamID;
      std::cout << "Masukkan Nama Ruang baru: ";
      std::cin.ignore();
      std::cin.getline(namaRuang, 50);
      std::cout << "Masukkan Lokasi baru: ";
      std::cin.getline(lokasi, 50);
      std::cout << "Masukkan Tanggal Mulai Pinjam baru (DD-MM-YYYY): ";
      std::cin.getline(tanggalMulaiPinjam, 15);
      std::cout << "Masukkan Jam Mulai Pinjam baru (HH:MM): ";
      std::cin.getline(jamMulaiPinjam, 10);
      std::cout << "Masukkan Tanggal Selesai Pinjam baru (DD-MM-YYYY): ";
      std::cin.getline(tanggalSelesaiPinjam, 15);
      std::cout << "Masukkan Jam Selesai Pinjam baru (HH:MM): ";
      std::cin.getline(jamSelesaiPinjam, 10);
      std::cout << "Masukkan Nama Peminjam baru: ";
      std::cin.getline(namaPeminjam, 50);
      std::cout << "Masukkan Keperluan baru: ";
      std::cin.getline(keperluan, 100);
      ubahData(pinjamID, namaRuang, lokasi, tanggalMulaiPinjam, jamMulaiPinjam, tanggalSelesaiPinjam, jamSelesaiPinjam, namaPeminjam, keperluan);
      tungguInput();
      break;
    case 4:
      clearScreen();
      std::cout << "Masukkan PinjamID yang akan dihapus: ";
      std::cin >> pinjamID;
      hapusData(pinjamID);
      tungguInput();
      break;
    case 5:
      cetakData();
      break;
    case 6:
      return 0;
    default:
      std::cout << "Pilihan tidak valid.\n";
      tungguInput();
    }
  } while (pilihan != 6);
}
