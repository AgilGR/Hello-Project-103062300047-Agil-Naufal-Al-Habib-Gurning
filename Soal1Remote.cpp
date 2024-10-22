#include <iostream>
using namespace std;

int main() {
    int angka[] = {1, 3, 4, 1, 2, 3, 1}; // array angka yang diberikan
    int n = 7; // ukuran dari array angka

    int hasil[100][100]; // array 2D untuk menyimpan hasil
    int ukuranBaris[100] = {0}; // array untuk menyimpan jumlah elemen di tiap baris
    bool sudahDipakai[101] = {false}; // array untuk menandai angka yang sudah dipakai
    int barisSekarang = 0; // indeks untuk baris yang sedang diproses

    int kolomSekarang = 0; // indeks kolom untuk elemen dalam baris
    for (int i = 0; i < n; i++) {
        if (!sudahDipakai[angka[i]]) {
            hasil[barisSekarang][kolomSekarang++] = angka[i]; // tambahkan elemen ke baris sekarang
            sudahDipakai[angka[i]] = true; // tandai elemen sudah dipakai
            ukuranBaris[barisSekarang]++; // tambahkan jumlah elemen di baris ini
        } else {
            barisSekarang++; // pindah ke baris baru
            kolomSekarang = 0; // reset kolom ke awal
            fill(sudahDipakai, sudahDipakai + 101, false); // reset tanda sudah dipakai
            hasil[barisSekarang][kolomSekarang++] = angka[i]; // tambahkan elemen pertama di baris baru
            sudahDipakai[angka[i]] = true; // tandai elemen sudah dipakai
            ukuranBaris[barisSekarang]++; // tambahkan jumlah elemen di baris ini
        }
    }

    // Tampilkan hasil
    cout << "Hasil: [";
    for (int i = 0; i <= barisSekarang; i++) {
        cout << "[";
        for (int j = 0; j < ukuranBaris[i]; j++) {
            cout << hasil[i][j];
            if (j != ukuranBaris[i] - 1) cout << ",";
        }
        cout << "]";
        if (i != barisSekarang) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
