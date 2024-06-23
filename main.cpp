#include <iostream>
#include <string>

struct Mahasiswa
{
  int nim;
  std::string nama;
  std::string jurusan;
  Mahasiswa *next;
};

Mahasiswa *head = nullptr;
Mahasiswa *last = nullptr;

void tambahData(int nim, const std::string &nama, const std::string &jurusan)
{
  Mahasiswa *newNode = new Mahasiswa{nim, nama, jurusan, nullptr};
  if (head == nullptr)
  {
    head = newNode;
    last = newNode;
    last->next = head;
  }
  else
  {
    newNode->next = head;
    last->next = newNode;
    last = newNode;
  }
}

Mahasiswa *cariDataByNim(int nim)
{
  if (head == nullptr)
    return nullptr;

  Mahasiswa *curr = head;
  do
  {
    if (curr->nim == nim)
      return curr;
    curr = curr->next;
  } while (curr != head);

  return nullptr;
}

void ubahData(int nim, const std::string &nama, const std::string &jurusan)
{
  Mahasiswa *mahasiswa = cariDataByNim(nim);
  if (mahasiswa)
  {
    mahasiswa->nama = nama;
    mahasiswa->jurusan = jurusan;
  }
  else
  {
    std::cout << "Data dengan NIM " << nim << " tidak ditemukan.\n";
  }
}

// Fungsi untuk menghapus data mahasiswa
void hapusData(int nim)
{
  if (head == nullptr)
    return;

  Mahasiswa *curr = head;
  Mahasiswa *previous = last;

  do
  {
    if (curr->nim == nim)
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

// Fungsi untuk mencetak semua data mahasiswa
void cetakData()
{
  if (head == nullptr)
  {
    std::cout << "Tidak ada data mahasiswa.\n";
    return;
  }

  Mahasiswa *curr = head;
  do
  {
    std::cout << "NIM: " << curr->nim << ", Nama: " << curr->nama << ", Jurusan: " << curr->jurusan << std::endl;
    curr = curr->next;
  } while (curr != head);
}

int main()
{
  int pilihan, nim;
  std::string nama, jurusan;

  while (true)
  {
    std::cout << "Menu:\n";
    std::cout << "1. Input/tambah data\n";
    std::cout << "2. Cari data berdasarkan NIM\n";
    std::cout << "3. Ubah data\n";
    std::cout << "4. Hapus data\n";
    std::cout << "5. Cetak semua data\n";
    std::cout << "6. Keluar\n";
    std::cout << "Pilihan: ";
    std::cin >> pilihan;

    switch (pilihan)
    {
    case 1:
      std::cout << "Masukkan NIM: ";
      std::cin >> nim;
      std::cout << "Masukkan Nama: ";
      std::cin.ignore();
      std::getline(std::cin, nama);
      std::cout << "Masukkan Jurusan: ";
      std::getline(std::cin, jurusan);
      tambahData(nim, nama, jurusan);
      break;
    case 2:
      std::cout << "Masukkan NIM yang dicari: ";
      std::cin >> nim;
      if (Mahasiswa *mhs = cariDataByNim(nim))
      {
        std::cout << "Data ditemukan: NIM: " << mhs->nim << ", Nama: " << mhs->nama << ", Jurusan: " << mhs->jurusan << std::endl;
      }
      else
      {
        std::cout << "Data tidak ditemukan.\n";
      }
      break;
    case 3:
      std::cout << "Masukkan NIM yang akan diubah: ";
      std::cin >> nim;
      std::cout << "Masukkan Nama baru: ";
      std::cin.ignore();
      std::getline(std::cin, nama);
      std::cout << "Masukkan Jurusan baru: ";
      std::getline(std::cin, jurusan);
      ubahData(nim, nama, jurusan);
      break;
    case 4:
      std::cout << "Masukkan NIM yang akan dihapus: ";
      std::cin >> nim;
      hapusData(nim);
      break;
    case 5:
      cetakData();
      break;
    case 6:
      return 0;
    default:
      std::cout << "Pilihan tidak valid.\n";
    }
  }
}
